#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MAKRA v milionech Euro
const float prvni_etapa = 892.20;
const float prvnia_etapa = 400.90;
const float druha_etapa = 763.30;
const float treti_etapa = 1992.20;
const float ctvrta_etapa = 4106.90;
const float delka_dunaj = 190.49;
const float delka_odra = 162.45;
const float delka_labe = 154.40 + 133.90; //k vybirani myta na Labe se bude zapocitavat cela vetev az k nemecku

float vypocetVydelkuZaRok ();
void procentualniPrirustekLodiZaRok (float vzrustOdFun);
float vypocetMytaZaRok();
float rekonstrukceEtap();
float nahodnyVzrust();
void potencialKanalu();
float soucetPotencialu();
//volitelna simulace na urcity pocet let od roku 2032
//zadame kolik let a je to
//defaultne na 20 let
int delka_simulace = 50;
int rok = 2017;

//zjistit jeste pocet lodi ale jak?---------------------------------------
//1 lod 312TEU co jest 4000t
//zjistim z poctu prepravy
int lodi;
//roky dokonceni etap
int etapa1 = 2017;
int etapa2 = 2019;
int etapa3 = 2024;
int etapa1a = 2026;
int etapa4 = 2033;

//hustota prepravy na jednotlovych kanalech za rok
float hustota_dunaj = 0;
float hustota_odra = 0;
float hustota_labe = 0;

//castky z udrzby a prijmu
float udrzba_kanalu = 9.2;
float prijem_elektrickeho_hospodarstvi = 0.5;
//
float myto = 0.00; //myto Eur na tunokilometr

float finance_cele_obdobi = 0;

//vypocet potencialu kanalu od roku 2017
//o kolik procent naroste doprava
float narustek = 1;

//v roce 2017 je tolik v milionech tun za rok
float preprava = 0;


float investice = 8155.6;
// deklarace fci


//potencial cilovych destinaci v roce 2017 kazdy rok se zvysuje

float Egypt = 0.518;
float Azerbajdzan = 0.057;
float Bosna = 0.183;
float Bremen = 0.344;
float Bulharsko = 0.313;
float Nemecko = 8.022;
float Bavorsko = 0.203;
float Gruzie = 0.010;
float Hamburg = 0.504;
float Iran = 0.711;
float Izrael = 0.472;
float Kazachstan = 0.169;
float Chorvatsko = 0.777;
float Libanon = 0.065;
float Moldavsko = 0.084;
float Rakousko = 7.944;
float Polsko = 2.250;
float Rotterdam = 0.430;
float Rumunsko = 0.932;
float Rusko = 1.784;
float Srbsko = 0.363;
float Slovensko = 1.259;
float Syrie = 0.144;
float Szczecin = 0.452;
float Cesko_jih = 2.161;
float Cesko_sever = 1.168;
float Turecko = 2.226;
float Turkmenistan = 0.013;
float Ukrajina1 = 0.352;
float Madarsko = 1.713;
float Kypr = 0.054;
float Cesko_vnitrostatni = 2.15;

// funkce
float vypocetVydelkuZaRok () {
	float celkove_finance = 0;
	
	celkove_finance = vypocetMytaZaRok();
	celkove_finance -= rekonstrukceEtap();
	celkove_finance -=udrzba_kanalu;
	celkove_finance += prijem_elektrickeho_hospodarstvi;
	
	finance_cele_obdobi += celkove_finance;
	return celkove_finance;
}
// sem bych zadaval ruzny přisrustek ptz tu je 1% ale kdyz se kouknes jak to jinde 
//tak bych to udelal ruzne
void procentualniPrirustekLodiZaRok (float vzrustOdFun) {
	//narustek o kolik procent lodni doprava zhoustla zadan v procentech
	//float vzrustOdFun = nahodnyVzrust();
	narustek = 1.00 + vzrustOdFun;
	hustota_dunaj *= narustek;
	hustota_odra *= narustek;
	hustota_labe *= narustek;
	//printf("rocni natustek dopravy o  %.2f proc.\n", vzrustOdFun * 100 );
}

float vypocetMytaZaRok(){
	float celkove_myto = 0;

	celkove_myto = delka_dunaj*myto * hustota_dunaj;
	celkove_myto += delka_odra*myto * hustota_odra;
	celkove_myto += delka_labe*myto * hustota_labe;

	return celkove_myto;
}

//zjistuje zda jsou rekonstrukce v danem roce
float rekonstrukceEtap(){
	float castka_rekonstrukce = 0;

	if(rok == 2036){
		castka_rekonstrukce = prvni_etapa*0.15;
	}
	if(rok == 2038){
		castka_rekonstrukce = druha_etapa*0.15;
	}
	if(rok == 2042){
		castka_rekonstrukce = treti_etapa*0.15;
	}
	if(rok == 2043){
		castka_rekonstrukce = prvnia_etapa*0.15;
	}
	if(rok == 2048){
		castka_rekonstrukce = ctvrta_etapa*0.15;
	}
	return castka_rekonstrukce;
}

