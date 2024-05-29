#include "CrossSet.h"
#include <algorithm>
#include <iterator>

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2)
{
    std::set<int> intersection;
    if (!set1.empty() && !set2.empty())
    {
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersection, intersection.begin()));
    }

    return intersection;
}
