#include <stdio.h> //9.c

int main(void) 
{ 
	FILE *scores_ptr ; 
	int score_array[10] ;
	int x = 0; 
	scores_ptr = fopen("test_scores.dat" , "r"); 
	if(scores_ptr == NULL) 
	  	printf("\n\ntest_scores.dat was not properly opened.\n");
      else
		{
		         for(x = 0 ; x < 10 ; x++ ) 
		         { 
			fscanf(scores_ptr ,"%d" , &score_array[x]); 
 		         } 
		         fclose(scores_ptr); 
                         for(x = 0 ; x < 10 ; x++ )
		               printf("Exam #%d score is %d \n", x + 1, score_array[x]); 
		}
	return(0); 
} 

