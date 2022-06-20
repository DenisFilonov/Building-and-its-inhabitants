#include "Resident.h"

Resident::Resident()
{
    name = new char[50]{ "Инициалы_Жильца" };
    year = 1901;
    number = 380651234567;
}

Resident::Resident(const char* _name, int _year, int64_t _number)
{
    int size = strlen(_name) + 1;
    name = new char[size];
    strcpy_s(name, size, _name);

    year = _year;
    number = _number;
}

Resident::Resident(const Resident& obj)
{
    int size = strlen(obj.name) + 1;
    this->name = new char[size];
    strcpy_s(this->name, size, obj.name);

    this->year = obj.year;
    this->number = obj.number;
}

Resident& Resident::operator=(const Resident& obj)
{
    int size = strlen(obj.name) + 1;
    this->name = new char[size];
    strcpy_s(this->name, size, obj.name);

    this->year = obj.year;
    this->number = obj.number;
    return *this;
}

Resident::~Resident()
{
    delete[] name;
}

void Resident::showResident()
{
    cout << "\n============================================";
    cout << "\n\tИнформация о жильце:";
    cout << "\nИнициалы: " << name;
    cout << "\nГод рождения: " << year;
    cout << "\nМобильный номер: " << number;
    cout << "\n============================================\n\n";
}

void Resident::setName(const char* _name)
{
    if (name != NULL) delete[] name;

    int size = strlen(_name) + 1;
    name = new char[size];
    strcpy_s(name, size, _name);

    cout << "\nИмя записано!\n\n";
}

const char* Resident::getName() const
{
    return name;
}

void Resident::setYear(int _year)
{
    if (_year > 1900)
    {
        year = _year;
        cout << "\nГод записан!\n\n";
    }
    else cout << "\nОшибка ввода данных!\n\n";
}

int Resident::getYear() const
{
    return year;
}

void Resident::setNumber(int64_t _number)
{
    if (_number > 0)
    {
        number = _number;
        cout << "\nНомер записан!\n\n";
    }
    else cout << "\nОшибка ввода данных!\n\n";
}

int64_t Resident::getNumber() const
{
    return int64_t(number);
}

void Resident::toBinFileRS(FILE* fp)
{
    int size = strlen(name) + 1;
    fwrite(&size, sizeof(int), 1, fp);
    fwrite(name, sizeof(char), size, fp);

    fwrite(&year, sizeof(int), 1, fp);
    fwrite(&number, sizeof(number), 1, fp);
    cout << "\nИнформация о жильце успешно сохранена!\n\n";
}

void Resident::fromBinFileRS(FILE* fp)
{
    char tmp[50] = "";
    int size = 0;

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    name = new char[size];
    strcpy_s(name, size, tmp);

    fread(&year, sizeof(int), 1, fp);
    fread(&number, sizeof(number), 1, fp);
    cout << "\nИнформация о жильце успешно загружена!\n\n";
}
