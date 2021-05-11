// Implemenetation
#include <iostream>
#include <string>
#include "date.h"

// Default contructor
date::date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

// Destructor
date::~date()
{
}

// Specific constructor
date::date(int dd, int mm, int yyyy)
{
	Day = dd;
	Month = mm;
	Year = yyyy;
}

//setters
void date::setDay(int dd)
{
	Day = dd;
}
void date::setMonth(int mm)
{
	Month = mm;
}
void date::setYear(int yyyy)
{
	Year = yyyy;
}
void date::setDate(int dd, int mm, int yyyy)
{
	Day = dd;
	Month = mm;
	Year = yyyy;
}

//getters
int date::getDay() const
{
	return Day;
}
int date::getMonth() const
{
	return Month;
}
int date::getYear() const
{
	return Year;
}
int date::getDateAsInt()
{
	return Day + (Month * 100) + (Year * 10000);
}

//comparison operator overloading
bool date::operator<(date &rhs) const
{
	if (this->getYear() < rhs.getYear())
	{
		return true;
	}
	else if (this->getYear() == rhs.getYear())
	{
		if (this->getMonth() < rhs.getMonth())
		{
			return true;
		}
		else if (this->getMonth() == rhs.getMonth())
		{
			if (this->getDay() < rhs.getDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool date::operator==(date &rhs) const
{
	if (this->getYear() == rhs.getYear())
	{
		if (this->getMonth() == rhs.getMonth())
		{
			if (this->getDay() == rhs.getDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

// Copy assignment
date &date::operator=(const int rhs)
{
	if (rhs == 0)
	{
		this->setDay(00);
		this->setMonth(00);
		this->setYear(0000);
	}
	return *this;
}
