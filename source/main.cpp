//#define NDEBUG

#include <iostream>
#include "debug.h"

#include <vector>
#include "CSVIterator.h"
#include "CCard.h"
#include "CDeck.h"

using namespace std;

int main () {
	ifstream file("../resource/data/cardData.csv");
	
	vector<CCard> cards;

    for( CSVIterator loop(file); loop != CSVIterator() ; ++loop ) {
		istringstream istr( ( *loop )[1] );
		int type;
		istr >> type;
		cards.push_back( CCard( ( *loop )[0], getECardTypeFromInt( type ) ) );
    }
	
	CDeck deck( cards );
	
	deck.printDeck();
	
	CCard thirdCard = deck.getAndRemoveCardFromDeck( 3 );
	
	deck.printDeck();
	
	CCard firstCard = deck.getAndRemoveTopCardFromDeck();
	
	deck.printDeck();
	
	deck.shuffleDeck();
	
	deck.printDeck();

	cin.ignore(1);
	
	return 0;
}