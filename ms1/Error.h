// compilation safegaurds
#ifndef ICT_ERROR_H_
#define ICT_ERROR_H_
#include <iostream>
namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
	   Error();
	   Error(const char* errorMessage);
   // destructor
	   virtual ~Error();
   // deleted constructor and operator=
	   Error(const Error& em) = delete;
	   Error& operator=(const Error& em) = delete;
   // operator= for c-style strings
	   void operator=(const char* errorMessage);
   // methods
	   void clear();
	   bool isClear()const;
	   std::ostream& write(std::ostream& ostr = std::cout)const;
	   void message(const char* value);
   // cast overloads
	   operator bool()const;
	   operator const char*() const;
   };
   // operator << overload prototype for cout
   std::ostream& operator<<(std::ostream& os, const Error& s);
}

#endif
