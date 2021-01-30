#include<iostream>
#include "ll.hpp"
using namespace std;
int main()
{
    List one,two,three;
    for(uint i =0;i<14;i++)
    {one.insert(i*2+i/2);}
    one.show();
    for(uint i =0;i<8;i++)
    {two.insert(i*3);}
    for(uint i =0;i<8;i++)
    {three.insert(i-1);}
    two.show();
    try
    {
        two.insertRange(one);
        two.show();
        two.insertRangeAt(three,6);
        two.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"\n";
    one.show();
    one.remove(3201);
    one.show();
    one.getridOf(0);
    one.getridOf(2);
    one.show();
}