#include <iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<string.h>
using namespace std;
class member
{
public:
    char name[40];
    int mid;
    long int contact_num;
    char email[40];
    int num_of_ibooks;
    float fine;
public :
    void get_mdata();
    void put_mdata();
}m1;
class books
{
public :
    char title[80];
    int isbn_num;
    char author[40];
    char genre[30];
    int bid;
    bool is_issued;
    time_t issue_time;
    int issued_mid;
public :
     void get_bdata();
    void put_bdata();


}b1;
class lib_func:protected books, protected member
{
public:
  ///  void search_menu(); // done
  ///  void update_menu(); //done
    void add_book(); //done
    void delete_book();  //done
    void modify_book();  // done
    void add_mem(); // done
    void delete_mem();  //done
    void modify_mem(); // done

   /// void issue();//done
 void reissue();//done
  ///void returnbook(); //done
  ///  void search_book_name();  //done
  ///  void search_book_isbn(); // done
  ///  void search_book_author();  // done
  ///  void search_book_genre(); // done
   /// void search_mem();  // done
    void display_mem_history();
    int calculate_fine(time_t t);
}lib;


 void books::put_bdata()
 {
    cout<<"The book details are here :\n\tTitle : ";
    puts(title);
    cout<<"\tAuthor : "; puts(author);
    cout<<"\tISBN : "<< isbn_num<<endl;
    cout<<"\tBook id no : "<<bid<<endl;
    cout<<"\tGenre : "; puts(genre);
    cout<<" \tIssue status : "; if(is_issued) cout<<"Issued" ;else cout<<"Not issued"<<endl;
    cout<<"\tIssue date and time is : "<<ctime(&issue_time);
    cout<<"\tMember who has issued : "; if(is_issued) cout<<issued_mid; else cout<<"Not available"<<endl;
    cout<<endl;

 }
 void books::get_bdata()
 {
     cout<<"Enter the details of the book"<<endl;
    cout<<"Name :   ";
    cin.getline(title,80);
    cout<<"Author :   ";
    cin.getline(author,40);
    cout<<"ISBN :   ";
    cin>>isbn_num;
    cout<<"Book id no :  ";
    cin>> bid;
    cout<<"Genre :   ";
    cin.getline(genre,30);
    is_issued=false;
    issue_time=time(NULL);
    issued_mid=0;
 }
void  member::put_mdata()
{
    cout<<"Here is your profile"<<endl;
    cout<<"Name : ";puts(name);
    cout<<"Library id number : "<<mid<<endl;
    cout<<"Email : ";puts(email);
    cout<<"Contact no : "<<contact_num;
    cout<<"Number of issued books : "<<num_of_ibooks;
    cout<<"Fine(if any) : "<<fine<<endl<<endl<<endl;
}

void  member::get_mdata()
{
    cout<<"Complete your profile"<<endl;
    cout<<"Name : ";cin.getline(name,40);
    cout<<"Library id number : "; cin>>mid;
    cout<<"Email : "; cin.getline(email,40);
    cout<<"Contact no : "; cin>>contact_num;
    fine=0;
    num_of_ibooks=0;
}

