#pragma once
#include <vector>
#include "Student.h"
#include <stdexcept>

using namespace std;
class Journal {
/*
	1 измена возраста по имени фамилии
	2 вывод всех кому больше 14 если тру если фолс то меньше 14
	3 если фамилия начинается на x вывести ФИ людей у которых ф начинается на x
	4 вывести всех м или д
*/
public:
	Journal(vector<Student> _students);

	void changingAgeByFirstLastName(string firstName, string lastName, int age);
	vector<Student&> getLessAgeThan(int age);
	void getMoreAgeThan(int age);
private:
	Journal();
	vector<Student> students;
};

