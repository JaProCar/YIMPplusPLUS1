#include "Zag.h"

using namespace std;
using namespace nm;

int main(){
    int choose;
    for(;;){
    cout << "Выберите действие с БД: 1.Вывод БД на экран 2.Поиск элемента 3.Добавление элемента 4.Удаление элемента 5.Редактирование элемента" << endl;
    cin >> choose;
    switch(choose){
    case 1:{
        display();
        break;
    }
    case 2:{
        cout << "Выберите режим поиска: 1. По названию 2. По продажам" << endl;
        int ed;
        cin >> ed;
        switch(ed){
        case 1:{
            string sh; // search
            cout << "Введите название элемента" << endl;
            cin >> sh;
            search(sh);
            break;
        }
        case 2:{
            int sh;// search
            cout << "Введите кол-во проданных билетов" << endl;
            cin >> sh;
            search(sh);
            break;
        }
        }
        break;
    }
    case 3:{
        add();
        break;
    }
    case 4:{
        del();
        break;
    }
    case 5:{
        edit();
        break;
    }
    }
    }
}