int lib_func::calculate_fine(time_t s)
{
    double seconds;
    seconds=difftime(time(NULL),s);
    seconds/=3600;
    seconds/=24;

    int days=(int)seconds;
    if(days<=15)
    {
        days=0;
    }
    else
        days=days-15;
    return days;
}
/*
void lib_func::display_mem_history()
{
    fflush(stdin);
    cout<<" Enter the member id of the person whose book history is to be displayed"<<endl;
    string mname;
    getline(cin,mname);
    cout<<"1"<<endl;
    ifstream ff(mname,ios::in);
    if(!ff)
    {
        cout<<"2"<<endl;
        cout<<"The records for this person does not exist"<<endl;

    }
    else
    {
        cout<<"2"<<endl;
        while(ff.read((char*)&b1,sizeof(b1)))
        {

            b1.put_bdata();
        }
        cout<<"3"<<endl;
    }
}
*/
// main search function
/*
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
        strcpy(pass,"*****");
        for(int i=0;i<4;i++)
        {
            enterp[i]=getch();
            cout<<"*";

        }
        if (strcmp(enterp,pass)==0)
        {
            cout<<"ACCESS GRANTED!!"<<endl;
            lib.search_mem();

        }

        else
            cout<<"YOU ARE NOT AN AUTHORISED MEMBER.ACCESS DENIED!!"<<endl;
    }

} */
/*
void lib_func::search_book_name()
{
    int t=0;
    fstream fi;
    fflush(stdin);
    cout<<"enter the name of the book you want to search"<<endl;
    char name[80];
    cin.getline(name,80);
    fi.open("book_list",ios::in);

    while(fi.read((char*)&b1,sizeof(b1)))
    {
        cout<<"k";

        if(strcmp(b1.title,name)==0)
        {
            cout<<"THE BOOK IS FOUND"<<endl;
            b1.put_bdata(); t++;
            break;
        }
    }
    if(t==0)
    {
        cout<<"THE BOOK YOU SEARCHED IS NOT PRESENT IN THE LIBRARY"<<endl;

    }
    fi.close();

}


void lib_func::search_book_isbn()
{
    int t=0;
    fflush(stdin);
    fstream fi;
    cout<<"enter the ISBN number of the book you want to search"<<endl;
    int is;
    cin>>is;
    fi.open("book_list",ios::in);

    while( fi.read((char*)&b1,sizeof(b1)))
    {

        if( is==b1.isbn_num)
        {
            cout<<"THE BOOK IS FOUND"<<endl;
            b1.put_bdata(); t++;
            break;
        }
    }
    if(t==0)
    {
        cout<<"THE BOOK YOU SEARCHED IS NOT PRESENT IN THE LIBRARY"<<endl;

    }
    fi.close();
}

void lib_func::search_book_author()
{
    int t=0;
    fstream fi;
    fflush(stdin);
    cout<<"enter the name of the author you want to search"<<endl;
    char auth[40];int key;
    cin.getline(auth,40);
    fi.open("book_list",ios::in);
    while(fi.read((char*)&b1,sizeof(b1)))
    {

        if(strcmp(b1.author,auth)==0)
        {
            t++;
            cout<<t<<". ";
            b1.put_bdata(); t++;

        }

    }
    if(t==0)
    {
        cout<<"NO BOOK BY THIS AUTHOR IS PRESENT IN THE LIBRARY"<<endl;

    }
    fi.close();
}


void lib_func::search_book_genre()
{
    int t=0;
    fflush(stdin);
    fstream fi;
    cout<<"Enter the genre you want to search"<<endl;
    char gre[30];
    cin.getline(gre,30);
    fi.open("book_list",ios::in);
    while( fi.read((char*)&b1,sizeof(b1)))
    {

        if(strcmp(b1.genre,gre)==0)
        {
            t++;
            cout<<t<<". "<<endl;
            b1.put_bdata();
            cout<<endl;
        }
    }
    if(t==0)
    {
        cout<<"THE BOOK YOU SEARCHED IS NOT PRESENT IN THE LIBRARY"<<endl;

    }
    fi.close();

}

// function to search members

void lib_func::search_mem()
{
        cout<<endl;
        fflush(stdin);
        cout<<"Enter the member id number whose records you need to view"<<endl;
        int mm, t=0;
        cin>>mm;
        fstream file;
        file.open("member_list",ios::out);
        while(!file.eof())
        {
            file.read((char*)&m1,sizeof(m1));
            if(m1.mid==mm)
            {
                t++;
                m1.put_mdata();
                break;
            }
        }
        if(t==0)
        {
            cout<<"NO MEMBER EXIST IN THE LIBRARY RECORDS WITH THAT ID NUMBER"<<endl;
        }
}
*/





void homescreen_menu()
{
        cout<<"\n\t\t\t\tWELCOME TO NSIT LIBRARY \n\n\t1. ISSUE A BOOK\n\t2. RETURN A BOOK\n\t3. REISSUE THE BOOK \n\t4. SEARCH  \n\t5. VIEW ISSUE HISTORY \n\t6. UPDATE RECORDS \n\t7. EXIT PORTAL"<<endl;
        cout<<"ENTER YOUR CHOICE : "<<endl;
}

/*
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
        strcpy(pass,"*****");
        for(int i=0;i<4;i++)
        {
            enterp[i]=getch();
            cout<<"*";

        }
        if (strcmp(enterp,pass)==0)
        {
            cout<<"ACCESS GRANTED!!"<<endl;
        }
        else
            cout<<"YOU ARE NOT AN AUTHORISED MEMBER....FUCK OFF"<<endl;
    }
} */
/*
void lib_func::issue()
{
    fflush(stdin);
    cout<<"Enter the mem id of the member"<<endl;
    string id;
    getline(cin,id);
    cout<<"1"<<endl;
    int x=0;
    for(int i=0;i<id.size();i++){
        x=x*10+(id[i]-'0');
    }
     member mm;
     cout<<"2"<<endl;
     bool found=false;
    ifstream ff("member_list",ios::in);
    while(ff.read((char*)&mm,sizeof(mm)))
    {
        cout<<"file reading"<<endl;
          if(mm.mid==x)
        {
            mm.num_of_ibooks+=1;
            found=true;
        }
    }
    ff.close();
    if(found)
    {
        cout<<"3"<<endl;
        ofstream fout(id,ios::app);
        cout<<"Enter book id"<<endl;
        int bookid;
        cin>>bookid;
        ifstream fin("book_list",ios::in);
        bool foundBook=false;
        while(fin.read((char*)&b1,sizeof(b1)))
            {
                cout<<"4"<<endl;

            if(b1.bid==bookid){
                b1.is_issued=true;
                b1.issue_time=time(NULL);                           ///date ka dekhna hai
                fout.write((char*)&b1,sizeof(b1));
                break;
        cout<<"5"<<endl;
            }
        }
        if(!foundBook){
            cout<<"We could not find the book with given book id";
        }
        fout.close();
        fin.close();
        ifstream pp("book_list");
        ofstream oo("bts");  books b;
        while(!pp.eof())
        {
    cout<<"6"<<endl;
            pp.read((char*)&b,sizeof(b));
            if(bookid==b.bid)
            {
                b.is_issued=true;                     /// issuedate to be updated
                b.issue_time=b1.issue_time;
                b.issued_mid=x;
            }
                oo.write((char*)&b,sizeof(b));
        }
        pp.close();
        oo.close();
        remove("book_list");
        rename("bts","book_list");
    }
    else
        cout<<"Member not found!"<<endl;

}



*/

