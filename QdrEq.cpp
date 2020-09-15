#include <stdio.h>

#include <math.h>

const long double eps = 1e-9;

const int ZeroSl = 0;
const int InfSl = - 1;
const int TwoSl = 2;
const int OneSl =1;
const int error = 404;

bool isZero(double a) {
	return fabs(a) < eps;
}

bool isEqual(double a, double b) {
	return isZero(a - b);   
}

bool Less(double a, double b) {
	return !isEqual(a, b) && (a < b);
}

int SolveLin (double b, double c, double* x) {
	if (isZero(b) && !isZero(c)) {
		return ZeroSl;
	}

	if (!isZero(b)) {
		*x = (-c) / b + eps;
		return OneSl;
	}

	if (isZero(b) && isZero(c)) {
		return InfSl;
	}
 }

int SolveQdr (double a, double b, double c, double* x1, double* x2) {
	double D = b * b - 4 * a * c;
	if (isZero(a)) {
		return error;
	}
	if (Less(0, D)) {
		*x1 = (-b + sqrt(D)) / (2 * a);
		*x2 = (-b - sqrt(D)) / (2 * a);
		return TwoSl;
	}

	if (isZero(D)) {
		*x1 = (-b) / (2 * a) + eps;
		return OneSl;
	}
	if (Less(D, 0)) {
		return ZeroSl;
	}
}

void U_tests () {
	double x1, x2, x;

	int Roots = SolveQdr(1, 2, 1, &x1, &x2); 
	if ((Roots == OneSl) && isEqual(x1, -1)){
		printf ("Test 1 ok\n");
	}else {
		printf ("Test 1 BAD Roots = 1, x1 = -1 expected, but Roots = %d, x1 = %lf, x2 = %lf\n", Roots, x1, x2);
	}

	Roots = SolveQdr(10, 2, 1, &x1, &x2); 
	if (Roots == ZeroSl) {
		printf ("Test 2 ok\n");
	}else {
		printf ("Test 2 BAD Roots = 0 expected, but Roots = %d, x1 = %lf, x2 = %lf\n", Roots, x1, x2);
	}

	Roots = SolveQdr(1, 4, -5, &x1, &x2);
	if ((Roots == TwoSl) && isEqual(x1, 1) && isEqual(x2, -5)) {
		printf ("Test 3 ok\n");
	}else {
		printf ("Test 3 BAD Roots = 1, x1 = 1, x2 = -5 expected, but Roots = %d, x1 = %lf, x2 = %lf\n", Roots, x1, x2);
	}

	Roots = SolveLin(2, 1, &x1); 
	if ((Roots == OneSl) && isEqual(-0.5 + eps, x1)){
		printf ("Test 4 ok\n");
	}else {
		printf ("Test 4 BAD Roots = 1, x1 = -0.5 expected, but Roots = %d, x1 = %lf\n", Roots, x1);
	}

	Roots = SolveLin(0, 1, &x1); 
	if (Roots == ZeroSl) {
		printf ("Test 5 ok\n");
	}else {
		printf ("Test 5 BAD Roots = 0 expected, but Roots = %d, x1 = %lf\n", Roots, x1);
	}

	Roots = SolveLin(0, 0, &x1);
	if (Roots == InfSl) {
		printf ("Test 6 ok\n");
	}else {
		printf ("Test 6 BAD Roots = ∞ expected, but Roots = %d, x1 = %lf\n", Roots, x1);
	}
}

int main() {

	printf ("%d", sizeof (long long double));

	U_tests ();

	printf("SolveQdr - Solve a qadratic equation ax²+bx+c=0 \n\n");

	printf( "ver. 1.0 (c) Eccentricity  \n\n");

	double a, b, c, x, D, x1, x2;

	printf("Please enter a = ");

	while (scanf("%lf", &a) != 1) {
		printf("OMG ERROR 404/==> Mentor has been detected! Try again \n");
		fflush (stdin);
	}

	printf("\nPlease enter b = ");

while (scanf("%lf", &b) != 1) {
		printf("OMG ERROR 404/==> Mentor has been detected! Try again \n");
		fflush (stdin);
	}

	printf("\nPlease enter c = ");

	while (scanf("%lf", &c) != 1) {
		printf("OMG ERROR 404/==> Mentor has been detected! Try again \n");
		fflush (stdin);
	}

	if (isZero(a)) {
		printf("This equation is not qadratic, but linear \n");
		int nRoots = SolveLin(b, c, &x1);

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
		}
	}else {
		int nRoots = SolveQdr(a, b, c, &x1, &x2);
		switch (nRoots) {
			case ZeroSl:
			printf("No solutions \n");
			break;
			case OneSl:
			printf ("One solution: x = %lf \n", x1);
			break;
			case TwoSl:
			printf("Two solutions x1 = %lf, x2 = %lf \n", x1, x2);
			break;
		}
	}	

printf("Congratulations you destroyed the qadratic equation \n");

return 0;
}

//---------------------------------------------------------------------------
