#include<iostream>
#include<fstream>
using namespace std;
#include<stdio.h>

int main()
{
    ofstream fi;
    string name;
    char hh[50];
   getline(cin,name);
    cout<<"here";
    fi.open(name,ios::app);
    fi<<"thdhhddkajdal"<<endl;
    fi.close();
    ifstream mm(name);
    mm>>hh;
    cout<<hh;
    cout<<"heretoo"<<endl;
    return 0;

}
