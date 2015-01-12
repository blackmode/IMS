#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prepravaEtap1();
void prepravaEtap3();
void prepravaEtap4();


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

//promenne pro vypocet vydelku
float myto = 0;

//preddefinovane promenne dle vetvi cilove destinace
float EgyptCR = 0.015;
float EgyptOdr = 0.364;
float EgyptLab = 0.139;

float AzerCR = 0.002;
float AzerOdr = 0.037;
float AzerLab = 0.018;

float BosnaCR = 0.067;
float BosnaOdr = 0.068;
float BosnaLab = 0.048;

float BremenCR = 0.034;
float BremenDun = 0.31;

float BulharCR = 0.067;
float BulharOdr = 0.161;
float BulharLab = 0.085;

float NemecCRL = 0.118;
float NemecCRO = 0.119;
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
float SlovenOdr = 0.349;
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
//*************************************//
/****************funkce***************/
//zjistuje zda jsou rekonstrukce v danem roce
float rekonstrukceEtap(int rok){
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
float energetickHospodarstvi(int rok){
	float prijem;
	if(rok >= etapa1 && rok < etapa2 )
		prijem = 0.5;
	if(rok >= etapa2 && rok < etapa3 )
		prijem = 2.6;
	if(rok >= etapa3 && rok < etapa1a )
		prijem = 4.2;
	if(rok >= etapa3 && rok < etapa1a )
		prijem = 6.0;
	if(rok >= etapa4 )
		prijem = 5.1;

	return prijem;
}

float vypocetMytaZaRok(){
	float celkove_myto = 0;

	celkove_myto = delka_dunaj*myto * dunaj;
	celkove_myto += delka_odra*myto * odra;
	celkove_myto += delka_labe*myto * labe;

	return celkove_myto;
}

void prepravaEtap1(){
	float prepravaDunaj = 0;
	float rust = 1.01;

	EgyptCR *= rust;
	prepravaDunaj += EgyptCR;

	AzerCR *= rust;
	prepravaDunaj += AzerCR;

	BosnaCR *= rust;
	prepravaDunaj += BosnaCR;

	BulharCR *= rust;
	prepravaDunaj += BulharCR;

	GruziCR *= rust;
	prepravaDunaj += GruziCR;

	IranCR *= rust;
	prepravaDunaj += IranCR;

	KazachCR *= rust;
	prepravaDunaj += KazachCR;

	ChorCR *= rust;
	prepravaDunaj += ChorCR;

	LibanCR *= rust;
	prepravaDunaj += LibanCR;

	MoldCR *= rust;
	prepravaDunaj += MoldCR;

	RakouCR *= rust;
	prepravaDunaj += RakouCR;

	RumunCR *= rust;
	prepravaDunaj += RumunCR;

	RuskoCR *= rust;
	prepravaDunaj += RuskoCR;

	SrbskoCR *= rust;
	prepravaDunaj += SrbskoCR;

	SlovenCR *= rust;
	prepravaDunaj += SlovenCR;

	SyrieCR *= rust;
	prepravaDunaj += SyrieCR;

	TurecCR *= rust;
	prepravaDunaj += TurecCR;

	TurkmCR *= rust;
	prepravaDunaj += TurkmCR;

	UkrajOdr *= rust;
	prepravaDunaj += UkrajCR;

	MadarCR *= rust;
	prepravaDunaj += MadarCR;

	KyprCR *= rust;	
	prepravaDunaj += KyprCR;


	dunaj = prepravaDunaj;
}

void prepravaEtap3(){
	float prepravaDunaj = 0;
	float prepravaOdra = 0;
	float rust = 1.01;

	EgyptCR *= rust;
	EgyptOdr *= rust;
	prepravaDunaj += EgyptOdr + EgyptCR;
	prepravaOdra += EgyptOdr;

	AzerCR *= rust;
	AzerOdr *= rust;
	prepravaDunaj += AzerOdr + AzerCR;
	prepravaOdra += AzerOdr;

	BosnaCR *= rust;
	BosnaOdr *= rust;
	prepravaDunaj += BosnaOdr + BulharCR;
	prepravaOdra += BosnaOdr;

	BulharCR *= rust;
	BulharOdr *= rust;
	prepravaDunaj += BulharOdr + BulharCR;
	prepravaOdra += BulharOdr;

	NemecCRO *= rust;
	NemecOdr *= rust;
	prepravaDunaj +=  NemecCRO + NemecOdr;
	prepravaOdra += NemecOdr + NemecCRO;

	GruziCR *= rust;
	GruziOdr *= rust;
	prepravaDunaj += GruziCR + GruziOdr;
	prepravaOdra += GruziOdr;

	IranCR *= rust;
	IranOdr *= rust;
	prepravaDunaj += IranOdr + IranCR;
	prepravaOdra += IranOdr;

	IzraeCR *= rust;
	IzraeOdr *= rust;
	prepravaDunaj += IzraeCR + IzraeOdr;
	prepravaOdra += IzraeOdr;

	KazachCR *= rust;
	KazachOdr *= rust;
	prepravaDunaj += KazachCR + KazachOdr;
	prepravaOdra += KazachOdr;

	ChorCR *= rust;
	ChorOdr *= rust;
	prepravaDunaj += ChorCR + ChorOdr;
	prepravaOdra += ChorOdr;

	LibanCR *= rust;
	LibanOdr *= rust;
	prepravaDunaj += LibanOdr + LibanCR;
	prepravaOdra += LibanOdr;

	MoldCR *= rust;
	MoldOdr *= rust;
	prepravaDunaj += MoldOdr + MoldCR;
	prepravaOdra += MoldOdr;

	RakouCR *= rust;
	RakouOdr *= rust;
	prepravaDunaj += RakouCR + RakouOdr;
	prepravaOdra += RakouOdr;

	PolskoCR *= rust;
	PolskoDun *= rust;
	prepravaDunaj += PolskoDun;
	prepravaOdra += PolskoDun + PolskoCR;

	RumunCR *= rust;
	RumunOdr *= rust;
	prepravaDunaj += RumunCR + RumunOdr;
	prepravaOdra += RumunOdr;

	RuskoCR *= rust;
	RuskoOdr *= rust;
	prepravaDunaj += RuskoCR + RuskoOdr;
	prepravaOdra += RuskoOdr;

	SrbskoCR *= rust;
	SrbskoOdr *= rust;
	prepravaDunaj += SrbskoCR + SrbskoOdr;
	prepravaOdra += SrbskoOdr;

	SlovenCR *= rust;
	SlovenOdr *= rust;
	prepravaDunaj +=  SlovenCR + SlovenOdr;
	prepravaOdra += SlovenOdr;

	CRDun *= rust;
	CROdr *= rust;
	prepravaDunaj += CRDun;
	prepravaOdra += CROdr;

	TurecCR *= rust;
	TurecOdr *= rust;
	prepravaDunaj +=  TurecCR + TurecOdr;
	prepravaOdra += TurecOdr;

	TurkmCR *= rust;
	TurkmOdr *= rust;
	prepravaDunaj += TurecCR + TurkmOdr;
	prepravaOdra += TurkmOdr;

	UkrajCR *= rust;
	UkrajOdr *= rust;
	prepravaDunaj += UkrajCR + UkrajOdr;
	prepravaOdra += UkrajOdr;

	MadarCR *= rust;
	MadarOdr *= rust;
	prepravaDunaj += MadarCR + MadarOdr;
	prepravaOdra += MadarOdr;

	KyprCR *= rust;
	KyprOdr *= rust;
	prepravaDunaj += KyprCR + KyprOdr;
	prepravaOdra += KyprOdr;


	dunaj = prepravaDunaj;
	odra = prepravaOdra;
}

void prepravaEtap4(){
	float prepravaDunaj = 0;
	float prepravaOdra = 0;
	float prepravaLabe = 0;
	float rust = 1.01;
    
    EgyptCR *= rust;
	EgyptOdr *= rust;
	EgyptLab *= rust;
	prepravaDunaj += EgyptOdr + EgyptCR + EgyptLab;
	prepravaOdra += EgyptOdr;
	prepravaLabe += EgyptLab;

	AzerCR *= rust;
	AzerOdr *= rust;
	AzerLab *= rust;
	prepravaDunaj += AzerOdr + AzerCR + AzerLab;
	prepravaOdra += AzerOdr;
	prepravaLabe += AzerLab;

	BosnaCR *= rust;
	BosnaOdr *= rust;
	BosnaLab *= rust;
	prepravaDunaj += BosnaOdr + BosnaCR + BosnaLab;
	prepravaOdra += BosnaOdr;
	prepravaLabe += BosnaLab;

	BulharCR *= rust;
	BulharOdr *= rust;
	BulharLab *= rust;
	prepravaDunaj += BulharOdr + BulharCR + BulharLab;
	prepravaOdra += BulharOdr;
	prepravaLabe += BulharLab;

	BremenCR *= rust;;
	BremenDun *= rust;
	prepravaDunaj += BremenDun;
	prepravaLabe += BremenDun + BremenCR;

	NemecCRO *= rust;
	NemecOdr *= rust;
	NemecCRL *= rust;
	NemecLab *= rust;
	prepravaDunaj +=  NemecCRO + NemecOdr + NemecLab;
	prepravaOdra += NemecOdr + NemecCRO;
	prepravaLabe += NemecLab + NemecCRL;

	GruziCR *= rust;
	GruziOdr *= rust;
	GruziLab *= rust;
	prepravaDunaj += GruziCR + GruziOdr + GruziLab;
	prepravaOdra += GruziOdr;
	prepravaLabe += GruziLab;

	HambuCR *= rust;
	HambuDun *= rust;
	prepravaLabe += HambuCR + HambuDun;
	prepravaDunaj += HambuDun;

	IranCR *= rust;
	IranOdr *= rust;
	IranLab *= rust;
	prepravaDunaj += IranOdr + IranCR + IranLab;
	prepravaOdra += IranOdr;
	prepravaLabe += IranLab;

	IzraeCR *= rust;
	IzraeOdr *= rust;
	IzraeLab *= rust;
	prepravaDunaj += IzraeCR + IzraeOdr + IzraeLab;
	prepravaOdra += IzraeOdr;
	prepravaLabe += IzraeLab;

	KazachCR *= rust;
	KazachOdr *= rust;
	KazachLab *= rust;
	prepravaDunaj += KazachCR + KazachOdr + KazachLab;
	prepravaOdra += KazachOdr;
	prepravaLabe += KazachLab;

	ChorCR *= rust;
	ChorOdr *= rust;
	ChorLab *= rust;
	prepravaDunaj += ChorCR + ChorOdr + ChorLab;
	prepravaOdra += ChorOdr;
	prepravaLabe += ChorLab;

	LibanCR *= rust;
	LibanOdr *= rust;
	LibanLab *= rust;
	prepravaDunaj += LibanOdr + LibanCR + LibanLab;
	prepravaOdra += LibanOdr;
	prepravaLabe += LibanLab;

	MoldCR *= rust;
	MoldOdr *= rust;
	MoldLab *= rust;
	prepravaDunaj += MoldOdr + MoldCR + MoldLab;
	prepravaOdra += MoldOdr;
	prepravaLabe += MoldLab;

	RakouCR *= rust;
	RakouOdr *= rust;
	RakouLab *= rust;
	prepravaDunaj += RakouCR + RakouOdr + RakouLab;
	prepravaOdra += RakouOdr;
	prepravaLabe += RakouLab;

	PolskoCR *= rust;
	PolskoDun *= rust;
	prepravaDunaj += PolskoDun;
	prepravaOdra += PolskoDun + PolskoCR;

	RotterCR *= rust;
	RotterDun *= rust;
	prepravaDunaj += RotterDun;
	prepravaLabe += RotterCR + RotterDun;

	RumunCR *= rust;
	RumunOdr *= rust;
	RuskoLab *= rust;
	prepravaDunaj += RumunCR + RumunOdr + RumunLab;
	prepravaOdra += RumunOdr;
	prepravaLabe += RumunLab;

	RuskoCR *= rust;
	RuskoOdr *= rust;
	RuskoLab *= rust;
	prepravaDunaj += RuskoCR + RuskoOdr + RuskoLab;
	prepravaOdra += RuskoOdr;
	prepravaLabe += RuskoLab;

	SrbskoCR *= rust;
	SrbskoOdr *= rust;
	SrbskoLab *= rust;
	prepravaDunaj += SrbskoCR + SrbskoOdr + SrbskoLab;
	prepravaOdra += SrbskoOdr;
	prepravaLabe += SrbskoLab;

	SlovenCR *= rust;
	SlovenOdr *= rust;
	SlovenLab *= rust;
	prepravaDunaj +=  SlovenCR + SlovenOdr +  SlovenLab;
	prepravaOdra += SlovenOdr;
	prepravaLabe += SlovenLab;

	CRDun *= rust;
	CROdr *= rust;
	CRLab *= rust;
	prepravaDunaj += CRDun;
	prepravaOdra += CROdr;
	prepravaLabe += CRLab;

	TurecCR *= rust;
	TurecOdr *= rust;
	TurecLab *= rust;
	prepravaDunaj +=  TurecCR + TurecOdr + TurecLab;
	prepravaOdra += TurecOdr;
	prepravaLabe += TurecLab;

	TurkmCR *= rust;
	TurkmOdr *= rust;
	TurkmLab *= rust;
	prepravaDunaj += TurecCR + TurkmOdr + TurkmLab;
	prepravaOdra += TurkmOdr;
	prepravaLabe += TurkmLab;

	UkrajCR *= rust;
	UkrajOdr *= rust;
	UkrajLab *= rust;
	prepravaDunaj += UkrajCR + UkrajOdr + UkrajLab;
	prepravaOdra += UkrajOdr;
	prepravaLabe += UkrajLab;

	MadarCR *= rust;
	MadarOdr *= rust;
	Madarlab *= rust;
	prepravaDunaj += MadarCR + MadarOdr + Madarlab;
	prepravaOdra += MadarOdr;
	prepravaLabe += Madarlab;

	KyprCR *= rust;
	KyprOdr *= rust;
	KyprLab *= rust;
	prepravaDunaj += KyprCR + KyprOdr + KyprLab;
	prepravaOdra += KyprOdr;
	prepravaLabe += KyprLab;

	dunaj = prepravaDunaj;
	odra = prepravaOdra;
	labe = prepravaLabe;
}
float inflace(){
	
	float a = 1.01;
	float b = 1.04;
	float vysl = a + (b-a)*(float) rand()/RAND_MAX;
	
	return vysl;
}
float udrzba_kanalu(int rok){
	float udrzbaKanal;
	if(rok >= etapa1 && rok < etapa2 )
		udrzbaKanal = 9.2;
	if(rok >= etapa2 && rok < etapa3 )
		udrzbaKanal = 16.9;
	if(rok >= etapa3 && rok < etapa1a )
		udrzbaKanal = 33.6;
	if(rok >= etapa3 && rok < etapa1a )
		udrzbaKanal = 35.9;
	if(rok >= etapa4 )
		udrzbaKanal = 54.8;
	
	return udrzbaKanal;
}
float vypocetVydelkuZaRok (int rok) {
	float finance = 0;
	
	finance = vypocetMytaZaRok(rok);
	finance -= rekonstrukceEtap(rok);
	finance -= udrzba_kanalu(rok);
	finance += energetickHospodarstvi(rok);
	
	return finance;
}
int main(){
	int delkaSimulace = 50;
	int rok = 2017;
	int i;

	for(i = 0; i < delkaSimulace; i++){
		if(rok == etapa3)
			myto = 0.01;
		if(rok >= etapa1 && rok < etapa3)
			prepravaEtap1();
		if(rok >= etapa3 && rok < etapa4){
			myto *= inflace();
			prepravaEtap3();
		}
		if(rok >= etapa4){
			myto *= inflace();
			prepravaEtap4();
		}

		printf("Celkove finance za rok %d jsou: %f\n", rok, vypocetVydelkuZaRok(rok));
		printf("rok: %d - %f \t %f \t %f\n", rok, dunaj, odra, labe);
		printf("-----------------------------------------------------\n");
		rok++;
    }

	return 0;
}