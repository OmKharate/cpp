#include<iostream>
#include<fstream>
using namespace std;

char M[100][4], R[4], IR[4], buffer[40];
int IC, C;

void init()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<4;j++)
            M[i][j] = '*';

    for(int i=0;i<4;i++)
        R[i] = IR[i] = '*';

    IC = C = 0;
}

void printMemory()
{
    for(int i=0;i<10;i++)
    {
        if(i<10) cout<<"0";
        cout<<i<<" ";

        for(int j=0;j<4;j++)
            cout<<M[i][j];

        cout<<endl;
    }
}

void load()
{
    ifstream fin("input.txt");

    int m = 0;
    bool program = false;

    while(fin.getline(buffer,40))
    {
        string line = buffer;

        if(line == "$AMJ")
        {
            init();
            m = 0;
            program = true;
        }

        else if(line == "$DTA")
        {
            program = false;
        }

        else if(line == "$END")
        {
            break;
        }

        else if(program)
        {
            int k = 0;

            while(buffer[k] != '\0')
            {
                for(int j=0;j<4 && buffer[k]!='\0';j++)
                    M[m][j] = buffer[k++];

                m++;
            }

            printMemory();
        }
    }

    fin.close();
}

int main()
{
    load();
    return 0;
}