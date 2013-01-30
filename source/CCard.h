#ifndef CCARD_H
#define CCARD_H

#include <iostream>
#include "debug.h"

#include "CCard.h"

enum ECardType {
	NONE = 0,
	PASS = 1,
	SHOOT
};

std::string getECardTypeString( ECardType type );

ECardType getECardTypeFromString( std::string str );

ECardType getECardTypeFromInt( int i );

class CCard {
	std::string m_strName;
	ECardType m_eType;
	private:
	public:
		CCard();
		CCard( std::string name, ECardType type );
		~CCard();
		std::string getName();
		void setName( std::string name );
		ECardType getType();
		void setType( ECardType type );
};

#else
#endif //CCARD_H