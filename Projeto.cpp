#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço de memória - para arryas e tudo mais
#include <locale.h> // Bblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings.

int registro() // Função que inicia o registro
{
	//início da criação das variáveis
	char arquivo[40]; // Esse nome sempre muda toda vez que um usuário novo é feito
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); // Identificação do arquivo
	scanf("%s", cpf); // %s serve pra armazenar dados da string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings. Neste caso, ele está cadastrando no arquivo a string do cpf
	
	FILE *file; // Cria o arquivo. FILE já é programado da biblioteca. O *file é o arquivo que estamos criando novo
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
	file = fopen(cpf,"r"); // "r" é de ler em inglês.
	
	if(file == NULL)
	{
		printf("Erro! Arquivo não localizado.");
		printf("\n\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // o fgets é o comando de busca do arquivo.
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
	
	printf("Digite o CPF do usuário que deseja deletar:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Este usuário não se encontra cadastrado no sistema. \n");
		system("pause");
		fclose(file);
	}
	
}


int main()
{
	int opcao=0; // Definindo as varáveis
	int laco=1;

	for(laco=1;laco=1;) // o 1ºx é o inicio e o 2ºx é a saída. Se ambos forem 1, sempra ficará preso alo, se repetindo pra sempre.
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	
		printf("--- Cartório da EBAC ---\n\n"); // Inicio do menu 
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1- Registrar nomes \n");
		printf("\t2- Consultar nomes \n");
		printf("\t3- Deletar nomes \n\n"); // fim do menu
	
		scanf("%d", &opcao); // armagenando as escolhas do usuario
	
		system("cls"); // Comando para o limpar a tela 
		
		
		switch(opcao) // inicio da seleção das funções
		{
			case 1:
			registro();
			break; // finalização desse case.
			
			case 2: 
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
			
			default: // em caso de situações que não correspondam com os cases em cena.
			printf("Essa opção não está disponível.\n");
			system("pause");
			break;
		}
		
	
	}
}
