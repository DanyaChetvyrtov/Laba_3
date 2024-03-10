#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    string main_string, sub_string;
    cout << "Введите основную строку:\n";
    getline(cin, main_string);

    cout << "Введите подстроку:\n";
    getline(cin, sub_string);

    cout << "\n\tВы ввели\n";
    cout << "Основная строка: " << main_string << endl;
    cout << "Подстрока: " << sub_string << endl;

    if (main_string.find(sub_string) != string::npos)
        cout << "\n\tСтрока содержит подстроку\n";
    else
        cout << "Строка НЕ содержит подстроку\n";

}