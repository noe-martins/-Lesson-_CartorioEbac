#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Aloca��o de mem�ria
#include <locale.h> // Textos por regi�o (Brasil)
#include <string.h> // Cuida das strings

int registro() // Fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio cria��o de vari�vel
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da cria��o de vari�vel
	
	printf("Digite o cpf a ser cadastrado: "); //coletando infoma��o do usu�rio
	scanf("%s",cpf);
	
	//Deixa o nome do arquivo igual ao cpf, pois o cpf � �nico etorna mais f�cil a consulta
	strcpy(arquivo, cpf); // Fun��o da biblioteca <string.h> que Copia os dados da vari�vel "cpf" para "arquivo"
	
	// Cria��o do arquivo e atribuindo o valor do cpf pra ele
	FILE *file; 
	file = fopen(arquivo, "w");
	fprintf(file,"CPF: ");
	fprintf(file,cpf);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclus�o e inserindo o valor da vari�vel nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclus�o e inserindo o valor da vari�vel sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclus�o e inserindo o valor da vari�vel cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta() // Fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	// Acessando arquivo para leitura
	FILE *file;
	file = fopen(cpf,"r");
	
	// Procura no "file" o "cpf" e se n�o encontra retorna mensagem de alerta
	if(file == NULL){
		
		printf("N�o foi poss�vel abrir o arquivo: N�o localizado!\n");
	
	}
	
	// La�o "while" junto com a fun��o para acessar string "fgets()"
	// Ao encontra o valor contido no "cpf", pega o valor apontado por "file" e vai jogando no "conteudo" at� retornar "NULL" na string
	while(fgets(conteudo,100,file) != NULL){
		
		printf("\nEssas s�o as informa��es do Usu�rio: \n\n");
		printf("\t%s",conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	system("pause");
	
}
int deletar() // Fun��o respons�vel por deletar um usu�rio do sistema
{
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar: ");
	scanf("%s",cpf);
	
	//remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	//Analisa se usu�rio est� cadastrado 
	if(file == NULL){
		printf("\nEsse usu�rio n�o est� cadastrado\n\n");
	}
	fclose(file); //Aqui fecha o arquivo
	
	//Certifica que o usu�rio existe e remove
	if(file != NULL){
		remove(cpf);
		printf("\nUsu�rio deletado com sucesso!\n\n");
	}
	
	system("pause");
}

int main()
{
	int opcao = 0;
	int laco_programa = 1;
	
	// La�o p/ n�o desligar o programa abruptamente a qualquer escolha feita pelo usu�rio
	for(laco_programa = 1;laco_programa = 1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Consulta o a localidade na Biblioteca <locale.h>, 
		//no caso � uma fun��o dela
		
		// Est�tica do Menu
		printf("------------ Cart�rio da EBAC -----------\n");
		printf("\t\t\t\t\t|\n");
		printf("   Escolha a op��o do Menu abaixo \t|\n");
		printf("\t\t\t\t\t|\n");
		printf("\t1 - Registrar nomes\t\t|\n");
		printf("\t2 - Consultar nomes\t\t|\n");
		printf("\t3 - Deletar nomes\t\t|\n");
		printf("\t\t\t\t\t|\n");
		printf("----------------------------------------\n\n");
		//printf("*Esse Software � de livre uso do aluno*\n");
		printf("Op��o: ");
	
		scanf("%d",&opcao); // Fun��o que armazena dado fornecido pelo usu�rio e atribui o valor a variavel escolhida
	
		system("cls"); // Fun��o system() lida diretamente com o S.O | ("cls") limpar tela
	
		// Processo referente as escolhas do usu�rio
		switch(opcao)
		{
			case 1:
				registro(); //chamada de fun��es
			break;
		
			case 2:
				consulta();
			break;
		
			case 3:
				deletar();
			break;
		
			default:
				printf("Essa op��o n�o est� dispon�vel\n\n");
				system("pause");
			break;
		} //fim de sele��o
	
	}
}
