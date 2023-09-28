#include "DT.h"

bool DT::isLeapYear() const
{
    return (year%4==0 &&(year%100!=0 ||year%400==0));
}

int DT::monthDays() const
{
    switch (month) {
        case 1:	case 3:	case 5:	case 7: case 8:	case 10: case 12:
            return 31;
            break;
        case 4: case 6: case 9: case 11: return 30; break;
        case 2: return isLeapYear() ? 29 : 28;  break;
    }
    return 0;
}

DT::DT() {
    tm* obj = new tm;
    time_t sec = time(NULL);
    localtime_r(&sec,obj);

    this->year = obj->tm_year + 1900;
    this->month = obj->tm_mon + 1;
    this->day = obj->tm_mday;
    this->hour = obj->tm_hour;
    this->min = obj->tm_min;
    this->sec = obj->tm_sec;
    this->format = true;
    delete obj;
}

DT::DT(char type, int day_or_hour, int month_or_minutes, int year_or_sec) {
    if(type == 'd'){
        tm* obj = new tm;
        time_t sec = time(NULL);
        localtime_r(&sec,obj);
        this->hour = obj->tm_hour;
        this->min = obj->tm_min;
        this->sec = obj->tm_sec;
        this->format = true;
        delete obj;
        setDay(day_or_hour);
        setMonth(month_or_minutes);
        setYear(year_or_sec);
    }
    else if(type=='t'){
        DT();
        tm* obj = new tm;
        time_t sec = time(NULL);
        localtime_r(&sec,obj);
        this->year = obj->tm_year + 1900;
        this->month = obj->tm_mon + 1;
        this->day = obj->tm_mday;
        delete obj;
        this->hour=day_or_hour;
        this->min=month_or_minutes;
        this->sec=year_or_sec;
        format=true;
    }
}

void DT::showDateAndTime(bool isSec) const {
    DT::showDate();
    DT::showTime(isSec);
}

void DT::showDate() const {
    std::cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << " ";
}

void DT::showTime(bool isSec) const {
    if (format)
    {
        std::cout << this->hour / 10 << this->hour % 10 << ":" << this->min / 10 << this->min % 10;
        if (isSec) std::cout << ":" << this->sec / 10 << this->sec % 10;
    }
    else
    {
        if (this->hour > 12 && this->hour <= 23) {
            std::cout << (this->hour - 12) / 10 << (this->hour - 12) % 10 << ":" << this->min / 10 << this->min % 10;
            if (isSec) std::cout << ":" << this->sec / 10 << this->sec % 10;
            std::cout << " PM";
        }
        else {
            std::cout << this->hour / 10 << this->hour % 10 << ":" << this->min / 10 << this->min % 10;
            if (isSec) std::cout << ":" << this->sec / 10 << this->sec % 10;
            std::cout << " AM";
        }
    }
}

void DT::setFormat(bool format) {
    this->format=format;
}

void DT::setDay(int day) {
    if(day>0 && day <=monthDays())
    this->day=day;
}

void DT::setMonth(int month) {
    if(month>0 && month<=12)
        this->month=month;
}

void DT::setYear(int year) {
    this->year=year;
}

int DT::getDay() const {
    return day;
}

int DT::getMonth() const {
    return month;
}

int DT::getYear() const {
    return year;
}

void DT::setHour(int hour) {
    if(hour>=0 && hour <=23)
        this->hour=hour;
}

void DT::setMin(int min) {
    if(min>=0 && min <=59)
        this->min=min;
}

void DT::setSec(int sec) {
    if(sec>=0 && sec<=59)
        this->sec=sec;
}

int DT::getHour() const {
    return hour;
}

int DT::getMin() const {
    return min;
}

int DT::getSec() const {
    return sec;
}

bool DT::valid() const
{
    return (day>0 && day<=monthDays() && month>=1 && month<=12 && hour>=0 && hour<=23 && min>=0 && min<=59 && sec>=0 && sec<=59);
}

bool DT::operator==(const DT &obj) const &{
    return (this->year==obj.year && this->month==obj.month && this->day==obj.day && this->hour==obj.hour && this->min==obj.min && this->sec==obj.sec);
}

bool DT::operator!=(const DT &obj) const &{
    return !(*this==obj);
}

bool DT::operator<(const DT &obj) const &{
    if (this->year < obj.year)
        return true;
    else if (this->year == obj.year && this->month < obj.month)
        return true;
    else if (this->year == obj.year && this->month == obj.month && this->day < obj.day)
        return true;
    else if(this->year == obj.year && this->month == obj.month && this->day == obj.day && this->hour<obj.hour)
        return true;
    else if(this->year == obj.year && this->month == obj.month && this->day == obj.day && this->hour==obj.hour && this->min<obj.min)
    return true;
    else if(this->year == obj.year && this->month == obj.month && this->day == obj.day && this->hour>obj.hour && this->min==obj.min && this->sec<obj.sec)
        return true;
    return false;
}

bool DT::operator>(const DT &obj) const &{
    return !(*this>obj) && !(*this==obj);
}
bool DT::operator>=(const DT& obj) const&
{
    return (*this > obj) || (*this == obj);
}

bool DT::operator<=(const DT& obj) const&
{
    return (*this < obj) || (*this == obj);
}

std::ostream& operator<<(std::ostream& os, const DT& t)
{
    os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year << " " << t.hour / 10 << t.hour % 10 << ":" << t.min / 10 << t.min % 10 << ":" << t.sec / 10 << t.sec % 10;
    return os;
}

std::istream& operator>>(std::istream& is, DT& t)
{
    do{
        std::cout << "dd mm yyyy hh min sec: ";
        is >> t.day >> t.month >> t.year >> t.hour >> t.min >> t.sec;
    } while (!t.valid());
    return is;
}