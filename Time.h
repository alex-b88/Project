#pragma once
#include <iostream>
#include<cstring>

using namespace std;

class Time_
{
	int hour;
	int min;
	int sec;
	bool format;

public:
	Time_();
	Time_(int hour, int min, int sec, bool format = true);
	~Time_();

	void setHour(int hour);
	void setHour();
	int getHour()const;
	void setMinutes(int minutes);
	void setMinutes();
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool format);
	bool getFormat()const;

	bool valid()const; //Time_ check
	void tickTime(int n); //every tick add one second
	void untickTime(int n); //every tick remove one second
	void showTime(bool isSec)const; //show Time_ by the format

//--------- ОПЕРАТОРЫ СРАВНЕНИЯ ---------
	bool operator == (const Time_& obj)const&;
	bool operator != (const Time_& obj)const&;
	bool operator > (const Time_& obj)const&;
	bool operator < (const Time_& obj)const&;
	bool operator >= (const Time_& obj)const&;
	bool operator <= (const Time_& obj)const&;

	//--------- ОПЕРАТОРЫ ПРИСВОЕНИЯ ---------
	Time_& operator += (int s);		// add seconds
	Time_& operator -= (int s);
	Time_& operator += (float m);	// add minutes
	Time_& operator -= (float m);
	Time_& operator += (long h);		// add hours
	Time_& operator -= (long h);

	//--------- АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ ---------
	Time_ operator + (int s)const&;	// add seconds
	Time_ operator - (int s)const&;
	Time_ operator + (float m)const&; // add minutes
	Time_ operator - (float m)const&;
	Time_ operator + (long h)const&; // add hours
	Time_ operator - (long h)const&;

	Time_& operator --();
	Time_ operator --(int);
	Time_& operator ++();
	Time_ operator ++(int);

	friend Time_ operator +(int sec, const Time_& a);
	friend Time_ operator -(int sec, const Time_& a);

	friend ostream& operator <<(ostream& os, const Time_& t);
	friend istream& operator >>(istream& is, Time_& t);

};

