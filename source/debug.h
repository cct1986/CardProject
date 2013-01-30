#ifndef DEBUG_H
#define DEBUG_H

#ifdef _DEBUG
#include <sstream>

#define TRACE(msg) {\
    std::ostringstream ss; \
    ss << msg; \
	std::cout << "[DEBUG] " << ss.str() << endl; \
}
#else // _DEBUG 
#define TRACE(msg)
#endif // _DEBUG

#endif //DEBUG_H