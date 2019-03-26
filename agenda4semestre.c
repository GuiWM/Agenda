#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pbuffer;

typedef struct var{
	int escolha, contador, i;
} variaveis;

typedef struct pe {
   char nome[25], cpf[15];
} pessoa;

variaveis *inicio;

void inserir();
void listar();

int main () {

    printf("---------- AGENDA -------------");

    pbuffer = malloc(sizeof(variaveis));

    inicio = pbuffer;

    inicio->contador = 0;

    do {
        printf("\n[>1<] INSERIR\n[>2<] LISTAR\n[>5<] SAIR\n");
        scanf("%d", &inicio->escolha);

		switch (inicio->escolha) {
			case 1:
				inserir();
				break;
			case 2:
				listar();
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

    if ((pbuffer = realloc(pbuffer, sizeof(variaveis) + sizeof(pessoa) + (sizeof(pessoa) * inicio->contador))) == NULL) {
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

}
