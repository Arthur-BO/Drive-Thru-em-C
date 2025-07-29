/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "projet.h"

 
ValorPedido ValorTotal[20];

pagamento      pag; 
produtagem        produ; 
int 	  	   ale, aux;
char 		       resp;





FILE * arqProdutos;
FILE * arqPedidos;

int main()
{		
	setlocale(LC_ALL, "portuguese");
	ale = retornoVenda();
	venda   vend;
	system ("color 5e");
	system ("Projeto-Cardápio"); 
	
	do{
		if(aux > 0)
		{
			printf("\n\n==================================");
			printf("\nItens no carrinho\n");
			int i;
			for(i=0;i<aux;i++)
			{
				printf("\nProduto: %i    ---    Unidades: %i\n",todosPedidos[i].CodProduto,todosPedidos[i].qtde);
			}
			printf("==================================");
		}
		
		
		
		vend.CodVenda = ale;
		
		printf("\nDigite o código do produto desejado\n "); fflush(stdin); scanf("\t\t\t\t%i",&vend.CodProduto);
		
		printf("\nQual a quantidade desejada?\n ");   fflush(stdin);  scanf("\t\t\t\t%i",&vend.qtde);
		
	
		todosPedidos[aux] = vend;
		aux++;
		
		printf("\nDeseja encerrar o pedido? \n s = sim | outra tecla = não\n "); resp = getche();
	}
	while(resp != 's' && resp !='S');

	RegistraVenda(aux);
	
	system("cls");
	system("mode 70,30");
	printf(" Pedido salvo.\n Itens do pedido: \n");
	
	PedidoFinal(aux);
	int i;
	float tot;
	int numvenda = 0;
	numvenda = retornoVenda();
	   for (i=numvenda; i== numvenda; i++)
    {
    	arqtot = fopen("RECIBO.TXT","w");
        ValorTotal[i].CodVenda = numvenda;
        tot += todosPedidos[i].qtde * produ.Custoprod;
        ValorTotal[i].Total = tot; 
            fprintf (arqtot, "\n+-----------------------------------------------------------+");
		    fprintf (arqtot, "\n|              Rogério Pilocage DriveThru                   |");
		    fprintf (arqtot, "\n+-----------------------------------------------------------+");
		    fprintf (arqtot, "\n                    TOTAL R$ %5.2f                      ", tot);
		    fprintf (arqtot, "\n+-----------------------------------------------------------+");
         fwrite(&ValorTotal[i], 1 , sizeof(ValorPedido) , arqtot);
     }


        fclose(arqtot);
	getch();
	
	char regVender[50];	
		sprintf(regVender,"%s%d","pagamento -v ",ale);	
		system(regVender);
		system("Projeto-Pague");	
}
