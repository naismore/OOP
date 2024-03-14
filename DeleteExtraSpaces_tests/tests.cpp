#include "catch2/catch.hpp"
#include "DeleteExtraSpaces/RES.h"

TEST_CASE("Delete extra spaces from a    dd   vv v   #")
{
	CHECK(RemoveExtraSpaces("a    dd   vv v   #") == "a dd vv v #");
}