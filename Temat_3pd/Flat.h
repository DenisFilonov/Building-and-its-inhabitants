#pragma once
#include"Resident.h"

class Flat
{
	int rooms;
	float square;
	int amountOfRes;
	Resident* arr;

public:
	Flat();
	Flat(int _rooms, float _square, int _amount);
	~Flat();

	void setRooms(int _rooms);
	int getRooms() const;

	void setSquare(float _square);
	float getSquare() const;

	int getAmountOfResidents() const;

	void showInfoOfFlat();

	void addResident(Resident obj);
	void delResident(const char* _name);
	int findIdOfResidentByName(const char* _name);
	void showAllResidents();
	void showCurrentResident(const char* _name);

	void setInfoOfResident(int id);//+

	void addPerson(Resident person);

	void toBinFileFL(FILE* fp);
	void fromBinFileFL(FILE* fp);
};

