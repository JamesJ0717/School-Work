/*
         * Name        : vm.cpp
         * Author      : James Johnson
         *
         * License     : Copyright (C) 2019 All rights reserved
    CS441 Prog1
        - write a program to run a VM

    This is what I am getting. The numbers for head movements and instructions
    are different than what you were getting, but this is my best attempt.
*/

#include <iostream>
#include <math.h>
#include <vector>

#define opc_left 0
#define opc_right 1
#define opc_halt 2
#define opc_fail 3
#define opc_draw 4
#define opc_alpha 5
#define opc_brae 6
#define opc_brane 7
#define opc_bra 8
#define opc_cmp 9

#define RAM_WORDS 4096

using namespace std;
// Functions

void showHelp(void)
{
  cout << "./a.out [something].bin [somethingelse].tape" << endl;
}

vector<int> toBin(int n)
{
  /*
      97 -> 01100001
      97  % 2 = 1, 97 / 2 = 48;
      48  % 2 = 0, 48 / 2 = 24;
      24  % 2 = 0, 24 / 2 = 12;
      12  % 2 = 0, 12 / 2 = 6;
      6   % 2 = 0, 6  / 2 = 3;
      3   % 2 = 1, 3  / 2 = 1;
      1   % 2 = 1, 1  / 2 = 0;
  */
  vector<int> bin(8, 0);
  for (int x = 8; x > 0; x--)
  {
    // cout << n << " " << n % 2 << " " << n / 2 << " ";
    bin.at(x - 1) = n % 2;
    n /= 2;
  }
  return bin;
}
int toDec(vector<int> p)
{
  int dec = 0, pCnt = 0;
  for (int quick = p.size() - 1; quick >= 0; quick--)
  {
    dec += p.at(pCnt) * pow(2, quick);
    // cout<<p[quick]* pow(2,quick)<<" ";
    pCnt++;
  }
  // cout<<endl;
  return dec;
}
int toHex(vector<int> q)
{
  int boop, nibble = 0;
  for (int goop = 0; goop < q.size(); goop++)
  {
    nibble += q.at(goop) * pow(2, goop);
  }
  boop = nibble;
  return boop;
}
int getAddress(vector<int> r)
{
  vector<int> bits(8, 0); // 007 --> 00000111

  for (int f = 0; f < bits.size(); f++)
  {
    bits.at(f) = r.at(f);
    // cout<<bits.at(f);
  }
  // cout << endl;
  int l = toDec(bits);
  return l;
}
char getLetter(vector<int> r)
{
  char letter;
  vector<int> bits(8, 0);
  for (int kit = 0; kit < bits.size(); kit++)
  {
    bits.at(kit) = r.at(kit);
  }
  letter = (char)toDec(bits);
  // cout<<toDec(bits)<<endl;
  return letter;
}

void halt(int hP, int hM, int inst, vector<char> tape)
{
  cout << "Halted after " << hM << " moves and " << inst << " instructions executed " << endl;
  for (int y = 0; y < tape.size(); y++)
  {
    cout << tape.at(y);
  }
  cout << endl;
  for (int y = 0; y < tape.size(); y++)
  {
    if (y == hP)
      cout << "^";
    else
    {
      cout << " ";
    }
  }
  cout << endl;
}
vector<char> draw(char let, int headPosition, vector<char> tape)
{
  vector<char> newTape = tape;
  newTape.at(headPosition) = let;
  return newTape;
}
bool cmp(char l, char m)
{
  // cout<<l<<" ";
  if (l == m)
  {
    // cout << "true ";
    return true;
  }
  else
  {
    // cout << "false ";
    return false;
  }
}
//

