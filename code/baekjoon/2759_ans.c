#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//@brief		 find the largest value in the array whose size is 'num'
int 
max_idx(const int32_t* pancakes, const int32_t num) {
	int32_t idx = 0;
	for (int32_t i = 1; i < num; i++) {
		if (pancakes[i] >= pancakes[idx]) {
			idx = i;
		}
	}
	return idx;
}

//@brief		 flip the array whose size is 'num'
void
flip(int32_t* pancakes, const int32_t num)
{
	int32_t temp = 0;
	for (int32_t i = 0; i < num/2; i++) {
		temp = pancakes[i];
		pancakes[i] = pancakes[num - 1 - i];
		pancakes[num - 1 - i] = temp;
	}
	return;
}

//@brief		sort array to be ascending
void 
sort(int32_t* pancakes, int32_t num) {
	int32_t cnt = 0;
	int32_t idx[100];

	for(int i = num; i>1; i--){ 
		int32_t max = max_idx(pancakes, i);

		if (max != i-1) {
			if (max != 0) {
				flip(pancakes, max + 1);
				idx[cnt] = max + 1;
				cnt++;
			}

			flip(pancakes, i);
			idx[cnt] = i;
			cnt++;
		}
	}

	printf("%d ", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", idx[i]);
	}
	printf("\n");

}

int main(void) {
	int32_t T = 0;
	scanf("%d", &T);

	while (T--) {
		int32_t num;
		scanf("%d", &num);

		int32_t* pancakes = calloc(num, sizeof(int32_t));
		memset(pancakes, 0, num * sizeof(int32_t));

		for (int32_t i = 0; i < num; i++) {
			scanf("%d", &pancakes[i]);
		}

		sort(pancakes, num);
	}

	return 0;
}
