#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int serach_idx(const int a[], int n, int key, int idx[]) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			idx[j++] = a[i];
		}
	}
	return j;
}

int main() {
	int n, key;
	printf("size of array : ");
	scanf("%d", &n);
	int *a = calloc(n, sizeof(int));
	int* idx = calloc(n, sizeof(int));

	if (a == NULL) {
		printf("fail to allocate memory\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {

		printf("x[%d] : ", i);
		scanf("%d", &a[i]);
	}

	printf("key : ");
	scanf("%d", &key);

	int num_of_key = serach_idx(a, n, key, idx);	
	printf("output : %d", num_of_key);
	return 0;
}
