#include <iostream>
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
//Functions

void showHelp(void)
{
    cout << "./a.out [something].bin [somethingelse].tape" << endl;
}

uint16_t binary(int i)
{
    cout << i << " ";
    int rem = 0;

    do
    {

    } while rem != 0;

    uint16_t bin;
    return bin;
}

void left(void) {}
void right(void) {}
void halt(void) {}
void fail(void) {}
void draw(void) {}
void alpha(void) {}
void brae(void) {}
void brane(void) {}
void bra(void) {}
void cmp(void) {}

//Main
int main(int argc, char *argv[])
{
    if (argv[1] == NULL || !strcmp(argv[1], "-h"))
    {
        showHelp();
        return 0;
    }
    //RAM allocation
    int ram[RAM_WORDS] = {0};

#pragma BIN STUFF
    //BIN STUFF
    //Read .bin file
    FILE *binFile = fopen(argv[1], "rb");
    vector<uint16_t> binInput(RAM_WORDS);

    int a = 0;
    char *c;
    cout << ".bin file : " << argv[1] << endl;
    while (!feof(binFile))
    {
        // binInput.at(a) = fgetc(binFile);
        binInput.at(a) = binary(fgetc(binFile));
        // cout << binInput.at(a) << " ";
        a++;
    }
    // fgets(binInput, 111111, binFile);
    // for (int q = 0; q < sizeof(binInput) / sizeof(binInput[111111]); q++)
    //     cout << binInput[q];
    fclose(binFile);

    // #pragma TAPE STUFF
    //     //TAPE STUFF
    //     // Open tape file
    //     FILE *tapeFile = fopen(argv[2], "r");
    //     vector<char> fileInput(111111, ' ');

    //     //Read tape file into LONG vector
    //     int i = 0;
    //     cout << "\n.tape file : " << argv[2] << endl;
    //     while (!feof(tapeFile))
    //     {
    //         char c = fgetc(tapeFile);
    //         fileInput.at(i) = c;
    //         cout << fileInput[i];
    //         i++;
    //     }
    //     fclose(tapeFile);

    //     //resize vector to length of tape
    //     int length, rows = 1;
    //     for (int j = 0; j < fileInput.size(); j++)
    //     {
    //         if (fileInput[j] != ' ')
    //             length = j;
    //     }
    //     // cout << "\nLength : " << length << endl;

    //     fileInput.resize(length);

    //     //get the number of rows in the tape
    //     for (int j = 0; j < fileInput.size(); j++)
    //     {
    //         if ((fileInput[j] == '\n' || fileInput[j] == '\r') && (fileInput[j + 1] == 'a' || fileInput[j + 1] == 'b'))
    //             rows++;
    //     }
    //     // cout << "Rows : " << rows << endl;

    // #pragma RUN STUFF
    //     //RUN STUFF
    //     for (int l = 0; l < rows; l++)
    //     {
    //         // run();
    //         int headPosition = 0;
    //         int headMovements = 0;
    //         int opc = 0;
    //         switch (opc)
    //         {
    //         case opc_left:
    //             left();
    //             break;
    //         case opc_right:
    //             right();
    //             break;
    //         case opc_halt:
    //             halt();
    //             break;
    //         case opc_fail:
    //             fail();
    //             break;
    //         case opc_draw:
    //             draw();
    //             break;
    //         case opc_alpha:
    //             alpha();
    //             break;
    //         case opc_brae:
    //             brae();
    //             break;
    //         case opc_brane:
    //             brane();
    //             break;
    //         case opc_bra:
    //             bra();
    //             break;
    //         case opc_cmp:
    //             cmp();
    //             break;

    //         default:
    //             break;
    //         }
    //     }

    return 0;
}