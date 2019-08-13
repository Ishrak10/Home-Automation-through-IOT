# Home_Automation

An implementation of Internet of things in which various electronic devices are controlled using a smartphone.

Hardware used :
- Node MCU ESP8266 wifi microcontroller
- 4-channel relay
- Breadboard
- Jumperwires
- Smartphone
- USB cable
- Laptop

Software used :
- Arduino IDE
- Notepad++

Working :
- User can toggle devices from status.php webpage
- Evertime the webpage is submitted, it redeirects to 2.php along with 4 variable values, each for the four devices
- 2.php also updates the values of table in the server database for future references
- HomeAutomation.ino is Arduino sketch that reads data from 2.php after every 5 seconds
- The pins are given output according to the data read by Node MCU from 2.php page
