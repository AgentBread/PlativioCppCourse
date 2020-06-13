#include <iostream>
#ifndef AUFGABE4_H
#define AUFGABE4_H
class Taxi {
private :
	bool frei ;
	int maxPlatz ;
	int fahrgaeste ;
	void setMaxPlatz( int maxPlatz ) ;
public :
	Taxi( ) ;
	Taxi( int _maxPlaces ) ;

	int getMaxPlatz( ) ;
	void setFrei( bool _frei ) ;
 	bool getFrei( ) ;
	void setFahrgaeste( int _guests ) ;
	int getFahrgaeste( ) ;
	int einsteigen( int number ) ;
	void aussteigen( int number ) ;
	} ;

class Taxiunternehmen {
private :
	Taxi *t1 ;
	Taxi *t2 ;
	Taxi *t3 ;
public :
 	Taxiunternehmen( Taxi* t ) ;
	void printInfo( ) ;
	bool taxiHinzufuegen( Taxi* t ) ;
	int anzahlTaxis( ) ;
	int maxAnzahlSitzplaetze( ) ;
 } ;
#endif
