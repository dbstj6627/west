#include <stdio.h>

int main() {
	int prime[500];
	int ptr = 0;;
	int cnt = 0;
	prime[ptr++] = 2;
	for (int n = 3; n <= 1000; n+=2) {
		int i;
		for (i = 1; i < ptr; i++) {
			cnt++;
			if (n % prime[i] == 0) {
				break;
			}
		}
			if (ptr == i) {
				prime[ptr++] = n;
			}
	}
	for (int i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);
	}
	printf("나눗셈 실행 횟수 : %d\n", cnt);

	return 0;
}
