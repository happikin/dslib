#include<iostream>
#include"genericDataStructures/ll.hpp"
/*template<class cType>
//class dbList;
uint dbList<cType>::index =0;

using namespace std;
template<class cType>
class dbList : public List<cType>
{
    private:    
        static uint index;
    public:
        dbList(){index++;}
};
//template<class cType>
int main()
{
    dbList<string>columnHeaders;
}*/

using namespace std;

int main()
{
    List<string>columnHeaders;
    int choice = 1;
    while(choice)
    {
        string temp;
        cout<<"ENTER THE COLUMN HEADERS : "<<endl;
        cin>>temp;
        columnHeaders.insert(temp);
        cout<<"press 1 for more and 0 to end";
        cin>>choice;
    }
}