int main(int argc, char *argv[])
{
  if (argc == 0 || argv[1] == NULL || !strcmp(argv[1], "-h"))
  {
    showHelp();
    return 0;
  }

#pragma BIN STUFF
  vector<vector<int> > ram(RAM_WORDS);
  for (int f = 0; f < RAM_WORDS; f++)
  {
    ram.at(f).resize(16);
  }

  // Read .bin file
  FILE *binFile = fopen(argv[1], "rb");
  // cout << ".bin file : " << argv[1] << endl;

  while (!feof(binFile))
  {
    for (int c = 0; c < ram.size(); c++)
    {
      vector<int> input(8), input2(8);
      input = toBin(fgetc(binFile));
      input2 = toBin(fgetc(binFile));
      for (int b = 0; b < input.size(); b++)
      {
        ram.at(c).at(b) = input.at(b);
        ram.at(c).at(b + 8) = input2.at(b);
      }
      if (ram.at(c).at(0) == 0 && ram.at(c).at(1) == 0 &&
          ram.at(c).at(2) == 0 && ram.at(c).at(3) == 0 &&
          ram.at(c).at(4) == 0 && ram.at(c).at(5) == 0 &&
          ram.at(c).at(6) == 0 && ram.at(c).at(7) == -1 &&
          ram.at(c).at(8) == 0 && ram.at(c).at(9) == 0 &&
          ram.at(c).at(10) == 0 && ram.at(c).at(11) == 0 &&
          ram.at(c).at(12) == 0 && ram.at(c).at(13) == 0 &&
          ram.at(c).at(14) == 0 && ram.at(c).at(15) == -1)
      {
        ram.resize(c + 1);
        break;
      }
    }
  }
  fclose(binFile);

#pragma TAPE STUFF
  // TAPE STUFF
  // Open tape file
  FILE *tapeFile = fopen(argv[2], "r");
  vector<vector<char> > fileInput(RAM_WORDS);
  for (int g = 0; g < RAM_WORDS; g++)
  {
    fileInput.at(g).resize(RAM_WORDS);
  }

  // Read tape file into LONG vector
  int i = 0;
  // cout << "\n.tape file : " << argv[2] << endl;
  while (!feof(tapeFile))
  {
    int boo = 0;
    char c = 'a';
    do
    {
      c = fgetc(tapeFile);
      fileInput.at(i).at(boo) = c;
      boo++;
    } while (c != '\n' && c != '\xff');
    // cout << fileInput[i];
    i++;
  }
  fclose(tapeFile);

  // resize vector to length of tape
  int length, rows = 1;
  for (int j = 0; j < fileInput.size(); j++)
  {
    for (int fast = 0; fast < fileInput.at(j).size(); fast++)
    {
      if (fileInput.at(j).at(fast) != ' ' &&
          (fileInput.at(j).at(fast) == 'a' | fileInput.at(j).at(fast) == 'b'))
        length = fast;
    }
  }
  // cout << "\nLength : " << length << endl;

  // get the number of rows in the tape

  for (int j = 0; j < fileInput.size(); j++)
  {
    for (int faster = 0; faster < fileInput.at(j).size(); faster++)
    {
      if (fileInput.at(j).at(faster) == '\xff')
      {
        fileInput.at(j).resize(faster);
      }
      else if ((fileInput.at(j).at(faster) == '\n' || fileInput.at(j).at(faster) == '\r'))
      {

        fileInput.at(j).resize(faster + 1);
        rows++;
      }
    }
  }
  fileInput.resize(rows);
  // cout << "Rows : " << rows << endl;

#pragma RUN STUFF
  // RUN STUFF

  for (int tapeLine = 0; tapeLine < rows; tapeLine++)
  {
    int headPosition = 0, headMovements = 0, numInstruct = 0, instruction = 0;
    char letterToDraw, letter = ' ';
    bool equal = true, blank = false;

#pragma setting up instructions

    for (;;)
    {
      int address = 0, opc, binOpCnt = 0;
      vector<int> binOp(4);
      // get instruction
      for (int opce = 8; opce < 12; opce++)
      {
        binOp.at(binOpCnt) = ram.at(instruction).at(opce);
        binOpCnt++;
      }
      opc = toDec(binOp);
      if (headPosition < 0)
      {
        opc = opc_right;
      }

#pragma switch
      switch (opc)
      {
      case opc_left:
        headPosition--;
        headMovements++;
        numInstruct++;
        break;
      case opc_right:
        headPosition++;
        headMovements++;
        numInstruct++;
        break;
      case opc_halt:
        headPosition = headPosition;
        headMovements = headMovements;
        numInstruct++;
        halt(headPosition, headMovements, numInstruct, fileInput.at(tapeLine));
        break;
      case opc_fail:
        headPosition = headPosition;
        headMovements = headMovements;
        numInstruct++;
        break;
      case opc_draw:
        numInstruct++;
        headMovements++;
        if (headPosition >= fileInput.at(tapeLine).size())
        {
          headPosition--;
        }
        else
        {
          if (ram.at(instruction).at(12) == '1')
          {
            letterToDraw = ' ';
            fileInput.at(tapeLine) = draw(letterToDraw, headPosition, fileInput.at(tapeLine));
          }
          else
          {
            letterToDraw = getLetter(ram.at(instruction));
            fileInput.at(tapeLine) = draw(letterToDraw, headPosition, fileInput.at(tapeLine));
          }
        }
        break;
      case opc_alpha:
        numInstruct++;
        break;
      case opc_brae:
        numInstruct++;
        address = getAddress(ram.at(instruction));
        if (equal)
        {
          instruction = address;
        }
        else
          instruction++;
        break;
      case opc_brane:
        numInstruct++;
        address = getAddress(ram.at(instruction));
        if (!equal)
        {
          instruction = address;
        }
        else
        {
          instruction++;
        }

        break;
      case opc_bra:
        numInstruct++;
        address = getAddress(ram.at(instruction));
        instruction = address;
        break;
      case opc_cmp:
        // cout<<opc<< " ";
        blank = ram.at(instruction).at(12);
        if (!blank)
        {
          letter = getLetter(ram.at(instruction));
        }
        else
        {
          letter = ' ';
        }
        numInstruct++;
        if (headPosition >= fileInput.at(tapeLine).size())
        {
          equal = cmp(letter, ' ');
        }
        else
        {
          equal = cmp(letter, fileInput.at(tapeLine).at(headPosition));
        }
        break;
      }
#pragma end of switch

      if (opc == opc_halt)
        break;
      if (opc != opc_brae && opc != opc_brane && opc != opc_bra)
        instruction++;
    }
  }

  return 0;
}
