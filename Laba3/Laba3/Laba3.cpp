#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;


bool in(char sub_str, string str) {
    return str.find(sub_str) != string::npos;
}

bool isInt(string str) {

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == 0)
            return false;

    return true;
}

string replaceDouble(string user_string, char change_from, string change_to) {
    string new_string;

    for (int i = 0; i < user_string.length() - 1; i++) {
        if (user_string[i] == change_from && user_string[i + 1] == change_from) {
            new_string += change_to;
            i++;
        }
        else
            new_string += user_string[i];
    }
    
    if(user_string.back() != change_from)
        new_string += user_string.back();

    return new_string;
}


void main()
{
    // locale::global(locale("Russian_Russia.1251")); // 866
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string user_str, valid_str, gap_string;
    int result = 0;

    getline(cin, user_str);
    cout << "Исходная строка:" << endl;
    cout << user_str << endl;


    for (int i = 0; i < user_str.length(); i++) 
        if (in(user_str[i], "0123456789+-"))
            valid_str += user_str[i];


    string double_plus = "++", double_minus = "--";
    

    while ((valid_str.find("+-") != string::npos) || (valid_str.find("-+") != string::npos) || (valid_str.find(double_plus) != string::npos) || (valid_str.find(double_minus) != string::npos)) {
        for (int i = 0; i < valid_str.length() - 1; i++) {
            if ((valid_str[i] == '+' && valid_str[i + 1] == '-') || (valid_str[i] == '-' && valid_str[i + 1] == '+')) {
                gap_string += "-";
                i++;
            }
            else
                gap_string += valid_str[i];
        }

        if ((valid_str.back() != '+') || (valid_str.back() != '-'))
            gap_string += valid_str.back();

        valid_str = gap_string;
        gap_string = "";


        valid_str = replaceDouble(valid_str, '-', "+");
        valid_str = replaceDouble(valid_str, '+', "+");
    }


    cout << "Валидная часть:" << endl;
    cout << valid_str << endl;
    cout << endl;

    
    int* num_array = new int[valid_str.length()];
    int j, array_index = 0;
    string sub_string, operators = "";

    
    valid_str += "+";

    if (isdigit(valid_str[0]))
        sub_string = valid_str[0];
    else {
        sub_string = "";
        operators = valid_str[0];
    }

    // Поиск и сохранение чисел строки
    for (int i = 0; i < valid_str.length()-1; i++) {
        j = i + 1;

        while (!in(valid_str[j + 1], "+-")) {
            if (in(valid_str[j], "+-") || j >= valid_str.length())
                break;
            sub_string += valid_str[j];
            j++;
        }

        sub_string += valid_str[j];

        if (isInt(sub_string)) {
            *(num_array + array_index) = stoi(sub_string);
            array_index++;
        }
        else
            operators += sub_string;
        

        sub_string = "";
        i = j-1;
    } 

    valid_str.pop_back();
    operators.pop_back();


    if (valid_str[0] == '-') {
        *(num_array) -= *(num_array) * 2;
        valid_str.erase(valid_str.begin());
        operators.erase(operators.begin());
    }
    else if (valid_str[0] == '+') {
        valid_str.erase(valid_str.begin());
        operators.erase(operators.begin());
    }
   

    int ans = 0;

    operators = "+" + operators;

    for (int i = 0; i < array_index; i++) {
        if (operators[i] == '-')
            *(num_array + i) -= *(num_array + i) * 2;
        ans += *(num_array + i);
    }

    cout << "Ответ:" << endl;
    cout << ans;
}