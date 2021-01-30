#include<iostream>
#include "ll.hpp"

using namespace std;

int main()
{
    List one,two;
    uint v;
    for(int i = 0;i<10;i++)
    {
        //cin>>v;
        one.insert(i*2);
    }
    for(int i = 0;i<10;i++)
    {
        //cin>>v;
        two.insert(i*3);
    }
    cout<<one.getCount()<<endl;
    cout<<two.getCount()<<endl;
    one.insertAt(121,2);
    one.show();
    cout<<one.getCount()<<endl;
    one.insertRange(two);
    one.show();
    cout<<one.getCount()<<endl;
    one.insertRangeAt(two,2);
    one.show();
    cout<<one.getCount()<<endl;
}