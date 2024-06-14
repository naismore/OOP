#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../HTTP/CHttpUrl.h"
#include "../HTTP/CUrlParsingError.h"

TEST_CASE("CHttpUrl constructor") {
    CHttpUrl httpUrl("http://example.com/path");
    REQUIRE(httpUrl.GetDomain() == "example.com");
    REQUIRE(httpUrl.GetDocument() == "/path");
    REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
    REQUIRE(httpUrl.GetPort() == 80);

    httpUrl = CHttpUrl("example.com", "path", Protocol::HTTPS);
    REQUIRE(httpUrl.GetDomain() == "example.com");
    REQUIRE(httpUrl.GetDocument() == "/path");
    REQUIRE(httpUrl.GetProtocol() == Protocol::HTTPS);
    REQUIRE(httpUrl.GetPort() == 443);

    httpUrl = CHttpUrl("example.com", "path", Protocol::HTTP, 8080);
    REQUIRE(httpUrl.GetDomain() == "example.com");
    REQUIRE(httpUrl.GetDocument() == "/path");
    REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
    REQUIRE(httpUrl.GetPort() == 8080);
}

TEST_CASE("CHttpUrl GetURL") {
    CHttpUrl httpUrl("http://example.com/path");
    REQUIRE(httpUrl.GetURL() == "http://example.com/path");

    httpUrl = CHttpUrl("example.com", "path", Protocol::HTTPS, 8443);
    REQUIRE(httpUrl.GetURL() == "https://example.com/path:8443");
}

TEST_CASE("CHttpUrl parsing error") {
    REQUIRE_THROWS(CHttpUrl("invalid url"));
    REQUIRE_THROWS(CHttpUrl("example.com", "", Protocol::HTTP));
    REQUIRE_THROWS(CHttpUrl("example.com", "path", Protocol::HTTP, 0));
}