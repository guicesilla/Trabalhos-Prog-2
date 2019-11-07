#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE * Alunos;
FILE * Disciplinas;
FILE * Prerequisitos;

typedef struct Disciplinas{
	
	char codigo[100];
	char nome[100];
	int creditos;
	int top;
	
}Disciplina;

typedef struct preRequisitos{
	
	char codigo[100];
	char nome[100];
	
}preRequisitos;

typedef struct Aluno{
	
	long int RA;
	char nome[100];
	char login[100];
	char senha[100];
	int cima;
	
}Aluno;

Aluno a[100];
int cima = 1;
Disciplina d;
preRequisitos p[50];

AlunoCadastro(Aluno a){
	
	printf("Digite seu RA:");
	scanf("%ld", &a.RA);
	printf("Digite seu nome:");
	scanf("%s",  &a.nome);
	printf("Digite seu login:");
	scanf("%s",  &a.login);
	printf("Digite a senha:");
	scanf("%s",  &a.senha);

}

SalvaAluno(){
	
	Alunos = fopen("Alunos.txt", "a+");
	
	int i;
	
	for(i = 0; i < cima ; i++){
		
		fprintf(Alunos, "%ld", a[i].RA);
		fprintf(Alunos, "%s",  a[i].nome);
		fprintf(Alunos, "%s",  a[i].login);
		fprintf(Alunos, "%s",  a[i].senha);
		
	}
	
	fclose(Alunos);
	
};

void loginAluno(){
	
	Alunos = fopen("Alunos.txt", "r");
	
	int i, j = 1;
	char aux1 [100];
	char aux2 [100];
	char aux3 [100];
	char aux4 [100];
	char buff[100];
	
	do{
	
	
	printf("Usuario:");
	scanf("%s", &aux1);
	printf("Senha:");
	scanf("%s", &aux2);
	
	
	
	for(i = 0; i < cima; i++){
		
	fscanf(Alunos, "%[^,],%[^,],%[^,],%[^\n]", &buff, &buff, &aux3, &aux4);
	
	if(strcmp(aux3, aux1) == 0 && strcmp(aux2, aux4) == 0){
		
		j = 0;
		
		break;
		
	}else{
		
		printf("Usuario nao encontrado\n");
		
	}
	
		
	}
	
 }while(j);
 
 	
};

consultaDisciplina(){
	
	char aux[100], pre[100];
	int i, j;
	
	Disciplinas = fopen("Disciplinas.text", "r");
	Prerequisitos = fopen("Prerequisitos.text", "r");
	
	printf("Digite a disciplina:");
	scanf("%s", &aux);
	
	for(i = 0; i < d.top ; i++){
		
	fscanf(Disciplinas, "%s", &d.codigo);
	
	if(aux == d.codigo){
	
	fscanf(Disciplinas, "%s", &d.codigo);
	printf("%s\n", d.codigo);
	fscanf(Disciplinas, "%s", &d.nome);
	printf("Nome:");
	printf("%s\n", d.nome);
	fscanf(Disciplinas, "%d", &d.creditos);
	printf("Quantidade de Creditos:");
	printf("%d\n", d.creditos);
		
		for(j = 0; j < 50; j++){
			
			fscanf(Prerequisitos, "%s", &p[j].codigo);
			
			if(strcmp(d.codigo, p[j].codigo) == 0 ){
				
				printf("Pre-requisito:");
				printf("%s\n", p[j].codigo);
				
			}
			
		}
	
	
	}else{
		
		printf("Codigo nao encontrado, Digite novamente.");
		
	}
	
	}
	
}

int main(){
	
	loginAluno();

	int navegacao;

	do{
	

	printf("    Menu de Opcoes\n");
	printf("Cadastro de Alunos - 1\n");
	printf("Consulta de Disciplinas - 2\n");
	printf("Sair - 3\n");
	
	scanf("%d", &navegacao);
	
	switch(navegacao){
		
		case 1:
			
			AlunoCadastro(a[cima]);
			SalvaAluno();
			
			break;
		
		case 2:
			
			consultaDisciplina();
			
			break;
	}
	
	}while(navegacao != 3);
	
	
}
