#ifndef DATETIME_DT_H
#define DATETIME_DT_H

#include <iostream>

class DT {
protected:
    int year,month,day,hour,min,sec;
    bool format;

    bool isLeapYear()const; //Проверка на високосный год
    int monthDays()const; //Количество дней по месяцу

public:
    DT(); // текущие дата и время
    DT(char type,int day_or_hour, int month_or_minutes, int year_or_sec);
    void showDateAndTime(bool isSec)const;
    void showDate()const;
    void showTime(bool isSec)const;

    void setFormat(bool format);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int getDay()const;
    int getMonth()const;
    int getYear()const;

    void setHour(int hour);
    void setMin(int min);
    void setSec(int sec);
    int getHour()const;
    int getMin()const;
    int getSec()const;

    bool valid()const;

    bool operator == (const DT& obj)const&;
    bool operator != (const DT& obj)const&;
    bool operator < (const DT& obj)const&;
    bool operator > (const DT& obj)const&;
    bool operator>=(const DT &obj) const &;
    bool operator<=(const DT &obj) const &;

    friend std::ostream& operator << (std::ostream& os, const DT& t);
    friend std::istream& operator >> (std::istream& is, DT& t);
};


#endif //DATETIME_DT_H
