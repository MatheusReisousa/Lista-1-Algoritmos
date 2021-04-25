// Nome Completo: Matheus Reis de Sousa      Matrícula: UC21105889        Curso: Engenharia de Software

#include <stdio.h>  // Biblioteca padrão que disponibiliza ferramentas como scanf e printf; 
#include <stdlib.h>  // Biblioteca de entrada e saída de dados;
#include <locale.h>  // Diretiva acessório, que permite a utilização de acentos sem demais problemass;
#include <string.h>  // Biblioteca de strings para manipular o tamanho dos caracteres, extremamente útil;

int main () {
	setlocale(LC_ALL, "portuguese"); //Comando da diretiva de localização em português;
	int sessao, publico, cont, idade, Qpipoca=0, masc = 0, fem = 0, kid = 0, teen = 0, adult = 0, granny = 0, cont_sessao, MascM, FemM; //Variáveis utilizadas no código, estas são as inteiras;
	char nomeFilme [50], sexo, pipoca; // Essas são as em caractere;
	do {
		system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
		printf("---------------|Projeto 01|---------------\n"); // Cabeçalho de charme;
		printf ("Olá, eu sou seu assistente virtual do cinema de Brasília.\nNome do Filme: ");
		scanf ("%[^\n]s", &nomeFilme); // Ferramenta de entrada de informação, dá suporte ao futuro strlen que me ajudará a verificar o espaço vazio;
		fflush (stdin); // Para prevenir;
		if (strlen(nomeFilme)-1 == 0){ // Subtrai 1 do strlen(nomeFilme) pois ele possui 1 de tamanho base;
			printf("\n-----------------------------\n"); //Secção dedicada a alertar o usuário sobre as limitações impostas ao código;
            printf("#Nome de filme ausente!#\n");
            printf("#Por favor, insira o nome de um filme!#\n");
            printf("-----------------------------\n\n");
            system("pause"); // Finalização do comando seguido reinício do comando;
		}
		
	} while (strlen(nomeFilme)-1 == 0); //Continuidade aos outros requisitos com as novas informações adquiridas com o ´´do``;
	
	do {
		system ("cls || clear"); 
		printf("---------------|Projeto 01|---------------\n");
		printf ("E quantas sessões do filme %s estão marcadas para hoje? ", nomeFilme);
		scanf ("%i", &sessao); // Entrada da quantidade de sessões no dia, restritas à 2;
		fflush (stdin); // Para prevenir;
		if (sessao != 2){ // Modelo de diferenciação para a resolução no código;
			printf("\n-----------------------------\n"); // Nova secção de redirecionamento;
            printf("#Quantidade inválida de sessões!#\n");
            printf("#Por favor, respeite a demanda de apenas 2 sessões!#\n");
            printf("-----------------------------\n\n");
            system("pause");
		}
		
	} while (sessao != 2); // Continuidade com os requisitos agora adquiridos no 2º ´´do``;
	
	
	do {
		system ("cls || clear"); 
		printf("---------------|Projeto 01|---------------\n");
		printf ("E quantas pessoas assistiram o filme %s? ", nomeFilme);
		scanf ("%i", &publico); // Entrada da quantidade de sessões no dia, restritas à 2;
		fflush (stdin); // Para prevenir;
		if (publico < 10){ // Modelo de diferenciação para a resolução no código;
			printf("\n-----------------------------\n"); //Secção de redirecionamento;
            printf("#Quantidade de pessoas insuficientes para completar as sessões!#\n");
            printf("#Por favor, respeite a demanda mínima de 10 pessoas!#\n");
            printf("-----------------------------\n\n");
            system("pause");
		}
		
	} while (publico < 10); //Valor mínimo de pessoas nas sessões;
	
	for (cont_sessao=0;cont_sessao<sessao;cont_sessao ++){ //Contador que dividirá as sessões;
		MascM = 0; //Separação dos contadores para cada sessão;
		FemM = 0;
		

		for (cont=0; cont < publico / sessao; cont ++) { // Contador utilizado para gravar informações sobre os diversos usuários que darão entrada;
			do {
				system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sessão 0%i|---------------\n", cont_sessao + 1);
				printf ("Cliente %i:\n", cont +1); // Coleta de dados e definição da posição do cliente em relação ao público;
				printf ("E qual seu gênero? (F/M)\n");
				scanf ("%c", &sexo);
				fflush (stdin); // Para previnir;
				if (sexo!='m' && sexo!='M' && sexo!='F' && sexo!='f'){
					printf("\n-----------------------------\n"); // Secção de redirecionamento;
		            printf("#Opção de gênero não autorizada!#\n");
		            printf("#Por favor, responda com ´´M`` para masculino ou ´´F`` para feminino#\n");
		            printf("-----------------------------\n\n");
		            system("pause");
				} else if (sexo == 'm' || sexo == 'M'){ 
					masc ++;
				} else if (sexo == 'f' || sexo == 'F'){
					fem ++;
				} 
			} while (sexo!='m' && sexo!='M' && sexo!='F' && sexo!='f'); // Continuidade dos requisitos com os novos valores adquiridos;
			
			do {
				system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sessão 0%i|---------------\n", cont_sessao + 1);
				printf ("Cliente %i:\n", cont +1); // Novamente uso o contador, mas agora para pegar a idade;
				printf ("E qual sua idade?\n");
				scanf ("%i", &idade);
				fflush (stdin); // Para previnir;
				if (idade < 3 || idade > 100){ // Condicional aplicada para delimitar o público;
					printf("\n-----------------------------\n");// Secção de redirecionamento;
		            printf("#Idade inválida!#\n");
		            printf("#Por favor, apenas idades entre 3 e 100 anos.#\n");
		            printf("-----------------------------\n\n");
		            system("pause");
				} else if (idade >= 3 && idade <= 13){ //Contador para coletar o número de pessoas de cada idade;
					kid ++;
				} else if (idade >= 14 && idade <= 17){
					teen ++;
				} else if (idade >= 18 && idade <= 64){
					adult ++;
				} else if (idade >= 65 && idade <=100 ){
					granny ++;
				} 
			} while (idade < 3 || idade > 100); // Valores mínimos e máximos para as idades das pessoas presentes;
			
			do {
				system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sessão 0%i|---------------\n", cont_sessao + 1);
				printf ("Cliente %i:\n", cont +1); // Coleta de dados e definição da posição do cliente em relação ao público;
				printf ("Deseja pipoca para acompanhar sua sessão de %s? (S para sim/ N para não))\n", nomeFilme);
				scanf ("%c", &pipoca);
				fflush (stdin); // Para previnir;
				if (pipoca != 's' && pipoca != 'S' && pipoca != 'n' && pipoca != 'N'){
					printf("\n-----------------------------\n"); // Secção de redirecionamento;
		            printf("#Escolha inválida!!#\n");
		            printf("#Por favor, responda com ´´S`` para sim ou ´´N`` para não#\n");
		            printf("-----------------------------\n\n");
		            system("pause");
				} else if (pipoca == 's' || pipoca == 'S'){ 
					Qpipoca ++;
				} 
			} while (pipoca!='s' && pipoca!='S' && pipoca!='n' && pipoca!='N');
			
			
			if ((sexo == 'M' || sexo == 'm') && (idade >= 18)) { //Contador para determinar os homens maiores de 18 para cada sessão;
				MascM++;
			} else if ((sexo == 'f' || sexo == 'F') && (idade >= 18)) {
				FemM++;
			}
			
			
		}
			system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sessão 0%i|---------------\n", cont_sessao + 1);
				printf ("Quantidade de homens adultos presentes na sessão: %i\n", MascM); //Inserção dos dados na tabela;
				printf ("Quantidade de mulheres adultas presentes na sessão: %i\n", FemM);
				system ("pause");
	} 
	system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
	printf("---------------|Projeto 01|---------------\n"); // Tabela de finalização :D ;
	printf ("Filme: %s\n", nomeFilme);
	printf ("Total de espectadores: %i\n", publico);
	printf ("Valor arrecadado com ingresso do filme: R$ %.2i\n", (publico*20)); // 20 porque é o preço de quinta no JK, baratin;
	printf ("Valor arrecadado com pipoca no início do filme: R$ %.2i\n", (Qpipoca*15)); // 15 porque a gente tá humilde;
	printf ("---------------\n");
	printf ("Sobre o volume do gênero:\n");
	printf ("Quantidade de espectadores do gênero masculino: %i\n", masc);
	printf ("Quantidade de espectadores do gênero feminino: %i\n", fem);
	printf ("---------------\n");
	printf ("Sobre o volume de espectadores de diferentes idades: \n");
	printf ("Crianças: %i\n", kid);
	printf ("Adolescentes: %i\n", teen);
	printf ("Adultos: %i\n", adult);
	printf ("Idosos: %i\n\n", granny);
	printf ("Amamos você Joyce <33333333 me da 10 pf nunca te pedi nada passei 4 horas na madrugada fazendo isso\nmeu amigo da UnB me ajudou muito tb manda um salve pro Guilherme família gente finissima o garoto"); // Joyce rainha, resto nadinha;
}




	
/*Fontes: https://youtube.com/watch?v=ukXa9LflfOQ
          https://www.youtube.com/watch?v=bYSQzUukpT0
          https://www.youtube.com/watch?v=BuwcscbPZHA
          
          */

