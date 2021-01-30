#include<iostream>
#define BEG 0
#define END 1
typedef unsigned int uint;
struct node
{
    int data;
    node * next;
};

class List
{
    node * start;
    uint count;
    public:
        List(){start=NULL; count=0;}
        node * gotoEnd()
        {
            node * loc=start;
            while(loc->next!=NULL){loc=loc->next;}
            return loc;
        }
        node * goTo(uint index)
        {
            index-=2;
            node* loc=start;
            uint i = 0;
            while(i < index)
            {loc=loc->next;i++;}
            return loc;
        }
        node * end()
        {
            node *loc=start;
            while(loc->next!=NULL){loc=loc->next;}
            return loc;
        }
        uint getCount(){return count;}
        void insert(int a,uint index = 0)
        {
            node *temp,*loc;
            temp = new node;
            temp->data = a;
                        
            switch(index)
            {
                case 0: temp->next = start;
                        start = temp;
                        break;
                case 1: loc = gotoEnd();
                        loc->next=temp;
                        temp->next=NULL;
                        break;
                default:
                        std::cout<<"INVALID POSITION VALUE "<<std::endl;
            }
            count++;
        }
        void insertAt(int value,uint index)
        {
            if(index>count+1 || index<0)
            {std::cout<<"EXEPTION : IndexOutOfRange \n";}
            else
            {
                node *temp,* loc = goTo(index);
                temp = new node;
                temp->data = value;
                temp->next = loc->next;
                loc->next = temp;
                count++;
            }
        }
        void insertRange(List &l,uint index = 0)   //will insert one list into another list
        {
            if (index == 0)
            {
                node *ptr=l.end();
                ptr->next=start;
                start = l.start;
                count = l.count + count;
            }
            else if (index == 1)
            {
                end()->next=l.start;
                count = l.count + count;
            }
            else
            {
                std::cout<<"INVALID POSITION CODE"<<std::endl;
            }
            
        } 
        void insertRangeAt(List &l,uint index)
        {
            if(index>count+1 || index<0)
            {std::cout<<"EXEPTION : IndexOutOfRange \n";}
            else
            {
                node*lptr,*sptr;
                lptr=l.gotoEnd();
                sptr = this->goTo(index);
                lptr->next = sptr->next;
                sptr->next=l.start;
                count += l.count;
            }
        }
        node* findItem(int item)   //wil return pointer to the node preceding the target node
        {
            node * loc = start;
            while(loc->next->data!=item)
            {
                loc=loc->next;
                if(loc->next==NULL)
                {
                    return NULL;
                    break;
                }
            }
            return loc;
        }
        void remove(int item)
        {
            if(start->data==item && start!=NULL)
            {
                node *ptr = start;
                start=start->next;
                delete ptr;
                count--;
            }
            else
            {
                node * ptr,* loc = findItem(item);
                if(loc!=NULL)
                {
                    ptr=loc->next;
                    loc->next=ptr->next;
                    delete ptr;
                    count--;
                }
            }
        }
        void getridOf(int item)
        {
            static node *sloc = start;
            if(sloc!=NULL)
            {
                if(start->data==item)
                {
                    node *ptr = start;
                    start=start->next;
                    sloc=start;
                    delete ptr;
                    count--;
                    getridOf(item);
                }
                else
                {
                    node * ptr,*loc = findItem(item);
                    if(loc!=NULL)
                    {
                        ptr=loc->next;
                        loc->next=ptr->next;
                        sloc=loc;
                        delete ptr;
                        count--;
                        getridOf(item);
                    }
                    else
                    {return;}   
                }
            }
            else
            {return;}
        }
        void removeAt(uint index)
        {
            if(index>count+1 || index<0)
            {std::cout<<"EXEPTION : IndexOutOfRange \n";}
            else
            {
                node *ptr,* loc = goTo(index);
                ptr=loc->next;
                loc->next=ptr->next;
                delete ptr;
                count--;
            }
        }
        void show()
        {
            node *loc;
            loc=start;
            std::cout<<"List Data :: ";
            while (loc!=NULL)
            {
                std::cout<<"["<<loc->data<<"]";
                loc=loc->next;
            }
            std::cout<<"\n";
        }
        ~List(){}
};