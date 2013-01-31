#ifndef CSVITERATOR_H
#define CSVITERATOR_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "CSVRow.h"

std::istream& operator>>(std::istream& str,CSVRow& data);

class CSVIterator
{   
public:
	typedef std::input_iterator_tag     iterator_category;
	typedef CSVRow                      value_type;
	typedef std::size_t                 difference_type;
	typedef CSVRow*                     pointer;
	typedef CSVRow&                     reference;

	CSVIterator(std::istream& str);
	CSVIterator();

	// Pre Increment
	CSVIterator& operator++();
	// Post increment
	CSVIterator operator++(int);
	CSVRow const& operator*()   const;
	CSVRow const* operator->()  const;

	bool operator==(CSVIterator const& rhs);
	bool operator!=(CSVIterator const& rhs);
private:
	std::istream*       m_str;
	CSVRow              m_row;
};
#else
#endif //CSVITERATOR_H