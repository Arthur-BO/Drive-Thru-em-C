/* Bibliotecas */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "projet.h"


/* Vari�veis de mem�ria [vari�veis globais] */

char rec;

/* CORPO DO PROGRAMA */

int main()
{
	system ("color 5e");
	pagamento Rpgto;
    cartoes   Rcart;
	setlocale (LC_ALL, "portuguese");
				Rcart.Codpgto = Rpgto.Codpgto; 
           pedecartao(&Rcart); 
           mascaracartao (&Rcart); 
           registracartao(Rcart);
    	printf("\nGerando recibo");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	system ("RECIBO.TXT");
	system ("mode 38,10");
	system ("cls");
	system ("color 5d");
	printf ("\n=====================================");
	printf ("\n        PAGAMENTO EM CART�O          ");
	printf ("\n=====================================");
	getch();
	return 0;
}
