import click
from .app_singleton import app

from .redis_store import redis_store


@app.cli.command()
def create_database():
    pass


@app.cli.command()
def test_redis():
    value = redis_store.get("harharhar")
    print(value)

