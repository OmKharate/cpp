#include<iostream>
using namespace std;

int main(){

int np,nf,pagenum,framenum,LA,PA,offset,pagesize;

cin>>np;
cin>>nf;
cin>>LA;
cin>>pagesize;
int*pagetable = new int[np];

for(int i=0;i<np;i++){
    cout<<"frame num for each page"<<i<<": ";
    cin>>pagetable[i];
}

pagenum =LA/pagesize;
offset = LA%pagesize;

if(pagenum>np){
   cout<<"invalid pagenumber";
   delete[] pagetable;
   return 0;

   
}
framenum=pagetable[pagenum];
if(framenum>nf){
    cout<<"invalid framenum";
    delete[] pagetable;
    return 0;
}

PA=framenum*pagesize + offset;

cout<<"the physical adresss for Lgical address"<<LA<<"is  "<<PA;

delete[] pagetable;
return 0;
}