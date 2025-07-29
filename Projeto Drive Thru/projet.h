#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

typedef   struct 
{ 
    int    	Codprod;
    char   	Nomeprod[25+1]; 
    float	Custoprod;
}produtagem;  

typedef struct 
{   
	int CodVenda;
	int CodProduto;
    int qtde;
}venda;

typedef   struct 
{   
    int    	Codpgto;
    char   	Formapgto[20+1]; 
    float	tot;
}  
pagamento; 

typedef   struct 
{   
	int     Codpgto;
    char   	numcartao[16]; 
}  
cartoes;

typedef struct
{
    int CodVenda;
    float Total;
}
ValorPedido; 

ValorPedido ValorTotal[20];

produtagem 	   modoprodu[50];
venda 		  modovendas[50];

venda vend;
produtagem produ;
pagamento      pag;  
cartoes       cart;
char formapgto;
FILE * arqPedidos;
FILE * arqProdutos;
FILE * arqpgto;
FILE *A;
FILE * recibo;
FILE * arqtot;

venda todosPedidos[100];



int retornoVenda()
{
	arqPedidos = fopen ("PEDIDOS.DAT", "a"); 
	if (arqPedidos == NULL) 
	{ 	
		setlocale(LC_ALL, "");
		system ("cls");
		system ("color 5e");
		printf("\n         Não há registro de pedidos.\n"); 
		printf("\nPressione qualquer tecla para iniciar seu pedido.\n");
		getch();
		system("Projeto-Vendas");
	}
	int CodVenda = 0;
	venda vend;
	while(fread(&vend, sizeof(vend), 1, arqPedidos)) 
	{
		if(CodVenda == 0)	
			CodVenda = vend.CodVenda;
		else
		{
			if(vend.CodVenda > CodVenda)
			{
				CodVenda = vend.CodVenda;
			}
		}		
	}

	CodVenda++;
	return CodVenda;
}

void PuxarMenu()
{	
	setlocale(LC_ALL, "portuguese");
	arqProdutos = fopen ("PRODUTOS.DAT", "r"); 
	if (arqProdutos == NULL) 
	{ 
		printf("\nArquivo não encontrado\n"); 
		getch();
		system("Projeto-Vendas");
	} 	
	
	printf("\n COD  -      NOME        -  VALOR  ");
	produtagem produ;
	while(fread(&produ, sizeof(produ), 1, arqProdutos)) 		
		printf ("\n %i    - %s      -  R$%.2f", vend.CodProduto, produ.Nomeprod, produ.Custoprod); 
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");								
	fclose(arqProdutos);
}

void RegistrodePedidos(venda vend)
{	
	setlocale(LC_ALL, "");
	arqPedidos = fopen ("PEDIDOS.DAT", "a"); 
	if (arqPedidos == NULL) 
	{ 
		printf("\nNão foi possível abrir um arquivo\n"); 
		getch();
		system("Projeto-Vendas");
	}		
	 	 
	fwrite(&vend, sizeof(vend), 1, arqPedidos); 		
		
	fclose(arqPedidos);
}

void RegistraVenda(int qtdePedidos)
{	
	setlocale(LC_ALL, "");
	int i;

	for(i=0;i<qtdePedidos;i++)
	{
		RegistrodePedidos(todosPedidos[i]);
	}
}


void PedidoFinal(int qtdePedidos)
{
	setlocale(LC_ALL, "");
	arqProdutos = fopen ("PRODUTOS.DAT", "r"); 
	if (arqProdutos == NULL) 
	{ 
		printf("\nArquivo não encontrado\n"); 
		getch();
		system("Projeto-Vendas");
	} 
	float tot = 0;
	produtagem produ;
	while(fread(&produ, sizeof(produ), 1, arqProdutos)) 
	{
		int i;
		for(i=0;i<qtdePedidos;i++)
		{
			if(produ.Codprod == todosPedidos[i].CodProduto)
			{
			printf ("\n\n Código: %i | Produto: %s | Preço: R$ %.2f | Unidades: %i \n Total parcial: R$%.2f", 
			produ.Codprod, produ.Nomeprod, produ.Custoprod,todosPedidos[i].qtde,todosPedidos[i].qtde * produ.Custoprod);
			tot += todosPedidos[i].qtde * produ.Custoprod;
			}
		}					 		
	}
	printf("\n\n Total do pedido: R$%.2f\n\n",tot);
	fclose(arqProdutos);
}

