#!/bin/sh
SERVICE='python ./run_p2pool.py --net lirecoin'

if ps ax | grep -v grep | grep "$SERVICE" > /dev/null
then
        echo "$SERVICE is already running!"
else
        screen -d -m -S P2P_DRK_DIFF python ./run_p2pool.py --net lirecoin --give-author 0 --disable-upnp -f 1 -a 8z4tu5GN6YckiXrqF6e9wUCxuVLFQJS5cm

	wait
fi
