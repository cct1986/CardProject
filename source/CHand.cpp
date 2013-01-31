#include "CHand.h"

using namespace std;

CHand::CHand() {
}

CHand::CHand( vector<CCard> cardList ) {
	m_vHand = cardList;
}

CHand::~CHand() {
}

vector<CCard> CHand::getHand() {
	return m_vHand;
}

int CHand::getCardNum() {
	int size = m_vHand.size();
	assert( size >= 0 );
	return size;
}

bool CHand::insertCard( CCard card ) {
	m_vHand.push_back ( card );
	return true;
}

/** Cards are lined up from Left to Right (index 0, 1, 2, 3, 4 ...) 
/*
**/
CCard CHand::getCard( unsigned int n ) {
	assert( n <= m_vHand.size() && 0 != n );
	assert( m_vHand.size() != 0 );

	if( 1 == n ) {
		return m_vHand.front();
	} else if ( m_vHand.size() - 1 == n ) {
		return m_vHand.back();
	}
	
	vector<CCard>::iterator it = m_vHand.begin();
	CCard card = *( it + n - 1 );
	return card;
}

/** Cards are lined up from Left to Right (index 0, 1, 2, 3, 4 ...) 
/*
**/
CCard CHand::getAndRemoveCardFromHand( unsigned int n ) {
	assert( n <= m_vHand.size() );
	assert( m_vHand.size() != 0 );
	
	vector<CCard>::iterator it = m_vHand.begin();
	CCard card = *( it + n - 1 );
	m_vHand.erase( it + n - 1 );
	return card;
}

void CHand::printHand() {
	ostringstream ss;
	
	for ( vector<CCard>::iterator it = m_vHand.begin() ; it != m_vHand.end(); ++it ) {
		ss << ( *it ).getName() << "  "; 
	}
	
	cout << "Hand card num:" << getCardNum() << endl;
	cout << "[HAND] " << ss.str() << endl << endl; 
}