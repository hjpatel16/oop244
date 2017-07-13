//TODO: add header guards here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: holiday namespace here
namespace holiday
{

	// TODO: declare the class Passenger here
	class Passenger
	{
		char m_name[32];
		char m_destination[32];
		int m_departureYear, m_departureDay, m_departureMonth;
	public:
		Passenger();
		Passenger(const char[], const char[], int, int, int);
		bool isEmpty() const;
		void travelWith(const Passenger* arrpassengers, int size) const;
	
		void display(bool onlyNames = false) const;
	};
	// TODO: add the class the attributes,
	//       the member function already provided,
	//       and the member functions that you must implement

}
#endif