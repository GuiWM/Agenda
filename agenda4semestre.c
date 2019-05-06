#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pbuffer;


typedef struct pe {
   char nome[20], cpf[15];
} pessoa;

typedef struct var{
	int escolha, contador, i, achei, posicao, j, min_id;
	char nome[20];
	pessoa atual, min;
} variaveis;

variaveis *inicio;

void inserir();
void listar();
void apagar();
void buscar();
void insertionSort();
void selectionSort();
void bubbleSort ();

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
    
    //insertionSort();
    //selectionSort();
    bubbleSort();
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
		if ((pbuffer = (pessoa *) realloc(pbuffer, sizeof(variaveis) + (sizeof(pessoa) * inicio->contador))) != NULL) {
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
// Primeiro algoritimo de ordenacao 

void insertionSort(){
	pessoa *dado;
	dado = pbuffer + sizeof(variaveis);
	if(inicio->contador > 1){
		for (inicio->j = 1; inicio->j < inicio->contador; inicio->j++) {
			inicio->atual = dado[inicio->j];
			for (inicio->i = inicio->j - 1; (inicio->i >= 0) && inicio->atual.nome[0] < dado[inicio->i].nome[0]; inicio->i--) {
				dado[inicio->i + 1] = dado[inicio->i];
			}
			dado[inicio->i+1] = inicio->atual;
			
		}
	}
}
void selectionSort(){ 
	pessoa *dado;
	dado = pbuffer + sizeof(variaveis);
	inicio->min_id = 0;
	for (inicio->i=0; inicio->i < inicio->contador-1; inicio->i++) { 
		 inicio->min = dado[inicio->i]; 
		 for (inicio->j=inicio->i+1; inicio->j<inicio->contador; inicio->j++) {
		   if (dado[inicio->j].nome[0] < inicio->min.nome[0]) { 
			 inicio->min = dado[inicio->j]; 
			 inicio->min_id = inicio->j; 
                    } 
                }
		 inicio->atual = dado[inicio->i]; 
		 dado[inicio->i] = dado[inicio->min_id]; 
		 dado[inicio->min_id] = inicio->atual;
		 inicio->min_id = inicio->i+1;
        }
}
void bubbleSort () { 
	
	pessoa *dado;
	dado = pbuffer + sizeof(variaveis);
	
	for (inicio->i=0; inicio->i< inicio->contador-1; inicio->i++) { 
		for (inicio->j=0; inicio->j < inicio->contador - inicio->i - 1; inicio->j++) {
			if (dado[inicio->j].nome[0] > dado[inicio->j+1].nome[0]) { 					
				inicio->atual = dado[inicio->j]; 
				dado[inicio->j] = dado[inicio->j+1]; 
				dado[inicio->j+1] = inicio->atual; 
			} 
		}
	} 
}
