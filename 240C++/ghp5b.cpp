//Program that adds each character to the stack and queue simultaneously
//
//Written by Alexandra Gostev
//Program Written April 9, 2018
//Program modified April 11, 2018
//Language: c++
//Compiler g++

#include <iostream>             //needed for cin and cout
#include <string>
#include <queue>
#include <stack>
#include <fstream>      //File Handling ( Allows me to read file(Definition taken from cplusplus.com))
#include <cassert>      //Allows use of assert

using namespace std;

int main (void)
{
	string word;
	stack <char> pali;
	queue <char> palin;
	stack <char> copypali;
	bool same = true;
	int palcount=0;
	string theFile;
	ifstream fileIn;   //Inputs file stream
	cout<<"Please enter the file name "<<endl;  //Asks user for file name
	cin>>theFile;
	fileIn.open(theFile.data());  //Opens the file
	assert(fileIn.is_open());   //Make sure file is opened properly
	while (!(fileIn.eof()))   //Make sure you havent reached the end of the file
	{
		fileIn >> word;
		for(int x=0;x<word.size();x++)
		{
			char a = word.at(x); //at researched on cplusplus.com
			pali.push(tolower(a));
			palin.push(tolower(a));
			copypali.push(tolower(a));
		}
		if(word.size()>1)
		{
			while(!pali.empty())
			{
				if(pali.top()==palin.front())
				{
					//cout << pali.top() << " ";
					//cout << palin.front() << " ";
					same=true;
				}
				else
				{
					same=false;
				}
				pali.pop();
				palin.pop();
			}
			if(same==true)
			{
				cout << "This word is a palindrome"<< endl;
				while(!copypali.empty())
				{
					cout << copypali.top() << "";
					copypali.pop();
				}
				palcount++;
				cout<<endl;
			}
			else
			{
				//cout << "The word is not a palindrome"<< endl;
			}
		}
		else
		{
			//cout << "The word is not a palindrome"<< endl;
		}
	}
	cout << "\nThere are "<<palcount<< " palindromes"<< endl;
	fileIn.close();   //Closes file
	return 0;
}
