IMS
===
 as
IMS

z knihy DOL jen takový rychlí průjezd :D
z úvodů typická souprava pro DOL 312 TEU o rozměrech 6.1x2.4x2.4 m        
35 jezů          
576 kč na tunu           
kamion 25t / 2 TEU (kontajner)            
vlak 1500t / 90TEU         
loď 4000t / 280TEU         
etapa 1- poblíž grosselzersdorf, poblíž Ganserndorf, malacky, poblíž kúty, hodonín,  - 2 plavební komory strana 222/223                          
etapa 2 - veselý nad moravou, uherské hradiště, otrokovice, přerov, kojetín - 5 plavební komory str 234/235                             
etapa 3- hranice, poruba, ostrava 2x, - 9 plavebních komor 252/253                                                           
etapa 3 odbočka - olomouc, přístav u štenberku 0 plavebních komor 256/257     navazuje na etapu 4                                             
etapa 1a polsko - raciborz, - 4 plavební komory 274/275                                                                        
etapa 4 - choceň, ústí nad orlicí, lanškroun, zábřeh, uničov, 11 plavebních komor, 5 tunelů, 2 mosty 280/281                      
31 plavebních komor                                                                                                     
délka 507,34, náklady 8880,6 milionu Eur                                                                                     
292/293 pěkné obrázky kolik to bude stát                                                                                       

rychlost lodě na kanály přibližně 10 uzlů což je přibližně 19km/h                                                                 
zdymadlo 170mx24m naplní za 22 min vyprázdní za 16 min  rozdíl hladin 7.5m => naplnění 1m za 2.9 min vyprázdnění 1m 2.1 min



místa přístav Štětín, Kędzierzyn-Koźle v Polsku, Vídeň, Kožle, Bratislava, přerov, uherské hradiště kroměříž, olomouc , ústí nad orlicí, pardubice, kunín, ostrava, raciborz

externí náklady při přepravě po vodě 3,5 krát nižší než při přepravě po železnici a 6,3 krát nižší než při přepravě po silnici.

přeprava materialu 35 mil. tun ročně

lodˇ 1050 t hamburg děčín 9Eur/t
vlak 22 vagonu 47 t samá 23Eur/t
24 kamionu 25 t samá 54Eur/t


cca 21,621,622 Eur na km = 605 405 000 Kč                                                                      

údržba 50 mil. euro za rok po dokončení 4. etapy z roku 2004                                                         

materiál 80 mil tun za rok                                                                              

náklady na přepravu v průměru 572kč na tunu                                                            

při lodi 4000t a 80 mil tun za rok propluje kanálem 20000 lodí za rok 




--------------------------------------------------
parametry (k)análu

    Vodní cesta je navrhována s následujícími rozměry:
    Třída vodní cesty[56]: Vb
    Přípustná délka tlačných souprav (m)[57]: 185
    Přípustná délka motor. náklad. lodí (m): 135
    Přípustná šířka plavidel (m): 11,4
    Přípustný ponor (m): 2,8
    Maximální nosnost souprav (t): 4 000
    Maximální nosnost motor. nákl. lodí (t): 2 700
    Délka plavebních komor (m): 190
    Šířka plavebních komor (m): 12,5
    Šířka plavební dráhy (m): 40,0
    Šířka lichoběžníkového profilu průplavu v hladině (m): 54,0
    Hloubka lichoběžníkového profilu průplavu (m): 4,0 – 5,0
    Minimální poloměr oblouků Rmin (m): 800
    Výjimečně přípustný poloměr oblouků Rmin min (m): 650
    Podjezdná výška mostů (m): 7,0


----------------------------------------------------------

    NAKODENI:
        define (naklady na výstavbu jednotlivých etap)

        #---tahle vypocita kolik to vydela za rok-----
        FCE1: (mýto, kolikJeMateriáluZaRok) {
            +rozdeleni pravdepodobnosti kdo kam pluje: 
            +rocni narust lodí s nakladem

        } 

        #---procentualni pribytek lodi za rok (random)-----
        FCE2: () {
            return;
        }

pozn.: myto = pocet KM * pocet tun * (0.006-0.01) €

pozn.: vydelek = vydelek - vydaje na udrzbu kanalu

pozn.: po 10 letech az si zvyknou na myto, jim je zvednout

pozn.: modelovani statistickych zacne od dokocneni vystavby, tj vsech 4 etap

pozn.: preprava na str. 110 a dal
