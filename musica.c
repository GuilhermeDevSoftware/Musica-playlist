#include <stdio.h>
#include <malloc.h>

#define INSERIR 1
#define PESQUISAR 2
#define ELIMINAR 3
#define MOSTRAR 4
#define TOCAR 5
#define SAIR 9


typedef struct No{
	char titulo[40];
	char interprete[40];
	int ID;
	char path[40];
	struct No * anterior;
	struct No * proximo;
} No;

void show(No * n){
	printf("\n=== MUSICAS CADASTRADAS ===\n");
	printf("\nMusica: %s", n->titulo);
	printf("\nInterprete: %s", n->interprete);
	printf("\nID: %d", n->ID);
}

typedef struct {
	struct No * primeiro;
	struct No * ultimo;
} Lista;

void init(Lista * l){
	l->primeiro = NULL;
	l->ultimo = NULL;
}

void inserir(Lista * l){
	No * novoNo = (No*)malloc(sizeof(No));
	printf("\nInforme o ID da musica: ");
	scanf("%d", & novoNo->ID);
	fflush(stdin);
	printf("\nInforme o nome da musca: ");
	scanf(" %[^\n]", novoNo->titulo);
	fflush(stdin);
	printf("\nInforme o interprete da musica: ");
	scanf(" %[^\n]", novoNo->interprete);
	fflush(stdin);	
	printf("\nInforme o path da musica: ");
	scanf(" %[^\n]", novoNo->path);	
	fflush(stdin);
	if (l->primeiro == NULL) {
		l->primeiro = (struct No *) novoNo;
		l->ultimo = (struct No *) novoNo;
		novoNo->anterior = NULL;
	} else {
		novoNo->anterior = l->ultimo;
		l->ultimo->proximo = novoNo;
		l->ultimo = novoNo;
	}
}

void pesquisar(Lista l){
		if (l.primeiro == NULL) {
		printf("\nEsta vazio");
		return;
	}
	else {
		int idPesquisa;
		printf("\nInforme o ID da musica: ");
	    scanf("%d", &idPesquisa);
	
	    No *p = l.primeiro;
	    while (p != NULL) {
	        if (p->ID == idPesquisa) {
	            show(p);
	            return;
	        }
	        p = p->proximo;		
		}	
	}
}

void mostrar(Lista l){
	No * p= (No *)l.primeiro;
	while(p != NULL){
		show(p);
		p = (No *)p->proximo;
	}
}

void tocar(){
	printf("\nTocando");
}

int menu(){
	int option;
	printf("\n\n===PLAYLIST AERO-MUSICAS===\n\n");
	printf("\n===SELECIONE SUA OPCAO===\n");
	printf("\n[1] INSERIR MUSICA.");
	printf("\n[2] PESQUISAR MUSICA.");
	printf("\n[3] ELIMINAR MUSICA.");
	printf("\n[4] MOSTRAR MUSICA.");
	printf("\n[5] TOCAR MUSICA.");
	printf("\n[9] SAIR.\n\n");
	printf("Informe sua opcao: ");
	scanf("%d", &option);
	return option;
}

int main(){
	Lista playlist;
	init(&playlist);
	
	int opcao = menu();
	while(opcao != SAIR){
		switch(opcao){
			case INSERIR : inserir(&playlist);
							break;
			case PESQUISAR : pesquisar(playlist);
							break;
			case MOSTRAR : mostrar(playlist);
							break;
			case TOCAR : tocar();
							break;												
		}
		opcao = menu();
	}
	return 0;
}