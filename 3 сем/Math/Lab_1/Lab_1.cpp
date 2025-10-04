#include <iostream>
#include <set>     // Для работы с множествами (set)
#include <algorithm>
#include <string>
#include <stdexcept>
#include <random>
#include <functional>  

using namespace std;

const int MIN = -30;
const int MAX = 30;

class Calculator
{
private:
    set<int> setA, setB, setC;
    set<int> universalSet;

    void Filling()
    {
        for (int i = MIN; i <= MAX; i++)
        {
            universalSet.insert(i);
        }
    }

    void clearBuf()
    {
        cin.clear();
        char c;

        while ((c = cin.get()) != '\n' && c != EOF)
        {
            // Просто продолжаем читать и игнорируем символы
        }
    }

    bool val_elem(int element)
    {
        return element >= MIN && element <= MAX;
    }

    void printSet(const set<int>& s, const string& name)
    {
        cout << name << " = {";
        bool first = true;
        for (int elem : s)
        {
            if (!first) cout << ", ";
            cout << elem;
            first = false;
        }
        if (s.empty()) cout << "#";
        cout << "}" << endl;
    }

    set<int>& getIndex(int index)
    {
        switch (index) 
        {
        case 1: return setA;
        case 2: return setB;
        case 3: return setC;
        default: throw invalid_argument("Неверный индекс множества");
        }
    }

    
    set<int> Union(const set<int>& s1, const set<int>& s2)
    {
        set<int> result = s1;  // Начинаем с первого множества
        for (int elem : s2) 
        {
            result.insert(elem);  // insert автоматически игнорирует дубликаты
        }
        return result;
    }

    set<int> Intersection(const set<int>& s1, const set<int>& s2)
    {
        set<int> result;
        for (int elem : s1)
        {
            if (s2.find(elem) != s2.end()) //end - если элемент не найден
            {
                result.insert(elem);
            }
        }
        return result;
    }

 
    set<int> Diff(const set<int>& s1, const set<int>& s2)
    {
        set<int> result;
        for (int elem : s1) 
        {
            if (s2.find(elem) == s2.end()) 
            {
                result.insert(elem);
            }
        }
        return result;
    }

  
    set<int> SymmetricDiff(const set<int>& s1, const set<int>& s2)
    {
        set<int> result;
        for (int elem : s1) {
            if (s2.find(elem) == s2.end()) {
                result.insert(elem);
            }
        }
        for (int elem : s2) {
            if (s1.find(elem) == s1.end()) {
                result.insert(elem);
            }
        }
        return result;
    }
    set<int> Complement(const set<int>& s)
    {
        set<int> result;
        for (int elem : universalSet) {
            if (s.find(elem) == s.end()) {
                result.insert(elem);
            }
        }
        return result;
    }

    void manualInput(set<int>& s, const string& setName)
    {
        s.clear();
        int count;
        cout << "Введите количество элементов для множества " << setName << ": ";
        while (!(cin >> count) || count < 0 || count >(MAX - MIN + 1))
        {
            cout << "Ошибка! Введите корректное количество (0-" << (MAX - MIN + 1) << "): ";
            clearBuf();
        }

        cout << "Введите " << count << " элементов из диапазона [" << MIN << ", " << MAX << "]:" << endl;
        for (int i = 0; i < count; i++)
        {
            int element;
            cout << "Элемент " << (i + 1) << ": ";

            while (!(cin >> element) || !val_elem(element))
            {
                cout << "Ошибка! Элемент должен быть в диапазоне [" << MIN << ", " << MAX << "]: ";
                clearBuf();
            }

            if (s.find(element) != s.end())
            {
                cout << "Элемент " << element << " уже существует в множестве" << endl;
                i--;
            }
            else
            {
                s.insert(element);
            }
        }
    }

