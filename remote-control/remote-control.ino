#include <ESP8266TelegramBOT.h>
#include <IRremoteESP8266.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
IRsend irsend(15);  //Pino LED IR

/*-------------------Telegram Configurações-----------------*/
#define BOTtoken ""  //token of TelegramBOT
#define BOTname ""
#define BOTusername ""
TelegramBOT bot(BOTtoken, BOTname, BOTusername);
int Bot_mtbs = 1000; //tempo de espera para atualizar mensagens(ms)
long Bot_lasttime;   //tempo da ultima mensagem atualizada
/*-----------------------------------------------------------*/

unsigned k_on    = 0x448F50A;     //Botão ON/OFF  FORMATO NEC
unsigned k_ok    = 0x448AA55;     //Botão OK
unsigned k_epg   = 0x44810EF;     //Botão EPG
unsigned k_info  = 0x4489867;     //Botão INFO
unsigned k_cima  = 0x4489A65;     //Botão para cima
unsigned k_baixo = 0x4488A75;     //Botão para baixo
unsigned k_volP  = 0x448A857;     //Botão volume +
unsigned k_volM  = 0x4482AD5;     //Botão volume -
unsigned k_pP    = 0x44820DF;     //Botão página +
unsigned k_pM    = 0x448609F;     //Botão página -
unsigned k_mute  = 0x448827D;     //Botão mudo
unsigned k_menu  = 0x4481AE5;     //Botão menu
unsigned k_exit  = 0x448B847;     //Botão sair
unsigned k_audio = 0x448A25D;     //Botão audio
unsigned k_1 = 0x448C837;         //Botão 1
unsigned k_2 = 0x44848B7;         //Botão 2
unsigned k_3 = 0x44808F7;         //Botão 3
unsigned k_4 = 0x448E817;         //Botão 4
unsigned k_5 = 0x4486897;         //Botão 5
unsigned k_6 = 0x44828D7;         //Botão 6
unsigned k_7 = 0x448D827;         //Botão 7
unsigned k_8 = 0x44858A7;         //Botão 8
unsigned k_9 = 0x44818E7;         //Botão 9
unsigned k_0 = 0x4487887;         //Botão 0

/*---------------------Canais Registrados---------------*/
unsigned rbs[]          = {k_1,k_7,k_0};  //Numero dos canais armazenados em array correspondendo na tecla para mudança do canal 170
unsigned sbt[]          = {k_1,k_7,k_9};
unsigned discovery[]    = {k_0,k_4,k_2};
unsigned disc_science[] = {k_0,k_4,k_8};
unsigned disc_turbo[]   = {k_0,k_4,k_9};
unsigned universal[]    = {k_2,k_4,k_1};
unsigned warner[]       = {k_2,k_4,k_7};

/*---------------------Telecine---------------*/
unsigned tc_action[]    = {k_2,k_2,k_5};
unsigned tc_cult[]      = {k_2,k_2,k_6};
unsigned tc_fun[]       = {k_2,k_2,k_7};
unsigned tc_pipoca[]    = {k_2,k_2,k_9};
unsigned tc_premium[]   = {k_2,k_3,k_1};
unsigned tc_touch[]     = {k_2,k_3,k_3};

/*-------------------Wi-Fi Configurações-----------------*/
const char* ssid = "";            //SSID da rede Wi-Fi
const char* password = "";        //senha da rede Wi-Fi
ESP8266WebServer server(80);            //Porta do servidor web
IPAddress ip(192, 168, 1, 13);    //IP esp8266
IPAddress gateway(192,168,1,254); //Gateway do AP
IPAddress subnet(255,255,255,0);  //Mascara de rede 
/*-----------------------------------------------------*/
/*Função para conectar em uma Rede Wifi */
void conectar(const char* nome, const char* senha, IPAddress ipv4, IPAddress gateway_ap){
  Serial.print("Connecting to "); 
  Serial.println(nome);
  WiFi.begin(nome, senha);
  WiFi.config(ipv4, gateway_ap, subnet);}
/*-----------------------------------------------------*/

/*Função para trocar o canal */
void trocar_canal(unsigned canal[]){ 
     irsend.sendNEC(k_exit, 32);
     delay(500);
     irsend.sendNEC(canal[0], 32);
     delay(500); 
     irsend.sendNEC(canal[1], 32);
     delay(500);
     irsend.sendNEC(canal[2], 32);
     delay(500);
     irsend.sendNEC(k_ok, 32); 
     delay(500);
     //bot.sendMessage("368953432","Canal trocado!" , "");
}


