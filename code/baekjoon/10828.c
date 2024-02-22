#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int stack[10000];
int cnt = 0;

void push(int input) {
	stack[cnt] = input;
	cnt++;
}


void pop() {
	if (cnt == 0) {
		printf("%d\n", -1);
	}
	else {
		cnt--;
		printf("%d\n", stack[cnt]);
		stack [cnt]= 0;
	}
}


void size() {
	printf("%d\n", cnt);
}


void empty() {
	if (cnt ==  0) {
		printf("%d\n",1);
	}
	else {
		printf("%d\n", 0);
	}
}

void top() {
	if (cnt == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", stack[cnt - 1]);
	}
}

int main() {
	int num, input;
	char function[10];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", &function);
		if (!strcmp(function, "push")) {
			scanf("%d", &input);
			push(input);
		}
		if (!strcmp(function, "pop")) {
			pop();
		}
		if (!strcmp(function, "size")) {
			size();
		}
		if (!strcmp(function, "top")) {
			top();
		}
		if (!strcmp(function, "empty")) {
			empty();
		}
	}

	

	return 0;
}
