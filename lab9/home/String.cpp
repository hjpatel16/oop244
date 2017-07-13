#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

namespace sict{

	//////////////////////////////////////////////////////
	//
	// Default Constructor
	// String::String(int capacity);
	//
	// initialize the string with an internal buffer capacity of 
	// "capacity." 
	// default capacity is 1 (minimum needed for an empty string)
	//
	// 
	String::String(int capacity)
	{
		this->m_capacity = capacity;
		this->m_pString = new char[this->m_capacity];
		this->m_pString[0] = '\0';
	}
	//////////////////////////////////////////////////////
	//
	// String::String(const char* p, int capacity);
	//
	// Construct a String from a char array
	// Should initialize the internal buffer to at least 
	// the length of the string need to hold pSource, 
	// or capacity, whichever is greater.
	//
	// 
	String::String(const char* pSource, int capacity)
	{
		int l = strlen(pSource);
		if ( l< capacity)
			this->m_capacity = capacity;
		else
			this->m_capacity = strlen(pSource) + 1;

		this->m_pString = new char[this->m_capacity];
		strcpy(this->m_pString, pSource);
	}
	//////////////////////////////////////////////////////
	//
	// String::String(const String &s, int capacity);
	//
	// Copy constructor
	//
	// Construct a String from another String
	//
	// 
	String::String(const String& other , int capacity)
	{
		this->m_capacity = other.m_capacity;
		if (!this->m_pString)
		{
			delete[] this->m_pString;
		}
		this->m_pString = new char[other.m_capacity];
		strncpy(m_pString, other.m_pString, other.m_capacity);
	}
	//////////////////////////////////////////////////////
	//
	// String::resize(int newsize)
	//
	// resize the internal buffer to the value given
	// do NOT shrink the string buffer smaller than 
	// that needed to hold the existing string!
	// (length + 1);
	//    
	void String::resize(int newsize)
	{
		String tmp;
		if (newsize > this->m_capacity)
		{
			this->m_capacity = newsize;

			 tmp.m_pString = new char[strlen(this->m_pString) + 1];
			strcpy(tmp.m_pString, this->m_pString);

			delete[] this->m_pString;

			this->m_pString = new char[this->m_capacity];
			strcpy(this->m_pString, tmp.m_pString);
		}
	}
	//////////////////////////////////////////////////////
	//
	// String::operator=(const String& other)
	// 
	// Assignment operator
	// copy string "other" to this object
	//   
	// 
	String& String::operator=(const String& other)
	{
		this->m_capacity = other.m_capacity;
		if (!this->m_pString)
		{
			delete[] this->m_pString;
		}
		this->m_pString = new char[other.m_capacity];
		strcpy(this->m_pString, other.m_pString);
		return *this;
	}
	//////////////////////////////////////////////////////
	//
	// String::~String
	// 
	// destructor
	// 
	// clean up the internal string buffer  
	// 
	String::~String()
	{
		this->m_pString[0] = '\0';
	}
	//////////////////////////////////////////////////////
	//
	// String::length()
	// 
	// return the length of the string
	// 
	// 
	int String::length() const
	{
		return strlen(this->m_pString);
	}
	//////////////////////////////////////////////////////
	//
	// String::operator const char*() const
	// 
	// convert the String to a char*
	// 
	// 
	String::operator const char *() const
	{
		return this->m_pString;
	}
	//////////////////////////////////////////////////////
	//
	// String::empty()
	// 
	// 
	// returns true if the string is empty
	// i.e. either the first char is \0, or 
	// length is 0.
	bool String::empty() const
	{
		return (this->m_pString[0] == '\0');
	}
	//////////////////////////////////////////////////////
	//
	// String::operator bool()
	// 
	// same as empty(), just wrapped in an operator
	// 
	//         
	String::operator bool() const
	{
		bool i = false;
		if (this->m_pString[0] != '\0')
		{
			return true;
		}
		return i;
	}
	//////////////////////////////////////////////////////
	//
	// String::operator==(const String& s2) const
	// 
	// returns true if *this == s2.
	// You can use the strcmp function to check if 
	// two strings are equal, or write your own
	// treating the string as a char-array
	//           
	bool String::operator==(const String& s2) const
	{
		bool i = false;
		if (strcmp(this->m_pString, s2.m_pString) == 0)
		{
			i = true;
		}
		return i;
	}
	//////////////////////////////////////////////////////
	//
	// String::operator+=(const String& s2)
	// 
	// Concatenates s2 to the end of *this
	//
	// implements *this = (*this + s2)
	// return *this
	// 
	//         
	String& String::operator+=(const String& s2)
	{
		*this = (*this + s2);
			return *this;
	}
	//////////////////////////////////////////////////////
	//
	// String::operator+(const String& s2) const
	// 
	// implements the operator (*this + s2)
	// returns the expression
	// DOES NOT MODIFY *this
	// 
	//     
	String String::operator+(const String& s2) const
	{
		String tmp;
		tmp.m_pString = new char[m_capacity + s2.m_capacity + 1];
		strcpy(tmp.m_pString, m_pString);
		strcat(tmp.m_pString, s2.m_pString);
		return tmp.m_pString;
	}
	//////////////////////////////////////////////////////
	//
	// String::operator+=(char c)
	// 
	// Adds a single char c to the end of the string in *this
	// 
	//        
	String& String::operator+= (char c)
	{
		int i = strlen(this->m_pString);
		this->m_pString[i] = c;
		i++;
		this->m_pString[i] = '\0';
		return *this;
	}
	//////////////////////////////////////////////////////
	//
	// String::substr
	 // 
	    // Returns a substring of the current string. In case of error
	    // return an empty String() object instead.
	    // 
	    // return the string slice starting at index, at most len characters
	    // 
	    // both index and len have to lie inside the string. If they do not, then 
	    // that is an error
	    // 
	    String String::substr(int index, int len) const
	    {
			String c;
			if (index < this->length() && len < this->m_capacity)
			{
				for (int i = index; i < len; i++)
				{
					c += this->m_pString[i];
				}
	
			}
			else
			{
				return c;
			}
			return c;
	    }
	
	//////////////////////////////////////////////////////
	//
	// operator<<
	// 
	// Print the string to the output stream
	// 
	// clean up the internal string buffer  
	//     
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		ostream << s.operator const char *();
		return ostream;
	}
	//////////////////////////////////////////////////////
	//
	// operator>>
	// 
	// Input a string from an input stream into the String s
	// 
	// Note: the input can be ANY length in character. You will need to 
	// read it one char at a time. 
	// 
	std::istream& operator>>(std::istream& istream, String &s)
	{
		s = "";
		char tempC = 0;
		do
		{
			tempC = istream.get();
			if (tempC != '\n')
			{
				s.resize(s.capacity() + 1);
				s += tempC;
			}
			else
				break;
		} while (1);
		return istream;
	}
}