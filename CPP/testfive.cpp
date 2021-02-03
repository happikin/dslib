#include<iostream>
#include"genericDataStructures/ll.hpp"

using namespace std;

int main()
{
    List<int>A;
    A.insert(11);
    A.insertAt(12,2);
    List<int>B;
    B.insert(33);
    B.insert(78);
    B.insert(39);
    A.show();
    B.show();
    cout<<"//----------//\n";
    
    
    A.insertRange(B);
    A.show();

    B.insertRange(A);
    B.show();   //INFINITE LOOP
    
}