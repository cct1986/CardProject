#ifndef CHAND_H
#define CHAND_H

#include <iostream>
#include "debug.h"
#include <assert.h>

#include <vector>
#include <sstream>
#include "CCard.h"

class CHand {

	std::vector<CCard> m_vHand;

public:
	CHand();
	CHand( std::vector<CCard> cardList );
	~CHand();

	std::vector<CCard> getHand();

	int getCardNum();

	bool insertCard( CCard card );

	CCard getCard( unsigned int n );
	CCard getAndRemoveCardFromHand( unsigned int n );

	void printHand();
};

#endif CHAND_H