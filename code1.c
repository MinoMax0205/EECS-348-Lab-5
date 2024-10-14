#include <stdio.h>

char *Month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

char u_input[20];
int counter = 0;
FILE *file;

float Array[12];

void findMaxMin(float Array[], int size, float *max, float *min, int *maxpos, int *minpos) {
	//Finds the highest and lowest values, as well as their positions for month
	*max = Array[0];
	*min = Array[0];
	*maxpos = 0;
	*minpos = 0;

	for (int i = 1; i < size; i++) {
		if (Array[i] > *max) {
			*max = Array[i];
			*maxpos = i;
		}
		if (Array[i] < *min) {
			*min = Array[i];
			*minpos = i;
		}
	}
}

void SixMonthAverage(float Array[], char *Month[]) {
	//Find the average for each 6 month period up to december
	float sum;
	for (int i = 0; i + 6 < 12; i++) {
		for (int j = i; j < i + 6; j++) {
			sum += Array[j];}
		printf("%s-%s: %.2f\n", Month[i], Month[i+6], sum/6);
       		sum = 0;	}
	printf("\n");
}

void HighToLowViaBubble(float Array[], char *Month[], int size){
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size-1-i; j++) {
			if( Array[i] < Array[j+1]) {
				//Swaps values
				float tempVal = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = tempVal;
				
				//Swaps the name of month to match position
				char *tempMonth = Month[j];
				Month[j] = Month[j+1];
				Month[j+1] = tempMonth;}
		}
	}
}

int main() {
	//Gets input from user
	printf("Enter the name of your Sales-Report File: ");
	scanf("%s",u_input);
	file = fopen(u_input, "r");
	float line;
	
	//Reads the file
	while (fscanf(file, "%f", &line) == 1) {
		Array[counter++] = line;
	}

	//Prints out all sales in Month-order
	printf("Month	     Sales");
	printf("\n");

	for (int i = 0; i < 12; i++) {
		printf("%-12s %-10.2f\n", Month[i], Array[i]);}
	
	printf("\n");
	printf("Sales Summary Report\n");
	
	float max, min;
	int maxpos, minpos;
	int size = sizeof(Array) / sizeof(Array[0]);
	//Calls function to find max and min of sales then prints it out
	findMaxMin(Array, size, &max, &min, &maxpos, &minpos);
	printf("Minimum Sales Value: %.2f	(%s)\n", min, Month[minpos]);
	printf("Maximum Sales Value: %.2f	(%s)\n\n", max, Month[maxpos]);

	printf("Six-Month Moving Average Report: \n");
	
	//Six-month moving report
	SixMonthAverage(Array, Month);

	//Sales report from highest to lowest
	printf("Sales Report (Highest to Lowest):\n\n");
	//Calls function to bubble sort both arrays before printing them.
	HighToLowViaBubble(Array, Month, size);

	for (int i = 0; i < 12; i++) {
		printf("%-12s %-10.2f\n", Month[i], Array[i]);}

	return 0;
}
