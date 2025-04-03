#include <iostream>
#include <clocale>
using namespace std;

const int N = 8; // Размер доски 8x8
int chet = 0;

// Функция для вывода доски
void printBoard(bool board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j]) {
                cout << "Ф "; // Ферзь
            }
            else {
                cout << ". "; // Пустая клетка
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для проверки, безопасно ли поставить ферзя на клетку
bool isSafe(bool board[N][N], int row, int col) {
    // Проверка по вертикали вверх
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) {
            return false;
        }
    }

    // Проверка по диагонали влево вверх
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Проверка по диагонали вправо вверх
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Рекурсивная функция для решения задачи
bool solveNQueens(bool board[N][N], int row) {
    if (row == N) {
        // Все ферзи расставлены успешно
        ++chet;
        cout << chet << "-ое решение" << endl;
        printBoard(board);
        return true;
    }

    bool res = false; // Флаг для отслеживания успешной расстановки
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = true; // Ставим ферзя
            cout << "Попытка поставить ферзя на (" << row << ", " << col << "):\n";
            printBoard(board);

            // Рекурсия для следующего ряда
            res = solveNQueens(board, row + 1) || res;

            board[row][col] = false; // Откат (backtracking)
            cout << "Откат на (" << row << ", " << col << "):\n";
            printBoard(board);
        }
    }

    return res;
}

int main() {
    setlocale(LC_ALL, "RUS");
    bool board[N][N] = { false }; // Инициализация доски (все клетки пусты)
    solveNQueens(board, 0); // Начинаем с первого ряда
    return 0;
}
