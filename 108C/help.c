#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dis(char (*data_array)[5][6],int, int, int);
void count(char (*data_array)[5][6], int, int, int);

int  main ( void )

{  
    //Local variables created below
    char data_array [4][5][6];   
    int page = 0, row = 0 , col = 0 ;

    //Necessary for random numbers.  Do not change this source code.
    srand ( (unsigned ) time ( 0 ) ) ;
    
    //ALGORITHM STEP 1: Populate the array with random upper-case
    //                  characters.  Do not change this source code.
    for ( page = 0 ; page < 4 ; page++ )
    {
	for ( row = 0 ; row < 5 ; row++ )
	{
	    for ( col = 0 ; col < 6 ; col++ )
	    {
		data_array [ page ] [ row ] [ col ] = rand ( ) % 26 + 65 ;
	    }
	}
    }

    dis(data_array,page,row,col);
    

    //ALGORITHM STEP 3: Develop a PCF to determine the number of z-axis pairs
    //that exist in the 3D array. An example of a z-axis pair would be the
    //letter W appearing at page 1, column 2, row 3 and the letter W
    //appearing at page 2, column 2, row 3. Your PCF  
    //shall print a message to the screen communicating the
    //total number of z-axis pairs.  Before writing 
    //any source-code for your PCF, you need to develop a solid
    //algorithm.  Make sure you test your algorithm using paper and
    //pencil. 
    
    count(data_array,page,row,col);

    //ALGORITHM STEP 4: Terminate
    return ( 0 ) ;


}    

//ALGORITHM STEP 2: Display contents of array as a series of 2D tables
//using a PCF
void dis( char (*data_array)[5][6],int page, int row, int col)
{
   	for ( page = 0 ; page < 4 ; page++ )
   	{
		printf("Page # %d \n",page+1);
        	for ( row = 0 ; row < 5 ; row++ )
        	{
            		for ( col = 0 ; col < 6 ; col++ )
            		{
              		 printf("%c", data_array [ page ] [ row ] [ col ]);
            		}
	   		 printf("\n");
        	}
		printf("\n\n");
   	}
	return;
}  

void count(char (*data_array)[5][6], int page, int row, int col)
{
	int count = 0;


	for (page = 0; page<4; page++)
	{
		for (row=0; row<5; row++)
		{
			for (col=0; col<6; col++)
			{
			 if (data_array[page][row][col] == data_array[page-1][row][col])
			  count++;
			}
		}
	}
	printf("The number of z-axis pairs are %d \n", count);

	return;
}
