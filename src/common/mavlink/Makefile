
# Каталог с входными файлами
MSGDEFS_DIR = message_definitions/v1.0
# Список имен входных файлов
MSGDEFS_NAMES = granum.xml
# Список путей до входных файлов
MSGDEFS = $(addprefix $(MSGDEFS_DIR)/, $(MSGDEFS_NAMES))

# Базовая строка вызова питоновского генератора
PY_GENERATOR_CALL = python3 -m pymavlink.tools.mavgen --lang=Python --wire-protocol=2.0 
# Выходной каталог для питоновских файлов
PY_GENERATOR_OUTDIR = pymavlink/dialects/v20
# Список путей питоновских выходных файлов
PYTHON_TARGETS = $(patsubst %.xml, $(PY_GENERATOR_OUTDIR)/%.py, $(MSGDEFS_NAMES))

# Базовая строка вызова для сишнего генератора
C_GENERATOR_CALL = python3 -m pymavlink.tools.mavgen --lang=C --wire-protocol=2.0
# Выходной каталог для сишных файлов
C_GENERATOR_OUTDIR = generated/c
# Файл-штамп, использующийся для проверки сишных файлов на устаревание
C_GENERATOR_STAMP = $(C_GENERATOR_OUTDIR)/include/mavlink/protocol.h


$(C_GENERATOR_STAMP): $(MSGDEFS)
	@echo "Генерю сишники для файлов $(MSGDEFS)"
	$(C_GENERATOR_CALL) --output=$(C_GENERATOR_OUTDIR)/include/mavlink $(MSGDEFS)

$(PY_GENERATOR_OUTDIR)/%.py: $(MSGDEFS_DIR)/%.xml
	@echo "генерю питоновский объект для файла $<"
	mkdir -p $(PY_GENERATOR_OUTDIR) # Питон сам не может :/ 
	$(PY_GENERATOR_CALL) --output=$@ $<


.PHONY: gen-c gen-py all clean 


gen-c: $(C_GENERATOR_STAMP)

gen-py: $(PYTHON_TARGETS)

all: gen-c gen-py

clean:
	rm -rf ./generated
	rm -f $(PYTHON_TARGETS)
