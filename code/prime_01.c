#include <stdio.h>

int main(void) {
	int counter = 0;
	for (int n = 2; n <= 1000; n++) {
		int i;
		for (i = 2; i < n; i++) {
			counter++;
			if (n % i == 0) {
				break;
			}
		}
		if (n == i) {
			printf("%d\n", n);
		}
	}
	printf("나눗셈 횟수 : %d\n", counter);

	return 0;
}
