#include <stdio.h>

// MAKRA v milionech Euro
const float prvni_etapa = 892.20;
const float prvnia_etapa = 400.90;
const float druha_etapa = 763.30;
const float treti_etapa = 1992.20;
const float ctvrta_etapa = 4106.90;
const float delka_dunaj = 190.49;
const float delka_odra = 162.45;
const float delka_labe = 154.40 + 133.90; //k vybirani myta na Labe se bude zapocitavat cela vetev az k nemecku
/*#define PRVNI_ETAPA 000   	//892.2
#define DRUHA_ETAPA 000		//763.3
#define TRETI_ETAPA 000		//1992.2
#define PRVNIA_ETAPA 000 	//400.9
#define CTVRTA_ETAPA 000 	//4106.9*/
//volitelna simulace na urcity pocet let od roku 2032
//zadame kolik let a je to
//defaultne na 20
int delka_simulace = 20;
int rok = 2033;

//hustota prepravy na jednotlovych kanalech za rok
float hustota_dunaj = 30.316;
float hustota_odra = 19.859;
float hustota_labe = 4.675;

//castky z udrzby a prijmu
float udrzba_kanalu = 50;
float prijem_elektrickeho_hospodarstvi = 5.1;
//
float myto = 0.01; //myto Eur na tunokilometr

// deklarace fci
float narustek = 1;
// funkce
int vypocetVydelkuZaRok () {

	return 0;
}
// sem bych zadaval ruzny přisrustek ptz tu je 1% ale kdyz se kouknes jak to jinde 
//tak bych to udelal ruzne
int procentualniPrirustekLodiZaRok () {
	//narustek o kolik procent lodni doprava zhoustla zadan v procentech
	narustek = 1.01;
	hustota_dunaj *= narustek;
	hustota_odra *= narustek;
	hustota_labe *= narustek;
	return 0;
}

float vypocetMytaZaRok(){
	float celkove_myto = 0;

	celkove_myto = delka_dunaj*0.01 * hustota_dunaj;
	celkove_myto += delka_odra*0.01 * hustota_odra;
	celkove_myto += delka_labe*0.01 * hustota_labe;

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

int main () {
	int i;
	float rekonstrukce = 0;
	//cyklus simulace
	for(i = 0; i < delka_simulace; i++){

		rekonstrukce = rekonstrukceEtap();

		//printf("rok %d a castka rek %.2f\n", rok, rekonstrukce );
		/*printf("hustota dopravy na dunajske vetvi %.3f\n", hustota_dunaj);
		printf("hustota dopravy na oderske vetvi %.3f\n", hustota_odra);
		printf("hustota dopravy na labske vetvi %.3f\n\n", hustota_labe);*/
		float mytne = vypocetMytaZaRok();
		printf("myto za rok %.3f v milionech Eur\n", mytne);

		printf("%.3f  %.3f  %.3f\n",hustota_dunaj, hustota_odra, hustota_labe );
		
		procentualniPrirustekLodiZaRok();
		rok++;
	}

	/**DEFINOVÁNÍ VSTUPŮ*/
	// volani fci
	//prvni_etapa_udrzba = prvni_etapa*0.2;
	//printf("%.2f\n", prvni_etapa_udrzba);
	//printf("hello\n");
	return 0;
}