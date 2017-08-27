#include <stdio.h>

long long m[100];

long long fib(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (m[n] == 0)
		m[n] = fib(n-1) + fib(n-2);
	return m[n];
}

int main() {
	for (int i = 1; i < 100; i++) {
		printf("%d %lld\n", i, fib(i));
	}
	return 0;
}