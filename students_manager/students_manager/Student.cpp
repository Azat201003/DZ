#include "Student.h"


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
