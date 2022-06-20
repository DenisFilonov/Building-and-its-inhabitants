#pragma once
#include"Flat.h"

class Building
{
	char* address;
	Flat arr[20];
public:
	Building();
	Building(const char* _address);
	~Building();

	void addPerson(int _flat, const char* _name, int _year, int64_t _telephone);//+
	void delPerson(const char* _name, int _flat);//+
	void showAllFlatsList(); //+
	void showAllPersonList();//+
	void setInfoOfPerson(const char* _name, int id);//+

	int getAmountOfResidentsInBuilding();//+
	int getRoomsInFlat(int _number);	// Задействовано здесь -> void getInfoOfFlat(int flat);
	float getSquareInFlat(int _flat);	// Задействовано здесь -> void getInfoOfFlat(int flat);

	void setAddressOfBuilding(const char* _address);//+
	int findFlatOfResidentByName(const char* _name);//+
	const char* getAddressOfBuilding();//+

	void setInfoOfFlat();//+
	void getInfoOfFlat();//+


	void addPerson(Resident person, int nFlat);

	void toBinFileB(FILE* fp);
	void fromBinFileB(FILE* fp);
};