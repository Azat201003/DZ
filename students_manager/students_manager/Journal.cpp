#include "Journal.h"

Journal::Journal(vector<Student> _students) {
	if (_students.size() == 0)
		throw std::length_error("size is zero");

	students = _students;
}

void Journal::changeAgeByFirstLastName(string firstName, string lastName, int age) {
	for (Student& student:students) {
		if (student.getFirstName() == firstName
		 && student.getLastName () == lastName )
			student.setAge(age);
	}
}

vector<Student*> Journal::getLessAgeThan(int age) {
	vector<Student*> result;
	for (Student& student : students) {
		if (student.getAge() < age)
			result.push_back(&student);
	}

	return result;
}

vector<Student*> Journal::getMoreAgeThan(int age) {
	vector<Student*> result;
	for (Student& student : students) {
		if (student.getAge() > age)
			result.push_back(&student);
	}

	return result;
}

vector<Student*> Journal::getLastNameStartWith(string start) {
	vector<Student*> result;
	for (Student& student : students) {
		if (student.getLastName().rfind("titi", 0) == 0)
			result.push_back(&student);
	}

	return result;
}

vector<Student*> Journal::getByGender(Student::Gender gender) {
	vector<Student*> result;
	for (Student& student : students) {
		if (student.getGender() == gender)
			result.push_back(&student);
	}

	return result;
}

void Journal::print() {
	for (Student student : students) {
		cout << student.getLastName() << " " << student.getFirstName() << ".\n";
		cout << (int)student.getAge() << " полных лет.\n";
		cout << "Пол: " << (student.getGender() == Student::Gender::male ? "мужской" : "женский") << endl;
		cout << endl;
	}
}

void Journal::print(const vector<Student*>& _students) {
	for (Student* student : _students) {
		cout << student->getLastName() << " " << student->getFirstName() << ".\n";
		cout << (int)student->getAge() << " полных лет.\n";
		cout << "Пол: " << (student->getGender() == Student::Gender::male ? "мужской" : "женский") << endl;
		cout << endl;
	}
}