#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

class Student{
	public:
		void createStudent();
		void showStudent();
		
		char* getadmno();
		char* getname();
		char* getstbno();
		int gettoken();
		
		void addToken();
		void resetToken();
		void setstbno(char t[]);
		void report();
	private:
		char admno[6];
	    char name[20];
	    char stbno[6];
	    int token;
			
};
#endif
