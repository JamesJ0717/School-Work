/*
 Programmer: James Johnson	Date Completed: January 26, 2017
 Instructor: Christopher Urban	Class: CS108

 Graded Homework Problem #5



 1. Introduce the program
 2. Prompt user for height of a cylinder.
 3. Record height of cylinder.
 4. Prompt user for radius of a cylinder.
 5. Record radius of cylinder.
 6. Calculate volume of cylinder (pi * height * (radius * radius))
 7. Display original values.
 8. Display the volume.
 9. End. 
*/

// Standard Output and Input functions in C
#include <stdio.h>
// Declare variable PI as a constant 
#define PI 3.141593

int main(void)
{
	//initiating variables
	float radius = 0.0, height = 0.0, volume = 0.0;
	
	//1. Describe the program
	printf("This program will calculate the volume of a cylinder you describe.\n\n");

	//2. Ask user for radius of a cylinder.
	printf("Please enter the radius of the cylinder in inches:\n");
	//3. Record radius
	scanf("%f", &radius);

	//4. Ask user for height of a cylinder.
	printf("Please enter the height of the cylinder in inches:\n");
	//5. Record height
	scanf("%f", &height);

	//6. Calculate the volume of a cylinder
	//Volume = PI * height * radius^2
	volume = PI * height * (radius * radius);

	//7. Display to user original inputs
	printf("The radius of the cylinder is %.2f, and the height is %.2f.\n", radius, height);

	//8. Display the volume of the cylinder in cubic inches
	printf("The volume of the cylinder is %.2f cubic inches.\n\n", volume);

	//9. End 
	printf("Have a good day. Bye!\n");

	return(0);
}
