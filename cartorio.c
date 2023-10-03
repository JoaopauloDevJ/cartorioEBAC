#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar da string

int registro()  //função responsavel por cadastra os usuários no sistema
{
	//inicio da criação de varioveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");   //coletando informações do usuario
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

int consulta()        //função responsavel por consultar os usuários do sistema
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
			printf("Esse CPF nao está cadastrado, tente novamente! \n");
		}
	
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: \n");
			printf("%s", conteudo);
			printf("\n\n");
	    }
	    
	system("pause");
	
}

int deletar()      //função responsavel por deletar os usuário do sistema
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF digitado não pode ser encontrado, tente novamente! \n");
	}
	else{
		printf("O usuário foi deletado com sucesso! \n");
	}
	system("pause");
	
}


int main()
{
	
	int opcao = 0;  //Definindo as variáveis
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
	
		system("cls");    //função responsavel por limpar a tela no sistema

	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");  //Inicio do menu
		printf("Escolher a opção desejada do menu\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao);  //amazenando a escolha do usúario
	
		system("cls");
		
		switch(opcao)       
		{
			case 1:                  //chamada de funções
				registro();
				break;	
				
			case 2:
				consulta();
		  		break;
			
					
			case 3 : 
				deletar();
				break;
				
				
			default :
				printf("Essa opção não está disponivel \nescolha uma opção novamente \n");
				system("pause");
				break;
				//final de seleção
		}

	
}
}
