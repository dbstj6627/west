#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int cnt = 0;

void set(int* a, int* b, int* c, int* pos, int n, int i) {
	for (int j = 0; j < n; j++) {
		if (!a[j] && !b[i + j] && !c[i - j + n - 1]) {
			assert(i < n);
			pos[i] = j;
			if (i == n - 1) {
				cnt++;
				return;
			}
			else {
				assert(i+j < 2*n-1);
				a[j] = b[i + j] = c[i - j + n - 1] = 1;
				set(a, b, c, pos, n, i + 2);
				assert(i+j < 2*n-1);
				a[j] = b[i + j] = c[i - j + n - 1] = 0;
			}
		}
	}

	return;
}

int main() {
	int n;
	scanf("%d", &n);

	if (n <= 3 || n >= 15) {
		return 1;
	}

	int* a = calloc(n, sizeof(int));
	int* b = calloc(2*n-1, sizeof(int));
	int* c = calloc(2 * n - 1, sizeof(int));
	int* pos = calloc(n, sizeof(int));
	memset(a, 0, sizeof(int) * n);
	memset(b, 0, sizeof(int) * (2*n-1));
	memset(c, 0, sizeof(int) * (2*n-1));
	memset(pos, 0, sizeof(int) * (n));


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
