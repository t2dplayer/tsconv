#include <iostream>
#include "date.h"

#include <chrono>
#include <sstream>
#include "igloo\igloo_alt.h"

using std::cout, std::cin;
using tsconv::Date;

using namespace igloo;

Describe(DateTests) {
    It(output_test_01) {
        std::stringstream ss;
        ss << d1;
        Assert::That(ss.str(), Equals("2020-07-01T20:56:59"));
    }
    It(output_test_02) {
        std::stringstream ss;
        ss << d2;
        Assert::That(ss.str(), Equals("2020-07-25T19:56:01"));
    }
    It(output_test_03) {
        std::stringstream ss;
        ss << d3;
        Assert::That(ss.str(), Equals("2020-07-26T18:01:59"));
    }
    It(output_test_daily) {
        std::stringstream ss;
        d1.setType(tsconv::ISOType::Dayly);
        ss << d1;
        Assert::That(ss.str(), Equals("2020-07-01"));
    }
    It(output_test_monthly) {
        std::stringstream ss;
        d1.setType(tsconv::ISOType::Monthly);
        ss << d1;
        Assert::That(ss.str(), Equals("2020-07"));
    }
    It(output_test_yeary) {
        std::stringstream ss;
        d1.setType(tsconv::ISOType::Yearly);
        ss << d1;
        Assert::That(ss.str(), Equals("2020"));
    }
    It(compare_test_less) {
        Assert::That(d4 < d5, Equals(true));
    }
    It(compare_test_greater) {
        Assert::That(d4 > d5, Equals(false));
    }
    It(compare_test_equal) {
        Assert::That(d4 == d4, Equals(true));
    }
    Date d1{{2020, 07, 1}, {20, 56, 59}};
    Date d2{{2020, 07, 25}, {19, 56, 1}};
    Date d3{{2020, 07, 26}, {18, 1, 59}};
    Date d4{{2020, 07, 15}, {20, 56, 29}};
    Date d5{{2020, 07, 15}, {20, 56, 30}};
};

int main(int argc, char* argv[]) {
    return TestRunner::RunAllTests(argc, argv);
    return 0;
}
