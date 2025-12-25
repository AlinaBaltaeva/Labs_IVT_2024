#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

class BooleanFunction {
public:
    string Name;
    string Vector;
    int VariablesCount;

    BooleanFunction(string name, string vector) : Name(name), Vector(vector) {
        VariablesCount = static_cast<int>(log2(vector.length()));
    }

    // Проверка сохранения 0
    bool PreservesZero() const {
        return Vector[0] == '0';
    }

    // Проверка сохранения 1
    bool PreservesOne() const {
        return Vector[Vector.length() - 1] == '1';
    }

    // Проверка самодвойственности
    bool IsSelfDual() const {
        int n = Vector.length();
        for (int i = 0; i < n / 2; i++) {
            if (Vector[i] == Vector[n - 1 - i])
                return false;
        }
        return true;
    }

    // Проверка монотонности
    bool IsMonotonic() const {
        int n = VariablesCount;
        int vectorLength = 1 << n;

        for (int i = 0; i < vectorLength; i++) {
            for (int j = 0; j < vectorLength; j++) {
                // Если i <= j покомпонентно (i является подмаской j)
                if ((i & j) == i) {
                    if (Vector[i] == '1' && Vector[j] == '0')
                        return false;
                }
            }
        }
        return true;
    }

    // Проверка линейности
    bool IsLinear() const {
        int n = VariablesCount;
        int vectorLength = 1 << n;

        // Преобразуем вектор в массив значений
        vector<int> values(vectorLength);
        for (int i = 0; i < vectorLength; i++) {
            values[i] = Vector[i] == '1' ? 1 : 0;
        }

        // Используем преобразование Жегалкина
        vector<int> coeffs = values;

        // Выполняем преобразование Мёбиуса для получения коэффициентов полинома Жегалкина
        for (int i = 0; i < n; i++) {
            int step = 1 << i;
            for (int j = 0; j < vectorLength; j += step * 2) {
                for (int k = j; k < j + step; k++) {
                    coeffs[k + step] ^= coeffs[k];
                }
            }
        }

        // Функция линейна, если в полиноме Жегалкина только коэффициенты
        // при константе и линейных членах (не более одной переменной)
        for (int i = 0; i < vectorLength; i++) {
            if (coeffs[i] == 1) {
                if (CountOnes(i) > 1)
                    return false;
            }
        }
        return true;
    }

private:
    // Подсчет единиц в двоичном представлении числа
    int CountOnes(int x) const {
        int count = 0;
        while (x > 0) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
};

class FunctionSystemAnalyzer {
public:
    vector<BooleanFunction> Functions;

    FunctionSystemAnalyzer() {}

    void AddFunction(string name, string vector) {
        // Проверяем корректность длины вектора
        int length = vector.length();
        if (length != 1 && length != 2 && length != 4 && length != 8) {
            throw invalid_argument("Длина вектора должна быть 1, 2, 4 или 8");
        }

        // Проверяем, что вектор состоит только из 0 и 1
        for (char c : vector) {
            if (c != '0' && c != '1') {
                throw invalid_argument("Вектор должен содержать только символы '0' и '1'");
            }
        }

        Functions.push_back(BooleanFunction(name, vector));
    }

    void PrintMembershipMatrix() {
        cout << "\nМатрица принадлежности функций к замкнутым классам:" << endl;
        cout << "Функция\tT0\tT1\tS\tM\tL" << endl;

        for (const auto& func : Functions) {
            cout << func.Name << "\t"
                << func.PreservesZero() << "\t"
                << func.PreservesOne() << "\t"
                << func.IsSelfDual() << "\t"
                << func.IsMonotonic() << "\t"
                << func.IsLinear() << endl;
        }
    }

