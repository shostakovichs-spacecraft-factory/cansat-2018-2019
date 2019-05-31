import os
import logging

from flask import Flask

from .assets import assets
from .redis_store import redis_store
from .auth import loginmanager

from .blueprints.pages import pages
from .blueprints.data import data
from .blueprints.gl_test import gl_test
from .blueprints.auth import auth

app = Flask(
    __name__,
    static_folder="static",
    template_folder="templates"
)

app.config.from_object(os.environ["GRAIN_CONFIG"])
log = logging.getLogger('werkzeug')
log.setLevel(app.config["WEB_LOG_LEVEL"])

assets.init_app(app)
redis_store.init_app(app)
loginmanager.init_app(app)

app.register_blueprint(pages)
app.register_blueprint(data)
app.register_blueprint(gl_test)
app.register_blueprint(auth)