#include<iostream>
#include<fstream>
using namespace std;
#include<stdio.h>
#include<ctime>


int main()
{
    cout<<"1....";
    time_t start[6];int d=0;
    start[0]=std::time(NULL);
     for (int n=0; n<100; ++n) {
        for (int m=0; m<100; ++m) {
           d += d*n*m;
        }
    }
    cout<<"2....";
    start[1]=std::time(NULL);
      for (int n=0; n<100; ++n) {
        for (int m=0; m<100; ++m) {
           d += d*n*m;
        }
    }
    cout<<"3....";
    start[2]=std::time(NULL);
      for (int n=0; n<100; ++n) {
        for (int m=0; m<100; ++m) {
           d += d*n*m;
        }
    }
    cout<<"4....";
    start[3]=std::time(NULL);
      for (int n=0; n<100; ++n) {
        for (int m=0; m<100; ++m) {
           d += d*n*m;
        }
    }
    cout<<"5....";
    start[4]=std::time(NULL);
      for (int n=0; n<100; ++n) {
        for (int m=0; m<100; ++m) {
           d += d*n*m;
        }
    }
    cout<<"6....";
    start[5]=std::time(NULL);
    fstream ff("time.dat",ios::out|ios::app);
    for(int i=0;i<=5;i++)
        ff.write((char*)&start[i],sizeof(start[i]));
    ff.close();
    cout<<"7....";time_t st;
    ifstream fff("time.dat",ios::in);

    while(!fff.eof())
    {
        fff.read((char*)&st,sizeof(st));
        cout<<st<<endl;
    }
    fff.close();
    return
    0;


}