    void randomInput(set<int>& s, const string& setName)
    {
        s.clear();
        int count;
        cout << "Введите количество элементов для случайного заполнения " << setName << ": ";
        while (!(cin >> count) || count < 0 || count >(MAX - MIN + 1)) {
            cout << "Ошибка! Введите корректное количество (0-" << (MAX - MIN + 1) << "): ";
            clearBuf();
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(MIN, MAX);

        while (s.size() < count)
        {
            int element = distrib(gen);
            s.insert(element);
        }
    }

    void autoInput(set<int>& s, const string& setName)
    {
        s.clear();

        int parityChoice = 0, signChoice = 0, multipleChoice = 0;

        cout << "\nВыберите критерий ЧЕТНОСТИ для " << setName << ":" << endl;
        cout << "0. Без условия четности" << endl;
        cout << "1. Только четные числа" << endl;
        cout << "2. Только нечетные числа" << endl;
        cout << "Ваш выбор: ";

        while (!(cin >> parityChoice) || parityChoice < 0 || parityChoice > 2)
        {
            cout << "Ошибка! Выберите от 0 до 2: ";
            clearBuf();
        }

        cout << "\nВыберите критерий ЗНАКА для " << setName << ":" << endl;
        cout << "0. Без условия знака" << endl;
        cout << "1. Только положительные числа" << endl;
        cout << "2. Только отрицательные числа" << endl;
        cout << "3. Только ноль" << endl;
        cout << "Ваш выбор: ";

        while (!(cin >> signChoice) || signChoice < 0 || signChoice > 3)
        {
            cout << "Ошибка! Выберите от 0 до 3: ";
            clearBuf();
        }

        cout << "\nВыберите критерий КРАТНОСТИ для " << setName << ":" << endl;
        cout << "0. Без условия кратности" << endl;
        cout << "1. Кратные 3" << endl;
        cout << "2. Кратные 5" << endl;
        cout << "Ваш выбор: ";

        while (!(cin >> multipleChoice) || multipleChoice < 0 || multipleChoice > 2)
        {
            cout << "Ошибка! Выберите от 0 до 2: ";
            clearBuf();
        }

        for (int i = MIN; i <= MAX; i++)
        {
            bool AllConditions = true;

            if (parityChoice != 0)
            {
                if (parityChoice == 1 && i % 2 != 0) AllConditions = false;
                if (parityChoice == 2 && i % 2 == 0) AllConditions = false;
            }

            if (signChoice != 0 && AllConditions)
            {
                if (signChoice == 1 && i <= 0) AllConditions = false;
                if (signChoice == 2 && i >= 0) AllConditions = false;
                if (signChoice == 3 && i != 0) AllConditions = false;
            }

            if (multipleChoice != 0 && AllConditions)
            {
                if (multipleChoice == 1 && i % 3 != 0) AllConditions = false;
                if (multipleChoice == 2 && i % 5 != 0) AllConditions = false;
            }

            if (AllConditions)
            {
                s.insert(i);
            }
        }

        cout << "Множество " << setName << " заполнено по выбранным критериям. Элементов: " << s.size() << endl;
    }

    void inputSet(set<int>& s, const string& setName)
    {
        int method;
        cout << "\nВыберите способ задания множества " << setName << ":" << endl;
        cout << "1. Ручной ввод" << endl;
        cout << "2. Рандомное заполнение" << endl;
        cout << "3. По условию" << endl;
        cout << "Ваш выбор: ";

        while (!(cin >> method) || method < 1 || method > 3)
        {
            cout << "Ошибка! Выберите от 1 до 3: ";
            clearBuf();
        }

        switch (method)
        {
        case 1: manualInput(s, setName); break;
        case 2: randomInput(s, setName); break;
        case 3: autoInput(s, setName); break;
        }
    }

    void SetMenu()
    {
        int choice;
        cout << "\nРедактирование множеств" << endl;
        cout << "1. Редактировать множество A" << endl;
        cout << "2. Редактировать множество B" << endl;
        cout << "3. Редактировать множество C" << endl;
        cout << "4. Вернуться в главное меню" << endl;
        cout << "Ваш выбор: ";

        while (!(cin >> choice) || choice < 1 || choice > 4)
        {
            cout << "Ошибка! Выберите от 1 до 4: ";
            clearBuf();
        }

        if (choice == 4) return;

        string setName;
        set<int>* targetSet = nullptr;

        switch (choice)
        {
        case 1: targetSet = &setA; setName = "A"; break;
        case 2: targetSet = &setB; setName = "B"; break;
        case 3: targetSet = &setC; setName = "C"; break;
        }

        inputSet(*targetSet, setName);
    }

    void showSets()
    {
        cout << "\nИсходные множества" << endl;
        printSet(setA, "A");
        printSet(setB, "B");
        printSet(setC, "C");
    }

    // Функция для выбора операции
    int chooseOperation(const string& stepName) 
    {
        int op;
        cout << "\n" << stepName << " - выберите операцию:" << endl;
        cout << "1. Объединение " << endl;
        cout << "2. Пересечение " << endl;
        cout << "3. Разность " << endl;
        cout << "4. Симметрическая разность" << endl;
        cout << "Ваш выбор: ";

        while (!(cin >> op) || op < 1 || op > 4) 
        {
            cout << "Ошибка! Выберите от 1 до 4: ";
            clearBuf();
        }
        return op;
    }

    // Функция для выбора множества
    int chooseSet(const string& prompt) 
    {
        int setNum;
        cout << prompt << " (1-A, 2-B, 3-C): ";
        while (!(cin >> setNum) || setNum < 1 || setNum > 3) 
        {
            cout << "Ошибка! Выберите от 1 до 3: ";
            clearBuf();
        }
        return setNum;
    }

    // Применение операции к двум множествам
    set<int> applyOperation(int operation, const set<int>& s1, const set<int>& s2) 
    {
        switch (operation) 
        {
        case 1: return Union(s1, s2);
        case 2: return Intersection(s1, s2);
        case 3: return Diff(s1, s2);
        case 4: return SymmetricDiff(s1, s2);
        default: return set<int>();
        }
    }

    void operations()
    {
        int choice;
        do {
            cout << "\nВыберите тип операции" << endl;
            cout << "1. Операция с 1 множеством (дополнение)" << endl;
            cout << "2. Операция с 2 множествами" << endl;
            cout << "3. Операция с 3 множествами" << endl;
            cout << "4. Вернуться в главное меню" << endl;
            cout << "Ваш выбор: ";

            while (!(cin >> choice) || choice < 1 || choice > 4)
            {
                cout << "Ошибка! Выберите от 1 до 4: ";
                clearBuf();
            }

            if (choice == 4) break;

            set<int> result;
            string operationName;

            switch (choice)
            {
            case 1:
            {
                // Операция с 1 множеством - дополнение
                int setNum = chooseSet("Выберите множество для дополнения");
                result = Complement(getIndex(setNum));
                string setName = (setNum == 1) ? "A" : (setNum == 2) ? "B" : "C";
                operationName = "Дополнение " + setName;
                break;
            }

            case 2:
            {
                // Операция с 2 множествами
                int op = chooseOperation("Операция с 2 множествами");
                int set1 = chooseSet("Выберите первое множество");
                int set2 = chooseSet("Выберите второе множество");

                string name1 = (set1 == 1) ? "A" : (set1 == 2) ? "B" : "C";
                string name2 = (set2 == 1) ? "A" : (set2 == 2) ? "B" : "C";

                result = applyOperation(op, getIndex(set1), getIndex(set2));

                
                switch (op) 
                {
                case 1: operationName = name1 + " U " + name2; break;
                case 2: operationName = name1 + " ∩ " + name2; break;
                case 3: operationName = name1 + " \\ " + name2; break;
                case 4: operationName = name1 + "  △ " + name2; break;
                }
                break;
            }

            case 3:
            {
                // Операция с 3 множествами
                cout << "\n Операция с 3 множествами" << endl;

                
                int op1 = chooseOperation("Операция между первыми двумя множествами");
                int set1 = chooseSet("Выберите первое множество");
                int set2 = chooseSet("Выберите второе множество");

                set<int> intermediate = applyOperation(op1, getIndex(set1), getIndex(set2));

                string name1 = (set1 == 1) ? "A" : (set1 == 2) ? "B" : "C";
                string name2 = (set2 == 1) ? "A" : (set2 == 2) ? "B" : "C";
                string opSymbol1 = (op1 == 1) ? "U" : (op1 == 2) ? "∩" : (op1 == 3) ? "\\" : " △";

                cout << "\nПромежуточный результат: (" << name1 << " " << opSymbol1 << " " << name2 << ")" << endl;
                printSet(intermediate, "Temp");

                
                int op2 = chooseOperation("Операция с третьим множеством");
                int set3 = chooseSet("Выберите третье множество");

                result = applyOperation(op2, intermediate, getIndex(set3));

                string name3 = (set3 == 1) ? "A" : (set3 == 2) ? "B" : "C";
                string opSymbol2 = (op2 == 1) ? "U" : (op2 == 2) ? "∩" : (op2 == 3) ? "\\" : " △";

                operationName = "(" + name1 + " " + opSymbol1 + " " + name2 + ") " + opSymbol2 + " " + name3;
                break;
            }
            }

            cout << "\nРезультат операции " << operationName << ":" << endl;
            printSet(result, "Result");

        } while (true);
    }

public:
    Calculator()
    {
        Filling();
    }

    void run()
    {
        cout << "Калькулятор множеств" << endl;

        inputSet(setA, "A");
        inputSet(setB, "B");
        inputSet(setC, "C");

        int choice;
        do {
            cout << "\nГлавное меню" << endl;
            cout << "1. Показать текущие множества" << endl;
            cout << "2. Редактировать множества" << endl;
            cout << "3. Выполнить операции над множествами" << endl;
            cout << "4. Выход" << endl;
            cout << "Ваш выбор: ";

            while (!(cin >> choice) || choice < 1 || choice > 4)
            {
                cout << "Ошибка! Выберите от 1 до 4: ";
                clearBuf();
            }

            switch (choice)
            {
            case 1: showSets(); break;
            case 2: SetMenu(); break;
            case 3: operations(); break;
            case 4: cout << "Выход из программы..." << endl; break;
            }

        } while (choice != 4);
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Calculator calculator;
    calculator.run();
    return 0;
}
