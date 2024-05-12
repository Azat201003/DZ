#include "Journal.h"

Journal::Journal(vector<Student> _students) {
	if (_students.size() == 0)
		throw std::length_error("size is zero");

	students = _students;
}

void Journal::changingAgeByFirstLastName(string firstName, string lastName, int age) {
	for (Student& student:students) {
		if (student.getFirstName() == firstName
		 && student.getLastName () == lastName )
			student.setAge(age);
	}
}

vector<Student&> Journal::getLessAgeThan(int age) {
	vector<Student&> result;
	for (Student& student : students) {
		if (student.getAge() < age)
			result.push_back(student);
	}
}
