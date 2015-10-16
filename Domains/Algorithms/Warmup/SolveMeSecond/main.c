#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int solveMeSecond(int a, int b) {
	return a + b;
}

int main() {
	int t, i;
	scanf("%d", &t);
	int num1, num2;
	int sum;
	for (i = 0; i < t; i++) {
		scanf("%d %d", &num1, &num2);
		sum = solveMeSecond(num1, num2);
		printf("%d\n", sum);
	}
	return 0;
}
