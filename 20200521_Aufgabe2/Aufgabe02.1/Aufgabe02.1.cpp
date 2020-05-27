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
void printara( string , string [ ] , int[ ] ) ;
void printroem( int ) ;
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
	string str ;				//1-2 letters in input
	int lastpos = 12 ;	//to prevent that currpos > lastpos in 1st iteration
	int currpos = 0 ;		//pos in rom of current match
	int rep = 1 ;				//repetition of the same element in rom
	int x = 0 ;					//x iterates through input
	bool valid = true ; //true = valid input
	do {
		bool found = false ; 
		if ( lastpos == currpos ) {
			rep++ ;
			}
		else {
			rep = 1 ;
			}
		if ( x + 1  < numeral.length( ) ) {
			str = string( 1 , numeral[ x ] ) + string( 1 , numeral[ x + 1 ] ) ;
			if ( str[ 0 ] == str[ 1 ] ) {
				rep++ ;
				x++ ;
				} 
			for ( int j = 0 ; j < 13 ; j++ ) {
				if ( rom[ j ] == str ) {
					currpos = j ;
					valid = currpos <= lastpos ; //invalid for current match > last match
					found = true ;
					break ;
					}
				}
				if ( found ) { 
					valid = valid && rep < 4 ;
					lastpos = currpos ;
					++x ;
					continue ; //if match found for 2 letters jump to next letters in numeral
					}
			}
		str = string( 1 , numeral[ x ] ) ;
		for ( int k = 0 ; k < 13 ; k++ ) { 
			if ( rom [ k ] == str ) {	//match found for 1 letter
				if ( k + 2 < 13 ) {			//k + 2 = next higher round number
					valid = ara[ k ] * rep < ara[ k + 2 ] ; 
					}
				currpos = k ;
				valid = valid && currpos <= lastpos ;
				found = true ;
				break ;
				}
			}
		valid = valid && found && rep < 4 ;
		lastpos = currpos ;
		++x ;
	} while ( valid && x < numeral.length ( ) ) ;
	if ( valid ) {
		printara( numeral , rom, ara ) ;
		return 0 ;
		}
/*
	if ( regex_match( numeral , regex( "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$") ) ) { //if statement for rom-to-ara conversion
		printara( numeral , rom[ ] , ara[ ] ) ;
		return 0 ;
		}
*/
//control statement to catch false input: if no mismatch is found, the function returns string::npos.
	else if ( numeral.find_first_not_of( "0123456789" ) != string::npos ) { 
		cout << "Invalid Input " << endl ;
		return 0 ;
		}
	int num = stoi( numeral ) ;
	if (num >= MIN_VALUE_ARA && num <= MAX_VALUE_ARA ) {
		printroem( num ) ;
		}
	return 0 ;
	}
//convert to roman
void printara( string numeral , string rom[ ] , int ara[ ] ) {
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
cout << output ;
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