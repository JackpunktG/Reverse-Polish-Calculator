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
		printf("%d - digit1\n", digit1);
		printf("%d - digit2\n", digit2);
		printf("%c - operator\n", operator_sign);
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

void clear_input_buffer() {						//clearing buffered inputs
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
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


	printf("The most basic version, only input two digits followed by operators... danke des!!!\n\n");
	while ((c = getchar()) != EOF) {
		printf("in while\n");
		if (c >= '0' <= '9') {

			printf("%d - digit_count\n", digit_count);
			printf("%d - digit_index\n", digit_index);
			if (digit_count > 0) {
				hold_value = digit[digit_index];
				printf("%d - digit[digit_index]\n", digit[digit_index]);
				digit[digit_index] = (pow(10, digit_count) * (c - '0'));
				digit[digit_index] += hold_value;
				digit_count++;
				printf("%d - digit\n", digit[digit_index]);

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
			printf("operator\n");
		}
		if (c == ' ' || c == '\t') {
			digit_count = 0;
			digit_index++;
			printf("' '\n");
		}
		if (c == '\n') {
			break;
		}
	}
	sum = rpc(digit, operator, digit_count);
	printf("%d", sum);
}
