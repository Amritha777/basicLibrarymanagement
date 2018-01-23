// update options
// get_bookdata() tobe specifies

void lib_func::add_book()
{
       fstream fi;
       fi.open("book_list.DAT",ios::out|ios::app);
       char y='y';
       cout<<"Enter the details of the book"<<endl;
       b1.get_bdata();
       while(y=='y'||y=='Y')
       {
            fi.write((char*)&b1,sizeoff(b1));
            cout<<"DO YOU WANT TO ADD MORE?(y/n)"<<endl;
            cin>>y;
       }
}
// need to add memdata function

void lib_func::add_mem()
{
       fstream fi;
       fi.open("member_list.DAT",ios::out|ios::app);
       char y='y';
       cout<<"Enter the details of the member"<<endl;
       m1.get_mdata();
       while(y=='y'||y=='Y')
       {
            fi.write((char*)&b1,sizeoff(b1));
            cout<<"DO YOU WANT TO ADD MORE?(y/n)"<<endl;
            cin>>y;
       }
}

void lib_func::delete_mem()
{
    ifstream fi("member_list.DAT",ios::in);
    ofstream fout("temp.DAT",ios::out);
    int mmid,found=0; char h='y';
    while(h=='y'|h=='Y')
    {
        cout<<"enter the member id no whose record is to be deleted"<<endl;
        cin>>mmid;
        while(!fi.eof())
        {
            fi.read((char*)m1,sizeof(m1));
            if(m1.get_mid()==mmid)
            {
                found++;
                m1.put_mdata();
                cout<<"this is the record to be deleted. proceed or not?";
                cin>>h;
                if(h=='y'|h=='Y')
                {
                    cout<<"RECORD DELETED!!"<<endl;
                }
                else
                    fout.write((char*)&m1,sizeof(m1));

            }
            else
                fout.write((char*)&m1, sizeof(m1));
            if(found==0)
                cout<<"RECORD NOT FOUND!!"<<endl;
            cout<<"do you want to delete more?"<<endl;
            cin>>h;
    }
    fi.close();
    fout.close();
    remove("member_list.DAT");
    rename("temp.DAT","member_list.DAT");

}

//get memdata to be specified

void lib_func::modify_mem()
{
    ifstream fi("member_list.DAT",ios::in);
    ofstream fout("temp.DAT",ios::out);
    int mmid,found=0; char h='y';
    while(h=='y'|h=='Y')
    {
        cout<<"enter the member id no whose record is to be modified"<<endl;
        cin>>mmid;
        while(!fi.eof())
        {
            fi.read((char*)m1,sizeof(m1));
            if(m1.get_mid()==mmid)
            {
                found++;
                member m2;
                m1.put_mdata();
                cout<<"this is the record to be modified. proceed or not?";
                cin>>h;
                if(h=='y'|h=='Y')
                {
                    cout<<"ENTER THE UPDATED DETAILS OF THE MEMBER"<<endl;
                    m2.get_mdata();
                    fout.write((char*)&m2,sizeof(m2));
                }
                else
                    fout.write((char*)&m1,sizeof(m1));

            }
            else
                fout.write((char*)&m1, sizeof(m1));
            if(found==0)
                cout<<"RECORD NOT FOUND!!"<<endl;
            cout<<"do you want to modify more records?"<<endl;
            cin>>h;
    }
    fi.close();
    fout.close();
    remove("member_list.DAT");
    rename("temp.DAT","member_list.DAT");

}

void lib_func::update_menu()
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
            cout<<"\n\n\tYOU WANT TO UPDATE: \n\ : \n1. ADD A BOOK\n2. DELETE A BOOK \n3. UPDATE THE DETAILSOF A BOOK\n4. ADD A MEMBER\n5. DELETE A MEMBER\n6. UPDATE THE RECORDS OF A MEMBER :"<<endl;
            cout<<"enter your choice :"<<endl;
            int chh;
            cin>>chh;
            if(chh==1) lib.add_book();
            else if(chh==2) lib.delete_book();
            else if(chh==3) lib.modify_book();
            else if(chh==4) lib.add_mem();
            else if(chh==5) lib.delete_mem();
            else if(chh==6) lib.modify_mem();
            else
                cout<<"YOU ENTERED THE WRONG CHOICE!!!"<<endl;
        }

        else
        cout<<"YOU ARE NOT AN AUTHORISED MEMBER!! ACCESS DENIED"<<endl;
    }

}
