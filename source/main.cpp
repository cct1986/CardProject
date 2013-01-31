//#define NDEBUG

#include <iostream>
#include "debug.h"

#include <vector>
#include "CSVIterator.h"
#include "CCard.h"
#include "CDeck.h"
#include "CHand.h"

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

	CCard card_1( "insertTop", NONE );
	deck.insertCardFromTop( card_1 );
	CCard card_2( "insertBottom", NONE );
	deck.insertCardFromBottom( card_2 );
	CCard card_3( "insert5thCard", NONE );
	deck.insertCard( 5, card_3 );

	deck.printDeck();

	CCard card_4( "insert2ndCard", NONE );
	deck.insertCard( 2, card_4 );

	deck.printDeck();

	CHand hand;
	hand.insertCard( deck.getAndRemoveTopCardFromDeck() );
	deck.printDeck();

	hand.insertCard( deck.getAndRemoveCardFromDeck( 3 ) );
	hand.printHand();

	deck.printDeck();

	cin.ignore(1);
	
	return 0;
}