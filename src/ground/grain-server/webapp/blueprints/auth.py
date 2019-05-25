from flask import Blueprint, jsonify, request, current_app, send_file

from ...common import definitions as common_definitions


auth = Blueprint('auth', __name__, url_prefix="/auth")