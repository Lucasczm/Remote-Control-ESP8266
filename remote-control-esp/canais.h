#ifndef CANAIS_H
#define CANAIS_H

#include <Arduino.h>
#include <IRremoteESP8266.h>


class Canais {
public:
	Canais();
	bool trocarCanal(String canal);
	void controleRemoto(String controle);
private:
	bool pergarNumero(String canal);
	bool interpretar(String canal);
	
	String canal;
};
#endif