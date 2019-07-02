#!/bin/bash

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")
MAVLINKDIR=$BASEDIR/../../common/mavlink

export MDEF=$MAVLINKDIR/message_definitions
pushd "$MAVLINKDIR/pymavlink"
python setup.py bdist_wheel

popd
PACKAGE=$(find "$MAVLINKDIR/pymavlink/dist" -name "pymavlink*.whl")
PACKAGE=$(echo $PACKAGE | head -n 1)
python -m pip install -U "$PACKAGE" 
