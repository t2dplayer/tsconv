#include "date.h"

using namespace tsconv;

const Date::Map Date::formatters = {
    {ISOType::Hourly, [](const Date& d){
         ISODate date = d.getDate();
         ISOTime time = d.getTime();
         // sorry, but this still the fastest way
         char str [20] = {};
         snprintf(str, 20, "%04d-%02d-%02dT%02d:%02d:%02d",
            date.y, date.m, date.d,
            time.h, time.m, time.s);
         return std::string(str);
     }},
    {ISOType::Dayly, [](const Date& d){
         ISODate date = d.getDate();
         // sorry, but this still the fastest way
         char str [11] = {};
         snprintf(str, 11, "%04d-%02d-%02d",
            date.y, date.m, date.d);
         return std::string(str);
     }},
    {ISOType::Monthly, [](const Date& d){
         ISODate date = d.getDate();
         // sorry, but this still the fastest way
         char str [8] = {};
         snprintf(str, 8, "%04d-%02d",
            date.y, date.m);
         return std::string(str);
     }},
    {ISOType::Yearly, [](const Date& d){
         return std::to_string(d.getDate().y);
     }},
};

bool Date::compare(const Date &d1,
                   const Date &d2,
                   Compare lambda) {
    if (d1.getDate().y != d2.getDate().y) {
        return lambda(d1.getDate().y, d2.getDate().y);
    } else if (d1.getDate().m != d2.getDate().m) {
        return lambda(d1.getDate().m, d2.getDate().m);
    } else if (d1.getDate().d != d2.getDate().d) {
        return lambda(d1.getDate().d,  d2.getDate().d);
    } else if (d1.getTime().h != d2.getTime().h) {
        return lambda(d1.getTime().h, d2.getTime().h);
    } else if (d1.getTime().m != d2.getTime().m) {
        return lambda(d1.getTime().m, d2.getTime().m);
    } else if (d1.getTime().s != d2.getTime().s) {
        return lambda(d1.getTime().s, d2.getTime().s);
    }
    return false;
}
