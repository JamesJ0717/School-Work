#include <stdio.h>

/* Algorithm:
Step 1. Create structure named student, use typedef to call it stdnt
Step 2. Initialize 1D array of struct student to hold 10 instances
Step 3. Populate each instance of student from specified file
  3a. Open file 
  3b. Read data from file
    3b1. Store data in element of struct student
  3c. Close file
Step 4. Get the average test score for each student
  4a. Take each test score from each student and add them together
  4b. Take the total and divide by number of tests
  4c. Store the average in the element of student for each instance
Step 5. Display information from each student
  5a. Display header information
  5b. Show each data from each element of each instance, one at a time
Step 6. Terminate
*/
  
//Declare Structure named student with typedef stdnt
typedef struct student
{
  //Declare string element last_name length of 20
  char last_name[20];
  //Declare 4 Test score elements of type int
  int test_1;
  int test_2;
  int test_3;
  int test_4;
  //Declare test_average element of type float
  float test_average;
}stdnt;

//Prototypes
void populate(stdnt *);
void averager(stdnt *);
void show_it(stdnt *);

int main(void)
{
  //Initialize 1D array holding 10 instances of struct student
  stdnt student[10];
  
  int i = 0;
  //PCF to fill the elements of student for each instance
  populate(student);
  //PCF to calculate the average test score for each instance
  averager(student);
  //PCF to display the array's information
  show_it(student);

 
  return 0;
}

void populate(stdnt *student_ptr )
{
  //Create file data type
  FILE *fp;
  
  //Open a file at this location and store it to the file data type
  fp = fopen("/home/f/csci/urbanc/ghp99.dat", "r");
  
  int i = 0; 
  //Loop to fill each instance of struct student
  for (i = 0; i < 10; i++)
  {
    //Read from the file and store data elements into the elements of
    //each instance of student
    fscanf(fp, "%s %i %i %i %i", &student_ptr[i].last_name,
      &student_ptr[i].test_1, &student_ptr[i].test_2, 
      &student_ptr[i].test_3, &student_ptr[i].test_4);
  }

  return;  
}

void averager(stdnt *student_ptr)
{
  int total = 0;
  
  int i = 0;
  //Loop to calculate average for each instance of student
  for (i = 0; i < 10; i++)
  {
    //Take the data from each element from 1 instance at a time
    //and add them together
    total = (student_ptr[i].test_1 + student_ptr[i].test_2 +
      student_ptr[i].test_3 + student_ptr[i].test_4);
 
    //Take the total and divide by 4 to get the average
    //and store in the element test_average 1 instance at a time
    student_ptr[i].test_average = (total / 4);
  }
  return;
}

void show_it(stdnt *student_ptr)
{
  int i = 0;

  //Show Header information
  printf("Student Name\t Test 1\t Test 2\t Test 3\t Test 4\t Test Average\n");

  //Loop to show data from each element from each instance
  for (i = 0; i < 10; i++)
  {
    //Show data from each element in each instance one at a time
    printf("%s\t\t %i\t %i\t %i\t %i\t %.2f\n", student_ptr[i].last_name,
      student_ptr[i].test_1, student_ptr[i].test_2, student_ptr[i].test_3, 
      student_ptr[i].test_4, student_ptr[i].test_average);   
  }
  
  return;
}

