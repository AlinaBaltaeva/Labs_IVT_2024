#include <iostream>
#include <clocale>

using namespace std;

class QuineMcCluskey 
{
private:
    char truthVector[17];
    char minterms[16][5];
    char primeImplicants[50][5];
    bool coverageMatrix[50][16];
    int mintermsCount;
    int primeImplicantsCount;
    int variables;

    void copyString(char* dest, const char* src, int maxLen) 
    {
        int i = 0;
        while (src[i] != '\0' && i < maxLen - 1) 
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    int stringLength(const char* str) 
    {
        int len = 0;
        while (str[len] != '\0') 
        {
            len++;
        }
        return len;
    }

    bool stringEqual(const char* str1, const char* str2) 
    {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') 
        {
            if (str1[i] != str2[i]) 
            {
                return false;
            }
            i++;
        }
        return str1[i] == str2[i];
    }

    void IstinTable() 
    {
        cout << "\n ТАБЛИЦА ИСТИННОСТИ " << endl;
        cout << "x y z w | f" << endl;
        cout << "--------|---" << endl;

        for (int i = 0; i < 16; i++) 
        {
            int x = (i >> 3) & 1;
            int y = (i >> 2) & 1;
            int z = (i >> 1) & 1;
            int w = i & 1;
            char value = truthVector[i];

            cout << x << " " << y << " " << z << " " << w << " | " << value << endl;
        }
    }
    //СДНФ
    void buildMinterms() 
    {
        mintermsCount = 0;
        for (int i = 0; i < 16; i++) 
        {
            if (truthVector[i] == '1') 
            {
                minterms[mintermsCount][0] = (i & 8) ? 'x' : 'X';
                minterms[mintermsCount][1] = (i & 4) ? 'y' : 'Y';
                minterms[mintermsCount][2] = (i & 2) ? 'z' : 'Z';
                minterms[mintermsCount][3] = (i & 1) ? 'w' : 'W';
                minterms[mintermsCount][4] = '\0';
                mintermsCount++;
            }
        }
    }

    const char* implicantToString(const char* implicant) 
    {
        static char result[10];
        int pos = 0;
        char vars[] = { 'x', 'y', 'z', 'w' };

        for (int i = 0; i < 4; i++) 
        {
            if (implicant[i] == '-') 
            {
                continue;
            }
            if (implicant[i] >= 'A' && implicant[i] <= 'Z')
            {
                result[pos++] = '_';
                result[pos++] = vars[i];
            }
            else if (implicant[i] >= 'a' && implicant[i] <= 'z') 
            {
                result[pos++] = vars[i];
            }
        }
        result[pos] = '\0';
        return result;
    }

    const char* mintermToString(const char* minterm) 
    {
        return implicantToString(minterm);
    }

    int countOnes(const char* term) 
    {
        int count = 0;
        for (int i = 0; i < 4; i++) 
        {
            if (term[i] >= 'a' && term[i] <= 'z') 
            {
                count++;
            }
        }
        return count;
    }
    //Поиск простых импликантов
    bool canCombine(const char* term1, const char* term2) 
    {
        int diffCount = 0;
        for (int i = 0; i < 4; i++) 
        {
            if (term1[i] != term2[i]) 
            {
                if (!((term1[i] >= 'A' && term1[i] <= 'Z' && term2[i] >= 'a' && term2[i] <= 'z' && term1[i] + 32 == term2[i]) ||
                    (term1[i] >= 'a' && term1[i] <= 'z' && term2[i] >= 'A' && term2[i] <= 'Z' && term1[i] - 32 == term2[i]))) {
                    return false;
                }
                diffCount++;
                if (diffCount > 1) 
                {
                    return false;
                }
            }
        }
        return diffCount == 1;
    }
    //Поиск простых импликантов
    void combineTerms(const char* term1, const char* term2, char* result) 
    {
        for (int i = 0; i < 4; i++) 
        {
            if (term1[i] != term2[i]) 
            {
                result[i] = '-';
            }
            else 
            {
                result[i] = term1[i];
            }
        }
        result[4] = '\0';
    }

    bool containsTerm(char terms[][5], int count, const char* term) 
    {
        for (int i = 0; i < count; i++) 
        {
            if (stringEqual(terms[i], term)) 
            {
                return true;
            }
        }
        return false;
    }

    void addUniqueTerm(char terms[][5], int& count, const char* term) 
    {
        if (!containsTerm(terms, count, term)) 
        {
            copyString(terms[count], term, 5);
            count++;
        }
    }

    bool covers(const char* implicant, const char* minterm) 
    {
        for (int i = 0; i < 4; i++) 
        {
            if (implicant[i] != '-') 
            {
                if (implicant[i] != minterm[i]) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    void findEssentialImplicants(int* essential, int& essentialCount) 
    {
        essentialCount = 0;
        int coverageCount[16];

        for (int j = 0; j < mintermsCount; j++) 
        {
            coverageCount[j] = 0;
            for (int i = 0; i < primeImplicantsCount; i++) 
            {
                if (coverageMatrix[i][j])
                {
                    coverageCount[j]++;
                }
            }
        }

        for (int j = 0; j < mintermsCount; j++) 
        {
            if (coverageCount[j] == 1) 
            {
                for (int i = 0; i < primeImplicantsCount; i++)
                {
                    if (coverageMatrix[i][j]) 
                    {
                        bool found = false;
                        for (int k = 0; k < essentialCount; k++) 
                        {
                            if (essential[k] == i)
                            {
                                found = true;
                                break;
                            }
                        }
                        if (!found) 
                        {
                            essential[essentialCount++] = i;
                        }
                    }
                }
            }
        }
    }

public:
    QuineMcCluskey() : variables(4), mintermsCount(0), primeImplicantsCount(0) {
        truthVector[0] = '\0';
    }

    bool setTruthVector(const char* vector) {
        int len = stringLength(vector);

        if (len != 16) {
            cout << "Ошибка: вектор должен содержать 16 символов!" << endl;
            return false;
        }

        for (int i = 0; i < 16; i++) {
            if (vector[i] != '0' && vector[i] != '1') {
                cout << "Ошибка: вектор должен содержать только 0 и 1!" << endl;
                return false;
            }
            truthVector[i] = vector[i];
        }
        truthVector[16] = '\0';

        buildMinterms();
        return true;
    }

    void displayTruthTable() {
        IstinTable();
    }
    //СДНФ
    void displaySDNF() {
        cout << "\n СОВЕРШЕННАЯ ДИЗЪЮНКТИВНАЯ НОРМАЛЬНАЯ ФОРМА " << endl;
        if (mintermsCount == 0) {
            cout << "f(x,y,z,w) = 0" << endl;
            return;
        }

        cout << "f(x,y,z,w) = ";
        for (int i = 0; i < mintermsCount; i++) {
            cout << mintermToString(minterms[i]);
            if (i < mintermsCount - 1) {
                cout << " + ";
            }
        }
        cout << endl;
    }
    //Поиск простых импликантов- ищет сколько 1 и указывает в группе
    void findPrimeImplicants() {
        cout << "\n ПОИСК СКЛЕЙКИ " << endl;

        char groups[5][16][5];
        int groupSizes[5] = { 0 };
        char currentTerms[50][5];
        int currentTermsCount = 0;
        bool used[50];

        
        for (int i = 0; i < mintermsCount; i++) {
            int ones = countOnes(minterms[i]);
            copyString(groups[ones][groupSizes[ones]], minterms[i], 5);
            groupSizes[ones]++;
            copyString(currentTerms[currentTermsCount], minterms[i], 5);
            currentTermsCount++;
        }

        cout << "Начальные группы:" << endl;
        for (int i = 0; i < 5; i++) {
            if (groupSizes[i] > 0) {
                cout << "Группа " << i << ": ";
                for (int j = 0; j < groupSizes[i]; j++) {
                    cout << implicantToString(groups[i][j]) << " ";
                }
                cout << endl;
            }
        }

        int stage = 1;
        bool changed = true;

        primeImplicantsCount = 0;

        while (changed) {
            changed = false;
            char newGroups[4][16][5];
            int newGroupSizes[4] = { 0 };

            for (int i = 0; i < currentTermsCount; i++) {
                used[i] = false;
            }

            cout << "\nЭтап склейки " << stage << endl;

            // Пробуем склеить термы из соседних групп
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < groupSizes[i]; j++) {
                    for (int k = 0; k < groupSizes[i + 1]; k++) {
                        if (canCombine(groups[i][j], groups[i + 1][k])) {
                            char combined[5];
                            combineTerms(groups[i][j], groups[i + 1][k], combined);

                            int ones = countOnes(combined);
                            copyString(newGroups[ones][newGroupSizes[ones]], combined, 5);
                            newGroupSizes[ones]++;
                            changed = true;

                            // Помечаем использованные термы
                            for (int m = 0; m < currentTermsCount; m++) {
                                if (stringEqual(currentTerms[m], groups[i][j]) ||
                                    stringEqual(currentTerms[m], groups[i + 1][k])) {
                                    used[m] = true;
                                }
                            }

                            cout << "Склейка: " << implicantToString(groups[i][j]) << " + "
                                << implicantToString(groups[i + 1][k]) << " = "
                                << implicantToString(combined) << endl;
                        }
                    }
                }
            }

            // Добавляем непокрытые термы в простые импликанты
            for (int i = 0; i < currentTermsCount; i++) {
                if (!used[i]) {
                    addUniqueTerm(primeImplicants, primeImplicantsCount, currentTerms[i]);
                }
            }

            if (changed) {
                cout << "\nРезультаты склейки этапа " << stage << ":" << endl;
                for (int i = 0; i < 4; i++) {
                    if (newGroupSizes[i] > 0) {
                        cout << "Группа " << i << ": ";
                        for (int j = 0; j < newGroupSizes[i]; j++) {
                            cout << implicantToString(newGroups[i][j]) << " ";
                        }
                        cout << endl;
                    }
                }

                // Обновляем группы для следующей итерации
                for (int i = 0; i < 4; i++) {
                    groupSizes[i] = newGroupSizes[i];
                    for (int j = 0; j < groupSizes[i]; j++) {
                        copyString(groups[i][j], newGroups[i][j], 5);
                    }
                }
                groupSizes[4] = 0;

                // Обновляем currentTerms
                currentTermsCount = 0;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < groupSizes[i]; j++) {
                        copyString(currentTerms[currentTermsCount], groups[i][j], 5);
                        currentTermsCount++;
                    }
                }
            }

            stage++;
        }

        // Добавляем оставшиеся термы
        for (int i = 0; i < currentTermsCount; i++) {
            addUniqueTerm(primeImplicants, primeImplicantsCount, currentTerms[i]);
        }

        cout << "\nПростые импликанты: ";
        for (int i = 0; i < primeImplicantsCount; i++) {
            cout << implicantToString(primeImplicants[i]) << " ";
        }
        cout << endl;
    }

