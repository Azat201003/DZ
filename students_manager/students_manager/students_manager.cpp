#include <iostream>
#include "Journal.h"

int main() {
	setlocale(LC_ALL, "ru");
	Student student1;
	Student student2;
	Student student3;
	student1.setAge(10);
	student2.setGender(Student::Gender::female);
	student1.setFirstName("Men");
	student2.setFirstName("Vladimir");
	student3.setFirstName("Uzbek");
	student1.setLastName("Coolov");
	student2.setLastName("Ulyanov");
	student3.setLastName("Uzbekov");

	vector<Student> students = { student1, student2, student3 };

	Journal journal(students);

	journal.print();

	cout << endl;
	Journal::print(journal.getByGender(Student::Gender::male));

	cout << endl;
	Journal::print(journal.getLastNameStartWith("U"));

	cout << endl;
	Journal::print(journal.getLessAgeThan(18));

	cout << endl;
	Journal::print(journal.getMoreAgeThan(20));

	journal.changeAgeByFirstLastName("Men", "Coolov", 19);

	cout << endl;
	Journal::print(journal.getMoreAgeThan(18));
}