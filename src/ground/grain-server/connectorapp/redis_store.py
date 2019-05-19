from redis.connection import ConnectionPool
from redis.client import StrictRedis

from ..common.config import get_config


pool = ConnectionPool.from_url(get_config()["REDIS_URL"])

redis_store = StrictRedis(connection_pool=pool)
