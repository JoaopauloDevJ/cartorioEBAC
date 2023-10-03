#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar da string

int registro()  //fun��o responsavel por cadastra os usu�rios no sistema
{
	//inicio da cria��o de varioveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");   //coletando informa��es do usuario
	scanf("%s", cpf);   //%s refere-si a string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string.
	
	FILE *file;                         //criando arquivos
	file = fopen(arquivo, "w");		    //criando arquivos/ w significa escrever
	fprintf(file, cpf);     //salva o valor do arquivo
	fclose(file);          //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);   
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	 
	 system("pause");
	 
}

int consulta()        //fun��o responsavel por consultar os usu�rios do sistema
{
	
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
		if(cpf == NULL)
		{
			printf("Esse CPF nao est� cadastrado, tente novamente! \n");
		}
	
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: \n");
			printf("%s", conteudo);
			printf("\n\n");
	    }
	    
	system("pause");
	
}

int deletar()      //fun��o responsavel por deletar os usu�rio do sistema
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF digitado n�o pode ser encontrado, tente novamente! \n");
	}
	else{
		printf("O usu�rio foi deletado com sucesso! \n");
	}
	system("pause");
	
}


int main()
{
	
	int opcao = 0;  //Definindo as vari�veis
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
	
		system("cls");    //fun��o responsavel por limpar a tela no sistema

	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");  //Inicio do menu
		printf("Escolher a op��o desejada do menu\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistma\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao);  //amazenando a escolha do us�ario
	
		system("cls");
		
		switch(opcao)       
		{
			case 1:                  //chamada de fun��es
				registro();
				break;	
				
			case 2:
				consulta();
		  		break;
			
					
			case 3 : 
				deletar();
				break;
				
			case 4 :
				printf("Obrigado por ultilizar o sistema!"); 
				return 0;
				break;
				
				
				
			default :
				printf("Essa op��o n�o est� disponivel \nescolha uma op��o novamente \n");
				system("pause");
				break;
				//final de sele��o
		}

	
}
}
