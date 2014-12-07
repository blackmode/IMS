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
void procentualniPrirustekLodiZaRok ();
float vypocetMytaZaRok();
float rekonstrukceEtap();
float nahodnyVzrust();
void potencialKanalu();
//volitelna simulace na urcity pocet let od roku 2032
//zadame kolik let a je to
//defaultne na 20 let
int delka_simulace = 30;
int rok = 2033;

//zjistit jeste pocet lodi ale jak?

//hustota prepravy na jednotlovych kanalech za rok
float hustota_dunaj = 30.316;
float hustota_odra = 19.859;
float hustota_labe = 4.675;

//castky z udrzby a prijmu
float udrzba_kanalu = 50;
float prijem_elektrickeho_hospodarstvi = 5.1;
//
float myto = 0.01; //myto Eur na tunokilometr

float finance_cele_obdobi = 0;

//vypocet potencialu kanalu od roku 2017

// deklarace fci
float narustek = 1;
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
void procentualniPrirustekLodiZaRok () {
	//narustek o kolik procent lodni doprava zhoustla zadan v procentech
	float vzrustOdFun = nahodnyVzrust();
	narustek = 1.00 + vzrustOdFun;
	hustota_dunaj *= narustek;
	hustota_odra *= narustek;
	hustota_labe *= narustek;
	printf("rocni natustek dopravy o  %.2f proc.\n", vzrustOdFun * 100 );
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
	float b = 0.04;
	float vysl = a + (b-a)*(float) rand()/RAND_MAX;
	
	return vysl;
}

void potencialKanalu(){
	int roky = 2017;

	float potencial = 37.827;
	for(roky = 2017; roky <= 2067; roky++){
		printf("rok: %d potencial: %.3f\n", roky, potencial );
		potencial *= 1.01;
	}
}

int main () {
	//zalezi jestli chceme mit kazdou simulaci stejne nebo ne 
	//zatim stejne kdyztak se zmeni
	//srand((unsigned int)time(NULL));
	int i;
	//float finance = 0;
	//cyklus simulace
	//zvysovani myta pod 10 letech
	potencialKanalu();
	int j = 0;
	for(i = 0; i < delka_simulace; i++){
		j++;
		if(j == 10){
			myto += 0.01;
			j = 0;
		}

		//printf("rok %d a castka rek %.2f\n", rok, rekonstrukce );
		/*printf("hustota dopravy na dunajske vetvi %.3f\n", hustota_dunaj);
		printf("hustota dopravy na oderske vetvi %.3f\n", hustota_odra);
		printf("hustota dopravy na labske vetvi %.3f\n\n", hustota_labe);*/
		//finance = vypocetVydelkuZaRok();
		printf("finance za rok: %d : %f\n", rok, vypocetVydelkuZaRok());

		printf("%.3f  %.3f  %.3f\n",hustota_dunaj, hustota_odra, hustota_labe );

		printf("------%f \n", nahodnyVzrust());
		
		procentualniPrirustekLodiZaRok();
		rok++;
	}

	printf("finance za celou simulaci  %.5f milionech Euro\n", finance_cele_obdobi);

	/**DEFINOVÁNÍ VSTUPŮ*/
	// volani fci
	//prvni_etapa_udrzba = prvni_etapa*0.2;
	//printf("%.2f\n", prvni_etapa_udrzba);
	//printf("hello\n");
	return 0;
}