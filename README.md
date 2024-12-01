# voice-led
## Installation
* [Arduino IDE on Windows/Linux/Mac](https://www.arduino.cc/en/software)
* [DSDTECHBluetooth on iOS](https://apps.apple.com/us/app/dsd-tech-bluetooth/id1441528159)
## Hardware Components
* Elegoo Arduino UNO R3 Super Starter Kit
* DSD Tech HM-10 Bluetooth Module
* KY-038 Sound Sensor
## Instructions
Open the Arduino IDE on your computer. Download 321project.ino and open the sketch. Connect the Arduino UNO R3 and your computer via USB cable. Upload the sketch onto the Arduino, and open the DSDTECHBluetooth app on your phone. Make sure Bluetooth is turned on on your phone in order to find the "DSD TECH" device. After connecting to it, the LED should be blue. Sending a 1 would turn on the sound sensor and allow for noise detection. If the sensor does not detect any sound, the LED would be turned off. If the sensor detected modrate sound, it will turn green. If it detects a sound of high volume, the LED will turn red. Sending any number that is not 1 will turn the LED Blue again. 