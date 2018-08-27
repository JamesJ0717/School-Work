//James Johnson

#include <stdio.h>

void populate ( char [ ][15] , int , int );
void show_it ( char [ ][15] , int , int );
void count_vowels ( char [][15] , int, int);

int  main ( void )

{  
    //ALGORITHM STEP 1: Create a character array with 10 rows 
    //and 15 columns
    char data_array [10][15];   
    int rows = 10 , columns = 15 ;

    //ALGORITHM STEP 2: Populate the array from the designated file
    //using the populate( ) PCF
    populate ( data_array , rows, columns );

    //ALGORITHM STEP 3: Display contents of array as a 2D table
    //using the display( ) PCF  
    show_it (data_array, rows, columns ) ;

    //ALGORITHM STEP 4: Count and then display to the screen the number   
    //of vowels in the array using a PCF.  Vowels are: a, e, i, o, u, y
    //The PCF should list the number of each vowel and the total number
    //of vowels.
    count_vowels(data_array, rows, columns);
  

    //ALGORITHM STEP 5: Terminate
    return ( 0 ) ;


}    


void populate ( char out_array[ ][15] , int in_r , int in_c )
{
    int row = 0 , col = 0 ;
    FILE *data;
    data = fopen( "/home/f/csci/urbanc/ghp17.dat" , "r" ); 
    
    for(row = 0; row < in_r ; row++)  
    {
        for(col = 0 ; col < in_c ; col++)
        {
           fscanf(data, "%c", &out_array[row][col]);
        }
    }
    fclose(data);

    return ;
   
}


void show_it ( char words[][15] , int in_r , int in_c  )
{
    int row = 0, col = 0;

    for (row = 0 ; row < in_r ; row++)
    {
        printf("\n" ) ;
        for(col = 0 ; col < in_c ; col++ )
        {
            printf("%c ", words[row][col] );
        }
    }
    printf("\n\n");
    return ;
}


void count_vowels ( char words[][15], int in_r, int in_c)
{
    int row = 0, col = 0, total_vowels = 0;
    int as = 0, es = 0, is = 0, os = 0, us = 0, ys = 0;
    char vowel = 'B';

    for (row = 0; row < in_r; row++)
    {
        for (col = 0; col < in_c; col++)
        {
            vowel = words[row][col];
            switch(vowel)
            {
		case 'a':
                case 'A':
		  total_vowels++;
		  as++;
		  break;
		case 'e':
                case 'E':
		  total_vowels++;
		  es++;
		  break;
		case 'i':
                case 'I':
		  total_vowels++;
		  is++;
		  break;
		case 'o':
                case 'O':
		  total_vowels++;
		  os++;
		  break;
		case 'u':
                case 'U':
		  total_vowels++;
		  us++;
		  break;
		case 'y':
                case 'Y':
		  ys++;
                  total_vowels++;
                  break;
            }
        }
    }
    printf("\nTotal number of A's: %d \n", as);
    printf("Total number of E's: %d \n", es);
    printf("Total number of I's: %d \n", is);
    printf("Total number of O's: %d \n", os);
    printf("Total number of U's: %d \n", us);
    printf("Total number of Y's: %d \n", ys);

    printf("\nTotal # of vowels: %d \n", total_vowels);

    return;
}
