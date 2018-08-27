/*
 * Programmer: James Johnson	Date Completed: January 26, 2017
 * Instructor: Christopher Urban	Class: CS108
 *
 * Graded Homework Problem #5
 *
 */

// Standard Output and Input functions in C
#include <stdio.h>
// Declare variable PI as a constant 
#define PI 3.141593

int main(void)
{
	//initiating variables
	double radius = 0.0, height = 0.0, volume = 0.0;

	//ask user for radius and height of a cylinder
	printf("Please enter the radius and height of the cylinder:\n");
	scanf("%lf%lf", &radius, &height);

	//calculate the volume of a cylinder
	//Volume = PI * height * radius^2
	volume = PI * height * (radius * radius);

	//display to user original inputs
	printf("The radius of the cylinder is %.2lf, and the height is %.2lf.\n", radius, height);

	//display the volume of the cylinder in cubic inches
	printf("The volume of the cylinder is %.2lf cubic inches.\n\n\n", volume);

	return(0);
}
