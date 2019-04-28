#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pbuffer;

typedef struct var{
	int escolha, contador, i, achei, posicao;
	char nome[20];
} variaveis;

typedef struct pe {
   char nome[20], cpf[15];
} pessoa;

variaveis *inicio;

void inserir();
void listar();
void apagar();
void buscar();

int main () {

    printf("---------- AGENDA -------------");

    pbuffer = malloc(sizeof(variaveis));

    inicio = pbuffer;

    inicio->contador = 0;

    do {
        printf("\n[>1<] INSERIR\n[>2<] LISTAR\n[>3<] APAGAR\n[>4<] BUSCAR\n[>5<] SAIR\n");
        scanf("%d", &inicio->escolha);

		switch (inicio->escolha) {
			case 1:
				inserir();
				break;
			case 2:
				listar();
				break;
			case 3:
				apagar();
				break;	
			case 4:
				buscar();
				break;	
			default:
                free(pbuffer);
                exit(1);
                break;
		}
	} while (1);

}
void inserir() {

    pessoa *p;

    if ((pbuffer = (pessoa *) realloc(pbuffer, sizeof(variaveis) + sizeof(pessoa) + (sizeof(pessoa) * inicio->contador))) == NULL) {
       printf("Falta de memória!");
       exit(1);
    }

    p = pbuffer + sizeof(variaveis) + (sizeof(pessoa) * inicio->contador);

    printf("\nNome: ");
    scanf("%s", p->nome);
    printf("\nCPF: ");
    scanf("%s", p->cpf);


    inicio->contador++;
}
void listar() {

   pessoa *p;

   p = pbuffer + sizeof(variaveis);

   for (inicio->i = 0; inicio->i < inicio->contador; inicio->i++) {
        printf("\n%s", p->nome);
        p++;
   }
   
   printf("\n");

}
void apagar() {
	/*
	if (inicio->contador == 0) {
		printf("------------");
		printf("AGENDA VAZIA!");
		printf("------------");	
	} else if ((pbuffer = (pessoa *) realloc(pbuffer, sizeof(variaveis) + (sizeof(pessoa) * inicio->contador))) != NULL) {
		printf("\n-------------------------\nPessoa excluida com sucesso...\n-------------------------\n");	
		inicio->contador--;
	}	*/
	
	inicio->achei = 0;
	inicio->posicao = 0;
	
	printf("Nome a ser apagado: ");
	scanf("%s", inicio->nome);
	
	pessoa *p;
	
	p = pbuffer + sizeof(variaveis);
	
	for (inicio->i = 0; inicio->i < inicio->contador; inicio->i++) {
		if (strcmp(p->nome, inicio->nome) == 0) {
			inicio->achei = 1;	
			inicio->posicao = inicio->i;
		}	
		p++;
	}	
	
	if (inicio->achei == 0) {
		printf("\n--------------------------\n");
		printf("  Nome nao encontrado...\n");
		printf("--------------------------\n");	
	} else {
		
		pessoa *aux;
		
		p = pbuffer + sizeof(variaveis) + (sizeof(pessoa) * inicio->posicao);
		
		aux = pbuffer + sizeof(variaveis) + (sizeof(pessoa) * inicio->posicao) + sizeof(pessoa);
		
		for (inicio->i = 0; inicio->i < (inicio->contador - inicio->posicao); inicio->i++) {
			strcpy(p->nome, aux->nome);
			strcpy(p->cpf, aux->cpf);
			p++;
			aux++;
		}	
		if ((pbuffer = (pessoa *) realloc(pbuffer, sizeof(variaveis) + (sizeof(pessoa) * (inicio->contador - 1)))) != NULL) {
			printf("\n-------------------------\nPessoa excluida com sucesso...\n-------------------------\n");	
			inicio->contador--;
		}	
	}		
	
	
}	
void buscar() {
	
	
	printf("Nome a ser buscado: ");
	scanf("%s", inicio->nome);
	
	pessoa *p;
	
	inicio->achei = 0;
	
	p = pbuffer + sizeof(variaveis);
	
	for (inicio->i = 0; inicio->i < inicio->contador; inicio->i++) {
		if (strcmp(p->nome, inicio->nome) == 0) {
			inicio->achei = 1;	
			printf("\n------------------------\n");
			printf("Nome: %s\nCPF: %s\n", p->nome, p->cpf);
			printf("------------------------\n");
		}	
		p++;
	}	
	
	if (inicio->achei == 0) {
		printf("\n------------------------\n");
		printf("  Nome nao encontrado...\n");
		printf("------------------------\n");	
	}	
	
	
}	
