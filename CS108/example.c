#include <stdio.h>

//Step 1. Create a struct called student that holds 6 components.
typedef struct student{

   char last_name[10];
   float test_1;
   float test_2;
   float test_3;
   float test_4;
   double test_average;
   } stdnt; 


//Step 4. Create a prototype for the populate function to
//	  give a "heads up" to carve out some memory for a
//	  type struct and a type int variable.
void populate(stdnt qqq[], int);


//Step 9. Create a prototype for the averager function
//        giving a heads up to RAM to carve out some
//	  memory for type struct and a type int variable later.
void averager(stdnt qqq[], int);


//Step 14. Create a protoptype for the show_it function
//         giving a heads up to RAM to carve out some
//	   memory for type struct and a type int variable later.
void show_it(stdnt qqq[], int);


	int main (void)
{ 
    	int i=0;
    	int row=10;
  
    	//Step 2. Create an array of structs called qqq that
   	//	  holds 10 instances of the struct called student. 
   	 	stdnt qqq[10];



  	//Step 3. Call the function populate that passes
 	//         the array qqq and the variable row 
	//	   whitch holds the value 10.
 		populate(qqq, row);



  	//Step 8. Call the function averager that
 	//	  passes the array of structs and the variable
	//        row whitch holds the value 10.	
  		averager(qqq , row);


	//Step 13. Call the function show_it that passes
	//         the array of structs and the variable
	//	   row witch holds the value 10.
  		show_it(qqq , row);

 		return 0 ; 
	 
}
	
	

	   // Step 5. Create a declaration for the populate function
	   //         that allocates some memory in RAM for an array of
  	  //          structs and an int variable.
  	 void  populate(stdnt qqq_p[], int row)
   	{
      	//Step 5.1 Create an int variable named i for use in a for loop.
     	 int i=0;
     
     	 // Step 6. Use the special FILE word and pointer variable qwerty
     	//          to lay foundatition for reading a file.
  	    	 	FILE *qwerty; 
  
     	 // Step 6.1 Open a file from the c directory
     	//           to be read and store it in qwerty. 
               
             qwerty=fopen("/home/f/csci/urbanc/ghp99.dat","r"); 
		
		//Step 6.1 These statemesnt check if the file was opened correctly and alearts the user.
		if(qwerty == NULL)
	 	   printf("\n\n/home/f/csci/urbanc/ghp99.dat was not properly opened\n");	
		else
	       	   printf("\n\n/home/f/csci/urbanc/ghp99.dat was opened in read mode.\n");
		 

      
     	// Step 6.2 Use a for loop to read the values from the file
    	//          into each element of the array qqq.
	
		for(i=0;i<row;i++)

		{
	        fscanf(qwerty, "%s %f %f %f %f",
				 &qqq_p[i].last_name,
				 &qqq_p[i].test_1,
				 &qqq_p[i].test_2,
				 &qqq_p[i].test_3,
				 &qqq_p[i].test_4);
		}
			
	
     	 //Step 6.3 Close the file.
		fclose(qwerty);

		//Step 7. Return Control back to the calling environment.
		return;   
   	}
	


    	 //Step 10. Create the funtion declaration for the averager
    	//          function that allocates momory in RAM for the
  	//          the structured array qqq and an int variable row.
   	void averager(stdnt qqq_p[], int row)
     	{
        	//Step 10.1 Create a counting variable of type int
	        //          for use in a for loop.
		int j=0;

		// Step 11. This for loop adds up the tests in each instance of 
       	       //           the array of structs called student and calculates
      	      //            their average. Then it stores the average in each 
    	     //             instance of student.
		for(j=0;j<row;j++)
		{
		 qqq_p[j].test_average = (qqq_p[j].test_1 + qqq_p[j].test_2 + qqq_p[j].test_3 + qqq_p[j].test_4)/4.0;
    			
		
		}
				
 
		//Step 12. Return Control to the calling environment.
		return; 

     	}

     	//Step 15. Function declaration for the show_it function
       //          that allocates memory in RAM for the array of structs
      //           called qqq and an int variable called row.
    	void show_it(stdnt qqq_p[], int row)
     	{
		//Step 16. Declare an int variable i for a for loop.
		int i=0;
        	
		//Step 17. Displays to the screen Last Name Test 1 Test 2 Test 3
	       //          Test 4 Test Average separated by tabs.
           	printf("\n\nLast Name \t\t Test 1 \t Test 2 \t Test 3 \t Test 4 \t Test Average");
		
		//Step 18. A loop is used to print from the array of structs, student,
		//         the last name, 4 tests, and the test average of 10 students.
             	for(i=0;i<row;i++)
	       	{
		printf("\n\n %s \t\t\t %f \t %f \t %f \t %f \t %lf \n\n\n ", 
			
		      qqq_p[i].last_name,
		      qqq_p[i].test_1,
 		      qqq_p[i].test_2,
		      qqq_p[i].test_3,
		      qqq_p[i].test_4,
		      qqq_p[i].test_average);


					
               }
		//Step 19. Return control to the calling environment.
		return;
     	}	

		

	
