#define BOOST_TEST_MODULE version_test

#include <boost/lexical_cast.hpp>
#include <boost/test/unit_test.hpp>
#include "versioner.h"

BOOST_AUTO_TEST_SUITE(version_test)

BOOST_AUTO_TEST_CASE(valid_version) {
    BOOST_CHECK(!Versioner::getVersion().empty());
}

BOOST_AUTO_TEST_SUITE_END()
