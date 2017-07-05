#!/bin/sh
# (C) 2017 depply@126.com

disable_jtag_enable_gpio03() {
        DISABLE_JTAG=0x2
        GPIO_FUNCTION=`devmem2 0x1804006c  | grep "Value at address" | cut -d ':' -f2`
        echo $DISABLE_JTAG,$GPIO_FUNCTION

        let "val=$GPIO_FUNCTION|$DISABLE_JTAG"
        newVal=`printf "%x\n" $val`

        #echo 0x$newVal
        devmem2 0x1804006c w 0x$newVal
}

disable_jtag_enable_gpio03

local statue=down

while true; do
        wan_addr=`ifconfig wwan0 | grep "inet addr"`
        if [ "x$wan_addr" != "x" ]; then
                echo "4G is up, ignore!!!"
                statue=up
        else
                echo "4G is down, redial!!!"
                statue=down
                ndist
        fi

        signal_led=`cat /sys/class/leds/ap147\:green\:signal/brightness`
        net_led=`cat /sys/class/leds/ap147\:green\:net/brightness`

        if [ "$statue" = "up" ]; then
                if [ "$signal_led" = "0" ]; then
                        echo 1 > /sys/class/leds/ap147\:green\:signal/brightness
                        echo 1 > /sys/class/leds/ap147\:green\:net/brightness
                else
                        echo ignore!!!
                fi
        else
                if [ "$signal_led" = "1" ]; then
                        echo 0 > /sys/class/leds/ap147\:green\:signal/brightness
                        echo 0 > /sys/class/leds/ap147\:green\:net/brightness
                else
                        echo ignore!!!
                fi
        fi

        sleep 30
done
