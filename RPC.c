#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100			// max number of places

int rpc(int digit[], char operator[], int count)
{
	int  o = 0;	//indexing for digits & Operators
	int digit1, digit2, operator_sign;
	int sum = 0;
	int a = 0;


		digit1 = digit[0];
		digit2 = digit[1];
		operator_sign = operator[1];
		printf("%d - digit1\n", digit1);
		printf("%d - digit2\n", digit2);
		printf("%c - operator\n", operator);
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


	printf("The most basic version, only input two digits followed by operators... danke des!!!\n\n");
	while ((c = getchar()) != EOF) {
		printf("in while\n");
		if (c >= '0' <= '9') {
			if (digit_count > 0)
				digit[digit_index] = digit[digit_index] + (c - '0');
			else
				digit[digit_index] = c - '0';
				digit_count++;
		}
		if (c == '+' || c == '-' || c == '/' || c == '*') {
			operator[operator_index++] = c;
			digit_count = 0;
			digit_index++;
		}
		if (c == ' ' || c == '\t') {
			digit_count = 0;
			digit_index++;
		}
		if (c == '\n') {
			puts(digit);
			digit_count = 0;
			digit_index = 0;
			break;
		}
		sum = rpc(digit, operator, digit_count);
		printf("%d", sum);


	}
}
