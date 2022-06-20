#include "Building.h"

Building::Building()
{
	address = new char[100]{ "ул. Кошице 3" };
}

Building::Building(const char* _address)
{
	if (address != NULL) delete[] address;

	int size = strlen(_address) + 1;
	address = new char[size];
	strcpy_s(address, size, _address);

	cout << "\nАдрес записан!\n\n";
}

Building::~Building()
{
	delete[] address;
	cout << "\nИнформация о здании успешно удалена!\n\n";
}

void Building::addPerson(int _flat, const char* _name, int _year, int64_t _telephone)
{
	arr[--_flat].addResident(Resident(_name, _year, _telephone));
}

void Building::delPerson(const char* _name, int _flat)
{
	arr[--_flat].delResident(_name);
}

void Building::showAllFlatsList()
{
	cout << "\n================================================";
	cout << "\nСписок квартир и информации:\n\n";
	for (int i = 0; i < 20; i++)
	{
		cout << "\n\tКвартира # " << i + 1;
		cout << "\nКоличество комнат: " << arr[i].getRooms();
		cout << "\nКвадратура: " << arr[i].getSquare();
		cout << "\nКоличество жильцов: " << arr[i].getAmountOfResidents() << endl;
	}
	cout << "\n================================================\n\n";
}

void Building::showAllPersonList()
{
	cout << "\n================================================";
	cout << "\nСписок жителей и информации:\n";

	for (int i = 0; i < 20; i++)
	{
		cout << "\n\tКвартира #" << i + 1 << endl;
		arr[i].showAllResidents();
	}
	cout << "\n================================================\n\n";
}

void Building::setInfoOfPerson(const char* _name, int id)
{
	int res = arr[id].findIdOfResidentByName(_name);
	arr[id].setInfoOfResident(res);
}

int Building::getAmountOfResidentsInBuilding()
{
	int sum = 0;
	for (int i = 0; i < 20; i++)
	{
		sum += arr[i].getAmountOfResidents();
	}
	return sum;
}

int Building::getRoomsInFlat(int _number) 
{
	return arr[--_number].getRooms();
}

float Building::getSquareInFlat(int _flat) 
{
	return arr[--_flat].getSquare();
}

void Building::setAddressOfBuilding(const char* _address)
{
	if (address != NULL) delete[] address;

	int size = strlen(_address) + 1;
	address = new char[size];
	strcpy_s(address, size, _address);

	cout << "\nАдрес сохранён!\n\n";
}

int Building::findFlatOfResidentByName(const char* _name) 
{
	int id = -1;
	for (int i = 0; i < 20; i++)
	{
		if (arr[i].findIdOfResidentByName(_name) != -1)
		{
			id = i;
		}
	}
	return id;
}

const char* Building::getAddressOfBuilding()
{
	return address;
}

void Building::setInfoOfFlat()
{
	int choise = 0;

	int amount;
	int id;
	float square;
	do
	{
		cout << "\n1. Изменить количество комнат в квартире.";
		cout << "\n2. Изменить общую площадь квартиры.";
		cout << "\n0. Выйти из меню.\nВыбор: ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "\nНомер квартиры: ";
			cin >> id;
			cout << "\nКоличество комнат: ";
			cin >> amount;
			arr[--id].setRooms(amount);
			break;

		case 2:
			cout << "\nНомер квартиры: ";
			cin >> id;
			cout << "\nПлощадь квартиры: ";
			cin >> square;
			arr[--id].setSquare(square);
			break;

		default: if (choise > 2 && choise != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
		}
	} while (choise != 0);
}

void Building::getInfoOfFlat()
{
	int choise = 0;

	int amount;
	int id;
	float sq = 0;
	char name[50] = "";
	do
	{
		cout << "\n1. Показать количество жителей в конкретной квартире.";
		cout << "\n2. Показать полную информацию о конкретной квартире.";
		cout << "\n3. Показать информацию о конкретном жителе квартиры.";
		cout << "\n4. Показать количество комнат в конкретной квартире.";
		cout << "\n5. Показать общую площадь в конкретной квартире.";
		cout << "\n0. Выйти из меню.\nВыбор: ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "\nНомер квартиры: ";
			cin >> id;
			amount = arr[--id].getAmountOfResidents();
			cout << "\nКоличество жильцов, проживающих в " << id << " квартире - " << amount << " человек.\n\n";
			break;

		case 2:
			cout << "\nНомер квартиры: ";
			cin >> id;
			arr[--id].showInfoOfFlat();
			break;

		case 3:
			cout << "\nНомер квартиры: ";
			cin >> id;
			cout << "\nФИО жителя: ";
			cin.ignore();
			cin.getline(name, 50);
			arr[--id].showCurrentResident(name);
			break;

		case 4:
			cout << "\nНомер квартиры: ";
			cin >> id;
			amount = getRoomsInFlat(id);
			cout << "\nКоличество комнат в квартире номер " << id << " - [" << amount << "] штук(а/и).\n\n";
			break;

		case 5:
			cout << "\nНомер квартиры: ";
			cin >> id;
			sq = getSquareInFlat(id);
			cout << "\nКоличество комнат в квартире номер " << id << " - [" << sq << "] кв.метров.\n\n";
			break;

		default: if (choise > 5 && choise != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
		}
	} while (choise != 0);
}

void Building::addPerson(Resident person, int nFlat)
{
	arr[--nFlat].addPerson(person);
}

void Building::toBinFileB(FILE* fp)
{
	fopen_s(&fp, "Building.dat", "wb");

	if (fp == NULL)
	{
		cout << "\nОшибка загрузки базы данных здания! Проверьте файлы\n\n";
	}
	else
	{
		int size = strlen(address) + 1;
		fwrite(&size, sizeof(int), 1, fp);
		fwrite(address, sizeof(char), size, fp);
		//записали адрес

		//записали данные хат
		for (int i = 0; i < 20; i++)
		{
			arr[i].toBinFileFL(fp);
		}
		fclose(fp);
		cout << "\nДанные здания успешно загружены в базу данных!\n\n";
	}
}

void Building::fromBinFileB(FILE* fp)
{
	fopen_s(&fp, "Building.dat", "rb");

	if (fp == NULL)
	{
		cout << "\nОшибка выгрузки базы данных квартир! Проверьте файлы\n\n";
		address = nullptr;
	}
	else
	{
		int size = 0;
		fread(&size, sizeof(int), 1, fp);
		address = new char[size];
		fread(address, sizeof(char), size, fp);

		for (int i = 0; i < 20; i++)
		{
			arr[i].fromBinFileFL(fp);
		}
		fclose(fp);
		cout << "\nДанные квартир успешно выгружены из базу данных!\n\n";
	}
}
