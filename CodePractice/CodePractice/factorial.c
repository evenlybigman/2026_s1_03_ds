#include <stdio.h>

int factorial(int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}

int main() {
	int n = 5;
	printf("%d 팩토리얼의 값: %d",n, factorial(n));
}