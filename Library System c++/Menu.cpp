#include "Menu.h"
#include "File.h"

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

void Menu::Introduction()
{
	cout<<endl<<endl;
    cout<<"\t\t\t\tWELCOME TO LIBRARY MANAGEMENT SYSTEM"<<endl<<endl;
    cout<<"\n\nARRANGED BY : Ahmet ALACAM";
    getch();
}

void Menu::Admin()
{
	int ch;
    cout<<"\n\n\n\tADMIN MENU"<<endl;
    cout<<"\n\n\n\tSTUDENT OPERATIONS";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS";
    cout<<"\n\n\t3.FIND SPECIFIC STUDENTS";
    cout<<"\n\n\t4.DELETE STUDENT RECORD"<<endl;
    cout<<"\n\n\n\tBOOKS OPERATIONS";
    cout<<"\n\n\t5.CREATE BOOK RECORD";
    cout<<"\n\n\t6.DISPLAY ALL BOOKS";
    cout<<"\n\n\t7.FIND SPECIFIC BOOKS";
    cout<<"\n\n\t8.DELETE BOOK RECORD";
    cout<<"\n\n\t9.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-9) ";
    
    cin>>ch;
    switch(ch)
    {
    File f;
            case 1:
                f.writeStudent();
				break;
            case 2: 
				f.displayStudents();
				break;
            case 3:
                char num[6];
				cout<<"\n\n\tPlease Enter The Admission No: ";
                cin>>num;
                f.specificStudent(num);
                break;
              case 4: 
			  	f.deleteStudent();
				break;
              case 5: 
			  	f.writeBook();
				break;
        	case 6:
            	f.displayBooks();
				break;
        	case 7: 
				{
                   char num[6];

                   cout<<"\n\n\tPlease Enter The book No. ";
                   cin>>num;
                   f.specificBook(num);
                   break;
            	}
        	case 8: 
				f.deleteBook();	
				break;
			case 9:
				Introduction();
				break;
			default:
				cout<<"\a";
       }
      //Introduction();
}

