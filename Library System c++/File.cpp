#include "File.h"
#include "Student.h"
#include "Book.h"

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

fstream fp,fp1;
Book bk;
Student st;

void File::writeBook()
{
	char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {

        bk.createBook();
        fp.write((char*)&bk,sizeof(Book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void File::writeStudent()
{
	char ch;
    fp.open("student.dat",ios::out|ios::app);
    do
    {
        st.createStudent();
        fp.write((char*)&st,sizeof(Student));
        cout<<"\n\ndo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void File::specificBook(char n[])
{
	cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(Book)))
    {
        if(strcmpi(bk.getbno(),n)==0)
        {
            bk.showBook();
             flag=1;
        }
    }

    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

void File::specificStudent(char n[])
{
	int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(Student)))
    {
        if((strcmpi(st.getadmno(),n)==0))
        {
            st.showStudent();
            flag=1;
        }
    }

    fp.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
     getch();
}

void File::deleteBook()
{
	char n[6];

    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(Book)))
    {
        if(strcmpi(bk.getbno(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(Book));
        }
    }

    fp2.close();
        fp.close();
        remove("book.dat");
        rename("Temp.dat","book.dat");
        cout<<"\n\n\tRecord Deleted ..";
        getch();
}

void File::deleteStudent()
{
	char n[6];
    int flag=0;

        cout<<"\n\n\n\tDELETE STUDENT...";
        cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
        cin>>n;
        fp.open("student.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&st,sizeof(Student)))
    {
        if(strcmpi(st.getadmno(),n)!=0)
                 fp2.write((char*)&st,sizeof(Student));
        else
               flag=1;
    }

    fp2.close();
        fp.close();
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
             cout<<"\n\n\tRecord Deleted ..";
        else
             cout<<"\n\nRecord not found";
        getch();
}

void File::displayBooks()
{
	fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";

    while(fp.read((char*)&bk,sizeof(Book)))
    {
        bk.report();
    }
         fp.close();
         getch();
}

void File::displayStudents()
{
	fp.open("student.dat",ios::in);
         if(!fp)
         {
               cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";

    while(fp.read((char*)&st,sizeof(Student)))
    {
        st.report();
    }

    fp.close();
    getch();
}

void File::bookIssue()
{
	char sn[6],bn[6];
    int found=0,flag=0;

    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(Student)) && found==0)
           {
        if(strcmpi(st.getadmno(),sn)==0)
        {
            found=1;
            if(st.gettoken()==0)
            {
                      cout<<"\n\n\tEnter the book no. ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(Book))&& flag==0)
                {
                       if(strcmpi(bk.getbno(),bn)==0)
                    {
                        bk.showBook();
                        flag=1;
                        st.addToken();
                        st.setstbno(bk.getbno());
                               int pos=sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(Student));
                        cout<<"\n\n\t Book issued successfully";
                    }
                    }
                  if(flag==0)
                        cout<<"Book no does not exist";
            }
                else
                  cout<<"You have not returned the last book ";

        }
    }
          if(found==0)
        cout<<"Student record not exist...";
    getch();
      fp.close();
      fp1.close();
}

void File::bookDeposit()
{
	char sn[6],bn[6];
    int found=0,flag=0,day,fine;

    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(Student)) && found==0)
       {
        if(strcmpi(st.getadmno(),sn)==0)
        {
            found=1;
            if(st.gettoken()==1)
            {
            while(fp1.read((char*)&bk,sizeof(Book))&& flag==0)
            {
               if(strcmpi(bk.getbno(),st.getstbno())==0)
            {
                bk.showBook();
                flag=1;
                cout<<"\n\nBook deposited in no. of days";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFine has to deposited Rs. "<<fine;
                }
                    st.resetToken();
                    int pos=-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(Student));
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"Book no does not exist";
              }
         else
            cout<<"No book is issued..please check!!";
        }
       }
      if(found==0)
    cout<<"Student record not exist...";
    getch();
  fp.close();
  fp1.close();
}

