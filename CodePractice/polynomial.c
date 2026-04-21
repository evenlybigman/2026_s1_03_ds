#include <stdio.h>
#define MAX_DEGREE_SIZE 101
typedef struct {
	int degree;
	double coef[MAX_DEGREE_SIZE];
}polynomial;

void print_poly(polynomial p) {
	for (int i = 0; i < p.degree; i++)
		printf("%.1lfx^%d + ", p.coef[i], p.degree - i);
	printf("%.1lf\n",p.coef[p.degree]);
}

polynomial poly_add(polynomial a, polynomial b) { //같은 차수의 계수를 더한다.
	polynomial c;
	int atos = 0, btos = 0, ctos = 0;
	int ad = a.degree, bd = b.degree;
	if (a.degree > b.degree) c.degree = a.degree;
	else c.degree = b.degree;
	while (atos <= a.degree && btos <= b.degree) {
		if (ad > bd) {
			c.coef[ctos++] = a.coef[atos++];
			ad--;
		}
		else if (ad == bd) {
			c.coef[ctos++] = a.coef[atos++] + b.coef[btos++];
			ad--;
			bd--;
		}
		else {
			c.coef[ctos++] = b.coef[btos++];
			bd--;
		}
	}
	return c;
}

int main() {
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4, { 7, 0, 5, 0 ,1 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add(a, b);
	printf("-----------------------------------------------------------\n");
	print_poly(c);
}