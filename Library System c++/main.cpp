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

int main()
{
	Menu m;
	File f1;
	char ch;
    m.Introduction();
    do
    {

        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK LIST";
        cout<<"\n\n\t02. BOOK ISSUE";
        cout<<"\n\n\t03. BOOK DEPOSIT";
        cout<<"\n\n\t04. ADMIN MENU";
        cout<<"\n\n\t05. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-5) ";
        ch=getche();
        switch(ch)
        {
        	case '1':
        		f1.displayBooks();
        		break;
        	case '2':
                f1.bookIssue();
                break;
            case '3':
				f1.bookDeposit();
                break;
            case '4':
				m.Admin();
                break;
            case '5':
				m.Introduction();
            default :
			cout<<"\a";
        }
        }
		while(ch!='5');
}
