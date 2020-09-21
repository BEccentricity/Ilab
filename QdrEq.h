#include <stdio.h>
#include <math.h>
#include <assert.h>

const long double eps = 1e-12;

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
		*x = (-c) / b;
		if (isZero(*x)) *x = 0.0;
		return OneSl;
	}

	if (isZero(b) && isZero(c)) {
		return InfSl;
	}
	return 0;
 }

int SolveQdr (double a, double b, double c, double* x1, double* x2) {
	double D = b * b - 4 * a * c;
	if (isZero(a)) {
		return SolveLin(b, c, x1);
	}
	if (Less(0, D)) {
		D= sqrt (D); 
		*x1 = (-b + D) / (2 * a);
		if (isZero(*x1)) *x1 = 0.0;
		*x2 = (-b - D) / (2 * a);
		if (isZero(*x2)) *x2 = 0.0;
		return TwoSl;
	}

	if (isZero(D)) {
		*x1 = (-b) / (2 * a);
		if (isZero(*x1)) *x1 = 0.0;
		return OneSl;
	}
	if (Less(D, 0)) {
		return ZeroSl;
	}
	return 0;
}

void getValue(double* value, char* Word) {

	printf("\nPlease enter %s = ", Word);
	while (scanf("%lf", value) != 1) {
		printf("OMG ERROR 404/==> Mentor has been detected! Try again \n");
		fflush (stdin);
	}
}

void Unit_tests () {
	
	double Test_a[] = 		{  1,	1,	0,   0,		1,  	1,		 0,		0,		2,		};
	double Test_b[] = 		{  2,	4,	1,   0,		0,  	1,		 2,		0,		3,		};
	double Test_c[] = 		{  1,  -5,	0,   0,		0,  	1,		 4,		1,		-5,		};
	int NumberOfRoots[] = 	{  1,	2,	1,   InfSl,	1,  	0,		 1,		0,		2,		};
	double Test_X1[] = 		{ -1,	1,	0,   NAN,	0,  	NAN,	-2,		NAN,	1,		};
	double Test_X2[] = 		{NAN,  -5,	NAN, NAN,	NAN,	NAN,	 NAN,	NAN,	-2.5,	};
	int NumberOfTests = sizeof(NumberOfRoots) / sizeof(int);
	int nRoots[NumberOfTests];
	double ResX1[NumberOfTests];
	double ResX2[NumberOfTests];

	for (int i = 0; i < NumberOfTests; ++i) {
		nRoots[i] = SolveQdr (Test_a[i], Test_b[i], Test_c[i], &ResX1[i], &ResX2[i]);
		switch (nRoots[i]) {
			case OneSl:
			if (isEqual(Test_X1[i], ResX1[i])) {
				printf ("Test %d ok\n", i+1);
			}else {
				printf ("Test %d BAD NumberOfRoots = 1, x1 = %lf expected, but NumberOfRoots = %d, x1 = %lf\n", i+1, Test_X1[i], nRoots[i] ,ResX1[i]);
			}
			break;
			case TwoSl:
			if (isEqual(Test_X1[i], ResX1[i]) && isEqual(Test_X2[i], ResX2[i])) {
				printf ("Test %d ok\n", i+1);
			}else {
				printf ("Test %d BAD NumberOfRoots = 2, x1 = %lf, x2 = %lf expected, but NumberOfRoots = %d, x1 = %lf, x2 = %lf\n", i+1, Test_X1[i], Test_X2[i], nRoots[i], ResX1[i], ResX2[i]);
			}
			break;
			default:
			if (NumberOfRoots[i] == nRoots[i]) {
				printf ("Test %d ok\n", i+1);
			}else {
				printf ("Test %d BAD NumberOfRoots = %d  expected, but Roots = %d\n", i+1, NumberOfRoots[i], nRoots[i]);
			}
			break;
		} 

	}
	printf("\n");
}

