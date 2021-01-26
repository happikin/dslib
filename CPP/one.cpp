#include<iostream>
#include"ll.hpp"

int main(int argc, char const *argv[])
{
    List one,two;
    //one.insert(1);
    //one.insert(2);
    for(int i =0; i<1000;i++)
    {one.insert(i);}
    for(int i =0; i<10;i++)
    {two.insert(i*11);}
    //one.insertRange(two,BEG);
    one.insertRange(two);
    one.show();

    std::cout<<"/n"<<one.getCount();
}