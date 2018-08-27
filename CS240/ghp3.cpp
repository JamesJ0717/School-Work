#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>

using namespace std;

int main(void)
{
	int count = 0;
	string userFile;
	string word;
	ifstream fileIn;
	char ch;

	cout<<"Please enter name of file: ";
	cin>>userFile;

	fileIn.open(userFile);
	assert(fileIn.is_open() );
	while (!(fileIn.eof()))
	{
		ch = fileIn.get();
		if(ch == '\n' || ch == '"') 
		{
			word.append(1,' ');
		}
		else
		{
			word.append(1, tolower(ch));
		}
	}
	for (int i = 0; i < word.length(); i++)
	{
		if(word.at(i)==' ' && word.at(i+1)=='d')
			count++;

	}
	cout<<count<<endl;

	return 0;
}