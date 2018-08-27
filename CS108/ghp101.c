// John DeRosa CS-108 GHP #10 
#include <stdio.h>
//1 create the prototype for the function greet which accepts no arguments 
//and returns nothing

void greet(void);

//2 create the prototype for the function get_x which takes no argument and returns a 
//float value

float get_x(void);

//3 create the prototype for the function get_y which returns a float and takes no 
//argument

float get_y(void);

//4 create the prototype for the function determine_pt which accepts two float 
//arguments and returns a char value

char determine_pt(float, float);

//5 create the prototype for the function display_result which takes a char 
//argument and reutrns no value 

void display_result(char);

int main(void)
{
	//6 declare the variables x_coordinate, y_coordinate and point_location
	float x_coordinate=0.0,y_coordinate=0.0;
	char point_location;
	
	//7 greet the user by calling the function greet
	
	greet();
	
	//8 prompt the user to enter the x coordinate
	//9 record the users input into the variable x_coordinate
	
	x_coordinate=get_x();
	
	//10 prompt the user to enter the y coordinate
	//11 record the users input into the variable y_coordinate
	
	y_coordinate=get_y(); 
  
	
	//12 determine the points location on the point by running through multiple 
	//tests
	//13 record the points location into the variable point_location
	
	point_location=determine_pt(x_coordinate,y_coordinate);

	//14 print the coordinates location to the user
	
	display_result(point_location); 
	
	//15 terminate the program
	
	return(0);
}


void greet(void)
{ //16 display a what the program does to the user
  
  printf("\n\nHi I determine a points location on a coordinate plane.\n");

  //17 return control to the main function

  return;
}

float get_x(void)
{ //18 create the local variable x_coordinate

  float x_coordinate=0.0;

  //19 prompt the user to enter the x coordinate

  printf("\n\nPlease enter the x coordinate\n");

  //20 record the users input into the variable x_coordinate

  scanf("%f",&x_coordinate);

  //21 return the x_coordinate to the main function

  return(x_coordinate);
}

float get_y(void)
{ //22 create the local variable y_coordinate

  float y_coordinate=0.0;

  //23 prompt the user to enter the y coordinate

  printf("\n\nPlease enter the y coordinate\n");

  //24 record the users input into the variable y_coordiante

  scanf("%f",&y_coordinate);

  //25 return y_coordinate to the main function

  return(y_coordinate);
}

char determine_pt(float x_coordinate, float y_coordinate)
{
  //26 declare the local variable location

  char location;

  //27 test to see if the point is in the 1st quadrant 
  //formula:(x>0 && y>0)
  if (x_coordinate>0 && y_coordinate>0)
  {
   //28 if it lies in the 1st quadrant set loaction to the correct char value
   location=1;
  }
  
  //29 test to see if the point is in the second quadrant
  //formula:(x<0 && y>0)
  else if (x_coordinate<0 && y_coordinate>0)
  {
   //30 if it lies in the second quadrant set loaction to the correct char value
   location=2;
  }

  //31 test to see if the point lies in the third quadrant
  //formula(x<0 && y<0)
  else if (x_coordinate<0 && y_coordinate<0)
  {
   //32 if it lies in the third quadrant set location to the correct char value
   location=3;
  }

  //33 test to see if the point lies in the fourth quadrant
  //formula:(x<0 && y<0)
  else if (x_coordinate>0 && y_coordinate<0)
  {
   //34 if it lies in the fourth quadrant set location to the correct char value
   location=4;
  }

  //35 test to see if the point lies on the x-axis
  //formula:(x==0 && y!=0)
  else if (x_coordinate==0 && y_coordinate!=0)
  {
   //36 if it lies on the x-axis set location to the correct char value
   location='x';
  }

  //37 test to see if the point lies on the y-axis
  //formula:(x!=0 && y==0)
  else if (x_coordinate!=0 && y_coordinate==0)
  {
   //38 if it lies on the y-axis set location to the correct char value
   location='y';
  }

  //40 test to see of the point lies on the origin
  //formula: doesnt fall into any other category
  else
  { //41 if the point is on the origin set location to the correct char value
    location='o';

  }

//42 return locations value to the main function
return(location);
   
}


void display_result(char point_location)
{ //43 create a switch case for each possible location
  
  switch(point_location)
  {
   //44 for the case 1 tell the user the point is in quadrant 1
   case 1: printf("\n\nYour point lies in the first quadrant.\n");
          break;
   //45 for the case 2 tell the user the point is in the second quadrant
   case 2: printf("\n\nYour point lies in the second quadrant.\n");
          break;
   //46 for the case 3 tell the user the point lies in quadrant 3
   case 3: printf("\n\nYour point lies in the third quadrant\n");
          break;
   //47 for the case 4 tell the user that their point lies in quadrant 4
   case 4: printf("\n\nYour point lies in the forth quadrant\n");
          break;
   //48 for the case 'x' tell the user their point lies on the x axis
   case 'x': printf("\n\nYour point lies on the X-axis.\n");
            break;
   //49 for the case 'y' tell the user their point lies on the y axis
   case 'y': printf("\n\nYour point lies on the Y-axis.\n");
            break;
   //50 for the case 'o' tell the user their point is on the origin
   case 'o': printf("\n\nYour point lies on the origin.\n");
            break;
   //51 close the switch statment
   default: printf("unknown location"); 
  }
  //52 close the function returning control to main
  return;

}
