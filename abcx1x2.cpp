#include <stdio.h>

#include <math.h>

const  long double eps = 1e-9;

bool isZero(double a) {
	return fabs(a) < eps;
}

bool isEqual(double a, double b) {
	return isZero(a - b);   
}

bool Less(double a, double b) {
	return !isEqual(a, b) && (a < b);
}


int main() {


	
	printf("SolveQdr - Solve a qadratic equation ax²+bx+c=0 \n\n");

	printf( "ver. 1.0 (c) Eccentricity  \n");

	printf("\n");

	double a, b, c, x, D, x1, x2;

	printf("Please enter a: \n");

	scanf("%lf", &a);

	printf("Please enter b: \n");

	scanf("%lf", &b);

	printf("Please enter c: \n");

	scanf("%lf", &c);

	D = b * b - 4 * a * c;
	if (isZero(a)) {
		printf("This equation is not qadratic, but linear \n");

		if (isZero(a) && !isZero(c)) {

			printf("No solutions \n");

		}

		if (!isZero(b)) {
			printf ("One solution: x = ");

			x1 = (-c) / b + eps;

			printf ("%lf" , x1);

			printf ("\n");
		}

		if (isZero(b) && isZero(c)) {
			printf ("Infinity solutions: x ∈  R \n");

		}
		return 0;

	}
	if (Less(0, D)) {
		x1 = (-b + sqrt(D)) / (2 * a);

		x2 = (-b - sqrt(D)) / (2 * a);

		printf("Two solutions x1 = %lf ", x1, ", ");

		printf("x2 = %lf", x2);

		printf("\n");

	}

	if (isZero(D)) {

		x1 = (-b) / (2 * a);

		printf("One solution x = %lf", x1);

		printf("\n");

	}
	if (Less(D, 0)) {
		printf("No solutions \n");
	}

printf("Congratulations you destroyed the qadratic equation \n");

return 0;
}
