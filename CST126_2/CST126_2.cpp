// CST126_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;


#include "stock.h"
/*
struct Stock {
	string stock_symbol;
	string name;
	double price;
	double earnings;
};
*/
//--------------------------------------------------------------------
bool OpenFile(ifstream& input_file);
//void fill_stock_from_file(Stock &, ifstream &, int & count);
void fill_stock_from_file(Stock & s, ifstream & in_file, int & count);
void tokenizer(char line[], string & symbol, string & name_with_quotes, double & price, double & earnings);

Stock st[4];
int cnt = 0;

int main(void)
{
	//  STUDENT TASK - define your variables
	// STUDENT TASK - look these up and add a comment to each one to describe what they are doing
	
	cout.setf(ios::fixed);   // makes sure cout prints a fixed number of decemals for float variables.
	cout.setf(ios::showpoint); // Always shows the decimal point even when 0.
	cout.precision(2);  // sets the amount of number after the decimal point to 2.


	int number_stocks = 4;
	
	ifstream stock_file;
	cout << "Welcome to the Stock Picker" << endl << endl;

	if (OpenFile(stock_file))
	{
		while (!stock_file.eof())
		{
			fill_stock_from_file(st[number_stocks], stock_file, number_stocks);
		}
		cout << fill_stock_from_file << endl;
		// STUDENT TASK - Loop through your stocks and print them
		
		cnt = 0;
		while (cnt < number_stocks)
		{
			st[cnt].print();
			cnt++;
		}
		
		cout << endl << "If you had a 10% appreciation in price the values would be" << endl;
		// STUDENT TASK - Loop through your stocks and 1 - give them a 10% price increase 2 - print them
		cnt = 0;
		while (cnt < number_stocks)
		{
			st[cnt].aprc_r();
			st[cnt].print();
			cnt++;

		}

	}

	return 0;

}
//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// bool    OpenFile(file)
// Input:  file name (retrieved from user);
// Output: file pointer. 
//         Returns true if able to open file and false if 
//           unable to open file
//  Hint:  we've had hands on that did this.
bool OpenFile(ifstream& input_file)
{

	// STUDENT TASK - Prompt the end user for the name of the file like in the sample output. 
	string file_name;
	cout << "What is the name of your file?" << endl;
	cin >> file_name;
	input_file.open(file_name);

	if (input_file.fail())
	{
		//  STUDENT TASK:  GIVE THE USER AN ERROR MESSAGE
		cout << "Failed to load file: " << file_name <<endl;
		return false;
	}
	else
		return true;
}


//--------------------------------------------------------------------
void fill_stock_from_file(Stock & s, ifstream & in_file, int & count)
//void fill_stock_from_file( ifstream &, int & count)  // temporary starting version.
{
	char line[81];

	//  STUDENT TASK - you'll need some variables.
	//Stock st;
	string symbol;
	string name_with_quotes;
	double price;
	double earnings;

	//in_file;

	in_file.getline(line, 80);
	if (!in_file.eof()) {
		tokenizer(line, symbol, name_with_quotes, price, earnings);
	//  STUDENT TASK -  update your stock here
	//	s.update(symbol, name_with_quotes, price, earnings);
		st[cnt].update(symbol, name_with_quotes, price, earnings);
		//s.print();
		cnt++;

		
	}
}

void tokenizer(char line[], string & symbol,string & name_with_quotes,double & price, double & earnings)
{

	string token;
	istringstream iss(line);

	std::getline(iss, symbol, ',');
	std::getline(iss, name_with_quotes, ',');
	std::getline(iss, token, ',');
	price = atof(token.c_str());
	std::getline(iss, token, ',');
	earnings = atof(token.c_str());

}
