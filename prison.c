#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 101

// baekjoon 6359

/*
	Assuming that there are n rooms, we want to open and close the doors of each multiple room from 1 to n.
	 At this time, we want to find the number of divisors in integers from 1 to n 
	 and then find the sum of the cases where the number of divisors is odd.
*/

int divisor(int num) {
	int cnt = 0;

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			cnt++;
		}
	}
	return cnt;
}

int game(int num) {
	int ans = 0;

	for (int j = 1; j <= num; j++) {
		if (divisor(j) % 2 != 0) {
			ans++;
		}
	}
	return ans;
}

int main() {
	int T;
	int n;
	scanf("%d", &T);


	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%d\n", game(n));
	}

	return 0;
}