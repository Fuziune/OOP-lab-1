#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tests.h"


// Substitution cipher or Caesar’s cipher.
// This program which reads a natural number n and a string s. The string s is encoded using Caesar’s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.


// DO NOT CHANGE THE SIGNATURE OF THIS METHOD

	
	// TODO your code here
	// add your encryption code here. the string s will be modified in place, using a displacement of n
void encrypt(char s[], int n) {
	char p = 'a', l = 'a';
	int o, i;
	for (i = 0;i <= strlen(s)-1;i++)
	{
		o = n;
			if (s[i] >= 'a' && s[i] <= 'z') {
				p = s[i];
				p = p + o;
				if (p < 0)
					p = -p;
				//printf("%d", s[i]+o);
				//printf("\n");
				if (s[i]+o > 'z')
					p = 'a' + (o - ('z' - s[i]))-1;
				if (p<'a')
					p = 'z' - ('a'-p - 1);
				
				
					s[i] = p;
				
			}
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				p = s[i];
				p = p + o;
				if (p < 0)
					p = -p;
				if (p > 'Z')
					p = 'A' + (p  - 'Z' - 1);
				if (p < 'A')
					p = 'Z' - ('A' -p - 1);
				
					s[i] = p;
				
				}

			}
		
	}


int main()
{
	int n,a;
	printf("n=");
	scanf("%d", &n);
	scanf("%d", & a);
	char s[300];
	scanf("%[^\n]s", s);
	encrypt(s, n);
	printf("encrypt string= %s", s);

	// To enable the tests, ctrl+click on ENABLE_TESTS (or go to the file "tests.h") and change the line
	// #define ENABLE_TESTS 0
	// to:
	// #define ENABLE_TESTS 1
#if ENABLE_TESTS > 0
	run_tests(true);
#endif
	
	// TODO your code here
	return 0;
}