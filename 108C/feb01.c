#include <stdio.h>

double fahrenheit = 0.0 ;
double celsius = 0.0 ;

void intro_msg(void);
double get_input(void);
double get_calc(double);
void display_results(double, double);

int main(void)
{
	//1. Introduce the program
	intro_msg();

	//2. Prompt user to enter the degrees in Fahrenheit
	//get_input();

	//3. Read the users input for degrees in Fahrenheit
	fahrenheit = get_input();

	//4. Perform conversion calculation using this formula
	// celsius = 5/9 * (fahrenheit - 32)
	celsius = get_calc(fahrenheit);

	//5. Display results
	display_results(fahrenheit, celsius);

	//6. Sign off with user
	printf("Good bye.\n\n");

	//7. Terminate
	return(0);
}

void intro_msg(void)
{
	printf("This program converts degrees fahrenheit to degrees celsius.\n");
	printf("Hope you find it useful.\n");
	return;
}

double get_input(void)
{
	printf("Please enter the temperature in degrees fahrenheit: ");
	scanf("%lf", &fahrenheit);
	return(fahrenheit);
}

double get_calc(double fahrenheit)
{
	celsius = 5/9 * (fahrenheit - 32);
	return(celsius);
}

void display_results(double fahrenheit, double celsius)
{
	printf("The temperature, %.2lf, in Fahrenheit would be %.2lf in Celsius.\n", fahrenheit, celsius);
	return;
}

