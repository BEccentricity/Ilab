#include <stdio.h>

#include <math.h>

int main() {
	
	printf ("This is programm for solution qadratic equation ax^2+bx+c=0 \n\n");

	printf ( "ver. 1.0 creator: Eccentricity  \n");

	printf ("\n");

	double a, b, c, x, d, x1, x2;

	printf("Please print a: \n");

	scanf ("%lf" , &a);

	printf("Please print b: \n");

	scanf ("%lf" , &b);

	printf("Please print c: \n");

	scanf ("%lf" , &c);

	d = b*b-4*a*c;
	if(a == 0 ){

		printf("This equation is not qadratic \n");

		if ((b == 0) && (c != 0)){

			printf("No solutions \n");

		}

		if(b != 0){
			printf ("One solution: x =");
			x1 = (-c)/b;
			printf ("%g" , x1);
			printf ("\n");
		}

		if((b == 0)&&(c == 0)){

			printf ("Infinity solutions: x ∈  R \n");

		}
		return 0;

	}
		if((a != 0) && (d > 0)){
			x1 = (-b+sqrt(d)) / (2*a);

			x2 = (-b-sqrt(d)) / (2*a);

			printf ("Two solutions x1 = %lf ", x1, ", ");

			printf ("x2 = %lf", x2);

			printf ("\n");

		}

		if(d == 0){
			x1 = (-b) / (2 * a);

			printf ("One solution x = %lf", x1);
			printf ("\n");

		}
		if (d < 0){
			printf ("No solutions \n");
		}
	return 0;
}
