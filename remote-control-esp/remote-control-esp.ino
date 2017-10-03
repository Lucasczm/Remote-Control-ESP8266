#include <ESP8266TelegramBOT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include "canais.h"


Canais ch; //Instancia a classe Canais

/*-------------------Telegram Configurações-----------------*/
#define BOTtoken ""  //token TelegramBot
#define BOTname ""
#define BOTusername ""
TelegramBOT bot(BOTtoken, BOTname, BOTusername);
int Bot_mtbs = 1000;	//tempo de espera para atualizar mensagens(ms)
long Bot_lasttime;		//tempo da ultima mensagem atualizada
/*-----------------------------------------------------------*/

/*-------------------Wi-Fi Configurações-----------------*/
const char* ssid = "";				//SSID da rede Wi-Fi
const char* password = "";		//senha da rede Wi-Fi
ESP8266WebServer server(80);			//Porta do servidor web
IPAddress ip(192, 168, 1, 13);			//IP esp8266
IPAddress gateway(192,168,1,254);		//Gateway do AP
IPAddress subnet(255,255,255,0);		//Mascara de rede 
/*-----------------------------------------------------*/
/*Função para conectar em uma Rede Wifi */
void conectar(const char* nome, const char* senha, IPAddress ipv4, IPAddress gateway_ap){
  Serial.print("Connecting to "); 
  Serial.println(nome);
  WiFi.begin(nome, senha);
  WiFi.config(ipv4, gateway_ap, subnet);}
/*-----------------------------------------------------*/

/*Função para receber mensagem do Telegram */
void Messages() {
	String mensagem;
	String channel;
	for (int i = 1; i < bot.message[0][0].toInt() + 1; i++) // Percorre as mensagens do recebida pelo Telegram
	{
		mensagem = bot.message[i][5];						//Verifica a string recebida para troca do canal  
		mensagem.toLowerCase() ;
		if (mensagem.indexOf("canal") != -1)				//Verficia na mensagem se a palavra canal foi encontrada
		{
			channel = mensagem.substring(mensagem.lastIndexOf("canal") + 6, mensagem.length());
			if (ch.trocarCanal(channel)) {					//Verifica se o canal é valido e troca
				bot.sendMessage(bot.message[i][4], "Trocado para o canal " + channel, "");
			}
			else 
				bot.sendMessage(bot.message[i][4], "Canal não encontrado", "");
		}
		else
			bot.sendMessage(bot.message[i][4],"Não entendi", ""); //Nenhum comando correspondido 
	}
	bot.message[0][0] = "";   // Limpa mensagens respondidas
}

void setup(){
	Serial.begin(115200); 
	conectar(ssid, password, ip, gateway);
	WiFi.softAP("Smart House", "smarthouse"); //AP Virtual (SSID, SENHA)
	if(WiFi.status() != WL_CONNECTED){
		delay(500);
	}
	Serial.println("WiFi connected");
	server.begin();
	Serial.println(WiFi.localIP());
	delay(5000);
	
	server.on("/", handleRoot);
}

void handleRoot() {
	String func =  server.arg("function");
	if(func !=""){
		ch.controleRemoto(func);
	}
	if(server.arg("canal") !=""){
		Serial.println("Canal "+server.arg("canal"));
		ch.trocarCanal(server.arg("canal"));
	}
	String s = MAIN_page;
	server.send(200, "text/html", s);
}
void loop(){
	if (millis() > Bot_lasttime + Bot_mtbs)  {  //Tempo para atualização das mensagens
		bot.getUpdates(bot.message[0][1]);  
		Messages();                            
		Bot_lasttime = millis();
	 }
	server.handleClient();    
}
    

