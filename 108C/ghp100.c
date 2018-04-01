//Step 1: make all precurserers
//Step 2: Greet User
//Step 3: Ask user for x coordinate
//Step 4: Ask user for y coordinate
//Step 5: With both the x & y coordinates determine which Quadrant the 
//point lies in or if it lies at the origin, x, or y axis
//Step 6: Display result to user
//Step 7: Thank the user
//Step 8: Terminate

#include <stdio.h>
void greet(void);
int get_x(void);
int get_y(void);
int determine_pt(void);
int display_result(void);
int main(void)
{
	int x;
	int y;
	int quadrant;
	greet();
	x = get_x();
	y = get_y();
	quadrant = determine_pt();
	display_result();
}
void greet(void)
{
	printf ("This program will detrmine where a point lies on a plane.\n");
}
int get_x(void)
{
	int result_x;
	printf ("Please enter the X coordinate: ");
	scanf ("%i", &result_x);
	return result_x;
}
int get_y(void)
{
        int result_y;
        printf ("Please enter the Y coordinate: ");
        scanf ("%i", &result_y);
        return result_y;
}
int determine_pt(void)
{
	int x;
	int y;
	int quadrant;
	if (x == 0 && y == 0)
	{
		quadrant = 0;
		return quadrant;
	}
	else
	{
		if (x != 0 && y == 0)
		{
			quadrant = 5;
			return quadrant;
		}
		else
		{
			if (x == 0 && y != 0)
			{
				quadrant = 6;
				return quadrant;
			}
			else
			{
				if (x > 0 && y > 0)
				{
					quadrant = 1;
					return quadrant;
				}
				else
				{
					if (x < 0 && y > 0)
					{
						quadrant = 2;
						return quadrant;
					}
					else
					{
						if (x < 0 && y < 0)
						{
							quadrant = 3;
							return quadrant;
						}
						else
						{
							quadrant = 4;
							return quadrant;
						}
					}
				}
			}
		}
	}
}
int display_result(void)
{
	int quadrant;
	switch (quadrant)
	{
		case 0:
			printf ("The point you entered lies at the origin.\n");
			break;
		case 1:
			printf ("The point you entered lies in Quadrant 1\n");
			break;
		case 2:
			printf ("The point you entered lies in Quadrant 2\n");
			break;
		case 3:
			printf ("The point you entered lies in Quadrant 3\n");
			break;
		case 4:
			printf ("The point you entered lies in Quadrant 4\n");
			break;
		case 5:
			printf ("The point you entered lies on the X-axis\n");
			break;
		case 6:
			printf ("The point you entered lies on the Y-axis\n");
			break;
	}
}
