from flask import Blueprint, render_template, abort, url_for
from jinja2 import TemplateNotFound

pages = Blueprint('pages', __name__, url_prefix="/")


@pages.route('/')
def landing():
    try:
        return render_template('landing.html')
    except TemplateNotFound:
        abort(404)


@pages.route("overview/")
def overview():
    try:
        return render_template('overview.html')
    except TemplateNotFound:
        abort(404)


@pages.route("plots/")
def plots():
    try:
        return render_template('plots.html')
    except TemplateNotFound:
        abort(404)
