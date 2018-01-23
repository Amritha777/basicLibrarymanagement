//  dbms

#include<iostream>
using namespace std;
#include<stdio.h>
#include<fstream>

class book
{
    int isbn;
    char title[50];
    int quantity;
    char author[50];
    char genre[50];

public :
     void getdata();
     void putdata();
     int getisbn();
     int getquantity();
};


void book::getdata()
{
    cout<<"enter the details of the book"<<endl;
    cout<<"name :   ";
    cin.getline(title,50);
    cout<<"author :   ";
    cin.getline(author,50);
    cout<<"isbn :   "<<
    cout<<"quantity :  ";
    cin>> quantity;
    cout<<"genre :   ";
    cin.getline(genre,50);
}

void book::putdata()
{
    cout<<"the book details are here :\nTitle : ";
    puts(title);
    cout<<"Author : "; puts(author);
    cout<<"isbn : "<< isbn<<endl;
    cout<<"quantity : "<<quantity<<endl;
    cout<<"genre : "; puts(genre);
    cout<<endl;
}

int book::getisbn()
{
    return isbn;
}

int book::getquantity()
{
    return quantity;
}

void buildbookdata()
{
    ofstream bk;
    bk.open("booklist",ios::app);
    book b;
    b.getdata();
    bk.write((char *)&bk,sizeof(bk));
    bk.close();
}


class member
{
    char name[50];
    int idnum;
    char address[100];
    int fine;
    public:
        void getperson();
        void showperson();
        int getidnum();


};

void book::showperson()
{
    cout<<"here is your profile"<<endl;
    cout<<"name : ";puts(name); cout<<"library id number : "<<idnum<<endl;
    cout<<"address : ";puts(address);
    cout<<"fine(if any) : "<<fine<<endl;
}
void book::getperson()
{
    cout<<"enter you details"<<endl;
    cout<<"name : "; gets(name);
    cout<<"address ;"; gets(address);
    cout<<"library id number : "; cin>>idnum;
}
int book::getidnum()
{
    retturn idnum;
}

void issuebook()
{

}


void returnbook()
{

}



