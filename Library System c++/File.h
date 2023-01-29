#ifndef FILE_H
#define FILE_H

#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
using namespace std;

class File{
	public:
		void writeBook();
		void writeStudent();
		
		void specificBook(char n[]);
		void specificStudent(char n[]);
		
		void deleteBook();
		void deleteStudent();
		
		void displayBooks();
		void displayStudents();
		
		void bookIssue();
		void bookDeposit();		
};
#endif
