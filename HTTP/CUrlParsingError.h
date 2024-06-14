#ifndef CURLPARSINGERROR_H
#define CURLPARSINGERROR_H

#include <stdexcept>
#include <string>

class CUrlParsingError : public std::invalid_argument {
public:
    CUrlParsingError(const std::string& what) : std::invalid_argument(what) {}
};

#endif // CURLPARSINGERROR_H