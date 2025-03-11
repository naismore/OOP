#define CATCH_CONFIG_MAIN // Это говорит Catch о том, что он должен предоставить main()
#include "../OOP6/CHttpUrl.h"
#include "../../catch2/catch.hpp"

TEST_CASE("Valid URL parsing", "[url]")
{
	// Тестирование корректных URL
	REQUIRE_NOTHROW(CHttpUrl("http://example.com"));
	REQUIRE_NOTHROW(CHttpUrl("https://example.com/index.html"));
	REQUIRE_NOTHROW(CHttpUrl("http://example.com:8080/test"));
}

TEST_CASE("Invalid URL parsing", "[url]")
{
	// Тестирование некорректных URL
	REQUIRE_THROWS_AS(CHttpUrl("htp://example.com"), CUrlParsingError);
	REQUIRE_THROWS_AS(CHttpUrl("http://example.com:-1"), CUrlParsingError);
	REQUIRE_THROWS_AS(CHttpUrl("", ""), std::invalid_argument);
}

TEST_CASE("Document name handling", "[url]")
{
	CHttpUrl url("example.com", "index.html");
	REQUIRE(url.GetDocument() == "/index.html");

	CHttpUrl url2("example.com", "/index.html");
	REQUIRE(url2.GetDocument() == "/index.html");

	CHttpUrl url3("example.com", "about");
	REQUIRE(url3.GetDocument() == "/about");
}

TEST_CASE("Protocol and port handling", "[url]")
{
	CHttpUrl url1("example.com", "index.html", Protocol::HTTP);
	REQUIRE(url1.GetProtocol() == Protocol::HTTP);
	REQUIRE(url1.GetPort() == 80);

	CHttpUrl url2("example.com", "index.html", Protocol::HTTPS);
	REQUIRE(url2.GetProtocol() == Protocol::HTTPS);
	REQUIRE(url2.GetPort() == 443);

	CHttpUrl url3("example.com", "index.html", Protocol::HTTPS, 8443);
	REQUIRE(url3.GetPort() == 8443);
}

TEST_CASE("Domain validation", "[url]")
{
	// Проверка на пустой домен
	REQUIRE_THROWS_AS(CHttpUrl("", "index.html"), std::invalid_argument);

	// Проверка на недопустимый домен
	REQUIRE_THROWS_AS(CHttpUrl("invalid_domain", "index.html"), CUrlParsingError);
}

TEST_CASE("Full URL construction", "[url]")
{
	CHttpUrl url("example.com", "/path/to/resource", Protocol::HTTP, 8080);

	// Проверка полного URL
	REQUIRE(url.GetURL() == "http://example.com:8080/path/to/resource");

	CHttpUrl url2("example.com", "/path/to/resource");

	// Проверка полного URL без порта
	REQUIRE(url2.GetURL() == "http://example.com/path/to/resource");
}
