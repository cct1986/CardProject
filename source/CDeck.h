#ifndef CDECK_H
#define CDECK_H

#include <iostream>
#include "debug.h"
#include <assert.h>

#include <sstream>
#include <algorithm>
#include <vector>
#include "CCard.h"

class CDeck {
	std::vector<CCard> m_vDeck; // Last (bottom) card of the deck is the first element

private:
public:
	CDeck( std::vector<CCard> cardList );
	~CDeck();

	std::vector<CCard> getDeck();

	int getCardNum();
	void shuffleDeck();

	bool insertCard( unsigned int pos, CCard card );
	bool insertCardFromTop( CCard card );
	bool insertCardFromBottom( CCard card ); 

	CCard getCard( unsigned int n );
	CCard getAndRemoveCardFromDeck( unsigned int n );
	CCard getAndRemoveTopCardFromDeck();

	void printDeck();
};

#endif