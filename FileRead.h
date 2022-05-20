#pragma once

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

inline void createFile() 
{
	fstream file;

	file.open("TEXT.txt", ios::app);

	file.close();
}

string Read()
{
	ifstream MyFile;
	MyFile.open("TEXT.txt");

	string text, temp;

	MyFile.seekg(0, ios::end);
	int file_size = MyFile.tellg();
	MyFile.close();

	MyFile.open("TEXT.txt");

	if ((!MyFile.is_open()) || (file_size < 1))
	{
		createFile();

		return "You need write in \"TEXT.txt\" You'r text!";
	}
	else
	{
		while (getline(MyFile, temp))
		{
			text = text + temp + "\n";
		}
	}


	MyFile.close();


	return text;
}

//Author: IPOleksenko