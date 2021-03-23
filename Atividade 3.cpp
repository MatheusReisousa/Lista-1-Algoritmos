// Entrada: a, b, c.
// Saída: x', x''.
// Processamento: realização do cálculo
#include<stdio.h>// inserção da biblioteca que responderá as ferramentas de entrada e saída: printf e scanf.
#include<math.h>// inserção de uma biblioteca auxiliar para as funções matemáticas específicas.
int main (){// entrada da função main.
	double a, b, c, x1, x2, delta;// operação onde se reserva o espaço necessário para as variáveis.
	printf ("Digite o valor da variavel a: ");// ferramenta de exibição de texto.
	scanf ("%lf", &a);// ferramenta de gravação de variável na memória.
	printf ("Digite o valor da variavel b: ");
	scanf ("%lf", &b);
	printf ("Digite o valor da variavel c: ");
	scanf ("%lf", &c);
	delta = sqrt(b * b - 4 * a * c);// linearização da fórmula de delta.
	if (a == 0 or delta < 0) { // resolução do conflito da lógica matemática com o programa, através da função ´´if``.
		printf ("Nao e possivel calcular. ");
		return 0;
	}
		
		else { // alternativa para a condição ´´if``.
			x1 = (-(b) + delta)/ 2 * a; // atribuição do cálculo às variáveis faltantes da função de bháskara.
			x2 = (-(b) - delta)/ 2 * a;
		}
	if (delta == 0) { // resolução de um caso específico através da função ´´if``.
		printf ("Para %lf, %lf, %lf, o resultado possui apenas uma raiz real: %.2lf", a, b, c, x1);
		return 0;
	}
	printf ("Para %lf, %lf, %lf, o resultado da formula e igual a : %.2lf, %.2lf", a, b, c, x1, x2);// resolução da fórmula.
	return 0;// ferramenta de retorno da função main.
}// final da função.