char menu (void)
{

    
    do 
    {
		system ("cls"); 
	    printf ("\n=============================================");
	    printf ("\n             OPÇÕES DE PAGAMENTO             ");
	    printf ("\n=============================================");
	    printf ("\n                1. Dinheiro                  ");
	    printf ("\n            2. Cartão de crédito             ");
	    printf ("\n            3. Cartão de débito              ");
	    printf ("\n                4. Cheque                    ");
	    printf ("\n               [S/s] = Sair                  ");
	    printf ("\n=============================================");
	    printf ("\n        Sua escolha:                       \n");
	    fflush(stdin); 
		formapgto = getche();
	} 
	while ( formapgto != 'S' && formapgto != 's' && (formapgto<'1'||formapgto>'4') ); 
	switch (formapgto)
	{
		case '1': printf ("\nPagamento em dinheiro \n");
		system ("Projeto-LeveDin"); break;
		case '2': printf ("\nPagamento em cartão de crédito \n");
		system ("Projeto-LeveCar"); break;
		case '3': printf ("\nPagamento em cartão de débito \n");
		system ("Projeto-LeveCar"); break;
		case '4': printf ("\nPagamento em cheque \n");
		system ("Projeto-LeveChe"); break;
		case 's': case 'S': exit(0); break;
	}

}

void  relatoriopagamentos	(void)
{  
	FILE * A;
   pagamento R;
   A = fopen ("PAGAMENTOS.DAT", "r");
        fprintf (A, "\n---------------------------------------------");
        fprintf (A, "\n            PAGAMENTOS EFETUADOS             ");
        fprintf (A, "\n---------------------------------------------");
        fprintf (A, "\n Codpgto       Formapgto            Valorpgto");
        fprintf (A, "\n---------------------------------------------");
   	    while ( !feof(A) )
   	    { 
		    fread (&R, sizeof(R), 1, A);
	   }
	   fclose(A);
   }



void  registracartao (cartoes R)
{
   FILE *A;
   A = fopen ("CARTOES.DAT", "a");
	fwrite (&R, sizeof(R), 1, A);
   fclose(A);
  
}

void pedecartao(cartoes *Rcart)
{   int i;
	printf ("\nDigite o número do cartão: "); 
	for (i=0; i<16; i++)
	{   do
		{
		   fflush (stdin); Rcart->numcartao[i] = getche();
	    }while ( Rcart->numcartao[i] <'0' || Rcart->numcartao[i] > '9');
	}
}

void mascaracartao(cartoes *Rcart)
{   int i;
	for (i=0; i<16; i++)
	{   if ( i>3 && i<12 )
		   Rcart->numcartao[i] = '*';
	}
	printf ("\nCartão a gravar:  %s", Rcart->numcartao); getch();
}

void  relatoriocartoes	(void)
{  FILE *A;
   cartoes R;
   A = fopen ("CARTOES.DAT", "r");
      fprintf (A, "\n---------------------------------------------");
        fprintf (A, "\n       PAGAMENTOS EFETUADOS COM CARTÃO       ");
        fprintf (A, "\n---------------------------------------------");
        fprintf (A, "\n Cod pedido           Número do cartão       ");
        fprintf (A, "\n---------------------------------------------");
   	    while ( !feof(A) )
   	    { 
		    fread (&R, sizeof(R), 1, A);
	        if ( !feof(A) )
	           fprintf (A, "\n%3d\t\t%-20s ", R.Codpgto, R.numcartao);
	   }
	   fclose(A);
   }

void registrapgto (pagamento Rpgto)
{
	
	pagamento R;
	arqpgto = fopen ("PAGAMENTOS.DAT", "a");
	if (arqpgto == NULL)
    {
    	printf("ERRO AO ABRIR O ARQUIVO PRODUTOS.DAT!");
    	getch();
    	exit(0);
	}
	fwrite (&Rpgto, sizeof(Rpgto), 1, arqpgto );
	R.Codpgto = system("CalculaQtdRegistrosArquivo2") + 1;
    fclose (arqpgto);
}

