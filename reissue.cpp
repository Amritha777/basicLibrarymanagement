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
