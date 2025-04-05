#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX 100			// max number of places

int rpc(int digit[], char operator[], int count)
{
	int  o = 0;	//indexing for digits & Operators
	int digit1, digit2;
	char operator_sign;
	int sum = 0;
	int a = 0;


		digit1 = digit[0];
		digit2 = digit[1];
		operator_sign = operator[0];
		switch (operator_sign) {
			case '+':
				sum = digit1 + digit2;
				break;
			case '-':
				sum = digit1 - digit2;
				break;
			case '*':
				sum = digit1 * digit2;
				break;
			case '/':
				sum = digit1 / digit2;
				break;
			default:
				printf("Error by switch");
				break;
		}
		return sum;
	
}

int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; i++) {
		p = p * base;
	}
	return p;
}

int main()
{
	int c = 0;
	int digit[MAX];
	char operator[MAX];
	int digit_index = 0;
	int operator_index = 0;
	int digit_count = 0;
	int sum = 0;
	int options = 0;
	int hold_value;


	printf("-- The version1.1 of Jack's RPC -- \nHandling only one calculation at a time, but NOW with multi-digit numbers!!\nInput the numbers and operator with a space in between... danke des :)\n\n");
	while ((c = getchar()) != EOF) {
		if (c >= '0' <= '9') {
			if (digit_count > 0) {
				if (c == ' ' || c == '\t') {
					digit_count = 0;
					digit_index++;
				}
				else {
					hold_value = digit[digit_index];
					hold_value *= 10;
					digit[digit_index] = (c - '0') + hold_value;
					digit_count++;
				}
			}
			else {
				digit[digit_index] = c - '0';
				digit_count++;

			}
		}
		if (c == '+' || c == '-' || c == '/' || c == '*') {
			operator[operator_index++] = c;
			digit_count = 0;
			digit_index++;
		}
		if (c == '\n') {
			break;
		}
	}
	sum = rpc(digit, operator, digit_count);
	printf("%d", sum);
}
