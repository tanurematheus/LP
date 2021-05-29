/*Criação de um menu para escolha das funções por parte do usuário, conforme o exemplo abaixo
1-	Incluir novo produto
2-	Consultar um produto
3-	Alterar dados de um produto
4-	Imprimir em tela lista de produtos.
5-  Deletar produto.
0-	Sair*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "my_lib.h"
#include "manipular_arquivos.h"

int main(){
	int x=1, size, consulta;
	Produto *lista_produtos;
	
	size=tamanho_arquivo();

	if(size){
		lista_produtos = malloc(size * sizeof(Produto));
		ler_produtos(lista_produtos);
	}else{
		lista_produtos=NULL;
	}		

	while(x){
		menu();		
		scanf("%d", &x);
		fflush(stdin);
		system("cls");
		switch (x){
		case incluir:						
			incluir_produto(lista_produtos, size);			
			size++;
			free(lista_produtos);
			lista_produtos = NULL;
			lista_produtos = malloc(size * sizeof(Produto));
			ler_produtos(lista_produtos);			
			break;			
		case consultar:
			printf("Informe o codigo do produto para consulta\n");
			consulta = consultar_produto(lista_produtos, size);
			if(consulta == -1){
				printf("Produto nao encontrado");
			}else{
				print_produto(lista_produtos[consulta]);
			}		
			break;
		case alterar:
			printf("Informe o codigo do produto para alteracao\n");
			consulta = consultar_produto(lista_produtos, size);
			if(consulta == -1){
				printf("Produto nao encontrado");
			}else{
				alterar_produto(lista_produtos, consulta, size);
				printf("produto alterado\n");
			}	
			break;
		case imprimir:			
			for(int i=0;i<size;i++){
				print_produto(lista_produtos[i]);
			}			
			break;
		case deletar:
			printf("Informe o codigo do produto para deletar\n");
			consulta = consultar_produto(lista_produtos, size);
			if(consulta == -1){
				printf("Produto nao encontrado");
			}else{
				deletar_produto(lista_produtos, consulta, size);
				size--;
				if(size){
					lista_produtos = malloc(size * sizeof(Produto));
					ler_produtos(lista_produtos);
				}else{
					lista_produtos=NULL;
				}	
				printf("produto deletado\n");
			}	
			break;
		case sair:
			printf("Saindo...\n");
			free(lista_produtos);
			lista_produtos = NULL;			
			break;							
		default:
			printf("Opcao nao existe\n");			
			break;
		}
		getch();
		fflush(stdin);
		system("cls");		
	}	
	system("pause");
	return 0;   
}