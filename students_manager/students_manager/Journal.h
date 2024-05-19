#pragma once
#include <vector>
#include "Student.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;
class Journal {
/*
	1 ������ �������� �� ����� �������
	2 ����� ���� ���� ������ 14 ���� ��� ���� ���� �� ������ 14
	3 ���� ������� ���������� �� x ������� �� ����� � ������� � ���������� �� x
	4 ������� ���� � ��� �
*/
public:
	Journal(vector<Student> _students);
	Journal(string fileName);

	void changeAgeByFirstLastName(string firstName, string lastName, int age);
	vector<Student*> getLessAgeThan(int age);
	vector<Student*> getMoreAgeThan(int age);
	vector<Student*> getLastNameStartWith(string start);
	vector<Student*> getByGender(Student::Gender gender);
	void print();
	static void print(const vector<Student*>&);
	void WTF(string fileName); // write to file
private:
	Journal();
	vector<Student> students;
	lastChange;
};

