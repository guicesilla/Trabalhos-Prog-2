//main.c
#include "Restaurante.h"
#include <stdio.h>
#include <stdlib.h>
#include "Restaurante.h"

int main(){

int op, mesa, id;
char txt;
long int temp;

Pedido * x = newPedido(txt,mesa,id,temp);
Pedidos * ps;

FILE *fp;



do{

printf("-----Menu-----\n");
printf("1 - Novo pedido\n");
printf("2 - Listar pedidos\n");
printf("3 - Remover pedido mais antigo\n");
printf("4 - Sair\n");

scanf("%d",&op);

    switch(op){

        case 1:

            lePedido(x);
            break;

        case 2:
			listaPedidos(x, ps);
            break;

        case 3:
			addPedido(x, ps);
            break;


}


}while(op != 4);



}
