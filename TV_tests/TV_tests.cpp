#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../TV/CTVSet.h"


TEST_CASE()
{
	CTVSet tv();
	CHECK(tv.Info() == "TV is off");
}
