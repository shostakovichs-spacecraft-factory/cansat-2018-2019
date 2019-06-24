from flask import Blueprint, jsonify, request, current_app, send_file, redirect, url_for, sessions
from flask_login import login_user, logout_user, current_user

from ...common import definitions as common_definitions

from ..auth import totp, OnlyUser


auth = Blueprint('auth', __name__, url_prefix="/auth")

@auth.route("/login", methods=["PUT"])
def login():

    if not current_user.is_authenticated:
        try:
            passcode = int(request.args.get("passcode") )
            if totp.verify(passcode):
                login_user(OnlyUser())
        except:
            pass

    return redirect( request.args.get('next') or url_for('/') )

@auth.route("/logout", methods=["PUT"])
def logout():
    if current_user.is_authenticated:
        logout_user()

    return redirect( request.args.get('next') or url_for('/') )
