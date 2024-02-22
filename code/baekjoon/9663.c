#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void set(int* a, int* b, int* c, int* pos, int n, int i) {
	for (int j = 0; j < n; j++) {
		if (!a[j] && !b[i + j] && !c[i - j + n - 1]) {
			pos[i] = j;
			if (i == n - 1) {
				cnt++;
				return;
			}
			else {
				a[j] = b[i + j] = c[i - j + n - 1] = 1;
				set(a, b, c, pos, n, i + 1);
				a[j] = b[i + j] = c[i - j + n - 1] = 0;
			}
		}
	}

	return;
}

int main() {
	int n;
	scanf("%d", &n);

	int* a =  calloc(n, sizeof(int));
	int* b = calloc(2*n-1, sizeof(int));
	int* c = calloc(2 * n - 1, sizeof(int));
	int* pos = calloc(n, sizeof(int));


	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < 2*n-1; i++) {
		b[i] = 0;
		c[i] = 0;
	}

	set(a, b, c, pos, n, 0);
	printf("%d\n", cnt);

	free(a);
	free(b);
	free(c);
	free(pos);

	return 0;
}