/*Função para receber mensagem do Telegram */
void Messages(String message) {
  if(message != ""){                // Verifica se a solicitação foi feita pelo HTTP (vazia telegram)
    bot.message[0][0]=1;            // Define valor true para uma nova mensagem
    bot.message[1][5] = message;    // Define a mensagem para o canal solicitado via HTTP 
  }
 
  for (int i = 1; i < bot.message[0][0].toInt() + 1; i++) // Percorre as mensagens do recebida pelo Telegram ou HTTP
  {
    if(bot.message[i][5].equalsIgnoreCase("rbs"))         //Verifica a string recebida para troca do canal  (equalsIgnoreCase) ignora Case sensitive
      trocar_canal(rbs);
    else if(bot.message[i][5].equalsIgnoreCase("sbt"))
      trocar_canal(sbt);
    else if(bot.message[i][5].equalsIgnoreCase("discovery"))
      trocar_canal(discovery);
    else if(bot.message[i][5].equalsIgnoreCase("science"))
      trocar_canal(disc_science);
    else if(bot.message[i][5].equalsIgnoreCase("turbo"))
      trocar_canal(disc_turbo);
    else if(bot.message[i][5].equalsIgnoreCase("universal"))
      trocar_canal(universal);
    else if(bot.message[i][5].equalsIgnoreCase("warner"))
      trocar_canal(warner);
   //TeleCine
    else if(bot.message[i][5].equalsIgnoreCase("tc action"))
      trocar_canal(tc_action);
    else if(bot.message[i][5].equalsIgnoreCase("tc cult"))
      trocar_canal(tc_cult);
    else if(bot.message[i][5].equalsIgnoreCase("tc fun"))
      trocar_canal(tc_fun);
    else if(bot.message[i][5].equalsIgnoreCase("tc pipoca"))
      trocar_canal(tc_pipoca);
    else if(bot.message[i][5].equalsIgnoreCase("tc premium"))
      trocar_canal(tc_premium);
    else if(bot.message[i][5].equalsIgnoreCase("tc touch"))
      trocar_canal(tc_touch);
    else
       bot.sendMessage(bot.message[i][4],"Não entendi", ""); //Nenhum comando correspondido
    }
  bot.message[0][0] = "";   // Limpa mensagens respondidas
}

void setup(){
  irsend.begin();
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
 //  bot.sendMessage("368953432","Fui Ligado!" , ""); //Mensagem no Telegram quando for inicializado
  server.on("/", handleRoot);
}

void handleRoot() {
  String func =  server.arg("function");
  if(func !=""){
  if(func == "ON"){
    irsend.sendNEC(k_on, 32);
    delay(50); 
  }
  else if (func == "cima") {
    irsend.sendNEC(k_cima, 32);
    delay(50);
  }
  else if (func == "baixo") {
    irsend.sendNEC(k_baixo, 32);
    delay(50);
  }
  else if (func == "ok") {
    irsend.sendNEC(k_ok, 32);
    delay(50);
  }
  else if (func == "vol+") {
    irsend.sendNEC(k_volP, 32);
    delay(50);
  }
  else if (func == "vol-") {
    irsend.sendNEC(k_volM, 32);
    delay(50);
  }
  else if (func == "p+") {
    irsend.sendNEC(k_pP, 32);
    delay(50);
  }
  else if (func == "p-") {
    irsend.sendNEC(k_pM, 32);
    delay(50);
  }
  else if (func == "audio") {
    irsend.sendNEC(k_audio, 32);
    delay(50);
  }
  else if (func == "mute") {
    irsend.sendNEC(k_mute, 32);
    delay(50);
  }
  else if (func == "epg") {
    irsend.sendNEC(k_epg, 32);
    delay(50);
  }
  else if (func == "inf") {
    irsend.sendNEC(k_info, 32);
    delay(50);
  }
  else if (func == "menu") {
    irsend.sendNEC(k_menu, 32);
    delay(50);
  }
  else if (func == "sair") {
    irsend.sendNEC(k_exit, 32);
    delay(50);
  }
  else if (func == "n1") {
    irsend.sendNEC(k_1, 32);
    delay(50);
  }
  else if (func == "n2") {
    irsend.sendNEC(k_2, 32);
    delay(50);
  }
  else if (func == "n3") {
    irsend.sendNEC(k_3, 32);
    delay(50);
  }
  else if (func == "n4") {
    irsend.sendNEC(k_4, 32);
    delay(50);
  }
  else if (func == "n5") {
    irsend.sendNEC(k_5, 32);
    delay(50);
  }
  else if (func == "n6") {
    irsend.sendNEC(k_6, 32);
    delay(50);
  }
  else if (func == "n7") {
    irsend.sendNEC(k_7, 32);
    delay(50);
  }
  else if (func == "n8") {
    irsend.sendNEC(k_8, 32);
    delay(50);
  }
  else if (func == "n9") {
    irsend.sendNEC(k_9, 32);
    delay(50);
  }
  else if (func == "n0") {
    irsend.sendNEC(k_0, 32);
    delay(50);
  }
 }
 if(server.arg("canal") !=""){
   Messages(server.arg("canal"));
 }
  String s = MAIN_page;
  server.send(200, "text/html", s);
}
void loop(){
  if (millis() > Bot_lasttime + Bot_mtbs)  {  //Tempo para atualização das mensagens
    bot.getUpdates(bot.message[0][1]);  
    Messages("");                             //Vazia para indicar que é pelo Telegram
    Bot_lasttime = millis();
  }
 server.handleClient();    
}
    

