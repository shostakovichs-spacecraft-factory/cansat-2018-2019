import os

from flask import Config as FlaskConfig


class Config(FlaskConfig):
    pass


def get_config():
    retval = Config(os.path.abspath(__file__))
    retval.from_object(os.environ["GRAIN_CONFIG"])
    return retval

