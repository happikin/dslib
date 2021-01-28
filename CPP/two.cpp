#include<iostream>
#include "ll.hpp"
using namespace std;
int main()
{
    List one,two;
    for(uint i =0;i<14;i++)
    {one.insert(i*2+i/2);}
    one.show();
    for(uint i =0;i<8;i++)
    {two.insert(i*3);}
    two.show();
    try
    {
        two.insertRange(one);
        two.show();
        two.insertRangeAt(two,2);
        two.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}