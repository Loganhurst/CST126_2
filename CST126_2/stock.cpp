//--------------------------------------------------------------------
// stock.cpp
//--------------------------------------------------------------------

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;


#include "stock.h"
/*
Stock::Stock(string c_symbol, string c_name_with_quotes, double c_price, double c_earnings)
{
	c_symbol;
	c_name_with_quotes;
	c_price;
	c_earnings;
}
*/

Stock::Stock()
{
	symbol = "";
	name_with_quotes = "";
	price = 0;
	earnings = 0;
}

