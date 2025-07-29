/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef   struct 
{ 
    int    	Codprod;
    char   	Nomeprod[25+1]; 
    float	Custoprod[100];
}produtagem;  

typedef struct 
{   
	int CodVenda;
	int   CodProduto;
    int   Qtde;
} pedidos;

produtagem    produ; 

void ver_produtos (void)
{
    FILE  *A; 
    A  =  fopen ("PRODUTOS.DAT" , "r"); 		
    if ( A == NULL ) 
    {
    printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    getch();
    exit(0);
	}
	fread ( &produ,  sizeof(produ), 1, A );
	fclose (A);
}

void consulta_produtos (void)
{
	system ("cls");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n               CADASTRO DE PRODUTOS             ");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf ("\n   CODPROD      NOME               VALOR (R$)   ");	
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    						ver_produtos();
	printf ("\n   %i\t\t%-20s\t%.2f" , produ.Codprod, produ.Nomeprod, produ.Custoprod ) ;
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    getch();	
}

void consulta_todos_produtos (void)
{
    FILE  *A;
    A  =  fopen ("PRODUTOS.DAT" , "r");		
    if ( A == NULL ) 
    {
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    	getch();
    	exit(0); 
	}
	system ("cls");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n               PRODUTOS CADASTRADOS             ");
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf ("\n   CODPROD      NOME               VALOR (R$)   ");	
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    while (!feof(A))
    { 
    fread ( &produ,  sizeof(produ), 1, A );
     
    if (!feof(A))
	{  
	    printf ("\n   %i\t\t%-20s\t%.2f" , produ.Codprod, produ.Nomeprod, produ.Custoprod ) ; 
    }
    }
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    getch();	
}

int main ()
{
	system ("color 5e");
	consulta_todos_produtos();
    return (0);
}
