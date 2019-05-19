from flask import Blueprint, render_template, abort, jsonify, request, current_app
from jinja2 import TemplateNotFound


gl_test = Blueprint('gl_test', __name__, url_prefix="/gl_test")


@gl_test.route('/')
def gl_test_index():
    try:
        return render_template('gl_test.html')
    except TemplateNotFound:
        abort(404)

