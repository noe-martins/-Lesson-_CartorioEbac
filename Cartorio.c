#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Aloca��o de mem�ria
#include <locale.h> // Textos por regi�o (Brasil)
#include <string.h> // Cuida das strings
#include <windows.h> //Biblioteca com API's do Windows

int registro() // Fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio cria��o de vari�vel
	char arquivo[40];
	char new_arquivo[40]; //vari�vel para criar um id "_cpf" no final da string
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da cria��o de vari�vel
	
	printf("Digite o cpf a ser cadastrado: "); //coletando infoma��o do usu�rio
	scanf("%s",cpf);
	
	//Deixa o nome do arquivo igual ao cpf, pois o cpf � �nico etorna mais f�cil a consulta
	strcpy(arquivo, cpf); // Fun��o da biblioteca <string.h> que Copia os dados da vari�vel "cpf" para "arquivo"
	strcpy(new_arquivo, cpf);// Copia tamb�m para o arquivo que vai fazer a concatena��o
	
	// Cria��o do arquivo e atribuindo o valor do cpf pra ele
	FILE *file; 
	file = fopen(arquivo, "w");
	fprintf(file,"CPF: ");
	fprintf(file,cpf);
	fclose(file); 
	
	strcat(new_arquivo,"_cpf");//Concatenando o arquivo novo
	rename(arquivo,new_arquivo);//Renomeando o arquivo antigo com o id no final da string "_cpf"
	
	file = fopen(new_arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclus�o e inserindo o valor da vari�vel nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(new_arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(new_arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclus�o e inserindo o valor da vari�vel sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(new_arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(new_arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclus�o e inserindo o valor da vari�vel cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(new_arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
}
int consulta(){ // Fun��o respons�vel por consultar usu�rios no sistema

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	strcat(cpf,"_cpf");
	
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
int deletar(){ // Fun��o respons�vel por deletar um usu�rio do sistema
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar: ");
	scanf("%s",cpf);
	
	strcat(cpf,"_cpf");//Concatenando a string para poder usar o id "_cpf" na busca
	
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
//Fun��o de valida��o de Login e Senha
int login(){
	char usuario_validacao[40];
	char usuario[40];
	char senha_validacao[40];
	char senha[40];
	int res = 0;
	
	printf("------------ Cart�rio da EBAC -----------\n\n");
	printf("\t      Tela de Login\n");
	printf("Usu�rio: ");
	scanf("%s",usuario);
	printf("Senha: ");
	scanf("%s",senha);
	
	FILE *file;
	file = fopen(usuario,"r");
	fscanf(file,"%s %s",usuario_validacao,senha_validacao);
	fclose(file);
	
	// Comando que compara duas strings, no caso os logins e senhas
	if(strcmp(usuario_validacao, usuario) == 0 && strcmp(senha_validacao,senha) == 0){
		res = 1;
	}else{
		res = 2;
	}
	
	return res;
}
//Fun��o para cadastrar novos usu�rios para login
int cadastro_login(){
	char new_usuario[40];
	char new_senha[40];
	
	printf("Digite o nome do usuario que deseja cadastrar: ");
	scanf("%s",new_usuario);
	
	FILE *file;
	file = fopen(new_usuario,"w");
	fprintf(file,new_usuario);
	fclose(file);
	
	file = fopen(new_usuario,"a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite a senha desse usu�rio: ");
	scanf("%s",new_senha);
	
	file = fopen(new_usuario,"a");
	fprintf(file,new_senha);
	fclose(file);
	
}

//Fun��o que pergunta ao usu�rio se deseja voltar ao menu
int voltar_menu_registro(int op){
	while (op == 2){
		registro();
		printf("\n\t\t---------------------------------\n");
		printf("\t\t|Cadastro realizado com sucesso!|\n");
		printf("\t\t---------------------------------\n\n");
		printf("------------- Se voc� deseja: --------------\n");
		printf("a) Voltar ao menu -> Digite (1)\n");
		printf("b) Adicionar um novo cadastro -> Digite (2)\n");
		printf("--------------------------------------------\n");
		scanf("%d",&op);
		system("cls");
	}
}
int main()
{
	int opcao = 0;
	int laco_programa = 1;
	int op = 0; //vari�vel para op��o de voltar para o menu
	int mn_inicial = 0;//vari�vel de opcao no menu inicial
	int result = 0; //vari�vel que vai receber o resultado da valida��o do login
	
	setlocale(LC_ALL, "Portuguese");
	
	pontoInicial: //Recurso para quebrar linha do c�digo na volta para o menu inicial
	
	//Preciso transformar isso em uma fun��o
	printf("------------ Cart�rio da EBAC -----------\n\n");
	printf("\t\t\t\t\t|\n");
	printf("     Escolha a op��o do Menu abaixo \t|\n");
	printf("\t\t\t\t\t|\n");
	printf("1 - Acessar programa de registro\t|\n");
	printf("2 - Cadastrar novo login e senha\t|\n");
	printf("3 - Sair do Programa\t\t\t|\n");
	printf("\t\t\t\t\t|\n");
	printf("----------------------------------------\n\n");
	scanf("%d",&mn_inicial);
	
	//Condicional do menu anterior
	if(mn_inicial == 2){
		system("cls");
		cadastro_login();
		printf("\n\t---------------------------------------\n");
		printf("\t|Login e Senha cadastrado com sucesso!|\n");
		printf("\t---------------------------------------\n\n");
		system("pause");
		system("cls");
		goto pontoInicial;
	} else if(mn_inicial == 3){
		system("cls");
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
	}
	system("cls");
	
	//Loop para permanecer dentro do sistema de registro
	while(mn_inicial == 1){
	
		result = login();
	
		if(result == 1){
	
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
				printf("\t4 - Sair do Programa\t\t|\n");
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
					
						printf("\n\t\t---------------------------------\n");
						printf("\t\t|Cadastro realizado com sucesso!|\n");
						printf("\t\t---------------------------------\n\n");
						printf("------------- Se voc� deseja: --------------\n");
						printf("a) Voltar ao menu -> Digite (1)\n");
						printf("b) Adicionar um novo cadastro -> Digite (2)\n");
						printf("--------------------------------------------\n");
						scanf("%d",&op);
						system("cls");
					
						voltar_menu_registro(op);
				
					break;
		
					case 2:
						consulta();
					break;
		
					case 3:
						deletar();
					break;
		
					case 4:
						printf("Obrigado por utilizar o sistema!\n");
						return 0;
					break;
			
					default:
						printf("Essa op��o n�o est� dispon�vel\n\n");
						system("pause");
					break;
				} //fim de sele��o
	
			}
		} else{
			printf("\n  |Login/Senha incorretos ou n�o existem!|\n\n");
			printf("------------- Se voc� deseja: --------------\n");
			printf("a) Voltar ao menu anterior -> Digite (0)\n");
			printf("b) Tentar novamente -> Digite (1)\n");
			printf("--------------------------------------------\n");
			scanf("%d",&mn_inicial);
			
			// Condicional para escolher se permanece no loop ou volta para o menu inicial
			if(mn_inicial == 0){
				system("cls");
				goto pontoInicial; // Volta para o Ponto Inicial do c�digo
			}
		
			system("cls");
		
		}
	}	
}
