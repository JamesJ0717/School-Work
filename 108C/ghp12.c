//James Johnson
#include <stdio.h>

int main(void)
{
	//Initiate Variables
	double temperature = 0.0;
	double highTemperature = 0.0;
	double mildTemperature = 0.0;
	double coldTemperature = 0.0;
	double averageTemperature = 0.0;
	int highestTemp = 0;
	int lowestTemp = 1;
	int totalTemp = 0.0;
	int highTempCounter = 0;
	int mildTempCounter = 0;
	int coldTempCounter = 0;
	int dayCounter = 0;

	//1. Greet user
	printf("Hello.\n");
	
	//2. Display the function of program
	printf("Please enter all temperatures in degrees Fahrenheit.\n");
	printf("When you are done, enter '-50'.\n");
	
	while(temperature > -50)
	{
		//3. Ask user to enter the high temperature in degrees F
		printf("Enter a high temperature: ");
	
		//4. Record the input
		scanf("%lf", &temperature);
		
		//5. As long as the temperature is logical
		if(temperature > -49 && temperature < 150)
		{	
			//6. Add the input to a category
			//6a. If the temperature is above 80F,
			//store in highTemperature
			//and increment highTempCounter
			if (temperature >= 80)
			{
				highTemperature = temperature;
				highTempCounter++;
			}
	
			//6b.If the temperature is between 50 and 79 inclusive
			//store in mildTemperature
			//and increment mildTempCounter
			else if (temperature >= 50 && temperature <= 79)
			{
				mildTemperature = temperature;
				mildTempCounter++;
			}
	
			//6c. If the temperature is less then 50F,
			//store it in coldTemperature 
			//and increment coldTempCounter
			else if (temperature < 50)
			{
				coldTemperature = temperature;
				coldTempCounter++;
			}
			
			//7. Check to see if the newest input is
			//greater than the previous high
			// If true store highest temperature
			if (temperature > highestTemp)
			{
	 			highestTemp = temperature;
			}
			
			//8. Check to see if the newest input is 
			// less than the previous high
			// if true store lowest temperature
			else if (temperature < lowestTemp)
			{
				lowestTemp = temperature;
			}
	
			//9. Increment dayCounter
			dayCounter++;

			//10. Add the temperature to a running total
			totalTemp = totalTemp + temperature;		
	
			//11. Calculate the average high temp
			averageTemperature = totalTemp / dayCounter;		
		}	
	}
	//12. Display results
	printf("\nNumber of High Temperature Days: %d", highTempCounter);
	printf("\nNumber of Mild Temperature Days: %d", mildTempCounter);
	printf("\nNumber of Cold Temperature Days: %d", coldTempCounter);
	
	printf("\nThe average high temperature: %.2lf", averageTemperature);
	printf("\nThe highest temperature entered: %d", highestTemp);	
	printf("\nThe lowest temperature entered: %d\n", lowestTemp);
	
	return(0);
}
