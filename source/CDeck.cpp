#include "CDeck.h"

using namespace std;

CDeck::CDeck( vector<CCard> cardList ) {
	m_vDeck = cardList;
}

CDeck::~CDeck() {
};

vector<CCard> CDeck::getDeck() {
	return m_vDeck;
}

int CDeck::getCardNum() {
	int size = m_vDeck.size();
	assert( size >= 0 );
	TRACE( size );
	return size;
}

void CDeck::shuffleDeck() {
	random_shuffle ( m_vDeck.begin(), m_vDeck.end() );
}

/** As it is set up such that the top of the deck is the last element of the vector,
/*  @param n : n-th card starting from top of the deck ( Top card is 1 )
/*
**/
CCard CDeck::getAndRemoveCardFromDeck( unsigned int n ) {
	assert( n <= m_vDeck.size() );
	assert( m_vDeck.size() != 0 );
	
	vector<CCard>::reverse_iterator rit = m_vDeck.rbegin();
	CCard card = *( rit + n - 1 );
	m_vDeck.erase( --( ( rit + n - 1 ).base() ) );
	return card;
}

CCard CDeck::getAndRemoveTopCardFromDeck() {
	assert( m_vDeck.size() != 0 );
	
	CCard card = m_vDeck.back();
	m_vDeck.pop_back();
	return card;
}

void CDeck::printDeck() {
	ostringstream ss;
	
	for ( vector<CCard>::iterator it = m_vDeck.begin() ; it != m_vDeck.end(); ++it ) {
		ss << ( *it ).getName() << "  "; 
	}
	
	cout << "Deck card num:" << getCardNum() << endl;
	cout << "[DECK] " << ss.str() << endl << endl; 
}