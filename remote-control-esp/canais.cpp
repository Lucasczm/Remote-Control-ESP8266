#include "canais.h"

IRsend irsend(15); //Pino led Ifravermelho

unsigned k_on		  = 0x448F50A;     //Botão ON/OFF  FORMATO NEC
unsigned k_ok		  = 0x448AA55;     //Botão OK
unsigned k_epg		= 0x44810EF;     //Botão EPG
unsigned k_info		= 0x4489867;     //Botão INFO
unsigned k_cima		= 0x4489A65;     //Botão para cima
unsigned k_baixo	= 0x4488A75;     //Botão para baixo
unsigned k_volP		= 0x448A857;     //Botão volume +
unsigned k_volM		= 0x4482AD5;     //Botão volume -
unsigned k_pP		  = 0x44820DF;     //Botão página +
unsigned k_pM		  = 0x448609F;     //Botão página -
unsigned k_mute		= 0x448827D;     //Botão mudo
unsigned k_menu		= 0x4481AE5;     //Botão menu
unsigned k_exit		= 0x448B847;     //Botão sair
unsigned k_audio	= 0x448A25D;     //Botão audio
unsigned k_1		  = 0x448C837;     //Botão 1
unsigned k_2		  = 0x44848B7;     //Botão 2
unsigned k_3		  = 0x44808F7;     //Botão 3
unsigned k_4		  = 0x448E817;     //Botão 4
unsigned k_5		  = 0x4486897;     //Botão 5
unsigned k_6		  = 0x44828D7;     //Botão 6
unsigned k_7		  = 0x448D827;     //Botão 7
unsigned k_8		  = 0x44858A7;     //Botão 8
unsigned k_9		  = 0x44818E7;     //Botão 9
unsigned k_0		  = 0x4487887;     //Botão 0

unsigned tecla[3];
String ch_numero;
Canais::Canais(){
	irsend.begin();
}


