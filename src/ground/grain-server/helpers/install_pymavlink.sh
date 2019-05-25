#!/bin/sh

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")
MAVLINKDIR=$BASEDIR/../../../common/mavlink

echo $BASEDIR
export MDEF=$MAVLINKDIR/message_definitions
cd $MAVLINKDIR/pymavlink

python setup.py bdist_wheel
cd $BASEDIR

yes | python -m pip uninstall pymavlink
python -m pip install pymavlink --no-index --find-links=$MAVLINKDIR/pymavlink/dist
