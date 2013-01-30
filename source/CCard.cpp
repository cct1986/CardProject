#include "CCard.h"

using namespace std;

string getECardTypeString( ECardType type ) {
	switch ( type ) {
	case PASS: return "PASS"; break;
	case SHOOT: return "SHOOT"; break;
	default: return "NONE"; break;
	}
}

ECardType getECardTypeFromString( string str ) {
	if( str.compare( "PASS" ) ) {
		return PASS;
	} else if( str.compare( "SHOOT" ) ) {
		return SHOOT;
	} else {
		return NONE;
	}
}

ECardType getECardTypeFromInt( int i ) {
	switch ( i ) {
	case 1: return PASS; break;
	case 2: return SHOOT; break;
	default: return NONE; break;
	}
}

CCard::CCard(){
	m_strName = "";
	m_eType = NONE;
}

CCard::CCard( string name, ECardType type ){
	m_strName = name;
	m_eType = type;
}

CCard::~CCard(){
}

string CCard::getName() { 
	return m_strName; 
}
void CCard::setName( string name ) { 
	m_strName = name; 
}
ECardType CCard::getType() { 
	return m_eType; 
}
void CCard::setType( ECardType type ) { 
	m_eType = type; 
}