//funkce na nahodny vzrust dopravy v intervalu od 1 do 4 procent
float nahodnyVzrust(){
	
	float a = 0.01;
	float b = 0.01;
	float vysl = a + (b-a)*(float) rand()/RAND_MAX;
	
	return vysl;
}

void potencialKanalu(){
	int roky = 2017;

	float potencial;
	potencial = soucetPotencialu();
	printf("%f\n", potencial);
	for(roky = 2017; roky <= 2067; roky++){
	//	printf("rok: %d potencial: %.3f\n", roky, potencial );
		potencial *= 1.01;
	}
}

float soucetPotencialu(){
	float potencial;

	potencial = Egypt+Azerbajdzan+Bosna+Bremen+Bulharsko+Nemecko+Bavorsko;
	potencial += Gruzie+Hamburg+Iran+Izrael+Kazachstan+Chorvatsko+Libanon;
	potencial += Moldavsko+Rakousko+Polsko+Rotterdam+Rumunsko+Rusko+Srbsko;
	potencial += Slovensko+Syrie+Szczecin+Cesko_sever+Cesko_jih+Cesko_vnitrostatni;
	potencial += Turecko+Turkmenistan+Ukrajina1+Madarsko+Kypr;

	return potencial;
}
//vypocet hustoty prepravy v zavislosti na otevrenych etapach
void vypocetPrepravy(float procento){
	float tmp = 1.105;	//nez se otevrou aspon 2 vetve tak takto
	procento += 1.00;
	//otevreni treti etapy
	if(etapa3 == rok){
		hustota_dunaj = 6.565;
		hustota_odra = 5.080;
		preprava *= procento;
	}
	else if(etapa1a == rok){
		procento =1.89;
		hustota_dunaj *= procento;
		hustota_odra *= procento;
		preprava *= procento;
	}
	else if((etapa1a+1) == rok){
		procento =1.47;
		hustota_dunaj *= procento;
		hustota_odra *= procento;
		preprava *= procento;
	}
	else if((etapa1a+2) == rok){
		procento =1.32;
		hustota_dunaj *= procento;
		hustota_odra *= procento;
		preprava *= procento;
	}
	else if(etapa3 > rok){
		preprava += tmp;
	}

	else if(etapa4 == rok){
		hustota_labe = 4.675;
		hustota_odra *= procento;
		hustota_dunaj *= 1.20;
		preprava *= 1.17;
	}
	else if((etapa4+1) == rok){
		hustota_labe *= 2.01;
		hustota_odra *= procento;
		hustota_dunaj *= 1.14;
		preprava *= 1.14;
	}
	else if((etapa4+2) == rok){
		hustota_labe *= 1.50;
		hustota_odra *= procento;
		hustota_dunaj *= 1.14;
		preprava *= 1.12;
	}
	else{
		hustota_odra *= procento;
		hustota_labe *= procento;
		hustota_dunaj *= procento;
		preprava *= procento;
	}

	//printf("\n%.3f preprava\n", preprava);
}
void energetickHospodarstvi(){
	if(rok == etapa2)
		prijem_elektrickeho_hospodarstvi = 2.6;
	if(rok == etapa3)
		prijem_elektrickeho_hospodarstvi = 4.2;
	if(rok == etapa1a)
		prijem_elektrickeho_hospodarstvi = 6.0;
	if(rok == etapa4)
		prijem_elektrickeho_hospodarstvi = 5.1;
}

//lod uveze 4000t materialu
void lodeZaRok(){
	lodi = preprava / 0.004;
	//printf("lode: %.0f\n", lodi);
}
float inflace(){
	
	float a = 1.01;
	float b = 1.04;
	float vysl = a + (b-a)*(float) rand()/RAND_MAX;
	
	return vysl;
}

int main () {
	//zalezi jestli chceme mit kazdou simulaci stejne nebo ne 
	//zatim stejne kdyztak se zmeni
	//srand((unsigned int)time(NULL));
	int i;
	float nahodny_vzrust;
	//float finance = 0;
	//cyklus simulace
	//zvysovani myta pod 10 letech
	potencialKanalu();
	for(i = 0; i < delka_simulace; i++){
	
		if(rok == etapa3)
			myto = 0.01;
		if(rok >= etapa3){
			myto *= inflace();
		}

		energetickHospodarstvi();

		nahodny_vzrust = nahodnyVzrust();
		vypocetPrepravy(nahodny_vzrust);
		lodeZaRok();
		printf("finance za rok %d : %f\n", rok, vypocetVydelkuZaRok());
		printf("myto za rok %d: %f Eur\n", rok, myto);
		printf("Preprava dunajska vetev: %.3f miliony tun\nPrepravaOderska vetev: %.3f miliony tun\nPreprava Labska vetev: %.3f miliony tun\n\n",hustota_dunaj, hustota_odra, hustota_labe );
		
		//procentualniPrirustekLodiZaRok(nahodny_vzrust);
		rok++;
	}
	finance_cele_obdobi -= investice;
	printf("finance za celou simulaci  %.5f milionech Euro za %d let\n", finance_cele_obdobi, delka_simulace);

	return 0;
}