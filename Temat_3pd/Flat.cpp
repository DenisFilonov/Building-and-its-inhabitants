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
    cout << "\nИнформация о квартире очищена.\n\n";
}

void Flat::setRooms(int _rooms)
{
    if (_rooms > 1)
    {
        rooms = _rooms;
        cout << "\nКоличество комнат установлено успешно!\n\n";
    }
    else cout << "\nОшибка ввода данных!\n\n";
}

int Flat::getRooms() const
{
    return rooms;
}

void Flat::setSquare(float _square)
{
    if (_square >= 18)
    {   //минимальный расчёт на персону
        square = _square;
        cout << "\nКоличество комнат установлено успешно!\n\n";
    }
    else cout << "\nОшибка ввода данных!\n\n";
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
    cout << "\n\tИнформация о квартире:";
    cout << "\nКоличество комнат: " << rooms;
    cout << "\nКвадратура: " << square;
    cout << "\nКоличество жильцов: " << amountOfRes;
    cout << "\n\t[Список жильцов:]\n\n";
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
    cout << "\nЖитель успешно вписан в квартиру!\n\n";
}

void Flat::delResident(const char* _name)
{
    int id = findIdOfResidentByName(_name);
    if (id == -1)
    {
        cout << "\nИнформация о жителе не найдена, проверьте вводимые данные.\n\n";
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
        cout << "\nЖитель успешно выписан из квартиры!\n\n";
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
        cout << "\tЖитель #" << i + 1 << endl;
        arr[i].showResident();
    }
}

void Flat::showCurrentResident(const char* _name)
{
    int id = findIdOfResidentByName(_name);

    if (id == -1)
    {
        cout << "\nИнформация о жителе не найдена, проверьте вводимые данные.\n\n";
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
        cout << "\n1. Изменить имя жителя.";
        cout << "\n2. Изменить год рождения.";
        cout << "\n3. Изменить номер телефона.";
        cout << "\n0. Выйти из меню.\nВыбор: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "\nНовое имя: ";
            cin.ignore();
            cin.getline(name, 50);
            arr[id].setName(name);
            break;

        case 2:
            cout << "\nГод рождения: ";
            cin >> year;
            arr[id].setYear(year);
            break;

        case 3:
            cout << "\nКонтактный номер: ";
            cin >> number;
            arr[id].setNumber(number);
            break;

        default: if (choise > 3 && choise != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
        }
    } while (choise != 0);
}

void Flat::addPerson(Resident person)
{
    //Вызов конструктора копирования
    Resident* tmp = new Resident[++amountOfRes];
    //Вызывается временный массив с объектами по умолчанию

    for (int i = 0; i < amountOfRes - 1; i++)
    {
        tmp[i] = arr[i];//Вызывается оператор присвоения
    }
    if (arr != NULL) delete[] arr;//Для каждого объекта вызовется деструктор
    arr = tmp;
    arr[amountOfRes - 1] = person;//Вызывается оператор присвоения
    cout << "\nЖитель успешно вписан в квартиру!\n\n";
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
    cout << "\nДанные квартир успешно загружены в базу данных!\n\n";
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
    cout << "\nДанные квартир успешно выгружены из базы данных!\n\n";
}
