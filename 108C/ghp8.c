# include <stdio.h>

#define pi 3.14159265

void function_1(void);
double function_2(void);
double function_3(void);
double function_4(double height, double radius);
void function_5(int precision, double height, double radius, double volume);

int main( void )
{
      //1. Create variables for height, radius, volume, and precision (formatting)
      double  height =  0.0 ,  radius = 0.0 ,  volume = 0.0  ;    
      int  precision =  2; 

      //2. Describe what the program does
      function_1();

      //3. Ask user for height of cylinder
      //4. Record the user's input for height
      height = function_2();

      //5. Ask user for radius of cylinder
      //6. Record the user's input for radius
      radius = function_3();

      //7. Compute value for volume (formula: pi*height*radius*radius)
      volume =  function_4(height, radius);

      //8. Display user inputs and the volume of cylinder in cubic inches
      function_5(precision, height, radius, volume);

      //9. Terminate
      return (0);
}

void function_1(void) 
{
      //2. Describe what the program does
      printf ("\n\nThis program calculates the volume of a cylinder.\n\n");
      return;
}

double function_2(void)
{
      double height = 0.0;
      //3. Ask user for height of cylinder
      printf ("Enter the height of the cylinder in inches:") ;

      //4. Record the user's input for height
      scanf ("%lf", &height) ;

      return(height);
}

double function_3(void)
{
      double radius = 0.0;
      //5. Ask user for radius of cylinder
      printf ("\n\nEnter the radius of the cylinder in inches:") ;

      //6. Record the user's input for radius
      scanf ("%lf", &radius) ;

      return(radius);
}

double function_4(double height, double radius)
{
      double volume = 0.0;
      //7. Compute value for volume (formula: pi*height*radius*radius)
      volume = pi * height * radius * radius  ; 

      return(volume);
}

void function_5(int precision, double height, double radius, double volume)
{
      //8. Display user inputs and the volume of cylinder in cubic inches
      printf ("\n\nThe volume of a cylinder with\n");
      printf ("a height of %.*lf inches\n", precision, height);
      printf ("and radius or %.*lf\n", precision, radius);
      printf ("is %.*lf cubic inches\n", precision, volume);

      return;
}
