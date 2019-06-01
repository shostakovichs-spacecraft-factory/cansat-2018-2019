CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
export PYTHONPATH=$PYTHONPATH:$CURRENT_DIR/

export FLASK_APP=webapp
export MAVLINK20=True
export MAVLINK_DIALECT=zikush
export GRAIN_CONFIG=configs.dev

if [ $# -ge 1 ]
	then
		source "$1/bin/activate"
fi
