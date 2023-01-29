#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

class Book{
	public:
		void createBook();
		void showBook();
		
		char* getbno();
		// 
		char* getaname();
		//
		void report();
	private:
		char bno[6];
		char bname[50];
		char aname[20];
		
};
#endif
