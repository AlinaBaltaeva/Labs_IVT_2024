#pragma once
#include "Time.h"
#include <fstream>
#include <iostream>
#include <string>

int make_file(const char* f_name)
{
    std::fstream file(f_name, std::ios::out | std::ios::trunc);
    if (!file)
    {
        return -1;
    }
    int n;
    Time time;
    std::cout << "N?: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> time;
        file << time << "\n";
    }
    file.close();
    return n;
}

int printFile(const char* fileName) {
    fstream file(fileName, ios::in);
    if (!file) { return -1; }
    Time m2; int i = 0;
    while (file >> m2) {
        cout << m2 << "\n";
        i++;
    }
    file.close();
    return i;
}


int del_file(const char* fileName, Time time)
{
    const char* temp_name = "temp.txt";
    fstream file(fileName, ios::in);
    fstream out_file(temp_name, ios::out);
    if (!file)
    {
        return -1;
    }
    int i = 0;
    Time m;
    while (file >> m)
    {
        if (!(m != time)) 
        {
            out_file << m << "\n";
            i++;
        }
    }
    file.close();
    out_file.close();
    remove(fileName);
    rename(temp_name, fileName);
    return i;
}
int decrease_records(const char* f_name, Time value) {
    const char* temp_name = "temp.txt";
    std::fstream in_file(f_name, std::ios::in);
    std::fstream out_file(temp_name, std::ios::out);

    if (!in_file || !out_file) return -1;

    Time t;
    int count = 0;
    while (in_file >> t) {
        if (!(t != value)) { // если равны заданному значению
            t.setMin(t.getMin() - 90);
            t.normalize();
            count++;
        }
        out_file << t << "\n";
    }

    in_file.close();
    out_file.close();

    std::remove(f_name);
    std::rename(temp_name, f_name);
    return count;
}

int add_k_to_beginning(const char* f_name, int k) {
    const char* temp_name = "temp.txt";
    std::fstream out_file(temp_name, std::ios::out);
    std::fstream in_file(f_name, std::ios::in);

    if (!in_file || !out_file) return -1;

    // ƒобавл€ем K новых записей
    Time t;
    for (int i = 0; i < k; i++) {
        std::cout << "Enter time (mm:ss): ";
        std::cin >> t;
        out_file << t << "\n";
    }

    //  опируем существующие записи
    while (in_file >> t) {
        out_file << t << "\n";
    }

    in_file.close();
    out_file.close();

    std::remove(f_name);
    std::rename(temp_name, f_name);
    return k;
}