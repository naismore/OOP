#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../RemoveExtraSpaces/RemoveExtraSpaces.h"

TEST_CASE("RemoveExtraSpaces")
{
	CHECK(RemoveExtraSpaces("The  quick  brown  fox  jumps  over  the  lazy  dog") == "The quick brown fox jumps over the lazy dog");
	CHECK(RemoveExtraSpaces("         ") == "");
	CHECK(RemoveExtraSpaces("     The quick     brown fox jumps    over the lazy   dog   ") == "The quick brown fox jumps over the lazy dog");
	CHECK(RemoveExtraSpaces("") == "");
	CHECK(RemoveExtraSpaces("\t") == "");
	CHECK(RemoveExtraSpaces("   \t The quick  \t   brown fox jumps  \t  over the lazy   dog\t   ") == "The quick brown fox jumps over the lazy dog");
}
