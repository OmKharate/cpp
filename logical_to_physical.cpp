#include<iostream>
using namespace std;

int main()
{
    int np, nf, LA, PA, offset, framenum, pagenum, PageSize;

    cout << "Enter number of pages: ";
    cin >> np;
    cout << "Enter number of frames: ";
    cin >> nf;
    cout << "Enter logical address: ";
    cin >> LA;

    cout << "Enter page size: ";
    cin >> PageSize;

    int* pagetable = new int[np];

    for(int i = 0; i < np; i++)
    {
        cout << "Enter frame number for page " << i << ": ";
        cin >> pagetable[i];
    }

    pagenum = LA / PageSize;
    offset = LA % PageSize;

    if(pagenum >= np)
    {
        cout << "Invalid page number";
        delete[] pagetable;
        return 0;
    }

    framenum = pagetable[pagenum];

    if(framenum >= nf)
    {
        cout << "Invalid frame number";
        delete[] pagetable;
        return 0;
    }

    PA = framenum * PageSize + offset;

    cout << "\nPhysical Address = " << PA << endl;
    cout << "Page Size = " << PageSize << endl;
    cout << "Page Number = " << pagenum << endl;
    cout << "Logical Address = " << LA << endl;
    cout << "Offset = " << offset << endl;

    delete[] pagetable;
    return 0;
}