#include "Time.h"
#include "file_work.h"
#include <iostream>

int main()
{
    Time time;
    int choise, t, tmp, k;
    char file_name[30];
    do
    {
        std::cout << "\n1. Make file";
        std::cout << "\n2. Print file";
        std::cout << "\n3. Delete record from file";
        std::cout << "\n4. Time reduction by 1.30 ";
        std::cout << "\n5. Add K elemets";
        std::cout << "\n0. Exit\n";
        std::cin >> choise;
        switch (choise)
        {
        case 1:
            std::cout << "file name? ";
            std::cin >> file_name;
            tmp=make_file(file_name);
            if (tmp < 0)
                cout << "Error creating file\n";
            else
                cout << "Created " << tmp << " records\n";
            break;
        case 2:
            cout << "File name: ";
            cin >> file_name;
            tmp = printFile(file_name);

            if (tmp > 0) {
                cout << "Printed " << tmp << " records successfully\n";
            }
            else if (tmp == 0) {
                cout << "File is empty or contains no valid records\n";
            }
            else {
                cout << "Error: Can't read file (file may not exist or is corrupted)\n";
            }
            break;

        case 3:
            std::cout << "file name?";
            std::cin >> file_name;
            std::cout << "time(mm:ss)";
            std::cin >> time;
            del_file(file_name,time);
            if (tmp < 0)
                cout << "Error processing file\n";
            else
                cout << "Kept " << tmp << " records\n";
            break;
        case 4: {
            Time time;
            std::cout << "file name? ";
            std::cin >> file_name;
            std::cout << "time(mm:ss)";
            std::cin >> time;
            tmp= decrease_records(file_name,time);
            if (tmp < 0)
            {
                std::cout << "Can't read file\n";
            }
            else
            {
                cout << "Modified " << tmp << " records\n";
            }
        }
        case 5: {
            Time m2;
            std::cout << "file name? ";
            std::cin >> file_name;
            std::cout << "enter K: ";
            std::cin >>k;
            tmp = add_k_to_beginning(file_name, k);
            if (tmp < 0)
            {
                std::cout << "Can't read file\n";
            }
            else
            {
                cout << "Added " << tmp << " records\n";
            }
            break;
        }
        }
    } while (choise != 0);

    return 0;
}