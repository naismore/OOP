#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../minidictionary/SearchTranslation.h"
#include "../minidictionary/AddTranslation.h"
#include "../minidictionary/OpenDictionaryFile.h"
#include <iostream>
#include <map>

TEST_CASE()
{
	std::map<std::string, std::string> dictionary;

	CHECK(AddTranslation("dog", "собака", dictionary));

	CHECK(SearchTranslation("dog", dictionary) == "собака");
}