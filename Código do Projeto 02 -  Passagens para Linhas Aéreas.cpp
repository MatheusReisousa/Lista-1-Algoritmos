// Nome Completo: Matheus Reis de Sousa      Matr�cula: UC21105889        Curso: Engenharia de Software

#include <stdio.h>  // Biblioteca padr�o que disponibiliza ferramentas como scanf e printf; 
#include <stdlib.h>  // Biblioteca de entrada e sa�da de dados;
#include <locale.h>  // Diretiva acess�rio, que permite a utiliza��o de acentos sem demais problemass;
#include <string.h>  // Biblioteca de strings para manipular o tamanho dos caracteres, extremamente �til;
#include <conio.h> // Biblioteca que permite a colora��o dos caracteres selecionados;

#define RED "\x1b[91m" //Aqui est� delimitado as cores que ser�o usadas
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m" // O reset serve para pausar o efeito da cor;

void mapaLimpo(int assentos, int cadeiras[25][8], char status [25][8]); //Estrutura das Matrizes que ser�o usadas posteriormente;
void mapaVoo(int assentos, int cadeiras [25][8], char status [25][8]); 


int main (void) {
	
	char destino [30], status [25][8];
	float dinheiro, valor, totalTUDO;
	int assentos, menu, numeroPassageiros, criancas, id = 0, lucro, comprados, confirmaId, decisao, criancasConf, decisaoN; 
	int cadeiras[25][8], idMatriz [25][8], reserva = 0, idUsu, asDisp, asRes, asConf, totalComp;
	
	
	
	
	setlocale(LC_ALL, "portuguese"); //Comando da diretiva de localiza��o em portugu�s;
	do {
		system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
		printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n");
		printf ("OL�, SOU SEU ASSISTENTE VIRTUAL. AQUI, IREMOS CADASTRAR O VOO O QUAL SER� DISPONIBILIZADA A COMPRA DE PASSAGENS.\n");
		printf ("_____________________________________________________\n\n");
		printf ("POR FAVOR, INSIRA O DESTINO DO VIAGEM: ");
		fgets  (destino, 30 , stdin);
		if (strlen(destino) - 1 == 0) { //O strlen cl�ssico, que previne o espa�o vazio de um utilizador desavizado;
			printf ("\n_____________________________________________________");
			printf ("\n\n---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
			printf ("O NOME DO DESTINO N�O PODE FICAR VAZIO!\n", destino);
			printf ("POR FAVOR, INSIRA UM NOME V�LIDO.\n", destino);
			printf ("_____________________________________________________\n\n");
			system ("pause");
		}
	}	while (strlen(destino) - 1 == 0);
			
		int len = strlen(destino); // Ferramenta destinada a remover o \n autom�tico do fgets, por quest�es apenas est�ticas;
        if(destino[len-1] == '\n' ){
            destino[len-1] = 0;
        }
        
		printf ("\n_____________________________________________________\n\n");
		
		do {
		
		printf ("QUAL O PRE�O DA PASSAGEM � %s? ", destino);
		scanf ("%f", &valor);
		if (valor < 0) {
			printf ("\n_____________________________________________________");
			printf ("\n\n---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
			printf ("O VALOR DA PASSAGEM PODE AT� SER GRATUITO, ENTRETANDO N�O PODE SER NEGATIVO!\n");
			printf ("POR FAVOR, INSIRA UM PRE�O V�LIDO DA PASSAGEM � %s!\n", destino);
			printf ("_____________________________________________________\n\n");
			system ("pause");
		}
	}	while (valor < 0);
	
	
	do {
		printf ("_____________________________________________________\n\n");
		printf ("QUAL A QUANTIDADE DE ASSENTOS DISPON�VEIS NO VOO � %s? ", destino);
		scanf ("%i", &assentos);
		if (assentos < 90 || assentos > 200) {
			printf ("\n_____________________________________________________");
			printf ("\n\n---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
			printf ("A QUANTIDADE DE ASSENTOS DISPOSTOS � %s N�O S�O CAPAZES DE COMPLETAR O AVI�O.\n", destino);
			printf ("POR FAVOR, INSIRA UM VALOR V�LIDO!\n");
			printf ("_____________________________________________________\n\n");
			system ("pause");
		}
	}	while (assentos < 90 || assentos > 200);
	
	mapaLimpo(assentos, cadeiras, status);
	
	do { // Introdu��o � interface e ao menu;
		system ("cls || clear"); // Adiciona a capacidade do algoritmo limpar a tela tanto em Linux como em Windows;
		printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
		printf (" [1] APRESENTA��O DO MAPA DE VOO PROVIS�RIO;\n");
		printf (" [2] EFETUA��O DE RESERVAS;\n");
		printf (" [3] CANCELAMENTO DE RESERVAS;\n");
		printf (" [4] CONFIRMAR RESERVAS;\n");
		printf (" [5] ESTAT�STICAS DE VOO;\n");
		printf (" [6] FINALIZAR O PROGRAMA;\n\n");
		printf ("_____________________________________________________\n\n");
		printf ("ESTE � O NOSSO MENU DE CONFIGURA��O DO VOO.\n");
		printf ("SELECIONE UMA DAS OP��ES APRESENTADAS PARA SER REDIRECIONADO AO MENU CORRESPONDENTE: ");
		scanf  ("%i", &menu);
	 
	
		switch (menu) {
			case 1: // O primeiro caso, destinado � vizualiza��o do imponente mapa de voo; 
			system ("cls || clear");
			printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n"); 
			mapaVoo (assentos, cadeiras, status); // Vizualizador do mapa de voo;
			system ("pause");
			break;
			
			case 2: // O segundo caso, destinado ao cadastro dos passageiros;
			id = id + 1;
			reserva ++;
			do {
				system ("cls || clear");
				printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");; 
				printf ("NESSA INTERFACE, IREMOS REALIZAR SUA RESERVA!\n");
				printf ("QUANTOS PASSAGEIROS IREMOS CADASTRAR?\n");
				scanf ("%i", &numeroPassageiros);
				if (numeroPassageiros < 1){
					printf ("\n_____________________________________________________");
					printf ("\n\n---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
					printf ("PRECISAMOS DE UM VALOR PLAUS�VEL DE PASSAGEIROS PARA CADASTRAR!\n");
					printf ("POR FAVOR, INSIRA UM N�MERO V�LIDO DE PASSAGEIROS A SEREM CADASTRADOS!\n", destino);
					printf ("_____________________________________________________\n\n");
					system ("pause");
				} 
			} while (numeroPassageiros < 1);
			
			do {
				system ("cls || clear");
				printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
				printf ("Dentre os %.3i passageiros, quantas crian�as de at� 5 anos ser�o cadastradas?\n", numeroPassageiros);
				scanf ("%i", &criancas);
				if (criancas < 0){
					printf ("\n_____________________________________________________");
					printf ("\n\n---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
					printf ("O N�MERO DE CRIAN�AS A SEREM CADASTRADAS N�O PODE FICAR VAZIO!\n", destino);
					printf ("POR FAVOR, INSIRA UM N�MERO V�LIDO.\n", destino);
					printf ("_____________________________________________________\n\n");
					system ("pause");
				}
			} while (criancas < 0);
			
			do {
				system ("cls || clear");
				printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
				mapaVoo (assentos, cadeiras, status);
				printf ("POR FAVOR, SELECIONE UM LUGAR DENTRE OS ASSENTOS DISPON�VEIS:\n");
				for (int i = 0; i < numeroPassageiros; i++ ) {
				printf ("PASSAGEIRO %.3i: ", i+1);
				scanf ("%i", &reserva);	
				fflush (stdin);
				for (int i = 0; i < 25; i++ ){ // Aqui � onde n�s conectamos o Id aos assentos escolhidos, o que � muito �til para determinar sua futura cor;
				for (int j = 0; j < 8; j++ ){ // Escolhi 25x8 porque achei melhor o espa�amento, apenas est�tico mesmo;
				if(cadeiras[i][j] == reserva ){ 
                status[i][j] = 'R'; // A matriz de Status determina a cor do assento, nesse caso, vermelho;
                idMatriz[i][j]= id;
                }
				}
			}
			}

			} while (reserva < 1 || reserva > assentos);
			
			do {
				totalComp = ((numeroPassageiros - criancas) * valor) + (criancas * valor / 2);
				fflush (stdin);
				system ("cls || clear");
				printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
				printf ("ESTE AQUI � O ID DE SUA RESERVA. COM ELE, EFETIVAREMOS SUA COMPRA MAIS TARDE, ASSIM COMO VOC� PODER� CANCELAR A RESERVA NO FUTURO.\n");
				printf ("ID: %i\n", id); 
				printf ("_____________________________________________________\n");
				printf ("AL�M DISSO, ESTE FOI O TOTAL DA COMPRA:\nR$ %i\n", totalComp);
				system ("pause");
				} while (id == 'R' );
						
			break;
			case 3: 
					system ("cls || clear");
					printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");; 
					system("cls"); 
			        printf("ESTE � O MENU DE CANCELAMENTO DE RESERVAS.\n");
			        printf("PARA CANCELAR SUA RESERVA, PRIMEIRAMENTE INSIRA AQUI SEU N�MERO DE IDENTIFICA��O (ID)\n");
					
			        do{ 
			        scanf("%d", &confirmaId);
			        if (idUsu != id);{ //If cl�ssico de confirma��o da execu��o;
			            printf("O ID INSERIDO AINDA N�O FOI CADASTRADO.\nPOR FAVOR DIGITE NOVAMENTE:\n");
			        }
			    	} while (idUsu == id);  
					mapaVoo (assentos, cadeiras, status); // Vizualizador do mapa de voo;
					printf ("TEM CERTEZA QUE DESEJA CANCELAR A COMPRA DE SUA PASSAGEM? ([S] PARA SIM E [N] PARA N�O)\n");
					do {
						scanf  ("%c", &decisao);
					if (decisao == 's' || decisao == 'S') {	 //Caso ele aceite confirmar a passagem, esta matriz ir� modificar o status antigo dela, que era reservado, para dispon�vel;
						for (int i = 0; i < 25; i++ ){
							for (int j = 0; j < 8; j++ ){
							if(status[i][j] == 'R' ){
			                status[i][j] = 'D'; //D est� associado a cor verde;
			                idMatriz[i][j]= id;
			                }
							}
							}							
						printf ("SUA RESERVA FOI CANCELADA COM SUCESSO!\n");
						system ("pause");
						break;
						} else if (decisao == 'n' || decisao == 'N') {
						printf ("OK, VOLTAREMOS AO MENU PRINCIPAL ENT�O.\n");
						system ("pause");
						break;
						} else
						printf ("POR FAVOR, ESCOLHA UMA OP��O V�LIDA ENTRE [S] PARA SIM E [N] PARA N�O.\n");
					} while (decisao != 'S' && decisao != 's' && decisao != 'N' && decisao != 'n');	
			break;
			case 4:  
			system ("cls || clear");
			printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");; 
			printf ("ESTE � O MENU DE CONFIRMA��O DE COMPRA.\n");
			printf ("PARA EFETUARMOS A CONFIRMA��O, INSIRA AQUI O SEU N�MERO DE IDENTIFICA��O (ID):\n");
			scanf  ("%i", &confirmaId);
			fflush (stdin);
			if (confirmaId != id){ //If cl�ssico de confirma��o da execu��o;
				printf ("O ID INSERIDO � INV�LIDO!\n");
				printf ("POR FAVOR, INSIRA UM ID EXISTENTE!\n");	
			} else 
			mapaVoo (assentos, cadeiras, status);
			printf ("DESEJA REALMENTE CONFIRMAR SUA RESERVA? ([S] PARA SIM E [N] PARA N�O)\n");
			scanf  ("%c", &decisaoN);
			fflush (stdin);
			if (decisaoN == 'S' || decisaoN == 's'){
				printf ("QUANTAS CRIAN�AS EST�O NA SUA RESERVA? ");
				scanf  ("%i", &criancasConf);
				printf ("OBRIGADO POR CONFIRMAR SUA RESERVA!\n");
				for (int i = 0; i < 25; i++ ){ // Extremamente parecido como o anterior, serve para desassociar a matriz reservado e torn�-la confirmado;
					for (int j = 0; j < 8; j++ ){ 
					if(status[i][j] == 'R' ){
	                status[i][j] = 'C'; // C � associado ao azul;
	                idMatriz[i][j]= id;
			            }
					}
				}
			} else if (decisaoN == 'n' || decisaoN == 'N'){ //If cl�ssico de confirma��o da execu��o;
				printf ("OK, IREMOS TE REDIRECIONAR PARA O MENU PRINCIPAL ENT�O.\n");
			} else{
				printf ("POR FAVOR, ESCOLHA UMA OP��O V�LIDA ENTRE [S] PARA SIM E [N] PARA N�O.\n");
			}
				
			system ("pause");
			break;
			
			case 5: { 
			int contador = 0; // Resolvi colocar o contador dos assentos dentro do switch case de estat�sticas porque n�o achei uma solu��o que tirasse o valor diretamente da matriz. Quem n�o tem c�o ca�a com gato;
			asDisp = 0; // Assentos Dispon�veis;
			asConf = 0; // Assentos Confirmados;
			asRes = 0; // Assentos Reservados ;
			for ( int i = 0; i < 25; i++) { // Refazer a estrutura da matriz foi a solu��o que encontrei para determinar o contador espec�fico para cada tipo de assento;
            for ( int j = 0; j < 8; j++){ 
			if (contador == assentos ) {
            		break;
				} else {
					contador ++;
					if(cadeiras[i][j]<=assentos && (status[i][j]=='D' || status[i][j]=='R' || status[i][j]=='C')){ //Status: [D]ispon�vel / [R]eservado/ [C]onfirmado;
		                	if (status[i][j]=='R'){
		                	asRes ++; 
		                } else if (status[i][j]=='D'){ 
		                    asDisp ++;
		                } else if (status[i][j]=='C'){
		                    asConf ++;
		                }
	                
               		}	
				}
			}
		}
			if (criancasConf > asConf){ // Dentro desse if, o lucro � calculado para a situa��o o qual h� apenas crian�as confirmadas;
				lucro = (criancasConf * valor / 2);
				system ("cls || clear");
				printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");; 
				printf ("ESTE � O MENU DE ESTAT�STICAS DA VIAGEM.\n");
				printf ("\n_____________________________________________________\n");
				printf ("O LUCRO DA VIAGEM EQUIVALE A %i", lucro);
				printf ("\n_____________________________________________________\n");
				printf ("ESTA � A LEGENDA DE ASSENTOS E SEUS ATRIBUTOS:\n");
				printf ("DISPON�VEIS: %i\n", asDisp);
				printf ("RESERVADOS: %i\n", asRes);
				printf ("CONFIRMADAS: %i\n", asConf);
				system ("pause");
			} else // J� aqui, serve para a situa��o padr�o;
			lucro = ((asConf - criancasConf) * valor) + (criancasConf * valor / 2);
			system ("cls || clear");
			printf ("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");; 
			printf ("ESTE � O MENU DE ESTAT�STICAS DA VIAGEM.\n");
			printf ("\n_____________________________________________________\n");
			printf ("O LUCRO DA VIAGEM EQUIVALE A %i", lucro);
			printf ("\n_____________________________________________________\n");
			printf ("ESTA � A LEGENDA DE ASSENTOS E SEUS ATRIBUTOS:\n");
			printf ("DISPON�VEIS: %i\n", asDisp);
			printf ("RESERVADOS: %i\n", asRes);
			printf ("CONFIRMADAS: %i\n", asConf);
			system ("pause");
			
			
			break;
				
			} 
			
			case 6: // A op��o de terminar o Loop e terminar o programa;
			system ("cls || clear");
			printf("---------------|SALUMAR LINHAS A�REAS|---------------\n\n");
			printf ("OBRIGADO POR OPTAR POR SALUMAR LINHAS A�REAS!\n");
			printf ("NOS PREOCUPAMOS COM O SEU CONFORTO, E POR ISSO, TORCEMOS PARA QUE TENHA UMA �TIMA VIAGEM!");

			
			break;
			default: 
			printf ("\n______________________________________________________\n\n");
			printf ("O VALOR INSERIDO N�O SE REFERE A NENHUMA DAS OP��ES DO MENU.\n");
			printf ("POR FAVOR SELECIONE, DENTRE AS OP��ES APRESENTADAS, OUTRO VALOR!\n");
			printf ("______________________________________________________\n\n");
			system ("pause");
			break;
		}
	}  while (menu != 6); // Estrutura do Loop que pode determinar o case 6 como o t�rmino do programa;
	

} 


void mapaLimpo(int assentos, int cadeiras[25][8], char status [25][8]) { //Estrutura do Mapa de Voo provis�rio, ele utiliza um contador para dar um boost de efici�ncia que veio a calhar;
	int i,j,contador=0; // Vari�veis intr�nsecas ao mapa;
	for ( i = 0; i < 25; i++)
        {
            for ( j = 0; j < 8; j++)
            {
            	if (contador == assentos){ //Se o contador for igual ao n�mero de assentos, o contador ir� parar de funcionar automaticamente;
            		break;
				} else {
				contador++ ;
            	cadeiras[i][j]=contador;
				}
            	
            }
        }


	for ( i = 0; i < 25; i++)
        {
            for ( j = 0; j < 8; j++)
            {
            status [i][j] = 'D';
            }  
        }
}

void mapaVoo (int assentos, int cadeiras [25][8], char status [25][8]){ // Mapa definitivo, que determina a maioria das matrizes utilizadas;
	int i,j, contador = 0; // Vari�veis intr�nsecas ao mapa;
	

    printf(BLUE "CONFIRMADO  |  " RESET); // Aqui se colore os assentos;
    printf(GREEN "DISPONIVEL  |  " RESET);
    printf(RED "RESERVADO  |  \n\n" RESET);
	for ( i = 0; i < 25; i++) { // Desenvolvimento da matriz;
            for ( j = 0; j < 8; j++){
            	if (contador == assentos ) { // Repeti��o que delimita a matriz;
            		break;
				} else {
					contador ++;
					if(cadeiras[i][j]<=assentos && (status[i][j]=='D' || status[i][j]=='R' || status[i][j]=='C')){ // A pior parte de descobrir como se faz, a matriz colorida foi montada com muito ardor aqui;
		                	if (status[i][j]=='R'){
		                	printf(RED "%.3d " RESET, cadeiras[i][j]);  
		                } else if (status[i][j]=='D'){ 
		                    printf(GREEN "%.3d " RESET, cadeiras[i][j]);
		                } else if (status[i][j]=='C'){
		                    printf(BLUE "%.3d " RESET, cadeiras[i][j]);
		                }
	                
               		}	
				}  
			printf ("  ");
        }
        printf("\n");
	}
		
}


        
/* FONTES:
- https://www.inf.pucrs.br/~pinho/LaproI/Vetores/Vetores.htm - �� Matrizes e Vetores``, M�rcio Pinho;
- https://youtu.be/8qbqFsPov3g - �� Matriz - Conceito e utiliza��o - Linguagem C``, Eduardo Casavella;
- https://youtu.be/6JErmAu7T-E - �� Matriz Bidimensional - scanf e for - Linguagem C``, Eduardo Casavella;
- https://github.com/vitorvd/Algoritmos/blob/main/ProjetoPratico2/VitorDudaVersiani_UC21106822_PP02.cpp - ��Projeto Pr�tico 02``, Vitor Versiani;
- https://github.com/Carlos-E-Souza/Primeiro-semestre-UCB/tree/main/Algoritmos_programa��o/PP02 - ��Algoritmos e Programa��o``, Carlos Souza;
*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

