#include <stdio.h>

int main (void)
{
  //Initiating variable
  long long int userNum = 1;
  int prime = 0;
    	
  while (userNum != 0)
  { 
    //1. Ask user to enter a number
    printf("\nPlease enter an integer to test as a prime number");
    printf(" or enter 0 to end: \n");
    //2. Store that number
    scanf("%lli", &userNum);
    
    //3. Test for prime
    //4. Value will be result of primality
    prime = isPrime(userNum);
   
    //5. A zero means the number is not prime.
    if(prime == 0)
    {
      //5a. Tell the user the results
      printf("\nYou entered %lli and %lli is not prime.\n", userNum, userNum);
    }
    //6. A one means the number is prime.
    else if (prime == 1)
    {
      //6a. Tell the user the results
      printf("\nYou entered %lli and %lli is prime.\n", userNum, userNum);
    }
  }
 
  return(0);
}   

//Function to determine the primality of a number
int isPrime(long long int n)
{
  //Initiate local variable
  int i = 0;

  //Use a loop to test each number upto half of one minus the number, 
  //Starting at 2 and incrementing by 1 each loop
  for (i = 2; i < ((n-1)/2); i++)
  {
    //If the result of the testing number modulo half of one minus that number is 0
    //Return a 0
    if(n % i == 0) 
    {  
      return 0;
    }
  }
  //Any other outcome
  //Return a 1
  return 1;
}

