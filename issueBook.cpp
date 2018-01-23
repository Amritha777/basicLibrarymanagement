
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

