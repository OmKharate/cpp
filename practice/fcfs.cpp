#include<iostream>
using namespace std;

class proccess{
public:
    int pid;
    int at;
    int bt;
    int tat;
    int wat;
    int ct;
    int start_time;

};


int main(){
    int n;
    int j;
    int i;
    cout<<"enter the number of proccesses";
    cin>>n;

    proccess p[n];

    for(i=0;i<n-1;i++){
        cout<<"enter proccess arrival time"<<i+1 <<endl;
        cin<<p[i].at;
        cout<<"enter procccess burst time"<<i+1<<endl;
        cin<<p[i].bt;
        p[i].pid;
    }

    for(i=0;i<n-1;i++){
       for(j=0;j<n-i-1;j++){
         if(p[j].at >p[j+1].at){

            swap(p[j],p[j+1]);

         }
       }
    }

    for(i=0;i<n;i++){
        if(i == 0){
            p[i].start_time = p[i].at;
        }
        else{
            if(p[i].at > p[i - 1].ct)
                p[i].start_time = p[i].at;
            else
                p[i].start_time = p[i-1].ct;
                
    } 
    p[i].ct = p[i].start_time + p[i].bt;
    p[i].tat = p[i].ct - p[i].at;
    p[i].wt = p[i].tat -p[i].bt;


    }

    int ttat =0;
    int twt =0;
        for(i = 0;i<n;i++)
             

}
