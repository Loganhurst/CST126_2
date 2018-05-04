//--------------------------------------------------------------------
// stock.h
//     
//--------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;





class Stock
{
public:
	
	Stock(string c_symbol, string c_name_with_quotes, double c_price, double c_earnings) {update(c_symbol, c_name_with_quotes, c_price, c_earnings); };
	Stock();
	auto print() { cout << symbol << "\t" << name_with_quotes << "\t Price: " << price << "\t Earnings " << earnings << "\t P/E " << price / earnings << endl; };
	double aprc_r(double aprc = 1.1) {return price = aprc * price; };

	double OPerct() { return price = price * 1 + price / 100; }
	void update(string c_symbol, string c_name_with_quotes, double c_price, double c_earnings) { symbol = c_symbol; name_with_quotes = c_name_with_quotes; price = c_price; earnings = c_earnings; };
	
private:
	string symbol;
	string name_with_quotes;
	double price;
	double earnings;
};
