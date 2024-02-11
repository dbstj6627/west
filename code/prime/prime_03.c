#include <stdio.h>

int main() {
	int prime[500];
	int ptr = 0;
	int cnt = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;

	for (int n = 5; n <= 1000; n += 2) {
		int flag = 0;
		for (int i = 1; cnt++, prime[i] * prime[i] <= n; i++) {
			cnt++;
			if (n % prime[i] == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			prime[ptr++] = n;
		}
	}
	for (int i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);
	}
	printf("곱셈과 나눗셈을 실행한 횟수 : %d\n", cnt);

	return 0;
}
