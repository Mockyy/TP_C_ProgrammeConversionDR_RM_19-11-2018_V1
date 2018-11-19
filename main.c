/****************************************************************************************************************
*-----------------------------------------------ALGORITHME------------------------------------------------------*
*****************************************************************************************************************

But : créer un algorithme qui convertit un chiffre romain en nombre décimal et vice-versa (de 1 à 3999).
Entrée : Un entier ou une chaine.
Sortie : Une chaine ou un entier.

CONST
    MAX : 15
    M : 1000
    D : 500
    C : 100
    L : 50
    X : 10
    V : 5
    I : 1

PROCEDURE choix
//L'utilisateur choisi si il veut convertir des nombres déciamux ou des nombres romains. Ou si il veut quitter.

    VAR
        nChoix : ENTIER

    ECRIRE "Programme : les chiffres romains"
    ECRIRE "1: Décimal -> Romain"
    ECRIRE "2: Romain -> Décimal"
    ECRIRE "0: Quitter"

    LIRE nChoix

    CAS nCHoix PARMI
        CAS 1: decimal_to_roman
        CAS 2: roman_to_decimal
        PARDEFAUT: stop
    FINCASPARMI

FINPROCEDURE


PROCEDURE decimal_to_roman
//Conversion décimal vers romain

    VAR
        nEntier : ENTIER
        cRomain : CHAINE

    DEBUT

    ECRIRE "Entrez un entier :"
    LIRE nEntier

    //On soustrait 1000 au nombre saisi et on ajoute un M à la chaine tant qu'il est supérieur à 1000.
    //On fait la même chose avec cue chaque nombre romain.
    TANTQUE (nEntier>=M) FAIRE
        cRomain <- cRomain & 'M'
        nEntier <- nEntier - M
    FINTANTQUE

    //Si le nombre (après soustraction) commence par 4 ou 9, on convertit par soustraction.
    //On fait la même chose pour chaque nombre romain.
    SI (nEntier<M ET nEntier>=900) ALORS
        cRomain <- cRomain & 'CM'
        nEntier <- nEntier - 900
    FINSI

    TANTQUE (nEntier>=D) FAIRE
        cRomain <- cRomain & 'D'
        nEntier <- nEntier - D
    FINTANTQUE

    SI (nEntier<D ET nEntier>=400) ALORS
        cRomain <- cRomain & 'CD'
        nEntier <- nEntier - 400
    FINSI

    TANTQUE (nEntier>=C) FAIRE
        cRomain <- cRomain & 'C'
        nEntier <- nEntier - C
    FINTANTQUE

    SI (nEntier<C ET nEntier>=90) ALORS
        cRomain <- cRomain & 'XC'
        nEntier <- nEntier - 90
    FINSI

    TANTQUE (nEntier>=L) FAIRE
        cRomain <- cRomain & 'L'
        nEntier <- nEntier - L
    FINTANTQUE

    SI (nEntier<L ET nEntier>=40) ALORS
        cRomain <- cRomain & 'XL'
        nEntier <- nEntier - 40
    FINSI

    TANTQUE (nEntier>=X) FAIRE
        cRomain <- cRomain & 'X'
        nEntier <- nEntier - X
    FINTANTQUE

    SI (nEntier=9) ALORS
        cRomain <- cRomain & 'IX'
        nEntier <- nEntier - 9

    TANTQUE (nEntier>=V) FAIRE
        cRomain <- cRomain & 'V'
        nEntier <- nEntier - V
    FINTANTQUE

    SI (nEntier=4) ALORS
        cRomain <- cRomain & 'IV'
        nEntier <- nEntier - 4

    TANTQUE (nEntier>=I) FAIRE
        cRomain <- cRomain & 'I'
        nEntier <- nEntier - I
    FINTANTQUE

    ECRIRE nEntier," = ",cRomain

FINPROCEDURE


PROCEDURE roman_to_decimal
//Converion de décimal vers romain.

    VAR
        nCpt : ENTIER
        nEntier : ENTIER
        cRomain : CHAINE

    DEBUT

    ECRIRE "Entrez un nombre romain : "
    LIRE cRomain

    //Pour chaque caractère, on additionne son équivalent en fonction du caractère suivant.
    POUR nCpt DE 1 A TAILLE(cRomain) FAIRE
        CAS cRomain[nCpt] PARMI
            CAS 'M' : nEntier <- nEntier + M
            CAS 'D' : nEntier <- nEntier + D
            CAS 'C' :
                CAS cRomain[nCpt+1] PARMI
                    CAS 'M' : nEntier <- nEntier + 900      //Dans le cas où 'C' est suivi de 'M', on aditionne 900 (au lieu de 100 + 1000).
                              nCpt <- nCpt + 1
                    CAS 'D' : nEntier <- nEntier + 400
                              nCpt <- nCpt + 1
                    PARDEFAUT : nEntier <- nEntier + C
                FINCASPARMI
            CAS 'L' :
                CAS cRomain[nCpt+1] PARMI
                    CAS 'M' : nEntier <- nEntier + 950
                              nCpt <- nCpt + 1
                    CAS 'D' : nEntier <- nEntier + 450
                              nCpt <- nCpt + 1
                    PARDEFAUT : nEntier <- nEntier + L
                FINCASPARMI
            CAS 'X' :
                CAS cRomain[nCpt+1] PARMI
                    CAS 'M' : nEntier <- nEntier + 990
                              nCpt <- nCpt + 1
                    CAS 'D' : nEntier <- nEntier + 490
                              nCpt <- nCpt + 1
                    CAS 'C' : nEntier <- nEntier + 90
                              nCpt <- nCpt + 1
                    CAS 'L' : nEntier <- nEntier + 40
                              nCpt <- nCpt + 1
                    PARDEFAUT : nEntier <- nEntier + X
                FINCASPARMI
            CAS 'V' :
                CAS cRomain[nCpt+1] PARMI
                    CAS 'M' : nEntier <- nEntier + 995
                              nCpt <- nCpt + 1
                    CAS 'D' : nEntier <- nEntier + 495
                              nCpt <- nCpt + 1
                    CAS 'C' : nEntier <- nEntier + 95
                              nCpt <- nCpt + 1
                    CAS 'L' : nEntier <- nEntier + 45
                              nCpt <- nCpt + 1
                    PARDEFAUT : nEntier <- nEntier + V
                FINCASPARMI
            CAS 'I' :
                CAS cRomain[nCpt+1] PARMI
                    CAS 'M' : nEntier <- nEntier + 999
                              nCpt <- nCpt + 1
                    CAS 'D' : nEntier <- nEntier + 499
                              nCpt <- nCpt + 1
                    CAS 'C' : nEntier <- nEntier + 99
                              nCpt <- nCpt + 1
                    CAS 'L' : nEntier <- nEntier + 49
                              nCpt <- nCpt + 1
                    CAS 'X' : nEntier <- nEntier + 9
                              nCpt <- nCpt + 1
                    CAS 'V' : nEntier <- nEntier + 4
                              nCpt <- nCpt + 1
                    PARDEFAUT : nEntier <- nEntier + I
                FINCASPARMI
            FINCASPARMI
        FINPOUR

    ECRIRE cRomain," = ",nEntier




////////////////////////
//PROGRAMME PRINCIPAL//
//////////////////////

DEBUT

    choix

FIN.










*****************************************************************************************************************
*-----------------------------------------------PROGRAMME-------------------------------------------------------*
****************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 15

void decimal();
void romain();
void quit();

void decimal(){

    int nEntier = 1, nCopy = 0, i = 0;
    char cRomain[MAX];

    for(i=0;i<=MAX;i++){
        cRomain[i] = ' ';
    }

    printf("Nombre : ");
    scanf("%d",&nEntier);

    nCopy = nEntier;
    i = 0;
    while(nEntier>=1000){
        cRomain[i] = 'M';
        nEntier -= 1000;
        i++;
    }

    if (nEntier<=999 && nEntier>=900){
        cRomain[i] = 'C';
        cRomain[i+1] = 'M';
        nEntier -= 900;
        i+=2;
    }

    while(nEntier>=500){
        cRomain[i] = 'D';
        nEntier -= 500;
        i++;
    }

    if (nEntier<=499 && nEntier>=400){
        cRomain[i] = 'C';
        cRomain[i+1] = 'D';
        nEntier -= 400;
        i+=2;
    }
    while(nEntier>=100){
        cRomain[i] = 'C';
        nEntier -= 100;
        i++;
    }

    if (nEntier<=99 && nEntier>=90){
        cRomain[i] = 'X';
        cRomain[i+1] = 'C';
        nEntier -= 90;
        i+=2;
    }

    while(nEntier>=50){
        cRomain[i] = 'L';
        nEntier -= 50;
        i++;
    }

    if (nEntier<=49 && nEntier>=40){
        cRomain[i] = 'X';
        cRomain[i+1] = 'L';
        nEntier -= 40;
        i+=2;
    }

    while(nEntier>=10){
        cRomain[i] = 'X';
        nEntier -= 10;
        i++;
    }

    if (nEntier==9){
        cRomain[i] = 'I';
        cRomain[i+1] = 'X';
        nEntier -= 9;
        i+=2;
    }

    while(nEntier>=5){
        cRomain[i] = 'V';
        nEntier -= 5;
        i++;
    }

    if (nEntier==4){
        cRomain[i] = 'I';
        cRomain[i+1] = 'V';
        nEntier -= 4;
        i+=2;
    }

    while(nEntier>=1){
        cRomain[i] = 'I';
        nEntier -= 1;
        i++;
    }

    printf("%d = %s",nCopy,cRomain);
}

void romain(){

    int nEntier = 0, i = 0;
    char cRomain[MAX];

    printf("\nEntrez un nombre romain : ");
    scanf("%s",&cRomain);

    while (cRomain[i]=='M' || cRomain[i]=='D' || cRomain[i]=='C' || cRomain[i]=='L' || cRomain[i]=='X' || cRomain[i]=='V' || cRomain[i]=='I'){
        switch(cRomain[i]){
        case 'M' : nEntier += 1000;i++;break;
        case 'D' : nEntier += 500;i++;break;
        case 'C' :
            switch (cRomain[i+1]){
                case 'M' : nEntier += 900;i+=2;break;
                case 'D' : nEntier += 400;i+=2;break;
                default : nEntier += 100;i++;break;
            };break;

        case 'L' :
            switch (cRomain[i+1]){
                case 'M' : nEntier += 950;i+=2;break;
                case 'D' : nEntier += 450;i+=2;break;
                default : nEntier += 50;i++;break;
            };break;

        case 'X' :
            switch (cRomain[i+1]){
                case 'M' : nEntier += 990;i+=2;break;
                case 'D' : nEntier += 490;i+=2;break;
                case 'C' : nEntier += 90;i+=2;break;
                case 'L' : nEntier += 40;i+=2;break;
                default : nEntier += 10;i++;break;
            };break;

        case 'V' :
            switch (cRomain[i+1]){
                case 'M' : nEntier += 995;i+=2;break;
                case 'D' : nEntier += 495;i+=2;break;
                case 'C' : nEntier += 95;i+=2;break;
                case 'L' : nEntier += 45;i+=2;break;
                default : nEntier += 5;i++;break;
            };break;

        case 'I' :
            switch (cRomain[i+1]){
                case 'M' : nEntier += 999;i+=2;break;
                case 'D' : nEntier += 499;i+=2;break;
                case 'C' : nEntier += 99;i+=2;break;
                case 'L' : nEntier += 49;i+=2;break;
                case 'X' : nEntier += 9;i+=2;break;
                case 'V' : nEntier += 4;i+=2;break;
                default : nEntier += 1;i++;break;
            };break;
        }
    }

    printf("%s = %d",cRomain,nEntier);

}

void quit(){

    printf("Fermeture.");
}

int main()
{
    int choix = 0;

    printf("Que voulez-vous faire ? \n1: Decimal vers romain \n2: Romain vers decimal \n3: Quitter\n\n");
    scanf("%d",&choix);

    switch(choix){
        case 1 : decimal();break;
        case 2 : romain();break;
        default : quit();break;
    }

    return 0;
}

