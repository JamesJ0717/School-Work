#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compress(void);
void decode(void);

int main(void)
{
	int choice = 0;

	cout<<"what would you like to do?\n";
	cout<<"1: Compress\n";
	cout<<"2: Decode\n";
	cin>>choice;

	switch(choice)
	{
		case 1:
			compress();
			break;
		case 2:
			decode();
			break;
	}
	return 0;
}

void compress(void)
{
	ifstream theFile;
	ofstream newFile;
	string userFile;
	string userOutFile;
	char ch;

	cout<<"Please enter the file to compress: ";
	cin>>userFile;

	cout<<"Please enter new file: ";
	cin>>userOutFile;

	theFile.open(userFile);
	newFile.open(userOutFile);

	while(!theFile.eof())
	{
		ch = theFile.get();
		//cout<<int(ch%26)<<" ";
		newFile<<ch%26;
	}

	newFile.close();
	theFile.close();

	return;
}

void decode(void)
{
	ifstream theFile;
	ofstream newFile;
	string userFile;
	string userOutFile;
	char ch;

	cout<<"Please enter the file to decode: ";
	cin>>userFile;

	cout<<"Please enter new file: ";
	cin>>userOutFile;

	theFile.open(userFile);
	newFile.open(userOutFile);

	while(!theFile.eof())
	{

		ch = theFile.get();
		if(ch == ' ')
		{
			continue;
		}
		else
		{
			cout<<char(ch*26);
			newFile<<char(ch*26);
		}
		
		
	}

	newFile.close();
	theFile.close();
	

	return;
}