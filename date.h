#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <functional>
#include <unordered_map>

namespace tsconv {
    //date format yyyy-mm-ddThh:mm:ss
    //hh -> 24h format
    using Int = unsigned int;
    using Short = unsigned short;
    enum class ISOType {Hourly, Dayly, Monthly, Yearly};
    struct ISODate {Int y = 0; Short m = 1, d = 1;};
    struct ISOTime {Short h = 0, m = 0, s = 0;};
    class Date {
        using OutputFormatter = std::function<std::string(const Date&)>;
        using Compare = std::function<bool(Int, Int)>;
        using Map = std::unordered_map<ISOType, OutputFormatter>;
        ISODate d;
        ISOTime t;
        ISOType type = ISOType::Hourly;
        static bool compare(const Date& d1,
                            const Date& d2,
                            Compare lambda = [](Int x, Int y){ return x < y;});
    public:
        static const Map formatters;
        Date(const ISODate& date,
             const ISOTime& time = {}): d(date), t(time){}
        Date() = delete;
        ISODate getDate() const {
            return d;
        }
        ISOTime getTime() const {
            return t;
        }
        void setType(ISOType type) {
            this->type = type;
        }
        friend std::ostream& operator<<(std::ostream& os,
                                 const Date& date) {
            if (date.formatters.size() != 0) {
                auto func = date.formatters.at(date.type);
                std::string output = func(date);
                os << output;
            }
            return os;
        }
        friend bool operator<(const Date& d1, const Date& d2) {
            return Date::compare(d1, d2);
        }
        friend bool operator>(const Date& d1, const Date& d2) {
            return Date::compare(d1, d2, [](Int x, Int y){return x > y;});
        }
        friend bool operator==(const Date& d1, const Date& d2) {
            return Date::compare(d1, d2) ? false : true;
        }
    };
}

#endif // DATE_H
