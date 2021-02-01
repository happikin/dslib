#include<iostream>
#include"ll.hpp"

int main(int argc, char const *argv[])
{
    List one,two,three;

    for(int i =0; i<5;i++)
    {one.insert(i*2);}
    for(int i =0; i<10;i++)
    {two.insert(i*11);}
    
    one.insert(87876,END);
    two.insertAt(1301,11);
    one.show();
    two.show();
    //two.insertRange(one,BEG);
    two.insertRangeAt(one,3);
    two.show();
    std::cout<<"\n";
    std::cout<<"\n"<<two.getCount();
}