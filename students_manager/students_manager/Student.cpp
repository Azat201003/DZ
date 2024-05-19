#include "Student.h"

Student::Student(string _firstName, string _lastName, Date _birthday, Gender _gender) {
    firstName = _firstName;
    lastName = _lastName;
    birthday = _birthday;
    gender = _gender;
    age = 24; // я не представляю пока как от настоящего времени отнять его др
}

Student::Student() {
    firstName = "none first name";
    lastName = "none last name";
    birthday = Date();
    gender = Gender::male;
    age = 24; // примерно
}


string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

unsigned int Student::getAge() const {
    return age;
}

Student::Gender Student::getGender() const {
    return gender;
}

Student::Date Student::getBirthday() const {
    return birthday;
}


void Student::setFirstName(string _firstName) {
    firstName = _firstName;
}

void Student::setLastName(string _lastName) {
    lastName = _lastName;
}

void Student::setAge(unsigned int _age) {
    age = _age;
}

void Student::setGender(Gender _gender) {
    gender = _gender;
}

void Student::setBirthday(Date _birthday) {
    birthday = _birthday;
}