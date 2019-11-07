//Guilherme Augusto Leme Cesila 217116
//Julia Yumy Nakamura 219372

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

FILE * fp;


//registro aluno.
typedef struct Aluno
{
    char nome[200];//
    long int ra;
    int idade;
    float CR;
} Aluno;

typedef struct Disciplina
{
    char nome[200];
    char professor[200];
    Aluno v[200];
    int top;//numero de alunos. come¸ca com zero.
} Disciplina;

Disciplina d;
Aluno a;

Aluno le()
{

//Le aluno do teclado.


    printf("--Adicionar Aluno--\n");

    printf("\nDigite o nome do Aluno:");
    scanf("%s",	 &a.nome);
    printf("\nDigite o RA do Aluno:");
    scanf("%ld", &a.ra);
    printf("\nDigite a idade do Aluno:");
    scanf("%d",  &a.idade);
    printf("\nDigite o CR do Aluno:");
    scanf("%f",  &a.CR);

    return a;

}

void imprimeA(Aluno al) //aluno le()
{

//imprime o aluno no terminal.

    printf("\nNome do Aluno:  %s",  al.nome);
    printf("\nRA do Aluno:    %ld", al.ra);
    printf("\nIdade do Aluno: %d",  al.idade);
    printf("\nCR do Aluno:    %f\n",al.CR);

}

void imprimeD()
{

//imprime a disciplina.
//primeiro o nome e o professor.
//finalmente, a lista de alunos.
// voce deve chamar o metodo imprimeA()

    fp = fopen("Disciplina.text", "r");

    fscanf(fp, "%s\n", &d.nome);
    fscanf(fp, "%s\n", &d.professor);

    printf("Disciplina:%s\n", d.nome);
    printf("Professor :%s\n", d.professor);

    int i;

    for(i = 0; i < d.top; i++)
    {
        imprimeA(d.v[i]);
    }

    fclose(fp);

}

void persisteD()
{

//salva a disciplina num arquivo.
//deve ser um unico arquivo com toda a informacao.
//Salvar informacoes no arquivo

    fp = fopen("Disciplina.text", "w");


    fprintf(fp, "%s\n", &d.nome);
    fprintf(fp, "%s\n", &d.professor);

    fclose(fp);

}

Disciplina carregaD()
{

int i;

fp = fopen("Disciplina.text", "a");

for(i = 0; i < d.top; i++){
	
	fprintf(fp, "%s\n",  &d.v[i].nome);
	fprintf(fp, "%ld\n", d.v[i].ra);
	fprintf(fp, "%d\n",  d.v[i].idade);
	fprintf(fp, "%f\n",  d.v[i].CR);
	
}

printf("\nAlunos salvos no arquivo com sucesso!\n");

fclose(fp);

}

Removealuno(long int RA)
{

    int i, j;

    for(i = 0; i < d.top; i++)
    {


        if(d.v[i].ra == RA)
        {

            printf("\n--Aluno Removido--\n");

            for(j = i; j > d.top - 1; j++)
            {
                d.v[j] = d.v[j + 1];
            }

            d.top = d.top - 1;

        }
    }
}

int main()
{


    int menu = 0;
  //  Disciplina x;
  //  Aluno a;
    long int remove;
    d.top = 0;

    fp = fopen ("Disciplina.text", "r");

    if(fp==NULL)
    {

        printf("Arquivo inexistente\n");
        printf("Digite o nome da Disciplina\n");
        gets(d.nome);
        printf("Digite o nome do professor\n");
        gets(d.professor);

        persisteD();
    }

    do
    {
        printf("*-------MENU-------*\n");
        printf("|1-Adicionar Aluno |\n");
        printf("|2-Remover Aluno   |\n");
        printf("|3-Listar Alunos   |\n");
        printf("|4-Salvar          |\n");
        printf("|5-Sair            |\n");
        printf("*------------------*\n");
        scanf("%d", &menu);

        switch(menu)
        {

        case 1:
           
            a = le();
            d.v[d.top] = a;
            d.top = d.top + 1;
            break;

        case 2:
            printf("Digite o RA de qual aluno a ser apagado:\n");
            scanf("%ld", &remove);
            Removealuno(remove);
            break;

        case 3:
            imprimeD();
            break;

        case 4:
            carregaD();
            break;
        }


    }
    while(menu != 5);

//printf("tamanho registro %lu\n",sizeof(Aluno));
//printf("tamanho long int %lu\n",sizeof(long int));
//printf("tamanho int %lu\n",sizeof(int));
//printf("tamanho float %lu\n",sizeof(float));
//printf("tamanho char 200*%lu\n",sizeof(char));
}
