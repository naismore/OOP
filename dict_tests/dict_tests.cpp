#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Dict/AddTranslation.h"
#include "../Dict/SearchTranslation.h"
#include <map>

TEST_CASE("AddTranslation")
{
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std::string> addingTranslation;
	CHECK(!AddTranslation("", "", dictionary, addingTranslation));
	CHECK(AddTranslation("cat", "кошка", dictionary, addingTranslation));
}

TEST_CASE("SearchTranslation")
{
	std::map<std::string, std::string> dictionary;
	dictionary["cat"] = "кошка";
	CHECK(SearchTranslation("", dictionary) == "Undefined");
	CHECK(SearchTranslation("cat", dictionary) == "кошка");
}