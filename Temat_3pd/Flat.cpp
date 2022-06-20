#include "Flat.h"

Flat::Flat()
{
    rooms = 1;
    square = 20.1;
    amountOfRes = 0;
    arr = nullptr;
}

Flat::Flat(int _rooms, float _square, int _amount)
{
    rooms = _rooms;
    square = _square;
    amountOfRes = _amount;
    arr = nullptr;
}

Flat::~Flat()
{
    for (int i = 0; i < amountOfRes; i++)
    {
        arr[i].~Resident();
    }
    cout << "\n���������� � �������� �������.\n\n";
}

void Flat::setRooms(int _rooms)
{
    if (_rooms > 1)
    {
        rooms = _rooms;
        cout << "\n���������� ������ ����������� �������!\n\n";
    }
    else cout << "\n������ ����� ������!\n\n";
}

int Flat::getRooms() const
{
    return rooms;
}

void Flat::setSquare(float _square)
{
    if (_square >= 18)
    {   //����������� ������ �� �������
        square = _square;
        cout << "\n���������� ������ ����������� �������!\n\n";
    }
    else cout << "\n������ ����� ������!\n\n";
}

float Flat::getSquare() const
{
    return square;
}

int Flat::getAmountOfResidents() const
{
    return amountOfRes;
}

void Flat::showInfoOfFlat()
{
    cout << "\n============================================";
    cout << "\n\t���������� � ��������:";
    cout << "\n���������� ������: " << rooms;
    cout << "\n����������: " << square;
    cout << "\n���������� �������: " << amountOfRes;
    cout << "\n\t[������ �������:]\n\n";
    showAllResidents();
    cout << "\n============================================\n\n";
}

void Flat::addResident(Resident obj)
{
    Resident* tmp = new Resident [++amountOfRes];
    for (int i = 0; i < amountOfRes - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL) delete[]arr;
    tmp[amountOfRes - 1] = obj;
    arr = tmp;
    cout << "\n������ ������� ������ � ��������!\n\n";
}

void Flat::delResident(const char* _name)
{
    int id = findIdOfResidentByName(_name);
    if (id == -1)
    {
        cout << "\n���������� � ������ �� �������, ��������� �������� ������.\n\n";
    }
    else
    {
        Resident* tmp = new Resident [--amountOfRes];
        for (int i = 0; i < amountOfRes; i++)
        {
            if (i < id)
            {
                tmp[i] = arr[i];
            }
            else if (i >= id)
            {
                tmp[i] = arr[i + 1];
            }
        }
        arr[id].~Resident();
        if (arr != NULL) delete[] arr;
        arr = tmp;
        cout << "\n������ ������� ������� �� ��������!\n\n";
    }
}

int Flat::findIdOfResidentByName(const char* _name)
{
    for (int i = 0; i < amountOfRes; i++)
    {
        if (strcmp(_name, arr[i].getName()) == 0)
        {
            return i;
        }
    }
    return -1;
}

void Flat::showAllResidents()
{
    for (int i = 0; i < amountOfRes; i++)
    {
        cout << "\t������ #" << i + 1 << endl;
        arr[i].showResident();
    }
}

void Flat::showCurrentResident(const char* _name)
{
    int id = findIdOfResidentByName(_name);

    if (id == -1)
    {
        cout << "\n���������� � ������ �� �������, ��������� �������� ������.\n\n";
    }
    else
    {
        arr[id].showResident();
    }
}

void Flat::setInfoOfResident(int id)
{
    int choise;
    int year;
    int64_t number;
    char name[50] = "";
    do
    {
        cout << "\n1. �������� ��� ������.";
        cout << "\n2. �������� ��� ��������.";
        cout << "\n3. �������� ����� ��������.";
        cout << "\n0. ����� �� ����.\n�����: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "\n����� ���: ";
            cin.ignore();
            cin.getline(name, 50);
            arr[id].setName(name);
            break;

        case 2:
            cout << "\n��� ��������: ";
            cin >> year;
            arr[id].setYear(year);
            break;

        case 3:
            cout << "\n���������� �����: ";
            cin >> number;
            arr[id].setNumber(number);
            break;

        default: if (choise > 3 && choise != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
        }
    } while (choise != 0);
}

void Flat::addPerson(Resident person)
{
    //����� ������������ �����������
    Resident* tmp = new Resident[++amountOfRes];
    //���������� ��������� ������ � ��������� �� ���������

    for (int i = 0; i < amountOfRes - 1; i++)
    {
        tmp[i] = arr[i];//���������� �������� ����������
    }
    if (arr != NULL) delete[] arr;//��� ������� ������� ��������� ����������
    arr = tmp;
    arr[amountOfRes - 1] = person;//���������� �������� ����������
    cout << "\n������ ������� ������ � ��������!\n\n";
}

void Flat::toBinFileFL(FILE* fp)
{
    fwrite(&rooms, sizeof(int), 1, fp);
    fwrite(&square, sizeof(float), 1, fp);

    fwrite(&amountOfRes, sizeof(int), 1, fp);
    for (int i = 0; i < amountOfRes; i++)
    {
        arr[i].toBinFileRS(fp);
    }
    cout << "\n������ ������� ������� ��������� � ���� ������!\n\n";
}

void Flat::fromBinFileFL(FILE* fp)
{
    fread(&rooms, sizeof(int), 1, fp);
    fread(&square, sizeof(float), 1, fp);

    fread(&amountOfRes, sizeof(int), 1, fp);
    arr = new Resident[amountOfRes];
    for (int i = 0; i < amountOfRes; i++)
    {
        arr[i].fromBinFileRS(fp);
    }
    cout << "\n������ ������� ������� ��������� �� ���� ������!\n\n";
}
