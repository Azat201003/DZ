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

		Date(string _date) {
			enum step {
				years,
				month,
				days
			};
			string buf;
			step nowStep = step::years;
			int _years = 0;
			unsigned int _month = 0;
			unsigned int _days = 0;
			for (char symbol : _date) {
				if (symbol == '.') {
					switch (nowStep)
					{
					case years:
						_years = stoi(buf);
						break;
					case month:
						_month = stoi(buf);
						break;
					case days:
						_days = stoi(buf);
						break;
					default:
						break;
					}
					buf = "";
					nowStep = ((nowStep == step::days) ? step::days : step(nowStep + 1));
					continue;
				}
				buf += symbol;
			}
			Date(_years, _month, _days);
		}

		Date() {
			years = 2000;
			month = 0;
			days  = 0;
		}

		string toString() {
			string result = "";

			result += to_string(years) + ".";
			result += to_string(month) + ".";
			result += to_string(days);

			return result;
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

