#pragma once
#include <string>
#include <stdexcept>

using namespace std;
class Student {
public:
	enum Gender {
		male,
		female
	};

	class Date {
	public:
		int years;
		unsigned int month;
		unsigned int days;
		Date(int _years, unsigned int _month, unsigned int _days) {
			if (_month > 12)
				throw invalid_argument("month is bigger than 12");

			bool yearIsLeap = false;
			if (_years / 4) { yearIsLeap = true; }
			if (_years / 100) { yearIsLeap = false; }
			if (_years / 400) { yearIsLeap = true; }

			unsigned int daysPerMonth[12] = {31, 28 + (int) yearIsLeap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			unsigned int daysMax = daysPerMonth[_month - 1];

			if (_days > daysMax)
				throw invalid_argument("days is bigger than " + to_string(daysMax));

			years = _years;
			month = _month;
			days  = _days ;
		}
		Date() {
			years = 2000;
			month = 0;
			days  = 0;
		}
	};

	Student(string _firstName, 
			string _lastName, 
			Date   _birthday, 
			Gender _gender);
	Student();

	Date		 getBirthday () const;
	string		 getFirstName() const;
	string		 getLastName () const;
	Gender		 getGender   () const;
	unsigned int getAge		 () const;

	void setGender   (Gender _age	   );
	void setFirstName(string _firstName);
	void setLastName (string _lastName );
	void setAge		 (unsigned int _age);
	void setBirthday (Date _age		   );
private:
	string firstName;
	string lastName;
	Gender gender;
	Date birthday;
	int age;
};

