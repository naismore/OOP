#ifndef CHTTPURL_H
#define CHTTPURL_H

#include <string>
#include <stdexcept>

enum class Protocol {
    HTTP,
    HTTPS
};

class CHttpUrl {
public:
    CHttpUrl(const std::string& url);
    CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol = Protocol::HTTP);
    CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port);

    std::string GetURL() const;
    std::string GetDomain() const;
    std::string GetDocument() const;
    Protocol GetProtocol() const;
    unsigned short GetPort() const;

private:
    std::string domain_;
    std::string document_;
    Protocol protocol_;
    unsigned short port_;
};

#endif // CHTTPURL_H