#!/bin/bash
PORT=/dev/ttyUSB0
ESPTOOL=~/.arduino15/packages/esp32/tools/esptool_py/4.9.dev3/esptool
MKLITTLE=~/.arduino15/packages/esp32/tools/mklittlefs/3.0.0-gnu12-dc7f933/mklittlefs
BAUD=460800
$ESPTOOL --chip esp32s3 --port $PORT --baud $BAUD  --before default_reset --after hard_reset write_flash  -z --flash_mode dio --flash_freq 80m --flash_size 16MB 0x0 CYC.ino.bootloader.bin 0x8000 CYC.ino.partitions.bin 0xe000 boot_app0.bin 0x10000 CYC.ino.bin 
$MKLITTLE -c data -p 256 -b 4096 -s 917504 littlefs.bin
$ESPTOOL --chip esp32s3 --port $PORT --baud $BAUD --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 3211264 littlefs.bin 
#pause
