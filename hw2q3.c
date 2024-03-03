#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 50
void array_sort(int grades[], int size);
void L_histogram(int grades[], char chr);
void R_histogram(int grades[], char chr);
void U_histogram(int grades[], char chr);
void D_histogram(int grades[], char chr);
int get_spaces(int grades[]);
void swap_arrays(int temp[], int grades[], int size);
void send_to_function(int grades[], char axis, char chr);
int max_occurrence(int grades[]);
/// <the main scans the details and send them to the right functions>
int main()
{
	char chr = ' ', axis = ' ';
	int grades[MAX_SIZE] = { 0 };

	printf("Please enter a character:\n");
	scanf(" %c", &chr);
	do {
		printf("Please enter histogram axis:(U/D/R/L)\n");
		scanf(" %c", &axis);
		if (axis != 'U' && axis != 'D' && axis != 'R' && axis != 'L')
			printf("Wrong direction, try again!\n");
	} while (axis != 'U' && axis != 'D' && axis != 'R' && axis != 'L');
	printf("Please enter grades:\n");
	for (int i = 0; scanf("%d", &grades[i]) == 1; i++)

		array_sort(grades, MAX_SIZE);
	send_to_function(grades, axis, chr);


	return 0;
}
/// <the function sorts the array from minimal to maximal>
///
/// </temp is a new array wich I save the minimal to the maximal
/// number in it and then replace it with grades>

void array_sort(int grades[], int size)
{
	int min = grades[0], temp[MAX_SIZE] = { 0 }, cnt = 0;
	for (int i = 0; i + 1; i++)
	{
		if (grades[i] == 0)
			break;
		for (int j = 0; j != -1; j++)
		{
			if (grades[j] == 0 || grades[j] == -1)
				break;
			if (grades[j] < min)
			{
				min = grades[j];
				cnt = j;
			}
		}
		grades[cnt] = 10;
		temp[i] = min;
		min = grades[0];
		cnt = 0;
	}
	swap_arrays(temp, grades, size);
}
//this function swap between two int arrays
//to save the temp array in the grades one
void swap_arrays(int temp[], int grades[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (temp[i] < 1 || temp[i] > 9)
			grades[i] = 0;
		else
			grades[i] = temp[i];
	}
}
/// <this function sends the details to the right function
/// according to the scanned axis>

void send_to_function(int grades[], char axis, char chr)
{
	if (axis == 'L')
		L_histogram(grades, chr);
	else if (axis == 'R')
		R_histogram(grades, chr);
	else if (axis == 'U')
		U_histogram(grades, chr);
	else if (axis == 'D')
		D_histogram(grades, chr);
}
/// <prints the histogram if its left>
///
/// <the function prints row by row the 1 checks how many numbers there are
/// in the sorted array and prints n chars near it
/// <param name="grades"></the sorted array of grades>
/// <param name="chr"></the char we want to print>
void L_histogram(int grades[], char chr)
{
	printf("Histogram: \n");
	int cnt = 0;
	for (int n = 1; n < 10; n++)
	{
		printf("%d ", n);
		for (int j = 0; grades[j] > 0 && grades[j] < 10; j++)
		{
			if (grades[j] == n)
				cnt++;
			for (int c = 0; c < cnt; c++)
				printf("%c ", chr);
			cnt = 0;

		}
		printf("\n");
	}

}
/// <prints the histogram if it's right>
///
/// <the function prints row by row, calculate the most repeated num
/// in the array and the number of spaces before starting printing
/// the chars should be (max_repeation - num_repeation)
/// then the function prints the right spaces and the number
/// <param name="grades"></the sorted array of grades>
/// <param name="chr"></the char we want to print>

void R_histogram(int grades[], char chr)
{
	printf("Histogram: \n");
	int	cnt = 0;
	int spaces = max_occurrence(grades);
	for (int n = 1; n < 10; n++)
	{
		cnt = 0;
		for (int j = 0; grades[j] > 0 && grades[j] < 10; j++)
		{
			if (grades[j] == n)
				cnt++;
		}
		for (int k = 0; k < spaces - cnt; k++)
			printf(" ");

		for (int c = 0; c < cnt; c++)
			printf("%c ", chr);

		printf("%d", n);
		printf("\n");
	}

}
/// <the function prints the histogram if it's up>
///
/// <the function prints the number 1-9 and then put the grades in temp
/// checks if the number 1 exists add to count and change it to 10 and so on>
/// <param name="grades"><the grades array>
/// <param name="chr"><the char we want to print>
void U_histogram(int grades[], char chr)
{
	int temp[MAX_SIZE] = { 0 };
	bool exist = false;
	for (int i = 0; grades[i] > 0 && grades[i] < 10; i++)
		temp[i] = grades[i];
	printf("Histogram:\n1 2 3 4 5 6 7 8 9\n");
	for (int j = 0; j < max_occurrence(grades); j++)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int k = 0; grades[k] > 0 && grades[k] < 10; k++)
			{
				if (temp[k] == i)
				{
					exist = true;
					temp[k] = 10;
					break;
				}
			}
			exist ? printf("%c ", chr) : printf("  ");
			exist = false;
		}
		printf("\n");
	}
}

/// <prints the histogram if it's Down>
///
/// <the function prints row by row, calculate the most repeated num
/// in the array and the number of spaces before starting printing
/// the chars should be (max_repeation - num_repeation)
/// then the function prints the right spaces and the number
/// <param name="grades"></the sorted array of grades>
/// <param name="chr"></the char we want to print>

void D_histogram(int grades[], char chr)
{
	int spaces = max_occurrence(grades);
	int cnt = 0;
	int repeat = spaces;
	printf("Histogram:\n");
	for (int j = 0; j < repeat; j++)
	{
		for (int n = 1; n < 10; n++)
		{
			for (int i = 0; grades[i] > 0 && grades[i] < 10; i++)
			{
				if (grades[i] == n)
					cnt++;
			}
			if (cnt >= spaces)
				printf("%c ", chr);
			else
				printf("  ");
			cnt = 0;
		}
		spaces--;
		printf("\n");
	}
	printf("1 2 3 4 5 6 7 8 9");
}
/// <the func gets the most common grade>
///
/// <checks all the grades and count them and calculate  the max cnt>
/// <param name="grades"></param>
/// <returns></return how many times the most common grades apperead>
int max_occurrence(int grades[])
{
	int max_rep = 0;
	for (int i = 0; grades[i] > 0 && grades[i] < 10; i++)
	{
		int cnt = 0;
		if (grades[i] != grades[i - 1])
		{
			for (int j = 0; grades[j] > 0 && grades[j] < 10; j++)
			{
				if (grades[j] == grades[i])
					cnt++;
			}
			if (cnt > max_rep)
				max_rep = cnt;
		}
	}
	return max_rep;
}