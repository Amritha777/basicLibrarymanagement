void lib_func::display_books()
{
    ifstream fi("book_list");
    books b;
    while(fi.read((char*)&b,sizeof(b)))
    {
        cout<<"\n"<<b.bid<<"\t";
        puts(b.title);

    }0;
    fi.close();

}


void lib_func::
