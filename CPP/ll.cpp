#include<iostream>

struct node
{
    int data;
    node * next;
};

class List
{
    node * start;
    unsigned int count;
    public:
        List(){start=NULL; count=0;}
        void insert(int a)
        {
            node *temp;
            temp = new node;
            temp->data = a;
            temp->next = start;
            start = temp;
            count++;
        }
        node * end()
        {
            node *loc=start;
            while(loc->next!=NULL){loc=loc->next;}
            return loc;
        }
        int getCount(){return count;}
        void insertRange(List l)   //will add an array of data at once
        {
            l.end()->next=this->start;
            start = l.start;
            this->count = l.count + this->count;
        } 
        void show()
        {
            node *loc;
            loc=start;
            while (loc!=NULL)
            {
                std::cout<<"["<<loc->data<<"]";
                loc=loc->next;
            }
        }
        ~List(){}
};

int main(int argc, char const *argv[])
{
    List one,two;
    //one.insert(1);
    //one.insert(2);
    for(int i =0; i<1000;i++)
    {one.insert(i);}
    for(int i =0; i<10;i++)
    {two.insert(i*11);}
    one.insertRange(two);

    one.show();

    std::cout<<"/n"<<one.getCount();
}