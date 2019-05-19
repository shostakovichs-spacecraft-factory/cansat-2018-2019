import csv
import os

from pymavlink import mavutil


class PictureAcceptor:
    def __init__(self):
        pass

    def accept(self, data, identifier):
        raise NotImplementedError


class PictureSaver(PictureAcceptor):
    def __init__(self, filename_template='spectrum/spectrum_%d_img.png'):
        super().__init__()

        self.filename_template = filename_template

    def accept(self, data, identifier):
        filename = self.filename_template % identifier

        if not os.path.exists(os.path.dirname(filename)):
            try:
                os.makedirs(os.path.dirname(filename))
            except OSError as exc:  # Guard against race condition
                if exc.errno != errno.EEXIST:
                    raise

        if identifier != 0:
            previous = self.filename_template % (identifier - 1)
            os.remove(previous)

        with open(filename, mode="wb") as output:
            output.write(bytes(data))
            output.flush()
            print("picture saved")


class PictureListener:
    DATA_PACKETS_COUNT = 0
    TOTAL_SIZE = 0
    WHOLE_DATA = []
    OUTPUT_DIR = ""
    number_of_whole_packages = 0
    state = "IDLE"

    def __init__(self, acceptor=PictureSaver()):
        self.acceptor = acceptor

    def accept_data(self, data, seqnr):
        self.WHOLE_DATA += data
        if seqnr == self.DATA_PACKETS_COUNT - 1:  # if last package
            self.WHOLE_DATA = self.WHOLE_DATA[:self.TOTAL_SIZE]
            self.number_of_whole_packages += 1

            self.acceptor.accept(self.WHOLE_DATA, self.number_of_whole_packages - 1)

            self.state = "IDLE"


class SpectrumAcceptor:
    def __init__(self):
        pass

    def accept(self, data, identifier):
        raise NotImplementedError


class SpectrumSaver(SpectrumAcceptor):
    def __init__(self, filename_template='spectrum/spectrum_%d.csv'):
        super().__init__()

        self.filename_template = filename_template

    def accept(self, data, identifier):
        with open(self.filename_template % identifier, mode="w", newline="") as ostream:
            fieldnames = ["nm", "intensity"]
            writer = csv.DictWriter(ostream, fieldnames)
            writer.writeheader()

            i = 0
            for el in data:
                nm = i
                intensity = el
                row = {"nm": nm, "intensity": intensity}
                writer.writerow(row)
                i += 1

            print("spectrum saved")


class SpectrumListener:
    DATA_PACKETS_COUNT = 0
    TOTAL_SIZE = 0
    WHOLE_DATA = []
    number_of_whole_packages = 0
    state = "IDLE"

    def __init__(self, acceptor=SpectrumSaver):
        self.acceptor = acceptor

    def accept_data(self, data, seqnr):
        self.WHOLE_DATA += data
        if seqnr == self.DATA_PACKETS_COUNT - 1:  # if last package
            self.WHOLE_DATA = self.WHOLE_DATA[:self.TOTAL_SIZE]
            self.number_of_whole_packages += 1

            self.acceptor.accept(self.WHOLE_DATA, self.number_of_whole_packages - 1)

            self.state = "IDLE"


class SpectrumAggregator:

    def __init__(self, spectrum_acceptor=SpectrumSaver, picture_acceptor=PictureSaver):
        self.picture_listener = PictureListener(acceptor=picture_acceptor)
        self.spectrum_listener = SpectrumListener(acceptor=spectrum_acceptor)
        self.picture_index_we_wait_for = 0
        self.spectrum_index_we_wait_for = 0

    def accept_message(self, msg):
        if self.picture_listener.state == "IDLE":  # ждем заголовка
            if msg.get_type() == "PICTURE_HEADER":  # получили заголовок картинки
                self.picture_listener.WHOLE_DATA = []
                self.picture_index_we_wait_for = 0
                self.picture_listener.DATA_PACKETS_COUNT = msg.packets
                self.picture_listener.TOTAL_SIZE = msg.size
                self.picture_listener.state = "ACCUM"

        elif self.picture_listener.state == "ACCUM":  # ждем данных
            if msg.get_type() == "ENCAPSULATED_DATA":
                seqnr = msg.seqnr
                if seqnr < self.picture_index_we_wait_for:
                    pass
                elif seqnr > self.picture_index_we_wait_for:
                    self.picture_listener.state = "IDLE"
                elif seqnr == self.picture_index_we_wait_for:
                    self.picture_listener.accept_data(data=msg.data, seqnr=seqnr)
                    self.picture_index_we_wait_for += 1

        if self.spectrum_listener.state == "IDLE":  # ждем заголовка
            if msg.get_type() == "INTENSITY_HEADER":  # получили заголовок спектра
                self.spectrum_listener.WHOLE_DATA = []
                self.spectrum_index_we_wait_for = 0
                self.spectrum_listener.DATA_PACKETS_COUNT = msg.packets
                self.spectrum_listener.TOTAL_SIZE = msg.size
                self.spectrum_listener.state = "ACCUM"

        elif self.spectrum_listener.state == "ACCUM":  # ждем данных
            if msg.get_type() == "INTENSITY_ENCAPSULATED_DATA":
                seqnr = msg.seqnr
                if seqnr < self.spectrum_index_we_wait_for:
                    pass
                elif seqnr > self.spectrum_index_we_wait_for:
                    self.spectrum_listener.state = "IDLE"
                elif seqnr == self.spectrum_index_we_wait_for:
                    self.spectrum_listener.accept_data(data=msg.data, seqnr=seqnr)
                    self.spectrum_index_we_wait_for += 1


def main():
    connection = mavutil.mavlink_connection("udpin:0.0.0.0:11000")
    spectrumAggregator = SpectrumAggregator()

    while True:
        msg = connection.recv_match(blocking=True)
        print(msg)
        spectrumAggregator.accept_message(msg)


if __name__ == "__main__":
    main()
