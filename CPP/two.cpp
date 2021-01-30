#include<iostream>
#include "ll.hpp"
using namespace std;
int main()
{
    List one,two,three;
    std::cout<<one.getCount()<<std::endl;
    for(uint i =0;i<14;i++) //1
    {one.insert(i*2+i/2);}
    one.show();
    std::cout<<one.getCount()<<std::endl;
    for(uint i =0;i<8;i++)
    {two.insert(i*3);}
    one.show();
    std::cout<<one.getCount()<<std::endl;
    for(uint i =0;i<8;i++)
    {three.insert(i-1);}
    one.show();
    std::cout<<one.getCount()<<std::endl;
    try
    {
        two.insertRange(one); //2
        two.show();
        two.insertRangeAt(three,6);
        one.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"\n";
    std::cout<<one.getCount()<<std::endl;
    one.remove(3201);
    one.show();
    std::cout<<one.getCount()<<std::endl;
    one.getridOf(0);
    one.show();
    std::cout<<one.getCount()<<std::endl;
    one.getridOf(2);
    one.show();
    std::cout<<one.getCount()<<std::endl;
    one.show();
    //std::cout<<"\n"<<std::endl;
    one.removeAt(2);
    one.show();
    std::cout<<one.getCount()<<std::endl;
    //int len = one.getCount();
    
}