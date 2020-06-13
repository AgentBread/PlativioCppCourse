/* ----------------------------------------------------------------------------
** Filename: aufgabe4.cpp
** Version: 0
** Revision: 1
** Release: 2020-06-07
** Author: Stephanie Walcher <mail>
** ----------------------------------------------------------------------------
** includes:
*/
#include <iostream>
#include <cstdlib> 
#include <list>
#include "aufgabe4.h"
/*
** ----------------------------------------------------------------------------
** defines:
*/
using namespace std ;
/*
** ----------------------------------------------------------------------------
** global variables:
** none
** ----------------------------------------------------------------------------
** forward declarations:
*/
/*
** ----------------------------------------------------------------------------
** usage:
** Uebung Taxi
** "main"
** parameters:
**  none
** returns:
** 0 = ok 1 = error
** ---------------------------------------------------------------------------
** remarks:
** none
*/
int main ( int argc , char* argv[ ] ) {
	new Taxiunternehmen ( NULL ) ;
	return 0 ;
	}

Taxi::Taxi( ) {
	setMaxPlatz( 3 ) ;
	setFahrgaeste( 0 ) ;
	frei = fahrgaeste  == 0 ;
	}

Taxi::Taxi( int _maxPlatz ) {
	frei = fahrgaeste == 0 ;
	setMaxPlatz( _maxPlatz ) ;
	}

int Taxi::getMaxPlatz( ) {
	return maxPlatz ;
	}

void Taxi::setFrei( bool _frei ) {
	frei = fahrgaeste < maxPlatz && _frei ;
	}

bool Taxi::getFrei( ) {
	return frei ;
	}

int Taxi::einsteigen( int personen ) {
	if ( personen > maxPlatz ) {
		setFahrgaeste( maxPlatz ) ;
		return personen - maxPlatz ;	
		}
	else {
		setFahrgaeste( personen ) ;
		}
	return 0 ;
	}

void Taxi::aussteigen( int personen ) {
	setFahrgaeste( fahrgaeste - personen ) ;
	if ( fahrgaeste <= 0 ) {
		frei = true ;
		fahrgaeste = 0 ;
		}
	}

void Taxi::setFahrgaeste( int _fahrgaeste ) {
	if ( fahrgaeste >= 0 && fahrgaeste <= maxPlatz ) {
		fahrgaeste = _fahrgaeste ;
		}
	}

int Taxi::getFahrgaeste( ) {
	return fahrgaeste ;
	}

void Taxi::setMaxPlatz( int _maxPlatz ) {
	maxPlatz = _maxPlatz ;
	}

//---------------------------------------------------

Taxiunternehmen::Taxiunternehmen ( Taxi *t ) {
	if (t == NULL ) {
		cout << "Taxi called" ;
		t1 = new Taxi ;
		}
	else 
		{
		t1 = t ; 
		}
	}

void Taxiunternehmen::printInfo( ) {
	Taxi *taxis [ ] = { t1 , t2 , t3 } ;
	for ( int i = 1 ; i < anzahlTaxis( ) + 1 ; i++ ) {
		cout << "Taxi" << i << ":" << endl ;
		if (taxis[i - 1] != NULL) {
			cout << "Taxi frei: " << taxis[i - 1]-> getFrei( ) << endl ;
			cout << "Anzahl der Fahrgaeste: " << taxis[i - 1]->getFahrgaeste( ) << endl ;
			cout << "Anzahl der maximalen Fahrgaeste: " << taxis[i - 1]->getMaxPlatz( ) << endl ;
			}
		else {
			cout << "Es gibt kein " << i << ". Taxi." << endl ;
			}
		}
	}

bool Taxiunternehmen::taxiHinzufuegen( Taxi *t ) {
	if ( ( t != t2 && t != t3 ) && (t == NULL || t3 == NULL ) ) {
		if ( t2 == NULL ) {
			t2 = t ;	
			}
		else {
		t3 = t ;
		}
		return true ;
		}
	else {
		return false ;
		}
	}

int Taxiunternehmen::anzahlTaxis( ) {
	int i = 1 ;
	i = t2 != NULL && t3 != NULL ? 3 : ( t2 != NULL ? 2 : 1 ) ;
	return i ;
	}

int Taxiunternehmen::maxAnzahlSitzplaetze( ) {
	list<Taxi*> taxis { t1, t2, t3 } ;
	int count = 0 ;
	for (Taxi *taxi : taxis) {
		if (taxi != NULL) {
			count += taxi->getMaxPlatz( ) ;
			}
		}
	return count ;
	}
