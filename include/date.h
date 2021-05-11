// date.h
#ifndef H_date
#define H_date

//-------------------------------------------------------------------------
// includes
#include <iostream>
#include <string>

//-------------------------------------------------------------------------
/**
 * @class date
 * @brief manages date, month, year data in program
 *
 */
class date
{
public:
	/**
	 * @brief Construct a new date object
	 * 
	 */
	date();

	/**
	 * @brief Construct a new date object
	 * 
	 * @param dd 
	 * @param mm 
	 * @param yyyy 
	 */
	date(int dd, int mm, int yyyy);

	/**
	 * @brief Destroy the date object
	 * 
	 */
	~date();

	/**
	 * @brief Set the Day object
	 * 
	 * @param dd 
	 * @return void
	 */
	void setDay(int dd);

	/**
	 * @brief Set the Month object
	 * 
	 * @param mm 
	 * @return void
	 */
	void setMonth(int mm);

	/**
	 * @brief Set the Year object
	 * 
	 * @param yyyy 
	 * @return void
	 */
	void setYear(int yyyy);

	/**
	 * @brief Set the Date object
	 * 
	 * @param dd 
	 * @param mm 
	 * @param yyyy 
	 * @return void
	 */
	void setDate(int dd, int mm, int yyyy);

	/**
	 * @brief extract date,month,year from program
	 * print details
	 * @return void
	 * 
	 */
	void print();

	/**
	 * @brief Get the Day object
	 * 
	 * @return int 
	 */
	int getDay() const;

	/**
	 * @brief Get the Month object
	 * 
	 * @return int 
	 */
	int getMonth() const;

	/**
	 * @brief Get the Year object
	 * 
	 * @return int 
	 */
	int getYear() const;

	/**
	 * @brief Get the Date As Int object
	 * 
	 * @return int 
	 */
	int getDateAsInt();

	/**
	 * @brief overload < operator
	 * 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	bool operator<(date &rhs) const;

	/**
	 * @brief 
	 * 
	 * @param rhs 
	 * @return true 
	 * @return false 
	 */
	bool operator==(date &rhs) const;

	/**
	 * @brief 
	 * 
	 * @param rhs 
	 * @return date& 
	 */
	date &operator=(const int rhs);

private:
	int Day;
	int Month;
	int Year;
};

#endif // !H_date
