#include <iostream>
#include <fstream>
#include "Zag.h"

using namespace std;

ostream& operator<<(ostream& os, const nm::tickets& Tickets){
    os << Tickets.name << " " << Tickets.sold << " " << Tickets.used;
    return os;
}

istream& operator>>(istream& is, nm::tickets& Tickets){
    is >> Tickets.name >> Tickets.sold >> Tickets.used;
    return is;
}

void nm::display(){
    string line;
    ifstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt"); // окрываем файл для чтения
    if(!f.is_open())
        return;
    while (getline(f, line)){
    cout << line << endl;
    }
    f.close();
}

void nm::search(string a){
    tickets editable;
    ifstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!f.is_open())
        return;
    while(f >> editable){
        if(editable.name == a){
            cout << editable.name << " " << editable.sold<< " " << editable.used << endl;
        }
    }
    f.close();
}

void nm::search(int a){
    tickets editable;
    ifstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!f.is_open())
        return;
    while(f >> editable){
        if(editable.sold == a){
            cout << editable.name << " " << editable.sold<< " " << editable.used << endl;
        }
    }
    f.close();
}

void nm::add(){
    tickets editable;
    cin >> editable;
    fstream f;
    f.open("/home/japrocar/Документы/Лабы/laba1/Base.txt", ios::app | ios::ate);
    if(!f.is_open())
        return;
    f << editable.name << " " << editable.sold << " " << editable.used;
    f.close();
}

void nm::del(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    tickets arr[i];
    fread.close();
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!fread.is_open())
        return;
    tickets editable2;
    for(int n = 0; n < i; n++){
        fread >> editable2;
        arr[n] = editable2;
    }
    fread.close();
    tickets editable;
    cout << "Введите названия, продажи, использования переменной ";
    cin >> editable;
    ofstream fwrite;
    fwrite.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!fwrite.is_open())
        return;
    for(int n = 0; n < i; n++){
        if((arr[n].name != editable.name) || (arr[n].sold != editable.sold) || (arr[n].used != editable.used)){
            fwrite << arr[n].name << " " << arr[n].sold << " " << arr[n].used << endl;
        }
    }
}

void nm::edit(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    tickets arr[i];
    fread.close();
    fread.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!fread.is_open())
        return;
    tickets editable;
    for(int n = 0; n < i; n++){
        fread >> editable;
        arr[n] = editable;
    }
    fread.close();
    tickets editableOLD;
    cout << "Введите старые название, продажи, использования переменной ";
    cin >> editableOLD;
    tickets editableNEW;
    cout << "Введите новые названия, продажи, использования переменной ";
    cin >> editableNEW;
    ofstream fwrite;
    fwrite.open("/home/japrocar/Документы/Лабы/laba1/Base.txt");
    if(!fwrite.is_open())
        return;
    for(int n = 0; n < i; n++){
        if((arr[n].name != editableOLD.name) || (arr[n].sold != editableOLD.sold) || (arr[n].used != editableOLD.used)){
            fwrite << arr[n].name << " " << arr[n].sold << " " << arr[n].used << endl;
        }else{
            fwrite << editableNEW.name << " " << editableNEW.sold << " " << editableNEW.used << endl;
        }
    }
}
