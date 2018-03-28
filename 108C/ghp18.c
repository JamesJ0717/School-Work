//James Johnson
#include <stdio.h>

void populate ( int [ ][15] , int , int );
void show_it ( int [ ][15] , int , int );
void check_it(int [][15], int, int);

int  main ( void )

{  
    //ALGORITHM STEP 1: Create a character array with 10 rows 
    //and 15 columns
    int data_array [10][15];   
    int rows = 10 , columns = 15 ;

    //ALGORITHM STEP 2: Populate the array from the designated file
    //using the populate( ) PCF
    populate ( data_array , rows, columns );

    //ALGORITHM STEP 3: Display contents of array as a 2D table
    //using the display( ) PCF  
    show_it (data_array, rows, columns ) ;

    //ALGORITHM STEP 4: Determine the number of horizontal pairs
    //that exist in the data file which was copied into the 2D array.
    //For example, the first two numbers on line number 1 are 3 and 3
    //which is a horizontal pair.  Develop a Programmer Created 
    //Function (PCF) which determines the total number of horizontal 
    //pairs and prints a message to the screen communicating the
    //total number of horizontal pairs to the user.
    check_it(data_array, rows, columns);  

    //ALGORITHM STEP 5: Terminate
    return ( 0 ) ;


}    


void populate ( int out_array[ ][15] , int in_r , int in_c )
{
    int row = 0 , col = 0 ;
    FILE *data;
    data = fopen( "/home/f/csci/urbanc/ghp18.dat" , "r" ); 
    
    for(row = 0; row < in_r ; row++)  
    {
        for(col = 0 ; col < in_c ; col++)
        {
           fscanf(data, "%d", &out_array[row][col]);
        }
    }
    fclose(data);

    return ;
   
}


void show_it ( int data_array[][15] , int in_r , int in_c  )
{
    int row = 0, col = 0;

    for (row = 0 ; row < in_r ; row++)
    {
        printf("\n" ) ;
        for(col = 0 ; col < in_c ; col++ )
        {
            printf("%d ", data_array[row][col] );
        }
    }
    printf("\n\n");
    return ;
}


void check_it( int data_array[][15] , int in_r, int in_c)
{
    int row = 0, col = 0;
    int num = 0, num2 = 0;
    int total_pairs = 0;
    
    for (row = 0; row < in_r; row++)
    { 
        for (col = 0; col < in_c; col++)
        {
	    if (col != 0)
		num2 = data_array[row][col-1];

	    num = data_array[row][col];
	    if (num == num2)
            {
		total_pairs++;
       	    }
        }
    }
    
    printf("\nTotal number of pairs: %d\n", total_pairs);

    return;
}


