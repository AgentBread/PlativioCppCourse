/* ----------------------------------------------------------------------------
** Filename: Aufgabe02.1.cpp
** Version: 0
** Revision: 1
** Release: 2020-05-xx
** Author: Stephanie Walcher <mail>
** ----------------------------------------------------------------------------
** includes:
*/
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <sstream>
#include <regex>
/*
** ----------------------------------------------------------------------------
** defines:
*/
using namespace std;
#define MIN_VALUE "I" //1
#define MAX_VALUE "MMMCMXCIX" //3999
#define MIN_VALUE_ARA 1
#define MAX_VALUE_ARA 3999
/*
** ----------------------------------------------------------------------------
** global variables:
** none
** ----------------------------------------------------------------------------
** forward declarations:
*/
int printara( string , string [ ] , int[ ] ) ;
void printroem( int ) ;
int repetitions ( string , int , int ) ;
/*
** ----------------------------------------------------------------------------
** usage:
** roemische in arabische Zahlen umwandeln: 1 bis 3999
** arabische in roemische Zahlen umwandeln: I bis MMMCMXCIX
** Richtung automatisch erkennen. Input validieren.
** "main"
** parameters:
**  none
** returns:
** 0 = ok 1 = error
** ---------------------------------------------------------------------------
** remarks:
** none
*/
int main( void ) {
	//ask for user input, cast to string numeral
	string numeral ;
	string rom[ ] = { "I" , "IV", "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" ,  "D" , "CM" , "M" } ;
	int ara[ ] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000 } ;
	cout << "Please enter roman rumeral between " << MIN_VALUE << " and " << MAX_VALUE << endl << "or enter integer between " << MIN_VALUE_ARA << " and " << MAX_VALUE_ARA << ": " ; 
	cin >> numeral ;
	int p = 12 ; //point to last element = "M", reduce to 0 under conditions
	int x = 0 ; //point to string input
	int c = 0 ; //counter for recurrance
	int a = 0 ; //output
	string str = numeral.substr ( x , 1 ) ;
	while( str == rom[ p ] && a >= 0 ) { //while eg "M" found
		c++ ;
		x++ ;
		a += ara[ p ] ;
		a = repetitions ( str , c , a ) ;
		str = numeral.substr ( x , 1 ) ;
		}
	bool valid = a >= 0 ;
	while ( valid ) {
		c = 0 ;
		p-- ;
		bool found = false ;
		str = numeral.substr( x , 2 ) ;
		if ( str == rom[ p ] || str == rom[ p - 2 ]) {
			while ( (str == rom[ p ] || str == rom[ p - 2 ] ) && a >= 0 ) {
				a += ara[ str == rom[ p - 2 ] ? p - 2 : p ] ;
				a = repetitions ( str , c , a ) ;
				p -= 3 ;
				x += 2 ;
				found = true ;
				}
			c = 0 ;
		}
		if ( !found ) {
			str = numeral.substr ( x , 1 ) ;
			if ( str == rom[ p - 1 ] ) {
				while ( str == rom [ p - 1 ] && a >= 0) {
					c++ ;
					a += ara[ p - 1 ] ;
					a = repetitions ( str , c , a ) ;
					x++ ;
					found = true ;
				}
			}
			if ( x < numeral.length( ) ) {
				str = numeral.substr ( x , 1 ) ;
				if ( str == rom[ p - 3 ] ) {
					while ( str == rom[ p - 3 ] && a >= 0 ) {
						c++ ;
						a += ara[ p - 3 ] ;
						a = repetitions ( str , c , a ) ;
						x++ ;
						found = true ;
					}
				}
				if ( !found ) {
					valid = p > 0 ;
				}
				valid = valid && x < numeral.size( ) && a >= 0 ;
				p -= 4 ;
				c = 0 ;
			}
		}
	}
	/*
	if ( regex_match( numeral , regex( "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$") ) ) { //if statement for rom-to-ara conversion
		printara( numeral , rom[ ] , ara[ ] ) ;
		return 0 ;
		}
*/
//control statement to catch false input: if no mismatch is found, the function returns string::npos.
	 if ( numeral.find_first_not_of( "0123456789" ) != string::npos && a <= 0 ) { 
		cout << "Invalid Input " << endl ;
		return 0 ;
		}
	int num = stoi( numeral ) ;
	if (num >= MIN_VALUE_ARA && num <= MAX_VALUE_ARA ) {
		printroem( num ) ;
		}
	else {
		cout << "Invalid Input " << endl ;
		}
	return 0 ;
	}
//within validation of input: check repetition of letters
int repetitions ( string str , int c , int a) {
	if ( str == "M" | str == "C" | str == "X" | str == "I" ) {
		if ( c > 3 ) {
			a = -1 ;
			}
		}
	else if ( str == "IV" | str == "V" | str == "IX" | str == "XL" | str == "L" | str == "XC" | str == "CD" | str == "D" | str == "CM" ) {
		if ( c > 1 ) {
			a = -1 ;
			}
		}
	return a ;
	}
//convert to arabic
int printara( string numeral , string rom[ ] , int ara[ ] ) {
	int output = 0 ;
	int nl = numeral.length( ) ;
	int c = 13 ;
	for ( int i = 0 ; i < nl ; i++ ) {
		string nums ;
		bool found = false ;
		if ( i + 1  < nl ) {
			nums = string( 1 , numeral[ i ] ) + string( 1 , numeral[ i + 1 ] ) ;
			for ( int j = 0 ; j < c ; j++ ) {
				if ( rom[ j ] == nums ) {
					output += ara[ j ] ;
					i++ ;
					found = true ;
					break ;
					}
				}
				if ( found ) { // if match found for 2 letters jump to next letters in numeral
					continue ;
					}
			}
		nums = string( 1, numeral[ i ] ) ;
		for ( int k = 0 ; k < c ; k++ ) {
			if ( rom[ k ] == nums ) {
				output += ara[ k ] ;
				break ;
				}
			}
		}
	return output ;
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