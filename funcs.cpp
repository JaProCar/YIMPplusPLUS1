#include <iostream>
#include <fstream>
#include "Zag.h"

using namespace std;

void nm::display(){
    string line;
    ifstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt"); // окрываем файл для чтения
    while (getline(f, line)){
    cout << line << endl;
    }
    f.close();
}

void nm::search(string a){
    string name, sold, used;
    ifstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    while(f >> name){
        f >> sold;
        f >> used;
        if(name == a){
            cout << name << " " << sold<< " " << used << endl;
        }
    }
    f.close();
}

void nm::search(int a){
    string name, sold, used;
    string x = to_string(a);
    ifstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    while(f >> name){
        f >> sold;
        f >> used;
        if(sold == x){
            cout << name << " " << sold<< " " << used << endl;
        }
    }
    f.close();
}

void nm::add(){
    string edName;
    int edSold, edUsed;
    cout << "Введите имя переменной ";
    cin >> edName;
    cout << "Введите кол-во проданных билетов ";
    cin >> edSold;
    cout << "Введите кол-во использованных билетов ";
    cin >> edUsed;
    ofstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt", ios::app | ios::ate);
    f << edName << " " << edSold << " " << edUsed << endl;
    f.close();
}

void nm::del(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    while(getline(fread, line)){
        i++;
    }
    tickets arr[i];
    fread.close();
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    string eds;
    int edi;
    for(int n = 0; n < i; n++){
        fread >> eds;
        arr[n].name = eds;
        fread >> edi;
        arr[n].sold = edi;
        fread >> edi;
        arr[n].used = edi;
    }
    fread.close();
    string edName;
    int edSold, edUsed;
    cout << "Введите имя переменной ";
    cin >> edName;
    cout << "Введите кол-во проданных билетов ";
    cin >> edSold;
    cout << "Введите кол-во использованных билетов ";
    cin >> edUsed;
    ofstream fwrite;
    fwrite.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    for(int n = 0; n < i; n++){
        if((arr[n].name != edName) || (arr[n].sold != edSold) || (arr[n].used != edUsed)){
            fwrite << arr[n].name << " " << arr[n].sold << " " << arr[n].used << endl;
        }
    }
}

void nm::edit(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    while(getline(fread, line)){
        i++;
    }
    tickets arr[i];
    fread.close();
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    string eds;
    int edi;
    for(int n = 0; n < i; n++){
        fread >> eds;
        arr[n].name = eds;
        fread >> edi;
        arr[n].sold = edi;
        fread >> edi;
        arr[n].used = edi;
    }
    fread.close();
    string oldName;
    int oldSold, oldUsed;
    cout << "Введите имя переменной ";
    cin >> oldName;
    cout << "Введите кол-во проданных билетов ";
    cin >> oldSold;
    cout << "Введите кол-во использованных билетов ";
    cin >> oldUsed;
    string newName;
    int newSold, newUsed;
    cout << "Введите имя переменной ";
    cin >> newName;
    cout << "Введите кол-во проданных билетов ";
    cin >> newSold;
    cout << "Введите кол-во использованных билетов ";
    cin >> newUsed;
    ofstream fwrite;
    fwrite.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    for(int n = 0; n < i; n++){
        if((arr[n].name != oldName) || (arr[n].sold != oldSold) || (arr[n].used != oldUsed)){
            fwrite << arr[n].name << " " << arr[n].sold << " " << arr[n].used << endl;
        }else{
            fwrite << newName << " " << newSold << " " << newUsed << endl;
        }
    }
}
