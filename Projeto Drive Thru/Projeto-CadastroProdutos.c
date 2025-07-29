
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef   struct 
{ 
    int    	Codprod;
    char   	Nomeprod[25+1]; 
    float	Custoprod;
}produtagem;  

typedef struct 
{   
	int CodVenda;
	int   CodProduto;
    int   Qtde;
} pedidos;

produtagem    produ; 


void  captura_produto (void)
{
	system ("color 5e");
	system ("mode 60,40");
	system ("cls");	
	produ.Codprod = system("CalculaQtdRegistrosArquivo") + 1;
	printf ("\nCodigo do produto: "); 
	printf ("%i", produ.Codprod);
	printf ("\nDigite o nome do produto: "); 
	fflush (stdin); 	gets(produ.Nomeprod); 
	printf ("\nDigite o valor do produto R$: ");
	fflush (stdin);     scanf  ("%f", &produ.Custoprod); 
}

void gravar_produto (void)
{
    FILE  *A; 
    A  =  fopen ("PRODUTOS.DAT" , "a");	
    if (A == NULL)
    {
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    	getch();
    	exit(0);
	}
	fwrite ( &produ,  sizeof(produ), 1, A );
	fclose (A);
}


int main ()
{
	char sina;
	
	system ("color 5e");
	setlocale(LC_ALL, "");
	system("cls");
	printf("Deseja cadastrar um produto? [S/N]\n");
	fflush(stdin);   scanf("%c", &sina);
	
	while (sina == 's' || sina == 'S'){
	captura_produto();
	gravar_produto();
	printf ("\nDeseja cadastrar outro produto? [S/N]\n");
	fflush(stdin);   scanf("%c", &sina);	
	}
	
    return (0);
}
