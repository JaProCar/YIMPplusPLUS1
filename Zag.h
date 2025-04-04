#include <iostream>

using namespace std;

namespace nm{
class tickets{
public:
    string name;
    int sold;
    int used;
};

void display();
void search(string a);
void search(int a);
void add();
void del();
void edit();
}
