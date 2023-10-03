#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o de mem�ria - para arryas e tudo mais
#include <locale.h> // Bblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings.

int registro() // Fun��o que inicia o registro
{
	//in�cio da cria��o das vari�veis
	char arquivo[40]; // Esse nome sempre muda toda vez que um usu�rio novo � feito
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); // Identifica��o do arquivo
	scanf("%s", cpf); // %s serve pra armazenar dados da string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings. Neste caso, ele est� cadastrando no arquivo a string do cpf
	
	FILE *file; // Cria o arquivo. FILE j� � programado da biblioteca. O *file � o arquivo que estamos criando novo
	file = fopen(arquivo, "w"); // O "w" cria um novo arquivo.
	fprintf(file, cpf);
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); //"a" serve pra atualizar o arquivo
	fprintf(file, "\nNome: "); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a"); 
	fprintf(file, "\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" � de ler em ingl�s.
	
	if(file == NULL)
	{
		printf("Erro! Arquivo n�o localizado.");
		printf("\n\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // o fgets � o comando de busca do arquivo.
	{
	
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
	fclose(file);
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Este usu�rio n�o se encontra cadastrado no sistema. \n");
		system("pause");
		fclose(file);
	}
	
}


int main()
{
	int opcao=0; // Definindo as var�veis
	int laco=1;

	for(laco=1;laco=1;) // o 1�x � o inicio e o 2�x � a sa�da. Se ambos forem 1, sempra ficar� preso alo, se repetindo pra sempre.
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	
		printf("--- Cart�rio da EBAC ---\n\n"); // Inicio do menu 
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1- Registrar nomes \n");
		printf("\t2- Consultar nomes \n");
		printf("\t3- Deletar nomes \n\n"); // fim do menu
	
		scanf("%d", &opcao); // armagenando as escolhas do usuario
	
		system("cls"); // Comando para o limpar a tela 
		
		
		switch(opcao) // inicio da sele��o das fun��es
		{
			case 1:
			registro();
			break; // finaliza��o desse case.
			
			case 2: 
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
			
			default: // em caso de situa��es que n�o correspondam com os cases em cena.
			printf("Essa op��o n�o est� dispon�vel.\n");
			system("pause");
			break;
		}
		
	
	}
}
