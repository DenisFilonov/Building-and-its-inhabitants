#include"Building.h"

int main()
{
	setlocale(NULL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fp = nullptr;

	/*Resident* R = new Resident();
	R->setName("���������");
	R->setNumber(2283225550255);
	R->setYear(2000);
	R->showResident();
	R->toBinFile(fp);
	R->fromBinFile(fp);
	R->showResident();*/

	//Flat* F = new Flat();
	//F->addResident(new Resident("����",1990,380555550011));
	//F->addResident(new Resident("����",1991,380555550011));
	//F->addResident(new Resident("����",1991,380555550011));
	//F->addResident(new Resident("���",1990,380555550011));
	//F->addResident(new Resident("�������",1990,380555550011));
	//F->showAllResidents();
	//cout << "\n===========================================================\n\n";
	//F->delResident("�������");
	//cout << "\nID: " << F->findIdOfResidentByName("����") << endl << endl;
	//cout << "\nAmount: " << F->getAmountOfResidents() << endl << endl;
	//F->showCurrentResident("����");
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
		cout << "\n1. ���� ��� ������ � ����������.";
		cout << "\n2. ���� ��� ������ � ��������.";
		cout << "\n0. ��������� ������ � �����������.\n�����: ";
		cin >> menu1;
		switch (menu1)
		{
		case 1://������ �� 5 ������ �� 4 ��������
			do
			{
				cout << "\n1. ������ ����� ������.";
				cout << "\n2. �������� ����� ������.";
				cout << "\n3. ���� ��� ��������� ���������� �������.";
				cout << "\n4. ���� ��� ��������� ���������� �������.";
				cout << "\n5. �������� ���������� � ���������� �������, ����������� � ����.";
				cout << "\n6. ������ ������������ �������� � ���� �� � ������.";
				cout << "\n7. �������� ���������� � ���� ������� � ����.";
				cout << "\n8. �������� ����������, ���������� �������.";
				cout << "\n9. �������� ������.";
				cout << "\n10. ������� ������.";
				cout << "\n0. ��������� �����.\n�����: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\n����� �����: ";
					cin.ignore();
					cin.getline(str, 50);
					bd->setAddressOfBuilding(str);
					break;

				case 2:
					cout << "\n����� ����: " << bd->getAddressOfBuilding() << endl << endl;
					break;

				case 3:
					bd->setInfoOfFlat();
					break;

				case 4:
					bd->getInfoOfFlat();
					break;

				case 5:
					digit = bd->getAmountOfResidentsInBuilding();
					cout << "\n����� � ���� ��������� " << digit << " �������.\n\n";
					break;

				case 6:
					cout << "\n����� ��������: ";
					cin >> number;
					if ((number / 4 + 1) % 2 == 0)
					{
						if ((number / 4 + 2 >= 5 / 4 + 1))
						{
							cout << "\n���� # " << (number / 4);
						}
						else cout << "\n���� # " << (number / 4 + 1);
					}
					else cout << "\n���� # " << (number / 4 + 1);

					if (number % 4 == 1)
					{
						cout << "\n������� ����� ������.\n\n";
					}
					else if (number % 4 == 2)
					{
						cout << "\n������ ����� �� ������.\n\n";
					}
					else if (number % 4 == 3)
					{
						cout << "\n����� ����� �� ������.\n\n";
					}
					else
					{
						cout << "\n������� ����� �����.\n\n";
					}
					break;

				case 7:
					bd->showAllPersonList();
					break;

				case 8:
					bd->showAllFlatsList();
					break;

				case 9:
					cout << "\n����� ��������: ";
					cin >> number;
					cout << "\n��� ������: ";
					cin.ignore();
					cin.getline(str, 50);
					cout << "\n��� ��������: ";
					cin >> digit;
					cout << "\n��������� �������: ";
					cin >> phonenumber;
					bd->addPerson(number, str, digit, phonenumber);
					break;

				case 10:
					cout << "\n��� ������: ";
					cin.ignore();
					cin.getline(str, 50);
					cout << "\n����� ��������: ";
					cin >> number;
					bd->delPerson(str, number);
					break;

				default: if (menu2 > 11 && menu2 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
				}
			} while (menu2 != 0);
			break;

		case 2:
			cout << "\n��� ������: ";
			cin.ignore();
			cin.getline(str, 50);
			number = bd->findFlatOfResidentByName(str);
			if (number == -1) cout << "\n������ �� ������! ��������� �������� ������.\n\n";
			else
			{
				cout << "\n����� �������� ������ � ���� ������: " << number + 1 << endl;
				bd->setInfoOfPerson(str, number);
			}
			break;

		default: if (menu1 > 2 && menu1 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
		}
	} while (menu1 != 0);

	bd->toBinFileB(fp);
	if (bd != NULL) delete bd;
	//====================================================================================================
	// new Main(); =Check=
	Resident one;	//������� / some unknow monster -> jump into this function to see why
	Resident two("������ ����",1991,380952283221);
	Resident three = two;
	three.setName("������� ����");
	one.~Resident();

	Flat f;
	f.addPerson(two);
	f.addPerson(three);
	f.addPerson(Resident("������ ����", 2010, 000000));
	cout << "\n\n============================================================\n\n";
	f.setRooms(3);
	f.setSquare(65.7);
	f.showInfoOfFlat();

	return 0;
}