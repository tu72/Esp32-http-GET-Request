# ESP32 WiFi Data Fetcher

This project allows an ESP32 board to connect to WiFi and fetch data from a local server running on your Windows PC.

## Prerequisites

1. ESP32 board (i have the ESP32-WROOM-32)
2. USB cable to connect ESP32 to your PC
3. Windows PC
4. Arduino IDE installed on your PC

## Setup Instructions

1. Install Arduino IDE:
   - Download and install Arduino IDE from https://www.arduino.cc/en/software

2. Install ESP32 board support in Arduino IDE:
   - Open Arduino IDE
   - Go to File > Preferences
   - In "Additional Boards Manager URLs", add: https://dl.espressif.com/dl/package_esp32_index.json
   - ![image](https://github.com/user-attachments/assets/253fffd6-7346-48e3-bd44-ad6334736590)

   - Go to Tools > Board > Boards Manager
   - Search for "esp32" and install "ESP32 by Espressif Systems"
   - ![image](https://github.com/user-attachments/assets/cdeb3af5-a626-4de2-8882-43bb5854f181)


3. Set up a local web server on your Windows PC (more details in here https://github.com/tu72/html-php-MySql-example )
   - Start Apache server in XAMPP Control Panel
   - ![image](https://github.com/user-attachments/assets/fa9547f9-8991-44e3-a01d-601c7adab12e)

   - copy the file named `fetchLastInput.php` to `C:\xampp\htdocs\` (if you followed https://github.com/tu72/html-php-MySql-example you don't have to do this step)

4. Modify the code: (fetchLastInput.ino)
   - Replace `YourWiFiSSID` with your actual WiFi network name
   - Replace `YourWiFiPassword` with your actual WiFi password
   - Replace `your-computer-ip-address` in `serverName` with your PC's local IP address
     (You can find this by opening Command Prompt and typing `ipconfig`)

5. Upload the code:
   - Connect your ESP32 to your PC via USB
   - In Arduino IDE, go to Tools > Board and select your ESP32 board
   - ![image](https://github.com/user-attachments/assets/998c34d0-f0d8-4cb6-923b-19458daf57af)
   - Click the Upload button (right arrow icon)

6. Monitor output:
   - Open the Serial Monitor (Tools > Serial Monitor) to view the ESP32's output (in this case we are using baud 115200)
   - ![image](https://github.com/user-attachments/assets/7bbd7eb1-8121-4497-957a-0249c3f28818)


## Troubleshooting

- Ensure your PC and ESP32 are on the same WiFi network
- Check that your firewall isn't blocking the connection
- Verify that Apache is running and `fetchLastInput.php` is accessible via web browser
