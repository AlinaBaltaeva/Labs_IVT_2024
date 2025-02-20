#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");
    string str;
    getline(cin, str);
    string str1 = "";        // для текущего слова
    string str2 = "";       // для самого длинного слова
    string str3 = "";       // для самого короткого слова
    int k = 0;             // длина текущего слова
    int max = 0;           // максимальная длина
    int min = 100000;     // минимальная длина

    for (int i = 0; i <= str.length(); i++) // увеличил длину на 1, чтобы захватить последнее слово
    {
        if (str[i] != ' ')
        {
            k++;
            str1 += str[i];
        }
        else
        {
            if (k > 0)               // если слово закончилось
            {
                if (k < min)
                {
                    min = k;
                    str3 = str1;    // запоминаем самое короткое
                }
                if (k > max)
                {
                    max = k;
                    str2 = str1;   // запоминаем самое длинное
                }
            }
            k = 0;                 // сбрасываем счетчик и строку
            str1 = "";
        }
    }

    cout << "Самое короткое слово: " << str3 << '\n';
    cout << "Самое длинное слово: " << str2 << '\n';

    return 0;
}
