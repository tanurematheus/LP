#ifndef MY_LIB_H
#define MY_LIB_H

#define incluir 1
#define consultar 2
#define alterar 3
#define imprimir 4
#define deletar 5
#define sair 0

typedef struct produto{
	char nome[50];
	int codigo;
    float preco;    
} Produto;

void menu(){
		printf("Escolha uma opcao:\n");
		printf("1-	Incluir novo produto\n");
		printf("2-	Consultar um produto\n");
		printf("3-	Alterar dados de um produto\n");
		printf("4-	Imprimir em tela lista de produtos\n");	
		printf("0-	Sair\n");
}

void menu_consulta(){
    printf("Escolha uma opcao de consulta:\n");
	printf("1-	Nome do produto\n");
	printf("2-	Codigo do produto\n");
}

void menu_alterar(){
	printf("Escolha uma opcao:\n");
	printf("1-	Alterar Nome do produto\n");
	printf("2-	Alterar Codigo do produto\n");
	printf("3-	Alterar Preco do produto\n");
	printf("0-	Sair\n");
}


void print_produto(Produto produto){
	printf("%s   ",produto.nome);
	printf("%d   ",produto.codigo);
	printf("%0.2f\n",produto.preco);
}

#endif

