// Nome Completo: Matheus Reis de Sousa      Matr�cula: UC21105889        Curso: Engenharia de Software

#include <stdio.h>  // Biblioteca padr�o que disponibiliza ferramentas como scanf e printf; 
#include <stdlib.h>  // Biblioteca de entrada e sa�da de dados;
#include <locale.h>  // Diretiva acess�rio, que permite a utiliza��o de acentos sem demais problemass;
#include <string.h>  // Biblioteca de strings para manipular o tamanho dos caracteres, extremamente �til;

int main () {
	setlocale(LC_ALL, "portuguese"); //Comando da diretiva de localiza��o em portugu�s;
	int sessao, publico, cont, idade, Qpipoca=0, masc = 0, fem = 0, kid = 0, teen = 0, adult = 0, granny = 0, cont_sessao, MascM, FemM; //Vari�veis utilizadas no c�digo, estas s�o as inteiras;
	char nomeFilme [50], sexo, pipoca; // Essas s�o as em caractere;
	do {
		system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
		printf("---------------|Projeto 01|---------------\n"); // Cabe�alho de charme;
		printf ("Ol�, eu sou seu assistente virtual do cinema de Bras�lia.\nNome do Filme: ");
		scanf ("%[^\n]s", &nomeFilme); // Ferramenta de entrada de informa��o, d� suporte ao futuro strlen que me ajudar� a verificar o espa�o vazio;
		fflush (stdin); // Para prevenir;
		if (strlen(nomeFilme)-1 == 0){ // Subtrai 1 do strlen(nomeFilme) pois ele possui 1 de tamanho base;
			printf("\n-----------------------------\n"); //Sec��o dedicada a alertar o usu�rio sobre as limita��es impostas ao c�digo;
            printf("#Nome de filme ausente!#\n");
            printf("#Por favor, insira o nome de um filme!#\n");
            printf("-----------------------------\n\n");
            system("pause"); // Finaliza��o do comando seguido rein�cio do comando;
		}
		
	} while (strlen(nomeFilme)-1 == 0); //Continuidade aos outros requisitos com as novas informa��es adquiridas com o ��do``;
	
	do {
		system ("cls || clear"); 
		printf("---------------|Projeto 01|---------------\n");
		printf ("E quantas sess�es do filme %s est�o marcadas para hoje? ", nomeFilme);
		scanf ("%i", &sessao); // Entrada da quantidade de sess�es no dia, restritas � 2;
		fflush (stdin); // Para prevenir;
		if (sessao != 2){ // Modelo de diferencia��o para a resolu��o no c�digo;
			printf("\n-----------------------------\n"); // Nova sec��o de redirecionamento;
            printf("#Quantidade inv�lida de sess�es!#\n");
            printf("#Por favor, respeite a demanda de apenas 2 sess�es!#\n");
            printf("-----------------------------\n\n");
            system("pause");
		}
		
	} while (sessao != 2); // Continuidade com os requisitos agora adquiridos no 2� ��do``;
	
	
	do {
		system ("cls || clear"); 
		printf("---------------|Projeto 01|---------------\n");
		printf ("E quantas pessoas assistiram o filme %s? ", nomeFilme);
		scanf ("%i", &publico); // Entrada da quantidade de sess�es no dia, restritas � 2;
		fflush (stdin); // Para prevenir;
		if (publico < 10){ // Modelo de diferencia��o para a resolu��o no c�digo;
			printf("\n-----------------------------\n"); //Sec��o de redirecionamento;
            printf("#Quantidade de pessoas insuficientes para completar as sess�es!#\n");
            printf("#Por favor, respeite a demanda m�nima de 10 pessoas!#\n");
            printf("-----------------------------\n\n");
            system("pause");
		}
		
	} while (publico < 10); //Valor m�nimo de pessoas nas sess�es;
	
	for (cont_sessao=0;cont_sessao<sessao;cont_sessao ++){ //Contador que dividir� as sess�es;
		MascM = 0; //Separa��o dos contadores para cada sess�o;
		FemM = 0;
		

		for (cont=0; cont < publico / sessao; cont ++) { // Contador utilizado para gravar informa��es sobre os diversos usu�rios que dar�o entrada;
			do {
				system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sess�o 0%i|---------------\n", cont_sessao + 1);
				printf ("Cliente %i:\n", cont +1); // Coleta de dados e defini��o da posi��o do cliente em rela��o ao p�blico;
				printf ("E qual seu g�nero? (F/M)\n");
				scanf ("%c", &sexo);
				fflush (stdin); // Para previnir;
				if (sexo!='m' && sexo!='M' && sexo!='F' && sexo!='f'){
					printf("\n-----------------------------\n"); // Sec��o de redirecionamento;
		            printf("#Op��o de g�nero n�o autorizada!#\n");
		            printf("#Por favor, responda com ��M`` para masculino ou ��F`` para feminino#\n");
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
				printf("---------------|Sess�o 0%i|---------------\n", cont_sessao + 1);
				printf ("Cliente %i:\n", cont +1); // Novamente uso o contador, mas agora para pegar a idade;
				printf ("E qual sua idade?\n");
				scanf ("%i", &idade);
				fflush (stdin); // Para previnir;
				if (idade < 3 || idade > 100){ // Condicional aplicada para delimitar o p�blico;
					printf("\n-----------------------------\n");// Sec��o de redirecionamento;
		            printf("#Idade inv�lida!#\n");
		            printf("#Por favor, apenas idades entre 3 e 100 anos.#\n");
		            printf("-----------------------------\n\n");
		            system("pause");
				} else if (idade >= 3 && idade <= 13){ //Contador para coletar o n�mero de pessoas de cada idade;
					kid ++;
				} else if (idade >= 14 && idade <= 17){
					teen ++;
				} else if (idade >= 18 && idade <= 64){
					adult ++;
				} else if (idade >= 65 && idade <=100 ){
					granny ++;
				} 
			} while (idade < 3 || idade > 100); // Valores m�nimos e m�ximos para as idades das pessoas presentes;
			
			do {
				system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sess�o 0%i|---------------\n", cont_sessao + 1);
				printf ("Cliente %i:\n", cont +1); // Coleta de dados e defini��o da posi��o do cliente em rela��o ao p�blico;
				printf ("Deseja pipoca para acompanhar sua sess�o de %s? (S para sim/ N para n�o))\n", nomeFilme);
				scanf ("%c", &pipoca);
				fflush (stdin); // Para previnir;
				if (pipoca != 's' && pipoca != 'S' && pipoca != 'n' && pipoca != 'N'){
					printf("\n-----------------------------\n"); // Sec��o de redirecionamento;
		            printf("#Escolha inv�lida!!#\n");
		            printf("#Por favor, responda com ��S`` para sim ou ��N`` para n�o#\n");
		            printf("-----------------------------\n\n");
		            system("pause");
				} else if (pipoca == 's' || pipoca == 'S'){ 
					Qpipoca ++;
				} 
			} while (pipoca!='s' && pipoca!='S' && pipoca!='n' && pipoca!='N');
			
			
			if ((sexo == 'M' || sexo == 'm') && (idade >= 18)) { //Contador para determinar os homens maiores de 18 para cada sess�o;
				MascM++;
			} else if ((sexo == 'f' || sexo == 'F') && (idade >= 18)) {
				FemM++;
			}
			
			
		}
			system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
				printf("---------------|Sess�o 0%i|---------------\n", cont_sessao + 1);
				printf ("Quantidade de homens adultos presentes na sess�o: %i\n", MascM); //Inser��o dos dados na tabela;
				printf ("Quantidade de mulheres adultas presentes na sess�o: %i\n", FemM);
				system ("pause");
	} 
	system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
	printf("---------------|Projeto 01|---------------\n"); // Tabela de finaliza��o :D ;
	printf ("Filme: %s\n", nomeFilme);
	printf ("Total de espectadores: %i\n", publico);
	printf ("Valor arrecadado com ingresso do filme: R$ %.2i\n", (publico*20)); // 20 porque � o pre�o de quinta no JK, baratin;
	printf ("Valor arrecadado com pipoca no in�cio do filme: R$ %.2i\n", (Qpipoca*15)); // 15 porque a gente t� humilde;
	printf ("---------------\n");
	printf ("Sobre o volume do g�nero:\n");
	printf ("Quantidade de espectadores do g�nero masculino: %i\n", masc);
	printf ("Quantidade de espectadores do g�nero feminino: %i\n", fem);
	printf ("---------------\n");
	printf ("Sobre o volume de espectadores de diferentes idades: \n");
	printf ("Crian�as: %i\n", kid);
	printf ("Adolescentes: %i\n", teen);
	printf ("Adultos: %i\n", adult);
	printf ("Idosos: %i\n\n", granny);
	printf ("Amamos voc� Joyce <33333333 me da 10 pf nunca te pedi nada passei 4 horas na madrugada fazendo isso\nmeu amigo da UnB me ajudou muito tb manda um salve pro Guilherme fam�lia gente finissima o garoto"); // Joyce rainha, resto nadinha;
}




	
/*Fontes: https://youtube.com/watch?v=ukXa9LflfOQ
          https://www.youtube.com/watch?v=bYSQzUukpT0
          https://www.youtube.com/watch?v=BuwcscbPZHA
          
          */

