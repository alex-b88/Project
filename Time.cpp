#include "Time.h"

Time_::Time_()
{
	tm* obj = new tm;
	time_t tik = time(NULL);
	localtime_r(&tik,obj);

	this->hour = obj->tm_hour;
	this->min = obj->tm_min;
	this->sec = obj->tm_sec;
	this->format = true;
}

Time_::Time_(int hour, int min, int sec, bool format)
{
	setHour(hour);
	setMinutes(min);
	setSeconds(sec);
	setFormat(format);
}

Time_::~Time_()
{
}

void Time_::setHour(int hour)
{
	if (hour >= 0 && hour <= 23)
		this->hour = hour;
}

void Time_::setHour()
{
	int tmp;
	cin >> tmp;
	if (tmp >= 0 && tmp <= 23)
		this->hour = tmp;
}

int Time_::getHour() const
{
	return hour;
}

void Time_::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)
		this->min = minutes;
}

void Time_::setMinutes()
{
	int tmp;
	cin >> tmp;
	if (tmp >= 0 && tmp <= 59)
		this->min = tmp;
}

int Time_::getMinutes() const
{
	return min;
}

void Time_::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds <= 59)
		this->sec = seconds;
}

int Time_::getSeconds() const
{
	return sec;
}

void Time_::setFormat(bool format)
{
	if (!format) this->format = false;
}

bool Time_::getFormat() const
{
	return format;
}

bool Time_::valid() const
{
	if (this->sec >= 0 && this->sec <= 59 && this->min >= 0 && this->min <= 59 && this->hour >= 0 && this->hour <= 23)
		return true;
	return false;
}

void Time_::tickTime(int n)
{
	if (n > 0) {
		for (int i = 0; i < n; i++)
		{
			sec++;
			if (sec > 59)
			{
				min++;
				sec -= 60;
			}
			if (min > 59) {
				hour++;
				min -= 60;
			}
			if (hour > 23)
				hour -= 24;
		}
	}
}

void Time_::untickTime(int n)
{
	if (n > 0) {
		for (int i = 0; i < n; i++)
		{
			sec--;
			if (sec < 0)
			{
				min--;
				sec += 60;
			}
			if (min < 0) {
				hour--;
				min += 60;
			}
			if (hour < 0)
				hour += 24;
		}
	}
}

void Time_::showTime(bool isSec) const
{
	if (format)
	{
		cout << this->hour / 10 << this->hour % 10 << ":" << this->min / 10 << this->min % 10;
		if (isSec) cout << ":" << this->sec / 10 << this->sec % 10;
	}
	else
	{
		if (this->hour > 12 && this->hour <= 23) {
			cout << (this->hour - 12) / 10 << (this->hour - 12) % 10 << ":" << this->min / 10 << this->min % 10;
			if (isSec) cout << ":" << this->sec / 10 << this->sec % 10;
			cout << " PM";
		}
		else {
			cout << this->hour / 10 << this->hour % 10 << ":" << this->min / 10 << this->min % 10;
			if (isSec) cout << ":" << this->sec / 10 << this->sec % 10;
			cout << " AM";
		}
	}
}

bool Time_::operator==(const Time_& obj) const&
{
	return (this->hour == obj.hour && this->min == obj.min && this->sec == obj.sec);
}

bool Time_::operator!=(const Time_& obj) const&
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
	if (this->hour > obj.hour)
		return true;
	else if (this->hour == obj.hour && this->min > obj.min)
		return true;
	else if (this->hour == obj.hour && this->min == obj.min && this->sec > obj.sec)
		return true;
	return false;
}

bool Time_::operator<(const Time_& obj) const&
{
	return !(*this > obj) && !(*this == obj);
}

bool Time_::operator>=(const Time_& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Time_& Time_::operator+=(int s)
{
	this->tickTime(s);
	return *this;
}

Time_& Time_::operator-=(int s)
{
	this->untickTime(s);
	return *this;
}

Time_& Time_::operator+=(float m)
{
	if (m > 0) {
		min += m;
		if (min > 59)
		{
			hour += (min - 1) / 60;
			min %= 60;
			if (hour > 23)
				hour -= 24;
		}
	}
	return *this;
}

Time_& Time_::operator-=(float m)
{
	if (m > 0) {
		min -= m;
		if (min < 0)
		{
			hour -= abs(min / 60) + 1;
			min = 60 - abs(min % 60);
			if (hour < 0)
				hour += 24;
		}
	}
	return *this;
}

Time_& Time_::operator+=(long h)
{
	if (h >= 0) {
		hour += h;
		if (hour > 23)
			hour -= 24;
	}
	return *this;
}

Time_& Time_::operator-=(long h)
{
	if (h >= 0) {
		hour -= h;
		if (hour < 0)
			hour += 24;
	}
	return *this;
}

Time_ Time_::operator+(int s) const&
{
	Time_ tmp = *this;
	tmp += s;
	return tmp;
}

Time_ Time_::operator-(int s) const&
{
	Time_ tmp = *this;
	tmp -= s;
	return tmp;
}

Time_ Time_::operator+(float m) const&
{
	Time_ tmp = *this;
	tmp += m;
	return tmp;
}

Time_ Time_::operator-(float m) const&
{
	Time_ tmp = *this;
	tmp -= m;
	return tmp;
}

Time_ Time_::operator+(long h) const&
{
	Time_ tmp = *this;
	tmp += h;
	return tmp;
}

Time_ Time_::operator-(long h) const&
{
	Time_ tmp = *this;
	tmp -= h;
	return tmp;
}

Time_& Time_::operator--()
{
	this->untickTime(1);
	return *this;
}

Time_ Time_::operator--(int)
{
	Time_ tmp = *this;
	this->untickTime(1);
	return tmp;
}

Time_& Time_::operator++()
{
	this->tickTime(1);
	return *this;
}

Time_ Time_::operator++(int)
{
	Time_ tmp = *this;
	this->tickTime(1);
	return tmp;
}

Time_ operator+(int sec, const Time_& a)
{
	return a + sec;
}

Time_ operator-(int sec, const Time_& a)
{
	return a - sec;
}

ostream& operator<<(ostream& os, const Time_& t)
{
	os << t.hour / 10 << t.hour % 10 << ":" << t.min / 10 << t.min % 10 << ":" << t.sec / 10 << t.sec % 10;
	return os;
}

istream& operator>>(istream& is, Time_& t)
{
	do {
		cout << "Ввести ЧЧ ММ СС: ";
		is >> t.hour >> t.min >> t.sec;
	} while (!t.valid());
	return is;
}
