#include <stdio.h>
 
struct Matrix_2x2 {
	int a, b, c, d;

	Matrix_2x2() : 
		a(1), 
		b(0), 
		c(0), 
		d(1) {}

	Matrix_2x2(int x) : 
		a(x), 
		b(x), 
		c(x),
		d(x) {}

	Matrix_2x2(int _a, int _b, int _c, int _d) : 
		a(_a),
		b(_b),
		c(_c),
		d(_d) {}

	void print() {
		printf("%d %d \n%d %d", a, b, c, d);
	}
};

Matrix_2x2 operator*(const Matrix_2x2 &u, const Matrix_2x2 &v) {
	Matrix_2x2 res;
	res.a = u.a * v.a + u.b * v.c;
	res.b = u.a * v.b + u.b * v.d;
	res.c = u.c * v.a + u.d * v.c;
	res.d = u.c * v.b + u.d * v.d;
	return res;
}

Matrix_2x2 deg(Matrix_2x2 s, int n) {
	if (n == 0) {
		return Matrix_2x2();
	} 
	if (n % 2 == 0) {
		Matrix_2x2 x = deg(s, n / 2);
		return x * x;
	} else {
		Matrix_2x2 x = deg(s, n - 1);
		return x * s;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	Matrix_2x2 Fibonacci(1, 1, 1, 0);
	Fibonacci = deg(Fibonacci, n - 1);
	printf("%d", Fibonacci.a);
	return 0;
}