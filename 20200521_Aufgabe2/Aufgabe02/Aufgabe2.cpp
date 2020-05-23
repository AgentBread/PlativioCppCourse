/* ----------------------------------------------------------------------------
** Filename: Aufgabe02.cpp
** Version: 0
** Revision: 1
** Release: 2020-05-22
** Author: Stephanie Walcher <mail>
** ----------------------------------------------------------------------------
** includes:
*/
#include <cstdlib>
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
/*
** ----------------------------------------------------------------------------
** global variables:
** none
** ----------------------------------------------------------------------------
** forward declarations:
*/
void printara( string ) ;
/*
** ----------------------------------------------------------------------------
** usage:
** roemische in arabische Zahlen umwandeln: 1 bis 3999
** "main"
** parameters:
**  none
** returns:
** 0 = ok 1 = error
** ---------------------------------------------------------------------------
** remarks:
** none
*/
int main( void ){
	//ask for user input, cast to string numeral
	string numeral ;
	cout << "Please enter roman rumeral between " << MIN_VALUE << " and " << MAX_VALUE << endl ;
	cin >> numeral ;
	printara( numeral ) ;
	system( "pause" ) ;
	return 0 ;
	}
//convert to roman
void printara( string numeral ) {
	int output = 0 ;
	int nl = numeral.length( ) ;
	int c = 13 ;
	string rom[ ] = { "I" , "IV", "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" ,  "D" , "CM" , "M" } ;
	int ara[ ] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000 } ;	
	if ( !regex_match( numeral , regex( "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$") ) ) {
		cout << "Invalid Input" << endl;
		return ;
		}
	for ( int i = 0 ; i < nl ; i++ ) {
		string nums ;
		bool found = false ;
		if ( i + 1  < nl ) {
			nums = string( 1 , numeral[ i ] ) + string( 1, numeral[ i + 1 ] ) ;
			for ( int j = 0 ; j < c ; j++ ) {
				if ( rom [ j ] == nums ) {
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
			if ( rom [ k ] == nums ) {
				output += ara[ k ] ;
				break ;
				}
			}
		}
cout << output ;
}