/*-------------------------------------------------------------- 
 Projeto final de LG1A1 - DriveThru.
 Autores: 
 Arthur Barbosa de Oliveira - SP3046974 
 Gabriel de Morais Ruiz -     SP3046893
 -------------------------------------------------------------*/

#include "projet.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

char   menuk (void)
{
	char escolha;
	system ("color 5e");
	system ("mode 40,20");
	system ("cls");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n                M E N U                 ");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n       1. Cadastro de produtos          ");
	printf ("\n       2. Consulta de produtos          ");
	printf ("\n       3. Fazer pedido                  ");
	printf ("\n       4. Pague                         ");
	printf ("\n       0. FIM                           ");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n   Escolha: "); fflush (stdin); escolha = getche();
	
    return (escolha);
}

void admin (char tecla)
{
    switch ( tecla )
    {
	   case '0': exit(0);
	   case '1': system ("Projeto-CadastroProdutos"); 		break;
	   case '2': system ("Projeto-Cardápio");				break;
	   case '3': system ("Projeto-Vendas"); 				break; 
	   case '4': system ("Projeto-Pague");					break;
	}	
}


int main ()
{
	setlocale (LC_ALL, "");
	char esc;
	while ( esc != '0' )
	{
	   esc = menuk();
       admin (esc);	
    }
	return (0);
}

