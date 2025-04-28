"esptool.exe" --chip esp32s3 --port "COM8" --baud 921600  --before default_reset --after hard_reset write_flash  -z --flash_mode keep --flash_freq keep --flash_size keep 0x0 "CYC.ino.bootloader.bin" 0x8000 "CYC.ino.partitions.bin" 0xe000 "boot_app0.bin" 0x10000 "CYC.ino.bin" 
"mklittlefs.exe" -c "data" -p 256 -b 4096 -s 131072 "littlefs.bin" 
pause
"esptool.exe" --chip esp32s3 --port "COM8" --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 3997696 "littlefs.bin" 
