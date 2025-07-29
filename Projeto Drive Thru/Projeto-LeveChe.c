/* Bibliotecas */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "projet.h"

/* Variáveis de memória [variáveis globais] */

char rec;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale (LC_ALL, "portuguese");
	system ("color 5e");
	printf("\nGerando recibo");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	system ("RECIBO.TXT");
	system ("cls");
	system ("mode 38,10");
	system ("color 51");
	printf ("\n=====================================");
	printf ("\n        PAGAMENTO EM CHEQUE          ");
	printf ("\n=====================================");
	getch();
	exit(0);
	return 0;
}
