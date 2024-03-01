#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//const int32_t MAX_CNT = 30;

static int32_t cnt = 0;
static int32_t num_of_change = 0;
static int32_t idx[30] = {0};

//@brief		 find the largest value in the array whose size is 'num'
int 
find_max(const int32_t* pancakes, const int32_t num) 
{
	int32_t max = pancakes[0];
	for (int32_t i = 0; i < num; i++) {
		if (pancakes[i] >= max) {
			max = pancakes[i];
		}
	}
	return  max;
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
sort(int32_t* pancakes, int32_t num)
{
	for (int32_t i = 0; i < num; i++) {
		if (pancakes[i] == find_max(pancakes, num-cnt)) {
			// when max is on the top
			if (i == 0) {
				flip(pancakes, (num-cnt));
				idx[num_of_change] = num - cnt;
				cnt++;
				num_of_change++;
				break;
			}
			 // when max is on the bottom
			else if (i == num-1-cnt) {
				cnt++;
				break;
			}
			// when max is neither top nor bottom
			else {
				flip(pancakes, (i + 1));
				idx[num_of_change] = i + 1;
				num_of_change++;
			}
		}
	}
}


//@brief		check if it is ascending
int 
is_ascending(const int32_t* arr, const int32_t size) 
{
	int32_t  val = 0;
	val = arr[0];

//#ifdef __DEBUG
//	for (int16_t i = 0; i < size; i++) {
//		fprintf(stderr, "%d ", *(arr + i));
//	}
//	printf("\n");
//#endif

	for (int32_t i = 1; i < size; ++i) {
		if (val > arr[i]) 
			return 0;
		val = arr[i];
	}
	return 1;
}

int main(void) 
{
	int32_t order = 0;
	scanf("%d", &order);

	while(order--) {
		int32_t num;
		scanf("%d", &num);

		int32_t* pancakes = (int32_t*)calloc(num, sizeof(int32_t));
		memset(pancakes, 0, num * sizeof(int32_t));

		for (int32_t i = 0; i < num; i++) {
			scanf("%d", &pancakes[i]);
		}

		while (!is_ascending(pancakes, num)) {
			sort(pancakes, num);
		}

		// result
		printf("%d ", num_of_change);
		for (int32_t i = 0; i < num_of_change; i++) {
			printf("%d ", idx[i]);
		}
		printf("\n");

		free(pancakes); pancakes = 0;

		cnt = 0;
		num_of_change = 0;
		memset(idx, 0, 30*sizeof(int32_t));
	}
	

	return 0;
}
