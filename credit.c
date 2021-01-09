/***************************************************************************
 * Assignment: Lab 3
 * 
 * @file    credit.c
 * @brief   Geometry Calculator
 * @author  Jennifer Quay Minnich
 * @date    Sept 24, 2020
 * 
 * @brief Luhn's Algorithm
 *
 * @details Using Luhn's Algorithm to test credit card validity from user's input.
 * Converted a character array (string) to an integer. 
 *
 * @bug none
 *
 * @todo none
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1
#define SIZE 32

//function prototypes
void convert_card(int card[], char num[], int num_digits);
int calculate_algorithm(int card[], int size);
void print_card(int card[], int size, int answer);

int main(void)
{
	int card[NUM_DIGITS];
	
	/* use visa to store the credit card number from stdin */
    char visa[SIZE + 1];

	//user input
	printf("Enter card number: "); 
	fgets(visa, SIZE, stdin);
	sscanf(visa, "%d", &card);

	//string to and int	
	convert_card(card, visa, NUM_DIGITS);

	//algorithm
	int answer;
	answer = calculate_algorithm(card, NUM_DIGITS);

	//prints card and confirms if valid
	print_card(card, NUM_DIGITS, answer);

	return 0;

}

void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';
		num = atoi(card);

}

int calculate_algorithm(int card[], int size)
{
	int i = 0;
	int presum[15];
	int presum1[15];
	int digit1 = 0;
	int digit2 = 0;
	int sum = 0;
	int answer = 0;
	for (i = 0; i < 16; i++){
		if((i % 2)==0){
			if((card[i] *2) < 10){
				presum[i] = card[i] * 2;
			}
			else{
			presum1[i] = card[i] * 2;
			digit1 = presum1[i]/10;
			digit2 = presum1[i] % 10;
			presum[i] = digit1 + digit2;
			}
		}
		else{
			presum[i]=card[i];
		}
	sum = sum + presum[i];
	}
	digit2 = sum % 10;
	if(digit2==0)
	{
		answer = 0;
	}
	else
	{
		answer = -1;
	}
	return answer;
}


void print_card(int card[], int size, int answer)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);

		if(answer==0)
		{
			printf("Card is Valid\n");
		}
		else
		{
			printf("Card is NOT Valid\n");
		}

}