    void buildCoverageMatrix() {
        cout << "\n ИМПЛИКАНТНАЯ МАТРИЦА " << endl;

        cout << "Импликанты\\Минтермы";
        for (int j = 0; j < mintermsCount; j++) {
            cout << "\t" << implicantToString(minterms[j]);
        }
        cout << endl;

        for (int i = 0; i < primeImplicantsCount; i++) {
            cout << implicantToString(primeImplicants[i]);
            for (int j = 0; j < mintermsCount; j++) {
                coverageMatrix[i][j] = covers(primeImplicants[i], minterms[j]);
                cout << "\t" << (coverageMatrix[i][j] ? "+" : "-");
            }
            cout << endl;
        }
    }

    void findMinimalCoverages() {
        cout << "\n ПОИСК МИНИМАЛЬНЫХ ПОКРЫТИЙ " << endl;

        int essential[50];
        int essentialCount = 0;
        findEssentialImplicants(essential, essentialCount);

        if (essentialCount > 0) {
            cout << "Существенные импликанты: ";
            for (int i = 0; i < essentialCount; i++) {
                cout << implicantToString(primeImplicants[essential[i]]) << " ";
            }
            cout << endl;
        }

        cout << "Минимальная ДНФ: ";
        if (primeImplicantsCount == 0) {
            cout << "0";
        }
        else {
            for (int i = 0; i < essentialCount; i++) {
                cout << implicantToString(primeImplicants[essential[i]]);
                if (i < essentialCount - 1) {
                    cout << " + ";
                }
            }
            if (essentialCount == 0 && primeImplicantsCount > 0) {
                cout << implicantToString(primeImplicants[0]);
            }
        }
        cout << endl;
    }

    void checkLinearity() {
        cout << "\n ПРОВЕРКА ЛИНЕЙНОСТИ " << endl;

        bool possiblyLinear = true;

        if (mintermsCount > 8 && mintermsCount < 16) {
            possiblyLinear = false;
        }

        if (possiblyLinear) {
            cout << "Функция может быть линейной" << endl;
        }
        else {
            cout << "Функция не линейна (обнаружены нелинейные свойства)" << endl;
        }
    }

    void minimize() {
        if (truthVector[0] == '\0') {
            cout << "Ошибка: сначала задайте вектор истинности!" << endl;
            return;
        }

        displayTruthTable();
        displaySDNF();
        checkLinearity();
        findPrimeImplicants();
        buildCoverageMatrix();
        findMinimalCoverages();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    QuineMcCluskey qm;
    char input[17];

    cout << " МИНИМИЗАЦИЯ ЛОГИЧЕСКОЙ ФУНКЦИИ МЕТОДОМ КВАЙНА " << endl;

    while (true) {
        cout << "\nВведите вектор истинности (16 символов 0 и 1): ";
        cin >> input;

        if (qm.setTruthVector(input)) {
            break;
        }
    }

    qm.minimize();

    return 0;
}