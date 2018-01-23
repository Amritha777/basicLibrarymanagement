///list of the utility functions to be made


 ///book::get_title();
 void books::put_bdata()
 {
    cout<<"The book details are here :\n\tTitle : ";
    puts(title);
    cout<<"\tAuthor : "; puts(author);
    cout<<"\tisbn : "<< isbn<<endl;
    cout<<"\tbook id no : "<<bid<<endl;
    cout<<"\tgenre : "; puts(genre);
    cout<<" Issue status : "; if(is_issue) cout<<"issued" ;else cout<<"not issued"<<endl;
    cout<<"Issue date : "<<issue_date;
    cout<<"Member who has issued : "; if(is_issue) puts(issued_mid); else cout<<"Not available"<<endl;
    cout<<endl;
    cout<<endl;
 }
 void books::get_bdata()
 {
     cout<<"enter the details of the book"<<endl;
    cout<<"name :   ";
    cin.getline(title,80);
    cout<<"author :   ";
    cin.getline(author,40);
    cout<<"isbn :   "; cin>>isbn_num;

    cout<<"book id no :  ";
    cin>> bid;
    cout<<"genre :   ";
    cin.getline(genre,30);
    is_issued=false;
    issue_date="00.00.0000";
    issued_mid=0;
 }
/// book::get_isbn();
/// book::get_author();
/// book::get_genre();
/// book::get_bid();
void books::issuedate_modify(xyz)
{

}
/// member::get_mid();
void  member::put_mdata()
{
    cout<<"Here is your profile"<<endl;
    cout<<"name : ";puts(name);
    cout<<"library id number : "<<idnum<<endl;
    cout<<"email : ";puts(email);
    cout<<"contact no : "<<contact_num;
    cout<<"fine(if any) : "<<fine<<endl<<endl<<endl;
}

void  member::get_mdata()
{
    cout<<"hComplete your profile"<<endl;
    cout<<"\tname : ";gets(name);
    cout<<"\n\tlibrary id number : "; cin>>idnum;
    cout<<"\n\temail : "; gets(email);
    cout<<"\n\tcontact no : "; cin>>contact_num;
    fine=0;

}

int lib_func::fine_nikal()
{


}
