/* ----------------------------------------------------------------------------
** Filename: Aufgabe3.cpp
** Version: 0
** Revision: 2
** Release: 2020-06-02
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
//#define _CRT_SECURE_NO_WARNINGS 1 
/*
** ----------------------------------------------------------------------------
** global variables:
** none
** ----------------------------------------------------------------------------
** forward declarations:
*/
void bubblesort_za( int , char*[ ] ) ;
void bubblesort_az( int  , char *[ ] ) ;
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
int main( int argc , char* argv [ ] ) {  //dateiname + Eingabe + Aufsgabe Datei + optionaler param to sort a-z or z-a + 0 = 5 args
  int n = 0 ; //Anzahl der Strings 
  int i ; //Laufvariable 1
  int j ; //Laufvariable 2
  char** file_strings ; //Zeiger auf Feld von char-Zeigern 
  char word[ 512 ] ; //Speicher zum Einlesen eines Strings 
  cout << "Enter input file name , output file name , and optionally za/az: " ;
  FILE* name_file = NULL ;
  if ( argc > 1 ) {
  name_file = fopen( argv [ 1 ] , "r" ) ;
  cout << endl << argv[ 1 ] << endl ;
  }
  else {
  name_file = fopen( "names_40.txt" , "r" ) ;
  }
  if ( name_file == NULL) {
    return 1 ;
  }
  while ( fgets( word , sizeof word , name_file ) ) {
    n++ ;
    }
  fseek( name_file , 0 , SEEK_SET ) ; 
  /* Speicher fuer Zeigerfeld reservieren: */
  file_strings = new( nothrow ) char*[ n ] ;
  if ( file_strings == NULL ) {
    cout << "Speichermangel!" << endl ;
    return 1 ;
  }
  /* n Strings lesen und dynamisch speichern: */
  for ( i = 0 ; i < n ; ++i ) {
    fgets( word , 512 , name_file) ; //fgets replaces /n with /0
    if ( ( file_strings[ i ] = new( nothrow ) char[ strlen( word ) + 1 ] ) == NULL ) {
      cout << "Speichermangel!" << endl ;
      return 1 ;
      }
    strcpy( file_strings[ i ] , word ) ; //umkopieren mit "fput", open with "w"
    }
  fclose( name_file ) ;
  /* Aufruf der Sortierfunktion: */
  cout << "argc: " << argc << endl ;
  cout << "argv[3]: " << argv[ 3 ] << endl ;
  if ( argc > 3 && argv [ 3 ] [ 0 ] == 'z' ) {
    bubblesort_za( n , file_strings ) ;
    }
  else if (argc > 3 && argv [ 3 ] [ 0 ] == 'a' ) {
    bubblesort_az( n , file_strings ) ;
    }
  else {
    cout << "Default-sorting A to Z." ;
    bubblesort_az( n , file_strings ) ;
    }
  //write into new txt file:
  ofstream sortedFile( argv [ 2 ] ) ;  //fopen
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
void bubblesort_za( int n , char *a[ ] ) {
  int i , j ;
  char* tmp ;
  int sw = 1 ; //switch to represent swopping (if 0: file sorted)
  while ( sw == 1 ) {
    sw = 0 ;
    i = n - 1 ;
    for ( j = 0 ; j < i ; ++j ) {
      if ( strcmp( a[ j ] , a[ j + 1 ] ) < 0 ) {
        sw = 1 ;
        tmp = a[ j ] ;
        a[ j ] = a[ j + 1 ] ;
        a[ j + 1 ] = tmp ;
	}
      }
    }
  }		
void bubblesort_az( int n , char *a[ ] ) {
  int i , j ;
  char* tmp ;
  int sw = 1 ; //switch to represent swopping (if 0: file sorted)
    while ( sw == 1 ) {
      sw = 0 ;
      i = n - 1 ;
      for ( j = 0 ; j < i ; ++j ) {
        if ( strcmp( a[ j ] , a[ j + 1 ] ) > 0 ) {
          sw = 1 ;
          tmp = a[ j ] ;
          a[ j ] = a[ j + 1 ] ;
          a[ j + 1 ] = tmp ;
          }
        }
      }
    }		
