#include "Student.h"

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

void Student::createStudent()
{
		cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>admno;
        cout<<"\n\nEnter The Name of The Student ";
        cin>>gets(name);fflush(stdin);
        token=0;
        stbno[0]='/0';
        cout<<"\n\nStudent Record Created..";
}

void Student::showStudent()
{
		cout<<"\nAdmission no. : "<<admno;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
        cout<<"\nBook No "<<stbno;
}

char* Student::getadmno()
{
	return admno;
}

char* Student::getname()
{
	return name;
}

char* Student::getstbno()
{
	return stbno;
}

int Student::gettoken()
{
	return token;
}

void Student::addToken()
{
	token=1;
}

void Student::resetToken()
{
	token=0;
}

void Student::setstbno(char t[])
{
	strcpy(stbno,t);
}

void Student::report()
{
	cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;
}
