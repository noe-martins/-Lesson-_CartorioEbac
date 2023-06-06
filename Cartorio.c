#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // Alocação de memória
#include <locale.h> // Textos por região (Brasil)
#include <string.h> // Cuida das strings

int registro() // Função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio criação de variável
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variável
	
	printf("Digite o cpf a ser cadastrado: "); //coletando infomação do usuário
	scanf("%s",cpf);
	
	//Deixa o nome do arquivo igual ao cpf, pois o cpf é único etorna mais fácil a consulta
	strcpy(arquivo, cpf); // Função da biblioteca <string.h> que Copia os dados da variável "cpf" para "arquivo"
	
	// Criação do arquivo e atribuindo o valor do cpf pra ele
	FILE *file; 
	file = fopen(arquivo, "w");
	fprintf(file,"CPF: ");
	fprintf(file,cpf);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclusão e inserindo o valor da variável nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclusão e inserindo o valor da variável sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclusão e inserindo o valor da variável cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta() // Função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	// Acessando arquivo para leitura
	FILE *file;
	file = fopen(cpf,"r");
	
	// Procura no "file" o "cpf" e se não encontra retorna mensagem de alerta
	if(file == NULL){
		
		printf("Não foi possível abrir o arquivo: Não localizado!\n");
	
	}
	
	// Laço "while" junto com a função para acessar string "fgets()"
	// Ao encontra o valor contido no "cpf", pega o valor apontado por "file" e vai jogando no "conteudo" até retornar "NULL" na string
	while(fgets(conteudo,100,file) != NULL){
		
		printf("\nEssas são as informações do Usuário: \n\n");
		printf("\t%s",conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	system("pause");
	
}
int deletar() // Função responsável por deletar um usuário do sistema
{
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar: ");
	scanf("%s",cpf);
	
	//remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	//Analisa se usuário está cadastrado 
	if(file == NULL){
		printf("\nEsse usuário não está cadastrado\n\n");
	}
	fclose(file); //Aqui fecha o arquivo
	
	//Certifica que o usuário existe e remove
	if(file != NULL){
		remove(cpf);
		printf("\nUsuário deletado com sucesso!\n\n");
	}
	
	system("pause");
}

int main()
{
	int opcao = 0;
	int laco_programa = 1;
	
	// Laço p/ não desligar o programa abruptamente a qualquer escolha feita pelo usuário
	for(laco_programa = 1;laco_programa = 1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Consulta o a localidade na Biblioteca <locale.h>, 
		//no caso é uma função dela
		
		// Estética do Menu
		printf("------------ Cartório da EBAC -----------\n");
		printf("\t\t\t\t\t|\n");
		printf("   Escolha a opção do Menu abaixo \t|\n");
		printf("\t\t\t\t\t|\n");
		printf("\t1 - Registrar nomes\t\t|\n");
		printf("\t2 - Consultar nomes\t\t|\n");
		printf("\t3 - Deletar nomes\t\t|\n");
		printf("\t\t\t\t\t|\n");
		printf("----------------------------------------\n\n");
		//printf("*Esse Software é de livre uso do aluno*\n");
		printf("Opção: ");
	
		scanf("%d",&opcao); // Função que armazena dado fornecido pelo usuário e atribui o valor a variavel escolhida
	
		system("cls"); // Função system() lida diretamente com o S.O | ("cls") limpar tela
	
		// Processo referente as escolhas do usuário
		switch(opcao)
		{
			case 1:
				registro(); //chamada de funções
			break;
		
			case 2:
				consulta();
			break;
		
			case 3:
				deletar();
			break;
		
			default:
				printf("Essa opção não está disponível\n\n");
				system("pause");
			break;
		} //fim de seleção
	
	}
}
