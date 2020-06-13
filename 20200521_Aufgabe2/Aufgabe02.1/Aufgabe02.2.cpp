/*-----------------------------------------------------------------------------
Aufgabe02.2.cpp
revision: 2
Author: Stephanie Walcher 
Date released: 01 June 2020
*/
//INCLUDES
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <sstream>
#include <regex>
#include "Aufgabe02.1\Aufgabe02.2.h"
//DEFINES
//in header file
//FORWARD-DECLARATIONS
//in header file
/*MAIN: 
use: convert between arabic and roman numbers with validation not using regex function
return: 0 = error-free, 1 = error
parameters = none
-----------------------------------------------------------------------------*/
int main( void ) {
	string input;
	int number = 0 ;
  while ( true ) {
   cout << "Enter 'exit' to end the program" << endl ;
   cout << "Enter value between " << MIN_VALUE << " and " << MAX_VALUE << " in either roman or arabic numerals: " ;
   cin >> input ;
   if ( input == "exit" ) {
    break ;
		}
	else if ( input.find_first_not_of( "0123456789" ) != string::npos ) {
		int output = roman_to_arabic( input ) ;
		cout << (output > 0 ? to_string( output ) : "Invalid Input" ) << endl ;
		}
		/* Regex Block:
            if (regex_match(input, regex("^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$"))) {
                cout << roman_to_arabic(input) << endl;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input" << endl;
            }*/
		else {
     stringstream s ;
     s << input ;
     s >> number ;
			if ( number >= MIN_VALUE && number <= MAX_VALUE ) {
				cout << arabic_to_roman( number ) << endl ;
				} 
			else {
				cout << "Invalid Input" << endl ;
				}
      }
    }
	return 0;
}
string arabic_to_roman( int number ) {
	string converted_num ;
  string rom[ 13 ] = { "I" , "IV" , "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" , "D" , "CM" , "M"} ;
  int ara[ 13 ] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000 } ;
  int c = 12 ;
  while (number > 0) {
		if ( ara[ c ] <= number ) {
			converted_num += rom[ c ] ;
      number -= ara[ c ] ;
      }
		else {
     c-- ;
     }
    }
	return converted_num ;
	}
int repetitions( const string& str , int c , int a) {
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
int roman_to_arabic( const string& roman_number ) {
	string rom[ 13 ] = { "I" , "IV", "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" ,  "D" , "CM" , "M" } ;
  int ara[ 13 ] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000 } ;
  int x = 0 ; //viewpoint input
  int p = 12 ; //viewpoint rom
  int c = 0 ; //counts repetitions
  int a = 0 ; //output , -1 in case of error ( to replace valid bool )
  string str = roman_number.substr ( x , 1 ) ;
  while( str == rom[ p ] && a >= 0 ) { 
		c++ ;
    x++ ;
    a += ara[ p ] ;
    a = repetitions ( str , c , a ) ;
    str = roman_number.substr ( x , 1 ) ;
    }
	bool valid = a >= 0 && x < roman_number.length( ) ;
  while ( valid ) {
		c = 0 ;
    p-- ;
    bool found = false ;
    if (x + 1 < roman_number.length( ) ) {
			str = roman_number.substr( x , 2 ) ;
      if (str == rom[ p ] || str == rom[ p - 2 ] ) {
				while ( ( str == rom[ p ] || str == rom[ p - 2 ] ) && a >= 0 ) {
					a += ara[ str == rom[ p - 2 ] ? p - 2 : p ] ;
          a = repetitions( str , c , a ) ;
          p -= 3 ;
          x += 2 ;
          found = true ;
          }
			c = 0 ;
				}
			}
		if ( !found ) {
			str = roman_number.substr ( x , 1 ) ;
			if ( str == rom[ p - 1 ] ) {
				while ( str == rom [ p - 1 ] && a >= 0) {
					c++ ;
					a += ara[ p - 1 ] ;
					a = repetitions ( str , c , a ) ;
					x++ ;
					found = true ;
					}
				}
			if ( x < roman_number.length( ) ) {
				str = roman_number.substr ( x , 1 ) ;
				if ( str == rom[ p - 3 ] ) {
					while ( str == rom[ p - 3 ] && a >= 0 && x < roman_number.length( ) ) {
						c++ ;
						a += ara[p - 3] ;
						a = repetitions( str , c , a ) ;
						x++ ;
						found = true ; 
						if (x < roman_number.length( ) ) {
							str = roman_number.substr( x , 1 ) ;
							}
						}
					}
				if ( !found ) {
					valid = p > 0 ;
					}
				}
			valid = valid && x < roman_number.length( ) && a >= 0 ;
			p -= 3 ;
			c = 0 ;
			}
		}
	return x == roman_number.length( ) ? a : -1 ;
	}