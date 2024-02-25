### 2024.02.12
# **Prime Algorithm - version_03**

## 1. code
 ```c
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() 
{
	int32_t prime[1001];
	int32_t cnt = 0;
	int32_t num;
	
	printf("enter the integer : ");
	scanf("%d", &num);


	for (int32_t i = 0; i <= num; i++) {
		prime[i] = i;
	}

	// 본인을 제외한 배수들을 0으로 만들기
	for (int32_t i = 2; i <= sqrt(num); i++) {
		if (prime[i] != 0) {
			for (int j = 2 * i; j <= num; j += i)
			{
				prime[j] = 0;
			}
		}
	}

	for (int32_t i = 2; i <= num; i++){
		if (prime[i] != 0){
			printf("%d\n", prime[i]);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
 ```
***

## 2. output
![!\[alt text\](image-4.png)](prime_03.png)
***

## 3. Analysis
### How to approach
The sieve method of Eratosthenes was used. Modify all multiples of 2 except for yourself to zero. Because 3 of the remaining numbers is prime, modify all multiples of 3 except for yourself to zero. Repeat this process. Outputting nonzero numbers yields prime numbers.

### Pros and Cons
For example, if a user enters 100, the repetition does not go to 100, but only to the square root of 10. Therefore, it has advantages of tremendous efficiency and fast time.
