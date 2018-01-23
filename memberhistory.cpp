
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
