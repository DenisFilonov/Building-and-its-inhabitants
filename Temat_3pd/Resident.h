#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>
using namespace std;

class Resident
{
	char* name;
	int year;
	int64_t number; 

public:
	Resident();
	Resident(const char* _name, int _year, int64_t _number);
	Resident(const Resident& obj); //����������� �����������
	/*
	1 - �������� ������� � ������� ��� ��������		void showResident(Resident a);
	2 - ������� ������� �� �������					Resident func() { return Resident(); }
	3 - �������� ������ ������� �� ������ �������	Resident a = b;
	*/
	Resident& operator = (const Resident& obj); // �������� ����������
	/*
	1 - ��������� ��� ������������� ������� �� �����
	Resident a, b(20, 1); a = b;
	*/
	~Resident();



	void showResident();


	void setName(const char* _name);
	const char* getName() const;

	void setYear(int _year);
	int getYear() const;

	void setNumber(int64_t _number);
	int64_t getNumber() const;

	void toBinFileRS(FILE* fp);
	void fromBinFileRS(FILE* fp);
};

