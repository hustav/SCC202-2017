#include <stdio.h>

long long expo(int x, int n) {
	if (n == 0) return 1;
	long long aux = expo(x, n/2);
	if (n % 2 == 0)
		return aux * aux;
	else
		return aux * aux * x;
}

int main() {
	for (int i = 0; i < 100; i++)
		printf("%d %lld\n", i, expo(2, i));
	return 0;
}