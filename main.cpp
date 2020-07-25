#include <iostream>
#include "date.h"

#include <chrono>
#include <sstream>

using std::cout, std::cin;
using tsconv::Date;

int main() {
    Date d{{2020, 07, 24}, {19, 56, 00}};
    d.setType(tsconv::ISOType::Hourly);
    size_t size = 1E7;
    std::stringstream os;
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < size; ++i)
        os << d << '\n';
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    cout << elapsed.count()/1000. << " seconds\n";
    return 0;
}
