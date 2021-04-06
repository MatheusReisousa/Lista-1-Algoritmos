#include <stdio.h>
int main ( ) {
	int idade;
	printf ("Quantos anos voce tem? ");
	scanf ("%d", &idade);
	if (idade>0, idade<=3){
		printf ("A idade %d esta relacionada a um bebe", idade);
	} else if (idade>3, idade<= 10) {
		printf ("A idade %d esta relacionada a uma criança", idade);
		} else if (idade > 10, idade <= 17){
			printf ("A idade %d esta relacionada a um adolescente", idade);
		} else if (idade > 17, idade <= 40) {
			printf ("A idade %d esta relacionada a um jovem adulto", idade);
		} else if (idade > 40, idade <= 60) {
			printf ("A idade %d esta relacionada a um adulto maduro", idade);
		} else if (idade > 60) {
			printf ("A idade %d esta relacionada a um idoso", idade);
		}
		return 0; 	
}
//informar a idade!
      //0-3 -> bebê
      //4-10 -> criança
      //11-17 -> adolescente
      //18-40 -> adulto
      //41-60 -> adulto 2
      //61 ... -> idoso
