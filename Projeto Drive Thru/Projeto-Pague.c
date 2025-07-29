/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include "projet.h"

char menu (void);
void registrapgto (pagamento Rpgto);
void  relatoriopagamentos	(void);
void  registracartao (cartoes R);
void pedecartao(cartoes *Rcart);
void mascaracartao(cartoes *Rcart);
int main (void);


pagamento      pag;  
cartoes       cart;
char formapgto;


int main (void)
{
	char opc;
	pagamento Rpgto;
    cartoes   Rcart;
    system ("mode 45,20");
	system ("color 5e");
	setlocale (LC_ALL,"portuguese");
		opc = menu();
	sleep(1);

	
	return 0;
}

