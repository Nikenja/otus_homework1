#define BOOST_TEST_MODULE test_version

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/test/unit_test.hpp>
#include "lib.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version) {
    int version = boost::lexical_cast<int>(Version::getVersion());
    BOOST_CHECK(version > 0);
}

BOOST_AUTO_TEST_SUITE_END()
