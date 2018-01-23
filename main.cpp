#include <iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
class member
{
protected :
    char name[40];
    int mid;
    long int contact_num;
    char email[40];
    int num_of_ibooks; /// to be used
    float fine;
public :

}m1;
class books
{
protected :
    char title[80];
    int isbn_num;
    char author[40];
    char genre[30];
    int bid;
    bool is_issued;
    char issue_date[10];
    int issued_mid;
public :
     void get_bdata();
    void put_bdata();


}b1;


void homescreen_menu()
{
        cout<<"\n\t\t\t\tWELCOME TO NSIT LIBRARY \n\n\t1. ISSUE A BOOK\n\t2. RETURN A BOOK\n\t3. REISSUE THE BOOK \n\t4. SEARCH  \n\t5. VIEW ISSUE HISTORY \n\t6. UPDATE RECORDS \n\t7. EXIT PORTAL"<<endl;
        cout<<"ENTER YOUR CHOICE : "<<endl;
}

class lib_func:protected books, protected member
{
public:
    void add_book(); //done
    void delete_book();  //done
    void modify_book();  // done
    void add_mem(); // done
    void delete_mem();  //done
    void modify_mem(); // done
    void update_mem_history();  /// notrequired
    void issue();//done
    void reissue();//done
    void returnbook(); //done
    void search_book_name();  //done
    void search_book_isbn(); // done
    void search_book_author();  // done
    void search_book_genre(); // done
    void search_mem();  // done
    void display_mem_history();
    void search_menu(); // done
    void update_menu(); //done
}lib;

void lib_func::search_menu()
{
    cout<<"\n\n\t YOU WANT TO SEARCH : "<<endl;
    cout<<"1. Books\n2. Members "<<endl;
    int ch1,ch2;
    cout<<"Enter your choice "<<endl;
    cin>>ch1;
    if(ch1==1)
    {
        cout<<"SEARCH BY :"<<endl<<"1. BOOK TITLE \n2. BOOK ISBN\n3. BOOK AUTHOR \n4. BOOK GENRE "<<endl;
        cin>>ch2;
        switch(ch2)
        {
            case 1 : lib.search_book_name(); break;
            case 2 : lib.search_book_isbn(); break;
            case 3 : lib.search_book_author(); break;
            case 4 : lib.search_book_genre(); break;
        }

    }
    else if(ch1==2)
    {
        cout<<"THIS WINDOW IS PASSWORD PROTECTED. PLEASE ENTER THE PASSWORD :"<<endl;
        char pass[5],enterp[5];
        pass="****";
        for(int i=0;i<4;i++)
        {
            cin.getch(enterp[i]);
            cout<<"*";

        }
        if (strcmp(enterp,pass)==0)
        {
            cout<<"ACCESS GRANTED!!"<<endl;
        }
        else
            cout<<"YOU ARE NOT AN AUTHORISED MEMBER....FUCK OFF"<<endl;
    }
}




int main()
{
    homescreen_menu();
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1 : lib.issue(); break ;
        case 2 : lib.returnbook(); break;
        case 3 : lib.reissue(); break;
        case 4 : lib.search_menu(); break;
        case 5 : lib.display_mem_history(); break;
        case 6 : lib.update_menu(); break;
        case 7 : {  exit(0); break;}
    }

    return 0;
}
