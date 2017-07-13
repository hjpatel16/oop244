#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
  void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }

  void Date::errCode(int errorCode)
  {
	  this->m_readErrorCode = errorCode;
  }
  
  void Date::set(int year, int mon, int day, int hour, int min)
  {
	  this->m_year = year;
	  this->m_mon = mon;
	  this->m_day = day;
	  this->m_hour = hour;
	  this->m_min = min;
	  this->m_readErrorCode = 0;
  }

  Date::Date()
  {
	this->m_dateOnly = false;
	 this->set();
  }
  Date::Date(int year, int mon, int day)
  {
	  this->m_year = year;
	  this->m_mon = mon;
	  this->m_day = day;
	  this->m_hour = 0;
	  this->m_min = 0;
	  this->m_dateOnly = true;
	  this->m_readErrorCode = 0;
  }
  Date::Date(int year, int mon, int day, int hour, int min)
  {
	  this->m_year = year;
	  this->m_mon = mon;
	  this->m_day = day;
	  this->m_hour = hour;
	  this->m_min = min;
	  this->m_dateOnly = false;
	  this->m_readErrorCode = 0;
  }
  bool Date::operator==(const Date& D)const
  {
	  return (this->value() == D.value());
  }
  bool Date::operator!=(const Date& D)const
  {
	  return (this->value() != D.value());
  }
  bool Date::operator<(const Date& D)const
  {
	  return (this->value() < D.value());
  }
  bool Date::operator>(const Date& D)const
  {
	  return (this->value() > D.value());
  }
  bool Date::operator>=(const Date& D)const
  {
	  return (this->value() >= D.value());
  }
  bool Date::operator<=(const Date& D)const
  {
	  return (this->value() <= D.value());
  }
  int Date::errCode() const
  {
	  return this->m_readErrorCode;
  }
  bool Date::bad()const
  {
	  return this->m_readErrorCode != 0;
  }
  bool Date::dateOnly()const
  {
	  return this->m_dateOnly;
  }
  void Date::dateOnly(bool value)
  {
	  this->m_dateOnly = value;
	  if (value == true)
	  {
		  this->m_hour = 0;
		  this->m_min = 0;
	  }
  }
  std::istream& Date::read(std::istream& is)
  {  
	  if (m_dateOnly)
	  {
		  if (is >> this->m_year)
			  is.ignore(100, '/');
		  else{
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  } 
		  if (is >> this->m_mon)
			  is.ignore(100, '/');
		  else
		  {
			  m_readErrorCode = CIN_FAILED;
			  return is;
		  }
		  is >> this->m_day;
			
	  }
	  else
	  {
		  is >> this->m_year;
		  is.ignore(100, '/');
		  is >> this->m_mon;
		  is.ignore(100, '/');
		  is >> this->m_day;
		  is.ignore(100, ',');
		  is.ignore(100, ' ');
		  is >> this->m_hour;
		  is.ignore(100, ':');
		  is >> this->m_min;
		  if (cin.fail())
			  this->m_readErrorCode = CIN_FAILED;
	  }
	  if (this->m_year < 2000 || this->m_year > 2030)
	  {	
		  this->m_readErrorCode = YEAR_ERROR;
		  return is;
	  }

	  if (this->m_mon < 1 || this->m_mon > 12)
	  {
		  this->m_readErrorCode = MON_ERROR;
		  return is;
	  }
	  if (this->m_day < 1 || this->m_day > 31)
	  {
		  this->m_readErrorCode = DAY_ERROR;
		  return is;
	  }
	  if (this->m_hour > 23)
	  {
		  this->m_readErrorCode = HOUR_ERROR;
		  return is;
	  }
	  if (this->m_min < 0 || this->m_min > 59)
	  {
		  this->m_readErrorCode = MIN_ERROR;
		  return is;
	  }

	  return is;
  }
  std::ostream& Date::write(std::ostream& ostr)const
  {
	  if (m_dateOnly)
	  {
		  ostr << this->m_year << "/";
		  if (this->m_mon < 10)
		  {
			  ostr << "0" << this->m_mon<<"/";
		  }
			 
		  else
			  ostr << this->m_mon<<"/";
		  if (this->m_day < 10)
		  {
			  ostr << "0" << this->m_day;
		  }
			  
		  else
			  ostr  << this->m_day;
	  }
	  else{
		  ostr << this->m_year << "/";

		  if (this->m_mon < 10)
		  {
			  ostr << "0" << this->m_mon<<"/";
		  }
			 
		  else
			  ostr << this->m_mon << "/";
		  if (this->m_day < 10)
		  {
			  ostr << "0" << this->m_day;
		  }
			  
		  else
			  ostr << "/" << this->m_day;

		  ostr << ", " << this->m_hour << ":" << this->m_min;
	  }

	  return ostr;
  }
  std::istream& operator>>(std::istream& is, Date& s)
  {
	  s.read(is);
	  return is;
  }
  std::ostream& operator<<(std::ostream& os, const Date& s)
  {
	 s.write(os);
	  return os;
  }

}
