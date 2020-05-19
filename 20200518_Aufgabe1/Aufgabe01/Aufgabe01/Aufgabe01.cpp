// Aufgabe01.cpp : Defines the entry point for the console application.
// Arabische Zahlen in römische Zahlen umwandeln, von 1 bis 2999

//#include "stdafx.h" 
//#include <limits>
#include <iostream>
#include "Aufgabe01.h"

int main()
{
	// ask for user input, cast to int number
	std::cout << "Please enter integer between " << MIN_VALUE << " and " << MAX_VALUE << ": ";
	int number{};
	std::cin >> number;

	build(number);


	//std::cin.clear(); // reset any error flags
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find a newline
	//std::cin.get(); // get one more char from the user
	return 0;
}

//takes user input and hard-coded letters from low to high to form roman numeral
std::string numerals(int number, std::string low, std::string mid, std::string high) 
{
	if (number < 4 || mid == "" || high == "") //amalgamated if-loop for digit < 4 and for thousand-digit (low=M and mid/high empty) up to 4999
		return std::string(number, low[0]); //string-function returns number * 1st letter of string low 
	else if (number == 4)
		return low + mid;
	else if (number == 5)
		return mid;
	else if (number < 9) //implies number > 5
		return mid + std::string(number % 5, low[0]);
	else if (number == 9)
		return low + high;
	return "";
}

 void build(int number) //constructs roman numerals; calls numerals() for input
{
	 // deconstruct digits 
	 int t{ number % 10000 / 1000 }; //int automatically drops numbers behind comma in C++
	 int h{ number % 1000 / 100 };   
	 int te{ number % 100 / 10 };
	 int o{ number % 10 / 1 };

	// build roman numerals
	std::string thous{ numerals(t, "M", "", "") }; //numeral for thousand-digit, M = 1000
	std::string hunds{ numerals(h, "C", "D", "M") }; //numeral for hundred-digit, C = 100, D = 500
	std::string tens{ numerals(te, "X", "L", "C") }; //numeral for ten-digit, X = 10, L = 50
	std::string ones{ numerals(o, "I", "V", "X") }; //numeral for one-digit, I = 1, V = 5

	std::cout << thous << hunds << tens << ones << '\n'; 

	return;
}