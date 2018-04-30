#include <iostream>
#include <vector>

using namespace std;

#define N_ARRAY 23

class Hasher
{
    public:
        Hasher() : elementarray(N_ARRAY)
        {
            for(i=0;i<23;i++)
            {
                elementarray[i] = "0";
            }
        }
    void hashThisWord(char firstLetter, char lastLetter, string wordHash)
    {
        sum = firstLetter + lastLetter;
        hashed = sum % 23;
        // cout<<hashed<<"\t"<<wordHash<<"\t";
        if (elementarray[hashed] == "0")
        {
            elementarray[hashed] = wordHash;
        }
        else if(elementarray[hashed] != "0")
        {
            while(i != 1)
            {
                i=0;
                if(hashed>23)
                {
                    hashed=0;
                }
                else
                {
                    hashed++;
                }
                if(elementarray[hashed] == "0")
                {
                    elementarray[hashed] = wordHash;
                    i++;
                }
            }
        }
    }
    void hashChecker(char firstLetter, char lastLetter, string wordHash)
    {
        sum = firstLetter + lastLetter;
        hashed = sum % 23;
        if(elementarray[hashed] == "0")
        {
            cout<<wordHash<<" is not in this list."<<endl;
        }
        else if(elementarray[hashed] != "0")
        {
            if(elementarray[hashed] == wordHash)
            {
                cout<<wordHash<<" was found at position #"<<hashed+1<<" on list."<<endl;
            }
            else
            {
                check = 0;
                while(i!=1)
                {
                    if(hashed>23 && check == 0)
                    {
                        hashed = 0;
                        check = 1;
                    }
                    else
                        hashed++;
                    if (hashed > 23 && check == 1)
                    {
                        cout<<wordHash<<" is not in this list."<<endl;
                        hashed = 0;
                        i++;
                    }
                    if(elementarray[hashed] == wordHash)
                    {
                        cout<<wordHash<<" was found at position #"<<hashed+1<<" on list."<<endl;
                        i++;
                    }
                }
            }
        }
    }
    void display()
    {
        for(i=0;i<23;i++)
        {
            if(elementarray[i] == "0")
            {
                // cout<<elementarray[i]<<endl;
                cout<<i+1<<". "<<"empty"<<endl;
            }
            else
            {
                cout<<i+1<<". "<<elementarray[i]<<endl;
            }
        }
    }
    protected:
        vector <string> elementarray;
        int sum, hashed, i, check;
        string wordHash;
        char firstLetter, lastLetter;
};

int main()
{
    Hasher hash;
    char firstLetter, lastLetter;
    int lengthOfWord, i;
    string word;

    cout<<"Enter a word:"<<endl;
    for(i=0;i<15;i++)
    {
        cout<<"#"<<i+1<<" ";
        cin>>word;
        firstLetter = word.at(0);
        lengthOfWord = word.length();
        lastLetter = word.at(lengthOfWord-1);
        hash.hashThisWord(firstLetter, lastLetter, word);
    }

<<<<<<< HEAD
=======



>>>>>>> 61b225e017f4f11e9d74b2bb5b5886b0faf7b774
    hash.display();

    cout<<endl;
    cout<<"Enter a word to see if it is stored in the program."<<endl;
    cout<<"When you are done enter '0'."<<endl;

    while(i != 1)
    {
        i = 0;
        cout<<"Enter word: ";
        cin>>word;
        if (word != "0")
        {
            firstLetter = word.at(0);
            lengthOfWord=word.length();
            lastLetter = word.at(lengthOfWord-1);
            hash.hashChecker(firstLetter, lastLetter, word);
        }
        else
        {
            i++;
        }
    }

    return 0;
}
