 //Guilherme Augusto Leme Cesila - 217116
 //Julia Yumy Nakamura Zanerato  - 219372
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include "Restaurante.h"

 FILE * fp;
 FILE * id;

 Pedido * newPedido(char * texto, int mesa, int ID, long int timestamp){

	Pedido * p = (Pedido *)malloc(sizeof(Pedido));
	p->mesa = mesa;
	p->ID = ID;
	p->timestamp = timestamp;
    strcpy(p->texto, &texto);
    
    return p;
}


Pedido * lePedido(){

	int i, top;
	int ID, mesa, timestamp; 
	char texto[1000];
	
	Pedidos * ps;
    Pedido * p;
	
	
	
	id = fopen("id.text", "r");
    fscanf(id ,"%d\n" , &ID);
    fclose(id);
    ID++;
    id = fopen("id.text", "w");
    fprintf(id,"%d\n",ID);
    ps->top = ID;
    fclose(id);

	p = newPedido(texto,mesa,ID,timestamp);
	
	printf("Digite a mesa:\n");
	scanf("%d", &mesa);
	
	p->mesa = mesa;
	
	printf("Digite o pedido:\n");
	scanf("%s", &p->texto);
	
	ps->p[1000];
	
	addPedido(p, ps);
	
	fclose(fp);

	return p;
	
}

void addPedido(Pedido * p, Pedidos *ps){
	
	int i;
	
	fp = fopen("Pedidos.text", "a");
	
	fprintf(fp, "%d\n",  p[i].mesa);
	fprintf(fp, "%s\n",  &p[i].texto);
	fprintf(fp, "%ld\n", p[i].timestamp == (long int) clock() / CLOCKS_PER_SEC);
		

}

Pedidos * listaPedidos(Pedido * p, Pedidos * ps){
	
	
	int i, aux;
	
	fp = fopen("Pedidos.text", "r"); 
	id = fopen("id.text", "r");
	
	
		
		fscanf(fp, "%d\n", &p[i].mesa);
		printf("%d\n",  p[i].mesa);
		fscanf(fp, "%s\n", &p[i].texto);
		printf("%s\n",  p[i].texto);
		fscanf(fp, "%ld\n", &p[i].timestamp);
		printf("%ld\n", p[i].timestamp);
		
	
	
	fclose(id);
	fclose(fp); 
}

Pedidos * removeMaisAntigo(Pedido * p, Pedidos * ps){

	int i, j, x;
	long int stop, total, tempo;
	
	fp = fopen("Pedidos.text", "a+");
	id = fopen("id.text", "a+");
	
	for(i = 0; i < ps->top; i++){
		
		stop = fscanf(fp, "%ld\n", p[i].timestamp);
		
		tempo = (long int) clock() / CLOCKS_PER_SEC; 
		
		total = stop - p[i].timestamp;
		
		fscanf(fp, "%d\n", &p[i].mesa);
		printf("%d\n", p[i].mesa);
		fscanf(fp, "%s\n", &p[i].texto);
		printf("%s\n", p[i].texto);
		printf("%ld\n", total);
		
		
		for(j = i; j > x - 1; j++){
			
			ps->p[j] = ps->p[j + 1];
			
		}
		
		ps->top = ps->top - 1;
		
	}
	
	fclose(fp);
	fclose(id);
} 
