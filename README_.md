# Room_automation
This is an application of IOT in real life.

Here, I controlled 2 lights , a fan and a plug socket using the following :
Node MCU
Arduino IDE
4-channel relay
6 maleToMale wires
USB cord
Adapter

Repository contains 2 php files :
1.) Select.php
    This php file is used to select whether the lights should be ON or OFF.
    It sends the variables to display.php
    
2.) Display.php
    This php file takes variables from select.php and changes the value of variables of the code of Arduino IDE.
