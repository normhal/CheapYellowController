# Setting up Platformio

# Elecrow display boards (all variants)

Download the Elecrow board description here:

https://www.elecrow.com/download/product/CrowPanel/ESP32-HMI/5.0-DIS07050H/PIO-Tutorial/esp32-s3-devkitc-1-myboard.zip

Unzip the file and place the json file here:

Windows:
C:\Users\<>\.platformio\platforms\espressif32\boards

Linux:
/home/<>/.platformio\platforms\espressif32\boards

Where <> is your username.

More details are available on the Elecrow website here:



Compiling:

1. Clone this respository
2. Open the folder in platformio
3. Upload
4. Build Filesystem Image
5. Upload Filesystem Image

More details:

Platformio will collect the necessary libraries while compiling before upload.  This will only occur the first time you compile the program.


Display boards currently defined in platformio.ini

Elecrow_DIS06043H       Elecrow 4.3" 480x272 model DIS06043H resistive touch
Elecrow_DIS08070H       Elecrow 7.0" 800x480 model DIS08070H capacitive touch