bool Canais::interpretar(String canal) {
	ch_numero = "";
	//--------------------Variedades-------------------//
	if (canal == "rbs")				        ch_numero = "170";
	if (canal == "record news")	      ch_numero = "174";
	if (canal == "record")			      ch_numero = "171";
	if (canal == "sbt")				        ch_numero = "179";
	if (canal == "band")			        ch_numero = "016";
	if (canal == "mtv")				        ch_numero = "123";
	if (canal == "multishow")		      ch_numero = "130";
	if (canal == "playtv")			      ch_numero = "148";
	//-------------------Series------------------------//
	if (canal == "a&e")				        ch_numero = "001";
	if (canal == "axn")				        ch_numero = "003";
	if (canal == "comedy central")	  ch_numero = "038";
	if (canal == "fox")				        ch_numero = "071";
	if (canal == "fx")				        ch_numero = "073";
	if (canal == "id")				        ch_numero = "113";
	if (canal == "isat")			        ch_numero = "113";
	if (canal == "lifetime")		      ch_numero = "116";
	if (canal == "sony")			        ch_numero = "028";
	if (canal == "syfy")			        ch_numero = "194";
	if (canal == "tbs")				        ch_numero = "195";
	if (canal == "tnt series")		    ch_numero = "201";
	if (canal == "universal")		      ch_numero = "241";
	if (canal == "warner")			      ch_numero = "247";
	//--------------------Filmes-----------------------//
	if (canal == "cinemax")			      ch_numero = "033";
	if (canal == "megapix")			      ch_numero = "128";
	if (canal == "paramount")		      ch_numero = "148";
	if (canal == "primebox")		      ch_numero = "166";
	if (canal == "space")			        ch_numero = "183";
	if (canal == "studio universal")  ch_numero = "191";
	if (canal == "tcm")				        ch_numero = "196";
	if (canal == "tnt")				        ch_numero = "199";
	//-------------------------HBO---------------------//
	if (canal == "hbo")				        ch_numero = "101";
	if (canal == "hbo family")		    ch_numero = "102";
	if (canal == "hbo plus")		      ch_numero = "105";
	if (canal == "hbo plus e")		    ch_numero = "107";
	if (canal == "hbo signature")	    ch_numero = "108";
	if (canal == "hbo2")			        ch_numero = "110";
	if (canal == "max")				        ch_numero = "118";
	if (canal == "max prime")		      ch_numero = "119";
	if (canal == "max prime e")		    ch_numero = "120";
	if (canal == "max up")			      ch_numero = "121";
	//---------------------Telecines-------------------//
	if (canal == "telecine action")	  ch_numero = "224";
	if (canal == "telecine cult")	    ch_numero = "226";
	if (canal == "telecine fun")	    ch_numero = "227";
	if (canal == "telecine pipoca")	  ch_numero = "229";
	if (canal =="telecine premiere")  ch_numero = "231";
	if (canal == "telecine touch")	  ch_numero = "233";
	//------------------Documentarios------------------//
	if (canal == "animal planet")     ch_numero = "005";
	if (canal =="discovery channel")  ch_numero = "042";
if (canal=="discovery civilization")ch_numero = "044";
	if (canal =="discovery science")  ch_numero = "048";
	if (canal == "discovery turbo")	  ch_numero = "049";
	if (canal == "nat geo wild")	    ch_numero = "136";
	if (canal == "h2")				        ch_numero = "099";
	if (canal == "history channel")	  ch_numero = "237";
	if (canal == "nat geo")			      ch_numero = "138";
	//--------------------Esportes---------------------//
	if (canal == "ei")				        ch_numero = "056";
	if (canal == "ei2")				        ch_numero = "057";
	if (canal == "sport tv")		      ch_numero = "185";
	if (canal == "sport tv2")		      ch_numero = "186";
	if (canal == "sport tv3")		      ch_numero = "188";
if (canal =="sport tv alternativo") ch_numero = "189";
if (canal =="sport tv2 alternativo")ch_numero = "187";
	if (canal == "band sports")		    ch_numero = "014";
	if (canal == "espn")			        ch_numero = "063";
	if (canal == "espn +")			      ch_numero = "068";
	if (canal == "espn brasil")		    ch_numero = "065";
	if (canal == "fox sports")		    ch_numero = "080";
	if (canal == "fox sports2")		    ch_numero = "081";
	if (canal == "comabate")		      ch_numero = "037";
	if (canal == "premiere 1")		    ch_numero = "";  
	if (canal == "premiere 2")		    ch_numero = "151";
	if (canal == "premiere 3")		    ch_numero = "153";
	if (canal == "premiere 4")		    ch_numero = "155";
	if (canal == "premiere 5")		    ch_numero = "157";
	if (canal == "premiere 6")	    	ch_numero = "159";
	if (canal == "premiere 7")		    ch_numero = "161";
	if (canal == "premiere 8")	    	ch_numero = "162";
	if (canal == "premiere 9")	    	ch_numero = "163";
	if (canal == "premiere clubes") 	ch_numero = "164";
	if (canal == "premiere fc")		    ch_numero = "";
	//---------------------Adultos---------------------//
	if (canal == "playboy")			      ch_numero = "149";
	if (canal == "sextreme")		      ch_numero = "181";
	if (canal == "sexyhot")			      ch_numero = "182";
	//--------------------Infantis---------------------//
	if (canal == "boomerang")		      ch_numero = "018";
	if (canal == "cartoon")			      ch_numero = "032";
	if (canal == "disney xd")		      ch_numero = "055";
	if (canal == "nickelodeon")		    ch_numero = "140";
	if (canal == "tooncast")		      ch_numero = "239";
	if (ch_numero != "") return true;
	else 	return false;
}
bool Canais::pergarNumero(String canal) {
	if (interpretar(canal)) {
		for (int i = 0; i < 3; i++) {
				 if	(ch_numero[i] == '0') tecla[i] = k_0;
			else if (ch_numero[i] == '1') tecla[i] = k_1;
			else if (ch_numero[i] == '2') tecla[i] = k_2;
			else if (ch_numero[i] == '3') tecla[i] = k_3;
			else if (ch_numero[i] == '4') tecla[i] = k_4;
			else if (ch_numero[i] == '5') tecla[i] = k_5;
			else if (ch_numero[i] == '6') tecla[i] = k_6;
			else if (ch_numero[i] == '7') tecla[i] = k_7;
			else if (ch_numero[i] == '8') tecla[i] = k_8;
			else if (ch_numero[i] == '9') tecla[i] = k_9;
			}
		return true;
	}
	else return false;
}
bool Canais::trocarCanal(String canal) {
	if (pergarNumero(canal)) {
		irsend.sendNEC(k_exit, 32);
		delay(500);
		irsend.sendNEC(tecla[0], 32);
		delay(500);
		irsend.sendNEC(tecla[1], 32);
		delay(500);
		irsend.sendNEC(tecla[2], 32);
		delay(500);
		irsend.sendNEC(k_ok, 32);
		delay(500);
		return true;
	}
	else return false;
}
void Canais::controleRemoto(String controle) {
	if (controle == "ON") {
		irsend.sendNEC(k_on, 32);
		delay(50);
	}
	else if (controle == "cima") {
		irsend.sendNEC(k_cima, 32);
		delay(50);
	}
	else if (controle == "baixo") {
		irsend.sendNEC(k_baixo, 32);
		delay(50);
	}
	else if (controle == "ok") {
		irsend.sendNEC(k_ok, 32);
		delay(50);
	}
	else if (controle == "vol+") {
		irsend.sendNEC(k_volP, 32);
		delay(50);
	}
	else if (controle == "vol-") {
		irsend.sendNEC(k_volM, 32);
		delay(50);
	}
	else if (controle == "p+") {
		irsend.sendNEC(k_pP, 32);
		delay(50);
	}
	else if (controle == "p-") {
		irsend.sendNEC(k_pM, 32);
		delay(50);
	}
	else if (controle == "audio") {
		irsend.sendNEC(k_audio, 32);
		delay(50);
	}
	else if (controle == "mute") {
		irsend.sendNEC(k_mute, 32);
		delay(50);
	}
	else if (controle == "epg") {
		irsend.sendNEC(k_epg, 32);
		delay(50);
	}
	else if (controle == "inf") {
		irsend.sendNEC(k_info, 32);
		delay(50);
	}
	else if (controle == "menu") {
		irsend.sendNEC(k_menu, 32);
		delay(50);
	}
	else if (controle == "sair") {
		irsend.sendNEC(k_exit, 32);
		delay(50);
	}
	else if (controle == "n1") {
		irsend.sendNEC(k_1, 32);
		delay(50);
	}
	else if (controle == "n2") {
		irsend.sendNEC(k_2, 32);
		delay(50);
	}
	else if (controle == "n3") {
		irsend.sendNEC(k_3, 32);
		delay(50);
	}
	else if (controle == "n4") {
		irsend.sendNEC(k_4, 32);
		delay(50);
	}
	else if (controle == "n5") {
		irsend.sendNEC(k_5, 32);
		delay(50);
	}
	else if (controle == "n6") {
		irsend.sendNEC(k_6, 32);
		delay(50);
	}
	else if (controle == "n7") {
		irsend.sendNEC(k_7, 32);
		delay(50);
	}
	else if (controle == "n8") {
		irsend.sendNEC(k_8, 32);
		delay(50);
	}
	else if (controle == "n9") {
		irsend.sendNEC(k_9, 32);
		delay(50);
	}
	else if (controle == "n0") {
		irsend.sendNEC(k_0, 32);
		delay(50);
	}
}
