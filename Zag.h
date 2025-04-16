#include <iostream>

using namespace std;

namespace nm{
class tickets{
public:
    string name;
    int sold;
    int used;
    friend ostream& operator<<(ostream& os, const tickets& Tickets);
    friend istream& operator>>(istream& is, const tickets& Tickets);
};

void display();
void search(string a);
void search(int a);
void add();
void del();
void edit();
}
