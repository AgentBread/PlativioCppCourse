/* ----------------------------------------------------------------------------
** Filename: Aufgabe3.cpp
** Version: 0
** Revision: 1
** Release: 2020-06-01
** Author: Stephanie Walcher <mail>
** ----------------------------------------------------------------------------
** includes:
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstdio>
/*
** ----------------------------------------------------------------------------
** defines:
*/
using namespace std ;
//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS 1 
//#endif
/*
** ----------------------------------------------------------------------------
** global variables:
** none
** ----------------------------------------------------------------------------
** forward declarations:
*/
void bubblesort( int , char*[ ] ) ;
/*
** ----------------------------------------------------------------------------
** usage:
** sort txt Datei ( z to a )
** "main"
** parameters:
**  none
** returns:
** 0 = ok 1 = error
** ---------------------------------------------------------------------------
** remarks:
** none
*/
int main ( void ) {
	int n = 0 ; //Anzahl der Strings 
  int i ; int j ; //Laufvariable 
  char ** file_strings ; //Zeiger auf Feld von char-Zeigern 
  char word[ 512 ] ; //Speicher zum Einlesen eines Strings 
	FILE* name_file = fopen( "names_40.txt", "r" ) ;
	if ( name_file == NULL) {
		return 1 ;
    }
  while ( fgets( word , sizeof word , name_file ) ) {
		n++ ;
    }
  fseek(name_file, 0, SEEK_SET) ; 
	/* Speicher fuer Zeigerfeld reservieren: */
  file_strings = new( nothrow ) char*[ n ] ;
    if ( file_strings == NULL ) {
			cout << "Speichermangel!" << endl ;
      return 1 ;
			}
	/* n Strings lesen und dynamisch speichern: */
	for ( i = 0 ; i < n ; ++i ) {
		fgets( word , 256 , name_file) ; //max number of char to be copied = 256
		if ( ( file_strings[ i ] = new( nothrow ) char[ strlen( word ) + 1 ] ) == NULL ) {
			cout << "Speichermangel!" << endl;
      return 1 ;
      }
    strcpy( file_strings[ i ] , word ) ; //String umkopieren
		}
  bubblesort(n, file_strings ) ; /* Aufruf der Sortierfunktion: */
	fclose( name_file ) ;
	//write into new txt file:
  ofstream sortedFile( "sorted.txt" ) ;
  for ( j = 0 ; j < n ; ++j ) {
		sortedFile << file_strings [ j ] ;
    }
  sortedFile.close( ) ;
  /* Speicher freigeben: */
  for ( i = 0 ; i < n ; i++ ) {
		delete[ ] file_strings[ i ] ;
    }
  delete[ ] file_strings ;
  return 0 ;
	}
void bubblesort( int n , char *a[ ] ) {
	int i , j ;
	char *tmp ;
	for ( i = n - 1 ; i > 0; --i ) {
		for ( j = 0 ; j < i ; ++j ) {
			if ( strcmp( a[ j ] , a[ j + 1 ] ) < 0 ) {
				tmp = a[ j ] ;
				a[ j ] = a[ j + 1 ] ;
				a[ j + 1 ] = tmp ;
				}
			}
		}
	}