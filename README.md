# Arduino-Temperature-Humidity-sensor

Measure the temperature and humidity and auto upload to the google drive

## Prepare a ESP8266 and DHT11 sensor
![esp8266](https://user-images.githubusercontent.com/90837134/176456931-0bdd932a-8ad2-47f4-8a18-7ea2d486adda.jpg)
![dht11](https://user-images.githubusercontent.com/90837134/176457280-3f3dc1d3-6e2e-494b-aa0e-4aafbb03c1ce.jpg)

If you are just getting started with the Nodemcu ESP8266 and DHT11 Temperature and Humidity sensor then these are the minimal connections that you will need for this project. You can power up your Nodemcu module using your laptop. Connect the VCC and GND pins of the DHT11 sensor with the 3.3V and GND pins of the Nodemcu Module, and connect the Data pin of the dht11 sensor with the digital pin D1 of the Nodemcu module. 

## Create the new google sheet

After that, open the script editor in the previous versions of the spreadsheet it was found in the tools but in the new versions of the spreadsheet, it is in the extensions with the name Apps Script click on it.And paste the following code in it.
