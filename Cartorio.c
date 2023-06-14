#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // Alocação de memória
#include <locale.h> // Textos por região (Brasil)
#include <string.h> // Cuida das strings
#include <windows.h> //Biblioteca com API's do Windows

int registro() // Função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio criação de variável
	char arquivo[40];
	char new_arquivo[40]; //variável para criar um id "_cpf" no final da string
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variável
	
	printf("Digite o cpf a ser cadastrado: "); //coletando infomação do usuário
	scanf("%s",cpf);
	
	//Deixa o nome do arquivo igual ao cpf, pois o cpf é único etorna mais fácil a consulta
	strcpy(arquivo, cpf); // Função da biblioteca <string.h> que Copia os dados da variável "cpf" para "arquivo"
	strcpy(new_arquivo, cpf);// Copia também para o arquivo que vai fazer a concatenação
	
	// Criação do arquivo e atribuindo o valor do cpf pra ele
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
	
	// Abrindo o arquivo no modo de inclusão e inserindo o valor da variável nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(new_arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(new_arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclusão e inserindo o valor da variável sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(new_arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(new_arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	// Abrindo o arquivo no modo de inclusão e inserindo o valor da variável cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(new_arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
}
int consulta(){ // Função responsável por consultar usuários no sistema

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	strcat(cpf,"_cpf");
	
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
int deletar(){ // Função responsável por deletar um usuário do sistema
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar: ");
	scanf("%s",cpf);
	
	strcat(cpf,"_cpf");//Concatenando a string para poder usar o id "_cpf" na busca
	
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
//Função de validação de Login e Senha
int login(){
	char usuario_validacao[40];
	char usuario[40];
	char senha_validacao[40];
	char senha[40];
	int res = 0;
	
	printf("------------ Cartório da EBAC -----------\n\n");
	printf("\t      Tela de Login\n");
	printf("Usuário: ");
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
//Função para cadastrar novos usuários para login
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
	
	printf("Digite a senha desse usuário: ");
	scanf("%s",new_senha);
	
	file = fopen(new_usuario,"a");
	fprintf(file,new_senha);
	fclose(file);
	
}

//Função que pergunta ao usuário se deseja voltar ao menu
int voltar_menu_registro(int op){
	while (op == 2){
		registro();
		printf("\n\t\t---------------------------------\n");
		printf("\t\t|Cadastro realizado com sucesso!|\n");
		printf("\t\t---------------------------------\n\n");
		printf("------------- Se você deseja: --------------\n");
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
	int op = 0; //variável para opção de voltar para o menu
	int mn_inicial = 0;//variável de opcao no menu inicial
	int result = 0; //variável que vai receber o resultado da validação do login
	
	setlocale(LC_ALL, "Portuguese");
	
	pontoInicial: //Recurso para quebrar linha do código na volta para o menu inicial
	
	//Preciso transformar isso em uma função
	printf("------------ Cartório da EBAC -----------\n\n");
	printf("\t\t\t\t\t|\n");
	printf("     Escolha a opção do Menu abaixo \t|\n");
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
				printf("\t4 - Sair do Programa\t\t|\n");
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
					
						printf("\n\t\t---------------------------------\n");
						printf("\t\t|Cadastro realizado com sucesso!|\n");
						printf("\t\t---------------------------------\n\n");
						printf("------------- Se você deseja: --------------\n");
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
						printf("Essa opção não está disponível\n\n");
						system("pause");
					break;
				} //fim de seleção
	
			}
		} else{
			printf("\n  |Login/Senha incorretos ou não existem!|\n\n");
			printf("------------- Se você deseja: --------------\n");
			printf("a) Voltar ao menu anterior -> Digite (0)\n");
			printf("b) Tentar novamente -> Digite (1)\n");
			printf("--------------------------------------------\n");
			scanf("%d",&mn_inicial);
			
			// Condicional para escolher se permanece no loop ou volta para o menu inicial
			if(mn_inicial == 0){
				system("cls");
				goto pontoInicial; // Volta para o Ponto Inicial do código
			}
		
			system("cls");
		
		}
	}	
}
