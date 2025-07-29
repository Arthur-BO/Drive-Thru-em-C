
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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


FILE *Arq;
int   numero_registros;


int main()
{
	Arq = fopen ("PRODUTOS.DAT", "r");
	if ( Arq == NULL) /* O arquivo não existe */
	   numero_registros = 0;
	else
	{   /* Calcula o tamanho do arquivo */
		if ( fseek (Arq, 0, SEEK_END) ) /* Aqui fseek tenta se posicionar no final do arquivo...*/
		{
           printf("\nERRO ao calcular o tamanho de arquivo!\n");
           getch();
           numero_registros = -1;
        }
        else
		{   /*...para que ftell 'conte' quantos bytes o arquivo tem */
		    /* Dividindo-se o total de bytes do arquivo pelo tamanho de cada registro */
		    /* tem-se o número de registros do arquivo. */
		    numero_registros =  ftell(Arq) / sizeof (produtagem); 
  	    }
  	    /* Fecha o arquivo */
  	    fclose (Arq);
	}
    /* Para teste: avisa quantos bytes o arquivo tem */
    /* printf ("\nO arquivo PRODUTOS.DAT tem [%i] registros.", numero_registros);*/

    /* 'devolve' a quantidade de registros para o programa 'chamador'*/
	return (numero_registros); 
}
