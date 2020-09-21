#include "QdrEq.h"

int main() {

	Unit_tests ();

	printf("SolveQdr - Solve a qadratic equation ax²+bx+c=0 \n\n");

	printf( "ver. 1.0 (c) Eccentricity  \n\n");

	double a = NAN, b = NAN, c = NAN, D = NAN, x1 = NAN, x2 = NAN;

	getValue (&a, "a");
	getValue (&b, "b");
	getValue (&c, "c");
	printf("\n");

	if (isZero(a)) {
		printf("This equation is not qadratic, but linear \n");
	}	
	int nRoots = SolveQdr(a, b, c, &x1, &x2);

	switch (nRoots) {
		case ZeroSl:
		printf("No solutions \n");
		break;
		case OneSl:
		printf ("One solution: x = %lf \n", x1);
		break;
		case InfSl: 
		printf ("Infinity solutions: x ∈  R \n");
		break;
		case TwoSl:
		printf("Two solutions: x1 = %lf, x2 = %lf \n", x1, x2);
		break;
		}

printf("Congratulations you destroyed the qadratic equation \n");

return 0;
}

//---------------------------------------------------------------------------
