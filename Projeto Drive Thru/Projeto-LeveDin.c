/* Bibliotecas */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "projet.h"


/* CORPO DO PROGRAMA */

int main()
{
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
	system ("color 5a");
	printf ("\n=====================================");
	printf ("\n        PAGAMENTO EM DINHEIRO        ");
	printf ("\n=====================================");
	getch();
	exit(0);
	return 0;
}



