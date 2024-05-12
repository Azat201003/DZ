#pragma once
#include <vector>
#include "Student.h"
#include <stdexcept>

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

	void changingAgeByFirstLastName(string firstName, string lastName, int age);
	vector<Student&> getLessAgeThan(int age);
	void getMoreAgeThan(int age);
private:
	Journal();
	vector<Student> students;
};

