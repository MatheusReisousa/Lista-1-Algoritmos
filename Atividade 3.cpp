// Entrada: a, b, c.
// Sa�da: x', x''.
// Processamento: realiza��o do c�lculo
#include<stdio.h>// inser��o da biblioteca que responder� as ferramentas de entrada e sa�da: printf e scanf.
#include<math.h>// inser��o de uma biblioteca auxiliar para as fun��es matem�ticas espec�ficas.
int main (){// entrada da fun��o main.
	double a, b, c, x1, x2, delta;// opera��o onde se reserva o espa�o necess�rio para as vari�veis.
	printf ("Digite o valor da variavel a: ");// ferramenta de exibi��o de texto.
	scanf ("%lf", &a);// ferramenta de grava��o de vari�vel na mem�ria.
	printf ("Digite o valor da variavel b: ");
	scanf ("%lf", &b);
	printf ("Digite o valor da variavel c: ");
	scanf ("%lf", &c);
	delta = sqrt(b * b - 4 * a * c);// lineariza��o da f�rmula de delta.
	if (a == 0 or delta < 0) { // resolu��o do conflito da l�gica matem�tica com o programa, atrav�s da fun��o ��if``.
		printf ("Nao e possivel calcular. ");
		return 0;
	}
		
		else { // alternativa para a condi��o ��if``.
			x1 = (-(b) + delta)/ 2 * a; // atribui��o do c�lculo �s vari�veis faltantes da fun��o de bh�skara.
			x2 = (-(b) - delta)/ 2 * a;
		}
	if (delta == 0) { // resolu��o de um caso espec�fico atrav�s da fun��o ��if``.
		printf ("Para %lf, %lf, %lf, o resultado possui apenas uma raiz real: %.2lf", a, b, c, x1);
		return 0;
	}
	printf ("Para %lf, %lf, %lf, o resultado da formula e igual a : %.2lf, %.2lf", a, b, c, x1, x2);// resolu��o da f�rmula.
	return 0;// ferramenta de retorno da fun��o main.
}// final da fun��o.
