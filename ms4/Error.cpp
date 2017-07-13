#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include "Error.h"

namespace ict{
  
	Error::Error()
	{
		m_message = nullptr;
	}
	Error::Error(const char* errorMessage)
	{
		m_message = nullptr;
		message(errorMessage);
	}
	void Error::operator=(const char* errorMessage)
	{
		message(errorMessage);
	}
	Error::~Error()
	{
		delete[] m_message;
	}
	void Error::clear()
	{
		delete[] this->m_message;
		this->m_message = nullptr;
	}
	bool Error::isClear()const
	{
		return (m_message == nullptr);
	}
	void Error::message(const char* value)
	{
		int j = strlen(value);
		if (isClear())
		{
			m_message = new char[j + 1];
			strcpy(m_message, value);
		}
		else
		{
			clear();
			m_message = new char[j + 1];
			strcpy(m_message, value);
		}
		
	}
	Error::operator const char*() const
	{
		return m_message;
	}
	Error::operator bool()const
	{
		return (m_message == nullptr);
	}
	std::ostream& Error::write(std::ostream& ostr)const
	{
		if (!isClear())
		{
			ostr << m_message;
		}
		return ostr;
	}
	std::ostream& operator<<(std::ostream& os, const Error& s)
	{
		s.write(os);
		return os;
	}
}