import os
from base64 import b32encode

from flask_login import LoginManager, UserMixin
import pyotp

loginmanager = LoginManager()
secret = os.environ["TOTP_SECRET"]
totp = pyotp.TOTP( b32encode( bytes(secret, "utf8") ) )

del(secret)

class OnlyUser(UserMixin):
    def __init__(self):
        self.id = "0"

@loginmanager.user_loader
def load_user(id):
    if id == "0":
        return OnlyUser()

    return None
