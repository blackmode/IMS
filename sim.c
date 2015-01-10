#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prepravaEtap1();
void prepravaEtap3();
void prapravaEtap4();


// constanty v milionech Euro
const float prvni_etapa = 892.20;
const float prvnia_etapa = 400.90;
const float druha_etapa = 763.30;
const float treti_etapa = 1992.20;
const float ctvrta_etapa = 4106.90;

//constanty delky rek
const float delka_dunaj = 190.49;
const float delka_odra = 162.45;
const float delka_labe = 154.40 + 133.90; //k vybirani myta na Labe se bude zapocitavat cela vetev az k nemecku

//prepraveneho materilau na jednotlivych vetvich
float dunaj = 0;
float odra = 0;
float labe = 0;

//jednotlive roky etap
const int etapa1 = 2017;
const int etapa2 = 2019;
const int etapa3 = 2024;
const int etapa1a = 2026;
const int etapa4 = 2033;

//preddefinovane promenne dle vetvi cilove destinace
float EgyptCR = 0.015;
float EgyptOdr = 0.364;
float EgyptLab = 0.139;

float AzerCR = 0.002;
float AzerOdr = 0.037;
float AzerLab = 0.018;

float BosnaCR = 0.067;
float BosnaOdr = 0.068
float BosnaLab = 0.048;

float BremenCR = 0.034;
float BremenDun = 0.31;

float BulharCR = 0.067;
float BulharOdr = 0.161;
float BulharLab = 0.085;

float NemecCR = 0.237;
float NemecOdr = 3.899;
float NemecLab = 3.902;

float GruziCR = 0.002;
float GruziOdr = 0.004;
float GruziLab = 0.004;

float HambuCR = 0.143;
float HambuDun = 0.361;

float IranCR = 0.139;
float IranOdr = 0.335;
float IranLab = 0.237;

float IzraeCR = 0.037;
float IzraeOdr = 0.238;
float IzraeLab = 0.197;

float KazachCR = 0.007;
float KazachOdr = 0.126;
float KazachLab = 0.036;

float ChorCR = 0.395;
float ChorOdr = 0.243;
float ChorLab = 0.139;

float LibanCR = 0.01;
float LibanOdr = 0.003;
float LibanLab = 0.025;

float MoldCR = 0.011;
float MoldOdr = 0.064;
float MoldLab = 0.012;

float RakouCR = 2.29;
float RakouOdr = 2.936;
float RakouLab = 2.718;

float PolskoCR = 0.537;
float PolskoDun = 1.713;

float RotterCR = 0.068;
float RotterDun = 0.362;

float RumunCR = 0.366;
float RumunOdr = 0.362;
float RumunLab = 0.204;

float RuskoCR = 0.205;
float RuskoOdr = 0.967;
float RuskoLab = 0.612;

float SrbskoCR = 0.101;
float SrbskoOdr = 0.186;
float SrbskoLab = 0.076;

float SlovenCR = 0.504;
float SlovenDun = 0.349;
float SlovenLab = 0.406;

float SyrieCR = 0.014;
float SyrieOdr = 0.077;
float SyrieLab = 0.053;

float CRDun = 2.161;
float CROdr = 0.903;
float CRLab = 0.265;

float TurecCR = 0.088;
float TurecOdr = 1.304;
float TurecLab = 0.834;

float TurkmCR = 0.001;
float TurkmOdr = 0.006;
float TurkmLab = 0.006;

float UkrajCR = 0.043;
float UkrajOdr = 0.244;
float UkrajLab = 0.065;

float MadarCR = 0.557;
float MadarOdr = 0.51;
float Madarlab = 0.086;

float KyprCR = 0.005;
float KyprOdr = 0.03;
float KyprLab = 0.139;

void prepravaEtap1(){
	float prepravaDunaj = 0;


	dunaj = prepravaDunaj;
}

void prepravaEtap3(){
	float prepravaDunaj = 0;
	float prepravaOdra = 0;


	dunaj = prepravaDunaj;
	odra = prepravaOdra;
}

void prapravaEtap4(){
	float prepravaDunaj = 0;
	float prepravaOdra = 0;
	float prepravaLabe = 0;



	dunaj = prepravaDunaj;
	odra = prepravaOdra;
	labe = prepravaLabe;
}

int main(){



	return 0;
}