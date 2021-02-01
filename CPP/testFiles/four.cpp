#include<iostream>
#include"genericDataStructures/ll.hpp"

using namespace std;

int main()
{
    List<int> L1;
    L1.insert(1);
    L1.insert(34);
    L1.insert(76);
    L1.insert(5);
    L1.show();

    List<char> L2;
    L2.insert('a');
    L2.insert('w');
    L2.insert('r');
    L2.insert('d');
    L2.show();

    List<string> L3;
    L3.insert("ajay");
    L3.insert("arshi");
    L3.insert("chiterlekha");
    L3.insert("yashesvi");
    L3.show();

    L1.remove(34);
    L1.show();
    L2.remove('a');
    L2.show();
    L3.remove("yashesvi");
    L3.show();
}