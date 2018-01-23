
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






void homescreen_menu()
{
        cout<<"\n\t\t\t\tWELCOME TO NSIT LIBRARY \n\n\t1. ISSUE A BOOK\n\t2. RETURN A BOOK\n\t3. REISSUE THE BOOK \n\t4. SEARCH  \n\t5. VIEW ISSUE HISTORY \n\t6. UPDATE RECORDS \n\t7. EXIT PORTAL"<<endl;
        cout<<"ENTER YOUR CHOICE : "<<endl;
}


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
}



