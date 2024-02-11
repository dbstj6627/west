### 2024.02.12
# **Prime Algorithm - version_03**

## 1. code
 ```c
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
 ```
***

## 2. output
![alt text](image-2.png)
***

## 3. Analysis
### How to approach
Suppose there is a square with area 100.   

If you want to know whether 100 is prime or not, you can try dividing only the length of one side of the square into prime numbers and judge that it is prime if the process is not divided at all.   

The length of one side of this square is 10.   
The prime numbers less than 10 are 2,3,5,7, but 2 and 5 divides 100.   

Thus, 100 is a composite number, not a prime number.

### Pros and Cons
Since the problem is solved using the square root of the integer, the number of calculations is the least compared to previous codes.
