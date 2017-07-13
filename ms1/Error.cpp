#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include "Error.h"

namespace ict{
  
	Error::Error()
	{
		this->m_message = nullptr;
	}
	Error::Error(const char* errorMessage)
	{
		this->m_message = nullptr;
		this->message(errorMessage);
	}
	void Error::operator=(const char* errorMessage)
	{
		this->message(errorMessage);
	}
	Error::~Error()
	{
		delete[] this->m_message;
		this->m_message = nullptr;
	}
	void Error::clear()
	{
		delete[] this->m_message;
		this->m_message = nullptr;
	}
	bool Error::isClear()const
	{
		return (this->m_message == nullptr);
	}
	void Error::message(const char* value)
	{
		if (this->isClear())
		{
			this->m_message = new char[strlen(value) + 1];
			strcpy(this->m_message, value);
		}
		else
		{
			delete[] this->m_message;
			this->m_message = nullptr;
			this->m_message = new char[strlen(value) + 1];
			strcpy(this->m_message, value);
		}
		
	}
	Error::operator const char*() const
	{
		return this->m_message;
	}
	Error::operator bool()const
	{
		return (this->m_message == nullptr);
	}
	std::ostream& Error::write(std::ostream& ostr)const
	{
		if (!isClear())
		{
			ostr << this->m_message;
		}
		return ostr;
	}
	std::ostream& operator<<(std::ostream& os, const Error& s)
	{
		s.write(os);
		return os;
	}
}