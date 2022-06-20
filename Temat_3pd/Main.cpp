#include"Building.h"

int main()
{
	setlocale(NULL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fp = nullptr;

	/*Resident* R = new Resident();
	R->setName("Ахмзыхвах");
	R->setNumber(2283225550255);
	R->setYear(2000);
	R->showResident();
	R->toBinFile(fp);
	R->fromBinFile(fp);
	R->showResident();*/

	//Flat* F = new Flat();
	//F->addResident(new Resident("Вася",1990,380555550011));
	//F->addResident(new Resident("Петя",1991,380555550011));
	//F->addResident(new Resident("Лена",1991,380555550011));
	//F->addResident(new Resident("Ира",1990,380555550011));
	//F->addResident(new Resident("удалить",1990,380555550011));
	//F->showAllResidents();
	//cout << "\n===========================================================\n\n";
	//F->delResident("удалить");
	//cout << "\nID: " << F->findIdOfResidentByName("Петя") << endl << endl;
	//cout << "\nAmount: " << F->getAmountOfResidents() << endl << endl;
	//F->showCurrentResident("Лена");
	//cout << "\n===========================================================\n\n";
	//F->showInfoOfFlat();
	//F->toBinFileFL(fp);
	//F->fromBinFileFL(fp);
	//F->showInfoOfFlat();
	//delete F;
	Building* bd = new Building();

	int menu1, menu2, menu3;
	int digit = 0;
	int number = 0;
	int64_t phonenumber = 0;
	float sq = 0;
	char str[50] = "";

	bd->fromBinFileB(fp);
	do
	{
		cout << "\n1. Меню для работы с квартирами.";
		cout << "\n2. Меню для работы с жильцами.";
		cout << "\n0. Завершить работу с приложением.\nВыбор: ";
		cin >> menu1;
		switch (menu1)
		{
		case 1://Здание из 5 этажей по 4 квартиры
			do
			{
				cout << "\n1. Задать адрес здания.";
				cout << "\n2. Показать адрес здания.";
				cout << "\n3. Меню для изменения информации квартир.";
				cout << "\n4. Меню для получения информации квартир.";
				cout << "\n5. Получить информацию о количестве жителей, проживающих в доме.";
				cout << "\n6. Узнать расположение квартиры в доме по её номеру.";
				cout << "\n7. Показать информацию о всех жильцах в доме.";
				cout << "\n8. Показать информацию, касающуюся квартир.";
				cout << "\n9. Добавить жителя.";
				cout << "\n10. Удалить жителя.";
				cout << "\n0. Вернуться назад.\nВыбор: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\nНовый адрес: ";
					cin.ignore();
					cin.getline(str, 50);
					bd->setAddressOfBuilding(str);
					break;

				case 2:
					cout << "\nАдрес дома: " << bd->getAddressOfBuilding() << endl << endl;
					break;

				case 3:
					bd->setInfoOfFlat();
					break;

				case 4:
					bd->getInfoOfFlat();
					break;

				case 5:
					digit = bd->getAmountOfResidentsInBuilding();
					cout << "\nИтого в доме проживает " << digit << " жильцов.\n\n";
					break;

				case 6:
					cout << "\nНомер квартиры: ";
					cin >> number;
					if ((number / 4 + 1) % 2 == 0)
					{
						if ((number / 4 + 2 >= 5 / 4 + 1))
						{
							cout << "\nЭтаж # " << (number / 4);
						}
						else cout << "\nЭтаж # " << (number / 4 + 1);
					}
					else cout << "\nЭтаж # " << (number / 4 + 1);

					if (number % 4 == 1)
					{
						cout << "\nКрайняя дверь справа.\n\n";
					}
					else if (number % 4 == 2)
					{
						cout << "\nПравая дверь по центру.\n\n";
					}
					else if (number % 4 == 3)
					{
						cout << "\nЛевая дверь по центру.\n\n";
					}
					else
					{
						cout << "\nКрайняя дверь слева.\n\n";
					}
					break;

				case 7:
					bd->showAllPersonList();
					break;

				case 8:
					bd->showAllFlatsList();
					break;

				case 9:
					cout << "\nНомер квартиры: ";
					cin >> number;
					cout << "\nФИО жителя: ";
					cin.ignore();
					cin.getline(str, 50);
					cout << "\nГод рождения: ";
					cin >> digit;
					cout << "\nМобильный телефон: ";
					cin >> phonenumber;
					bd->addPerson(number, str, digit, phonenumber);
					break;

				case 10:
					cout << "\nФИО жителя: ";
					cin.ignore();
					cin.getline(str, 50);
					cout << "\nНомер квартиры: ";
					cin >> number;
					bd->delPerson(str, number);
					break;

				default: if (menu2 > 11 && menu2 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
				}
			} while (menu2 != 0);
			break;

		case 2:
			cout << "\nФИО жителя: ";
			cin.ignore();
			cin.getline(str, 50);
			number = bd->findFlatOfResidentByName(str);
			if (number == -1) cout << "\nЖитель не найден! Проверьте вводимые данные.\n\n";
			else
			{
				cout << "\nНомер квартиры жильца в базе данных: " << number + 1 << endl;
				bd->setInfoOfPerson(str, number);
			}
			break;

		default: if (menu1 > 2 && menu1 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
		}
	} while (menu1 != 0);

	bd->toBinFileB(fp);
	if (bd != NULL) delete bd;
	//====================================================================================================
	// new Main(); =Check=
	Resident one;	//бабайка / some unknow monster -> jump into this function to see why
	Resident two("Иванов Саша",1991,380952283221);
	Resident three = two;
	three.setName("Иванова Лена");
	one.~Resident();

	Flat f;
	f.addPerson(two);
	f.addPerson(three);
	f.addPerson(Resident("Иванов Петя", 2010, 000000));
	cout << "\n\n============================================================\n\n";
	f.setRooms(3);
	f.setSquare(65.7);
	f.showInfoOfFlat();

	return 0;
}