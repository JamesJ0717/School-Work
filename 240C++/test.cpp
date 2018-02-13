#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	double years[6][3] = {2100000, 1400000, 900000, 
							0, 0, 0, 
							0, 0, 0, 
							0, 0, 0, 
							0, 0, 0,
							0, 0, 0};
	double change[3][3] = {.011, .003, .007,
						   .001, .012, .003,
						   .002, .006, .013};


	// for (int x = 0; x < 6; x++)
	// {
	// 	cout<<endl;
	// 	for (int y = 0; y < 3; y++)
	// 	{
	// 		printf("|%.3f\t\t", years[x][y]);
	// 		printf("|%.3f\t\t", change[x][y]);

	// 	}
	// }

	//cout<<endl;
	for (int x = 0; x < 5; x++)
	{
		cout<<endl;
		for (int y = 0; y < 3; y++)
		{
			//printf("%-.3f\t\t", years[x][y]);
			//printf("|%-.3f\t\t", change[4][4]);
			double newPop = (years[x][y] + (years[x][y]*change[0][y]) + (years[x][y]*change[1][y]) + (years[x][y]*change[2][y]));
			printf("%-.3f\t\t", (years[x][y]*change[0][y]) + (years[x][y]*change[1][y]) + (years[x][y]*change[2][y]));
			years[x+1][y] = newPop;
		}
	}

	cout<<endl;
	
	for (int x = 0; x < 6; x++)
	{
		cout<<endl;
		for (int y = 0; y < 3; y++)
		{
			printf("%.3f\t\t", years[x][y]);
		}
	}

	return 0;

}