#include <stdio.h>

void greet(void);
int get_x(void);
int get_y(void);
char determine_pt(int, int);
void display_result(char);

int main(void)
{
	//Initiate local variables
	int xCoord = 0, yCoord = 0;
	char quad;

	//1. Greet the user
	greet();

	//2. Prompt user to enter an X coordinate
	//3. Record user input and store in variable
	xCoord = get_x();

	//4. Prompt user to enter a Y coordinate
	//5. Record user input and store in variable
	yCoord = get_y();

	//6. Determine where on a cartesian plane the point lies
	quad = determine_pt(xCoord, yCoord);

	//7. Display results to screen
	display_result(quad);

	return(0);
}

void greet(void)
{
	//1. Greet the user
	printf("Hello.\n\n");

	return;
}

int get_x(void)
{
	int funcX = 0;
	
	//2. Prompt user to enter x coordinate
	printf("\nPlease enter the X coordinate: \n");

	//3. Record user input and store in variable
	scanf("%d", &funcX);

	return(funcX);
}

int get_y(void)
{
	int funcY = 0;
	
	//4. Prompt user to enter y coordinate
	printf("\nPlease enter the Y coordinate: \n");

	//5. Record user input and store in variable
	scanf("%d", &funcY);

	return(funcY);
}

char determine_pt(int x, int y)
{
	char funcQuad;

	//6. Determine where on the cartesian plane the point lies
	// If the X coordinate is positive
	// and the Y coordinate is not equal to 0 
	if (x > 0 && y != 0)
	{
		// if the y coordinate is positive
		if (y > 0)
			// set variable equal to 1st quadrant
			funcQuad = 'a';
		
		// if the y coordinate is negative	
		else if (y < 0)
			// set variable equal to 4th quadrant
			funcQuad = 'd';
	}

	// if the x coordinate is negative
	// and the y coordinate is not equal to 0
	else if (x < 0 && y != 0)
	{
		// if the y coordinate is positive
		if (y > 0)
			// set variable equal to 2nd quadrant
			funcQuad = 'b';

		// if the y coordinate is negative
		else if (y < 0)
			// set variable equal to 3rd quadrant
			funcQuad = 'c';
	}

	// if the x coordinate is 0
	else if (x == 0 && y != 0)
	{
		// if the y coordinate is positive
		if ( y > 0)
			// set variable equal to Y axis above X axis
			funcQuad = 'e';

		// if the y coordinate is negative
		else if (y < 0)
			// set variable equal to Y axis below X axis
			funcQuad = 'g';
	}

	// if the y coordinate is equal to 0
	else if (y == 0 && x != 0)
	{
		// if the x coordinate is positive
		if (x > 0)
			// set variable equal to X axis to the right of the Y axis
			funcQuad = 'h';

		// if the x coordinate is negative
		else if (x < 0)
			// set variable equal to X axis to the left of the Y axis
			funcQuad = 'f';
	}

	// if the x coordinate and y coordinate are equal to 0
	else if (x == 0 && y == 0)
	{
		// set variable equal to origin
		funcQuad = 'i';
	}

	return(funcQuad);
}

void display_result(char quadrant)
{
	//Make a switch for the quadrant
	switch(quadrant)
	{
		case 'a':
			//Print result to the screen
			printf("\nThat point is in quadrant 1.\n\n");
			break;
		
		case 'b':
			//Print result to the screen
			printf("\nThat point is in quadrant 2.\n\n");
			break;
			
		case 'c':
			//Print result to the screen
			printf("\nThat point is in quadrant 3.\n\n");
			break;
			
		case 'd':
			//Print result to the screen
			printf("\nThat point is in quadrant 4.\n\n");
			break;
			
		case 'e':
			//Print result to the screen
			printf("\nThat point is on the Y axis above the X axis.\n\n");
			break;
			
		case 'f':
			//Print result to the screen
			printf("\nThat point is on the X axis to the left of the Y axis.\n\n");
			break;
			
		case 'g':
			//Print result to the screen
			printf("\nThat point is on the Y axis below the X axis.\n\n");
			break;
			
		case 'h':
			//Print result to the screen
			printf("\nThat point is on the X axis to the right of the Y axis.\n\n");
			break;

		case 'i':
			//Print result to the screen
			printf("\nThat point is at the origin.\n\n");
			break;
	}
	return;
}
