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

bool CDeck::insertCard( unsigned int pos, CCard card ) {
	assert( pos < m_vDeck.size() && 0 != pos );

	if( 1 == pos ) {
		return insertCardFromTop( card );
	} else if ( m_vDeck.size() - 1 == pos ) {
		return insertCardFromBottom( card );
	}

	vector<CCard>::reverse_iterator rit = m_vDeck.rbegin();
	m_vDeck.insert ( ( rit + pos - 1 ).base() , card );
	return true;
}

bool CDeck::insertCardFromTop( CCard card ) {
	m_vDeck.push_back( card );
	return true;
}

bool CDeck::insertCardFromBottom( CCard card ) {
	m_vDeck.insert ( m_vDeck.begin() , card );
	return true;
}

/** As it is set up such that the top of the deck is the last element of the vector,
/*  @param n : n-th card starting from top of the deck ( Top card is 1 )
/*
**/
CCard CDeck::getCard( unsigned int n ) {
	assert( n <= m_vDeck.size() && 0 != n );
	assert( m_vDeck.size() != 0 );

	if( 1 == n ) {
		return m_vDeck.back();
	} else if ( m_vDeck.size() - 1 == n ) {
		return m_vDeck.front();
	}
	
	vector<CCard>::reverse_iterator rit = m_vDeck.rbegin();
	CCard card = *( rit + n - 1 );
	return card;
}

/** As it is set up such that the top of the deck is the last element of the vector,
/*  @param n : n-th card starting from top of the deck ( Top card is 1 )
/*
**/
CCard CDeck::getAndRemoveCardFromDeck( unsigned int n ) {
	assert( n <= m_vDeck.size() );
	assert( m_vDeck.size() != 0 );

	if( 1 == n ) {
		return getAndRemoveTopCardFromDeck();
	} 

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