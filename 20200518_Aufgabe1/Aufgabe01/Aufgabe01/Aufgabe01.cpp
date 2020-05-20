/*
** ----------------------------------------------------------------------------
** Filename: Aufgabe01.cpp
** Version: 0
** Revision: 1
** Release: 2020-05-20
** Author: Stephanie Walcher <mail>
** ----------------------------------------------------------------------------
** includes:
** ----------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <string>
/*
** ----------------------------------------------------------------------------
** defines:
** ----------------------------------------------------------------------------
*/
using namespace std;
#define MIN_VALUE 1
#define MAX_VALUE 4999

/*
** ----------------------------------------------------------------------------
** global variables:
** ----------------------------------------------------------------------------
** 
** ----------------------------------------------------------------------------
** forward declarations:
** ----------------------------------------------------------------------------
*/
void printroem( int ) ;
/*
** ----------------------------------------------------------------------------
** usage:
** Arabische in Roemische Zahlen umwandeln: 1 bis 3999
** ----------------------------------------------------------------------------
 ** "main"
 ** parameters:
 **  none
** returns:
 ** 0 = ok 1 = error
 ** ---------------------------------------------------------------------------
 ** remarks:
 ** ----------------------------------------------------------------------------
*/
int main( void ){
	//ask for user input, cast to int number
	std::cout << "Please enter integer between " << MIN_VALUE << " and " << MAX_VALUE << ": " ;
	int number = 0 ;
	std::cin >> number ;
	if (number >= MIN_VALUE && number <= MAX_VALUE) {
		printroem( number ) ;
		}
	//cstdlib::sytem( pause ) ;
	return 0 ;
	}
//convert to roman
void printroem( int num ) {
	string rom[ ] = { "I" , "IV", "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" ,  "D" , "CM" , "M" } ;
	int ara[ ] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000 } ;
	int c = 12 ;
	while ( num > 0 ) {
		if ( num >= ara[ c ] ) {
			cout << rom[ c ] ;
			num = num - ara[ c ] ;
		}
		else {
			c--;
		}
	}
}