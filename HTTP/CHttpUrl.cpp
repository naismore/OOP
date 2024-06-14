#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <stdexcept>
#include <string>
#include <cctype>

CHttpUrl::CHttpUrl(const std::string& url) {
    // парсинг URL
    size_t pos = url.find("://");
    if (pos == std::string::npos) {
        throw CUrlParsingError("Invalid URL: no protocol specified");
    }
    std::string protocolStr = url.substr(0, pos);
    if (protocolStr == "http") {
        protocol_ = Protocol::HTTP;
    }
    else if (protocolStr == "https") {
        protocol_ = Protocol::HTTPS;
    }
    else {
        throw CUrlParsingError("Invalid URL: unknown protocol");
    }
    size_t start = pos + 3;
    pos = url.find('/', start);
    if (pos == std::string::npos) {
        domain_ = url.substr(start);
        document_ = "/";
    }
    else {
        domain_ = url.substr(start, pos - start);
        document_ = url.substr(pos);
        if (!document_.empty() && document_[0] != '/') {
            document_ = "/" + document_;
        }
    }
    port_ = (protocol_ == Protocol::HTTP) ? 80 : 443;
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol)
    : domain_(domain), document_(document), protocol_(protocol) {
    if (domain.empty()) {
        throw std::invalid_argument("Invalid domain: cannot be empty");
    }
    if (document.empty()) {
        throw std::invalid_argument("Invalid document: cannot be empty");
    }
    if (document[0] != '/') {
        document_ = "/" + document_;
    }
    port_ = (protocol_ == Protocol::HTTP) ? 80 : 443;
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
    : domain_(domain), document_(document), protocol_(protocol), port_(port) {
    if (domain.empty()) {
        throw std::invalid_argument("Invalid domain: cannot be empty");
    }
    if (document.empty()) {
        throw std::invalid_argument("Invalid document: cannot be empty");
    }
    if (port < 1 || port > 65535) {
        throw std::invalid_argument("Invalid port number: out of range");
    }
    if (document[0] != '/') {
        document_ = "/" + document_;
    }
}

std::string CHttpUrl::GetURL() const {
    std::string url = (protocol_ == Protocol::HTTP) ? "http" : "https";
    url += "://" + domain_ + document_;
    if (port_ != ((protocol_ == Protocol::HTTP) ? 80 : 443)) {
        url += ":" + std::to_string(port_);
    }
    return url;
}

std::string CHttpUrl::GetDomain() const {
    return domain_;
}

std::string CHttpUrl::GetDocument() const {
    return document_;
}

Protocol CHttpUrl::GetProtocol() const {
    return protocol_;
}

unsigned short CHttpUrl::GetPort() const {
    return port_;
}