#ifndef MANIPULAR_ARQUIVOS_H
#define MANIPULAR_ARQUIVOS_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_lib.h"

void incluir_produto(Produto *lista_produtos, int size){
	int x=1;
	Produto produto;
	printf("Informe o nome do produto:\n");
	gets(produto.nome);
	fflush(stdin);
	while(x){
		printf("Informe o codigo do produto:\n");
		scanf("%d", &produto.codigo);
		fflush(stdin);
		if(size){
			for(int i=0;i<size;i++){						
				if(lista_produtos[i].codigo == produto.codigo){
					printf("Codigo ja existe\n");
					getch();
					fflush(stdin);
					system("cls");
					x=1;
					break;
				}else{
					x=0;
				}
			}
		}else{
			x=0;
		}	
	}	
	printf("Informe o preco do produto:\n");
	scanf("%f", &produto.preco);
	fflush(stdin);
	system("cls");	

	FILE * arq;
	arq = fopen("dados.bin", "ab");

	if(arq != NULL){
		fwrite(&produto, sizeof(produto), 1, arq);
		fclose(arq);
		printf("Item Incluido\n");		 
	}else{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); 
	}
}

int tamanho_arquivo(){
	int size=0;
	FILE * arq = fopen("dados.bin", "rb");
	if(arq != NULL){		
		while(1){
			Produto p;
			size_t r = fread(&p, sizeof(Produto), 1, arq);			
			if(r < 1)
				break;
			else		
				size+=1;
		}
		fclose(arq); 	
	}
	return size;
}

void ler_produtos(Produto *lista_produtos){	
	int y = 0;
	FILE * arq = fopen("dados.bin", "rb");	
	
	if(arq != NULL){		
		while(1){
			Produto p;
			size_t r = fread(&p, sizeof(Produto), 1, arq);			
			if(r < 1){
				break;
			}else{				
				lista_produtos[y].codigo = p.codigo;
				strcpy(lista_produtos[y].nome, p.nome);
				lista_produtos[y].preco = p.preco;
				y++;
			}
		}
		fclose(arq); 
	}else{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); 
	}
}

void alterar_arquivo(Produto *lista_produtos, int size){
	FILE * arq = fopen("dados.bin","wb");
	
	fwrite(lista_produtos, sizeof(Produto), size, arq);	

	fclose(arq);
}

void alterar_produto(Produto *lista_produtos, int consulta, int size){
	int x=1, f=1, z, c;

	while(x){
		menu_alterar();
		scanf("%d", &x);
		fflush(stdin);
		system("cls");
		switch (x){
		case 1:
			printf("Informe o novo nome do produto:\n");
			gets(lista_produtos[consulta].nome);
			fflush(stdin);			
			break;
		case 2:
			while(f){
				printf("Informe o novo codigo do produto:\n");
				scanf("%d", &z);
				c=1;
				for(int i=0;i<size;i++){
					if(lista_produtos[i].codigo == z){
						printf("Codigo ja existe\n");
						c=0;
						getch();
						fflush(stdin);
						system("cls");						
						break;
					}
				}
				if(c){
					lista_produtos[consulta].codigo = z;
					f = 0;
				}	
			}
			break;
		case 3:
			printf("Informe o novo preco do produto:\n");
			scanf("%f",&lista_produtos[consulta].preco);
			fflush(stdin);			
			break;
		case sair:
			printf("saindo...\n");
			break;
		default:
			printf("Opcao nao existe\n");
			break;
		}
		alterar_arquivo(lista_produtos, size);
		getch();
		fflush(stdin);
		system("cls");
	}
}

int consultar_produto(Produto *lista_produtos, int size){
		int  codigo;

		scanf("%d", &codigo);
		fflush(stdin);
		system("cls");
		for(int i=0;i<size;i++){
			if(codigo == lista_produtos[i].codigo){
				return i;
			}
		}			
		return -1;	
}

void deletar_produto(Produto *lista_produtos, int consulta, int size){
	FILE * arq = fopen("dados.bin","wb");

	for(int i=0; i<size;i++){
		if(i!=consulta){
			fwrite(&lista_produtos[i], sizeof(Produto), 1, arq);
		}
	}
	fclose(arq);	
}

#endif