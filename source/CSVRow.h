#ifndef CSVROW_H
#define CSVROW_H 

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVRow
{
public:
	std::string const& operator[](size_t index) const;

	size_t size() const;

	void readNextRow(std::istream& str);

private:
	std::vector<std::string>    m_data;
};

#else
#endif //CSVROW_H