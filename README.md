# Remote Control Telegram ESP8266

This code provides a visual interface for simulate a remote control in web server and provide channel changes using the telegram API

## Getting Started



### Prerequisites

You need installed this libraries for ESP8266

* [IRremoteESP8266](https://github.com/markszabo/IRremoteESP8266)

* [ESP8266-TelegramBot](https://github.com/Gianbacchio/ESP8266-TelegramBot)


### Settings

.ino file configure 
```
Line 12, 13, 14 set your token, bot name and bot username
Line 21 at 26 set your wi-fi configurations
Line 62 set a SSID and password for Virtual AP
```
canais.cpp file configure
```
Line 3 set the signal pin of IR LED
Line 5 at 28 configure the keys of your receiver
Line 40 at 135 configure the number of channel on receiver
```

### Using
You can use the remote control accessing your esp by web server

	http://192.168.4.1/
        
Send a message for your telegram bot with the word canal following the channel you want
 						
	Canal MTV

You can change channel by URL http://192.168.4.1/?canal= (channel you want)

	http://192.168.4.1/?canal=mtv
    

## Authors

* [Lucas Machado](https://github.com/Lucasczm)

See also the list of [contributors](https://github.com/ChuckCM/Remote-Control-ESP8266/contributors) who participated in this project.
