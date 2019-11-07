
#ifndef RESTAURANTE_H
#define RESTAURANTE_H

typedef struct Pedido{

	int mesa;
	int ID;
	char texto[1000];
	long int timestamp;

}Pedido;

typedef struct Pedidos{

	Pedido * p[100];
	int top;

}Pedidos;


Pedido * newPedido(char * texto, int mesa, int ID, long int timestamp);

//Cria um novo pedido.

Pedido * lePedido();

//Le um pedido do teclado.

void addPedido(Pedido * p, Pedidos * ps);

//Salva pedido do arquivo no vetor Pedido v.

Pedidos * listaPedidos(Pedido * p, Pedidos * ps);

//Lista todos os pedidos do arquivo.

Pedidos * removeMaisAntigo(Pedido * p, Pedidos * ps);

//Primeiro printa na tela o pedido com o ID mais baixo e o remove do arq.

#endif