/*
void lib_func::returnbook()
{
    fflush(stdin);
    cout<<"1"<<endl;
    cout<<"Enter the mem id of the member"<<endl;
    string id;
    getline(cin,id);
     ifstream ff("member_list",ios::in);
     member mm;
     bool found;
      int x=0;
        for(int i=0;i<id.size();i++){
            x=x*10+(id[i]-'0');
        }
        cout<<"2"<<endl;
    while(ff.read((char*)&mm,sizeof(mm)))
    {

        if(mm.mid==x)
        {
            found=true;
        }
    }
    ff.close();
    cout<<"3"<<endl;
    if(found)
    {
        cout<<"4"<<endl;
        ifstream fout(id);
        ofstream temp("t",ios::app);
        cout<<"Enter the id of the book you want to return"<<endl;
        int bookid,ff=0;
        cin>>bookid;
        bool miliKya=false;
        while(fout.read((char*)&b1,sizeof(b1)))
        {

            cout<<"5"<<endl;
            if(bookid==b1.bid)
            {
                b1.issue_time=time(NULL);          /// issuedate to be updated
            }
                temp.write((char*)&b1,sizeof(b1));
        }
        if(!miliKya)
            cout<<"Invalid book id !!"<<endl;
        fout.close();
        temp.close();
        char file1[10];
        cout<<"6"<<endl;
        for(int i=0;i<id.size();i++)
        {
            file1[i]=id[i];
        }
        remove(file1);
        rename("t",file1);
        ifstream pp("book_list");
        ofstream oo("bts");books b;
        while(pp.read((char*)&b,sizeof(b)))
        {

            cout<<"7"<<endl;
            if(bookid==b.bid)
            {
                b.issued_mid=x;
                b.issue_time=b1.issue_time;                        /// issuedate to be updated
            }
                oo.write((char*)&b,sizeof(b));
        }
        pp.close();
        oo.close();
        remove("book_list");
        rename("bts","book_list");
    }
    else
        cout<<"you entered the wrong member id !!"<<endl;
        cout<<"8"<<endl;
}


*/



void lib_func::reissue()
{
    fflush(stdin);
    cout<<"1"<<endl;
    cout<<"Enter the mem id of the member"<<endl;
    string id;
    getline(cin,id);
     ifstream ff("member_list",ios::in);
     member mm;
     int x=0;
     cout<<"2"<<endl;
     bool found;
        for(int i=0;i<id.size();i++){
            x=x*10+(id[i]-'0');
        }
    while(ff.read((char*)&mm,sizeof(mm)))
    {
        cout<<"3"<<endl;
        if(mm.mid==x)
        {
            found=true;
        }
    }
    ff.close();
    if(found)
    {
        cout<<"4"<<endl;
        ifstream fout(id);
        ofstream temp("t",ios::app);
        cout<<"Enter the id of the book you want to return"<<endl;
        int bookid,ff=0;
        cin>>bookid;
        bool miliKya=false;
        while(fout.read((char*)&b1,sizeof(b1)))
        {
            cout<<"5"<<endl;
            if(bookid==b1.bid)
            {
                b1.issue_time=time(NULL);          /// issuedate to be updated
            }
                temp.write((char*)&b1,sizeof(b1));
        }
        if(!miliKya)
            cout<<"Invalid book id !!"<<endl;
        fout.close();
        temp.close();
        char file1[10];
        cout<<"6"<<endl;
        for(int i=0;i<id.size();i++)
        {
            file1[i]=id[i];
        }
        remove(file1);
        rename("t",file1);
        ifstream pp("book_list");
        ofstream oo("bts");books b;
        cout<<"7"<<endl;
        while(pp.read((char*)&b,sizeof(b)))
        {
            cout<<"8"<<endl;

            if(bookid==b.bid)
            {
                b.issued_mid=x;
                b.issue_time=b1.issue_time;                        /// issuedate to be updated
            }
                oo.write((char*)&b,sizeof(b));
        }
        pp.close();
        oo.close();
        remove("book_list");
        rename("bts","book_list");
    }
    else
        cout<<"you entered the wrong member id !!"<<endl;
}








int main()
{
    homescreen_menu();
    int choice;
    cin>>choice;
        lib.reissue();
   /* switch(choice)
    {
        case 1 : lib.issue(); break ;
        case 2 : lib.returnbook(); break;
        case 3 : lib.reissue(); break;
        case 4 : lib.search_menu(); break;
        case 5 : lib.display_mem_history(); break;
        case 6 : lib.update_menu(); break;
        case 7 : {  exit(0); break;}
    }
    */
    return 0;
}
