#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinctand in decreasing order, and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 

int nrr(int a[5])
{  
	int b=0;
	for (int i = 1; i <= 4; i++)
	{
		b = b * 10 + a[i];
	}
	return b;
}

int nrtwofour(int a)
{
	int b=0;
	while (a > 0)
	{
		b = b + a % 10;
		a /= 10;
	}
	if (b == 24)
		return 1;
	
	return 0;
}

int condition(int v[])
{
	int nr = nrr(v);
	if (nrtwofour(nr) == 0)
		return 0;

	for (int i = 1; i <= 3; i++)
	{
		if (v[i] <= v[i + 1])
			return 0;
	}

	return 1;
}


void bt(int v[5], int k) {
	if (k == 5) {
		if (condition(v) == 1) {
			for (int i = 1; i <= 4; ++i) {
				printf("%d", v[i]);
			}
			printf("\n");
		}

		return;
	}

	for (int i = 9; i >= 0; --i) {
		if (k == 1 && i == 0) continue;
	
		v[k] = i;
		bt(v, k + 1);
	}
}

int main(int argc, char* argv[]) {
	int v[5];
	bt(v, 1);

	return 0;
}

