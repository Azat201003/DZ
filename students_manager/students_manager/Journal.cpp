#include "Journal.h"

Journal::Journal(vector<Student> _students) {
	if (_students.size() == 0)
		throw std::length_error("size is zero");

	students = _students;
}

Journal::Journal(string fileName) {
	enum step {
		lastname,
		firstname,
		age,
		birthday,
		gender
	};
	ifstream file(fileName);

	string stroke;
	string buf = "";
	while (getline(file, stroke)) {
		step nowStep = step::lastname;
		students.push_back(Student());
		for (char symbol : stroke) {
			if (symbol == ' ')
				continue;
			if (symbol == ',') {
				switch (nowStep)
				{
				case lastname:
					students[students.size() - 1].setLastName(buf);
					break;
				case firstname:
					students[students.size() - 1].setFirstName(buf);
					break;
				case age:
					students[students.size() - 1].setAge(stoi(buf));
					break;
				case birthday:
					students[students.size() - 1].setBirthday(Student::Date(buf));
					break;
				case gender:
					students[students.size() - 1].setGender(buf != "female" ? Student::Gender::male : Student::Gender::female);
					break;
				default:
					break;
				}
				buf = "";
				nowStep = nowStep == step::gender ? step::gender : step(nowStep + 1);
				continue;
			}
			buf += symbol;
		}
	}
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

void Journal::WTF(string fileName) {
	string result = "";
	ofstream file(fileName, ios::out | ios::trunc);
	for (Student& student : students) {
		result += student.getLastName() + ",";
		result += student.getFirstName() + ",";
		result += to_string(student.getAge()) + ",";
		result += student.getBirthday().toString() + ",";
		result += ((student.getGender() == Student::Gender::male) ? "male" : "female");
		result += ",\n";
	}
	file << result;
}
