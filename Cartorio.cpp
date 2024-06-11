#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

int registro(){ // Função responsável por cadastrar usuários no sistema
	char arquivo[50]; // Inicío da criação de variáveis/string
	char cpf[20];
	char nome[50];
	char sobrenome[50];
	char cargo[50]; // Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s",cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); // Fecha o arquivo
	
	system("pause");
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[20];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informações do usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	char cpf[20];
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando informações do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main(){
	
	int opcao=0; // Definindo variáveis
	int x=1;
	
	for(x=1;x=1;){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n"); 
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // Responsável por limpar a tela
		
		switch(opcao){ // Início da seleção do menu
			case 1:
			registro(); // Chamada de funções
			break;	
			
			case 2:
			consulta(); // Chamada de funções
			break;
			
			case 3:
			deletar(); // Chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break; // Fim da seleção do menu
		}
	}
}

