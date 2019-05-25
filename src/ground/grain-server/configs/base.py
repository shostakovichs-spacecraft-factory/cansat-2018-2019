import logging
from datetime import timedelta

# Общие настройки
LOG_LEVEL = logging.ERROR
""" уровень логгирования """

REDIS_URL = "redis://:@localhost:6379/0"
""" Адрес редис сервера """

# Настройки connector app
# ==================================================

CONN_PLOT_DATA_PBACK = timedelta(seconds=120)
""" Интервал времени в течение которого будут хранится даннные телеметрии для отображения от "сейчас" """

CONN_LISTEN_URL = 'udpin:0.0.0.0:11000'
""" Адрес для mavutil, на котором служба будет слушать сообщения """

CONN_LOG_LEVEL = LOG_LEVEL
""" Уровень логирования демона """


# Настройки iridium app
# ==================================================



# Настройки веб службы
# ==================================================
WEB_LOG_LEVEL = LOG_LEVEL

PLOT_DATA_UPDATE_PERIOD_MS = 500
""" период обновления графиков (в мс) """

MODEL_DATA_UPDATE_PERIOD_MS = 100
""" период обновления модели (в мс) """

SPECTRUM_DATA_UPDATE_PERIOD_MS = 1000
""" период обновления модели (в мс) """

STATUS_DATA_UPDATE_PERIOD_MS = 1000
""" период обновления статуса (в мс) """

IMU_PLOT_SCOPE_MS = timedelta(seconds=15)
""" Диапазон отображения на графике последних данных с IMU"""

PRESSTEMP_PLOT_SCOPE_MS = timedelta(seconds=15)
""" Диапазон отображения на графиках последних данных температуры и давления"""
PRESSTEMP_INTERNAL_PLOT_SCOPE_MS = PRESSTEMP_PLOT_SCOPE_MS
PRESSTEMP_EXTERNAL_PLOT_SCOPE_MS = PRESSTEMP_PLOT_SCOPE_MS

MAP_PLOT_SCOPE_MS = timedelta(seconds=15)
""" Диапазон отображения на графике последних данных положения """