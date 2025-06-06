esptool.exe --chip esp32s3 --port COM38 --baud 921600  --before default_reset --after hard_reset write_flash  -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0 CYC.ino.bootloader.bin 0x8000 CYC.ino.partitions.bin 0xe000 boot_app0.bin 0x10000 CYC.ino.bin 
pause
mklittlefs.exe -c data -p 256 -b 4096 -s 917504 littlefs.bin 
esptool.exe --chip esp32s3 --port COM38 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 3211264 littlefs.bin 
pause