    void AnalyzeSystem() {
        bool hasT0 = false, hasT1 = false, hasS = false, hasM = false, hasL = false;

        for (const auto& func : Functions) {
            if (!func.PreservesZero()) hasT0 = true;
            if (!func.PreservesOne()) hasT1 = true;
            if (!func.IsSelfDual()) hasS = true;
            if (!func.IsMonotonic()) hasM = true;
            if (!func.IsLinear()) hasL = true;
        }

        // Проверка полноты по теореме Поста
        bool isComplete = hasT0 && hasT1 && hasS && hasM && hasL;

        //cout << "\nАнализ системы функций:" << endl;
        //cout << "Принадлежность дополнениям замкнутых классов:" << endl;
        //cout << "¬T0: " << hasT0 << ", ¬T1: " << hasT1 << ", ¬S: " << hasS
            //<< ", ¬M: " << hasM << ", ¬L: " << hasL << endl;

        // Проверка на базис
        bool isBasis = isComplete && IsMinimalSystem();

        cout << "\nРезультаты:" << endl;
        cout << "Система является полной: " << (isComplete ? "ДА" : "НЕТ") << endl;
        cout << "Система является базисом: " << (isBasis ? "ДА" : "НЕТ") << endl;

        if (!isComplete) {
            cout << "\nСистема не полна, так как отсутствуют функции из следующих классов:" << endl;
            if (!hasT0) cout << "- Не сохраняет 0" << endl;
            if (!hasT1) cout << "- Не сохраняет 1" << endl;
            if (!hasS) cout << "- Не самодвойственная" << endl;
            if (!hasM) cout << "- Не монотонная" << endl;
            if (!hasL) cout << "- Не линейная" << endl;
        }
    }

private:
    bool IsMinimalSystem() {
        // Система является базисом, если она полна и минимальна
        for (size_t i = 0; i < Functions.size(); i++) {
            // Проверяем, будет ли система полной без i-й функции
            vector<BooleanFunction> tempFunctions;
            for (size_t j = 0; j < Functions.size(); j++) {
                if (j != i) {
                    tempFunctions.push_back(Functions[j]);
                }
            }
            if (IsSystemComplete(tempFunctions)) {
                return false; // Нашли функцию, которую можно удалить
            }
        }
        return true;
    }

    bool IsSystemComplete(const vector<BooleanFunction>& functions) {
        if (functions.empty()) return false;

        bool hasT0 = false, hasT1 = false, hasS = false, hasM = false, hasL = false;

        for (const auto& func : functions) {
            if (!func.PreservesZero()) hasT0 = true;
            if (!func.PreservesOne()) hasT1 = true;
            if (!func.IsSelfDual()) hasS = true;
            if (!func.IsMonotonic()) hasM = true;
            if (!func.IsLinear()) hasL = true;
        }

        return hasT0 && hasT1 && hasS && hasM && hasL;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    FunctionSystemAnalyzer analyzer;

    cout << "Проверка полноты системы функций" << endl;
    

    try {
        // Пример ввода функций
        cout << "\nВведите функции (для завершения введите 'end'):" << endl;

        while (true) {
            cout << "Имя функции: ";
            string name;
            getline(cin, name);

            if (name == "end") break;

            cout << "Вектор функции (длина 1, 2, 4 или 8): ";
            string vector;
            getline(cin, vector);

            analyzer.AddFunction(name, vector);
            cout << "Функция " << name << " добавлена.\n" << endl;
        }

        // Если функций не введено, используем демонстрационный пример
        if (analyzer.Functions.empty()) {
            cout << "\nИспользуется демонстрационный пример:" << endl;

            // Пример полной системы (базис)
            analyzer.AddFunction("Импликация", "0111");    // x → y
            analyzer.AddFunction("Штрих Шеффера", "1110"); // x | y (NAND)

            cout << "Добавлены функции: Импликация (0111), Штрих Шеффера (1110)" << endl;
        }

        // Вывод матрицы принадлежности
        analyzer.PrintMembershipMatrix();

        // Анализ системы
        analyzer.AnalyzeSystem();

        // Демонстрация проверки линейности
        cout << "\nПроверка линейности" << endl;
        for (const auto& func : analyzer.Functions) {
            cout << "Функция " << func.Name << ": " << (func.IsLinear() ? "Линейна" : "Нелинейна") << endl;
        }

    }
    catch (const exception& ex) {
        cout << "Ошибка: " << ex.what() << endl;
    }

    cout << "\nНажмите любую клавишу для выхода...";
    cin.get();
    return 0;
}