### 2024.02.12
# **Prime Algorithm - version_02**

## 1. code
 ```c
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
 ```
***

## 2. output
![alt text](image-1.png)
***

## 3. Analysis
### How to approach
All even numbers except 2 are synthetic numbers, so add 2 to the decimal array first. 

Then divide 3 or more odd numbers into the elements in the decimal array.

If they are not separated until the end, the number becomes prime numbers

### Pros and Cons
It's faster than the previous algorithm.

*But, fast algorithms require a lot of memory.*
