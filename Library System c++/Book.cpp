#include "Book.h"

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

void Book::createBook()
{
		cout<<"\nNEW BOOK ENTRY...\n";
    	cout<<"\nEnter The book no: ";
        cin>>bno;fflush(stdin);
        cout<<"\n\nEnter The Name of The Book: ";
        gets(bname);fflush(stdin);
        cout<<"\n\nEnter The Author's Name: ";
        gets(aname);
        cout<<"\n\n\nBook Created..";
}

void Book::showBook()
{
		cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        puts(bname);
        cout<<"Author Name : ";
        puts(aname);
}

char* Book::getbno()
{
	return bno;
}

//hemen alt satır
char * Book::getaname()
{
	return aname;
}

void Book::report()
{
	cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
}
