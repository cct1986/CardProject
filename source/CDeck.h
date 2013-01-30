#ifndef CDECK_H
#define CDECK_H

#include <iostream>
#include "debug.h"

#include <sstream>
#include <assert.h>
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
		CCard getAndRemoveCardFromDeck( unsigned int n );
		CCard getAndRemoveTopCardFromDeck();
		
		void printDeck();
};

#endif