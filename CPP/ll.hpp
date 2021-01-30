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
        node * goTo(int index)
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
        void insert(int a,int index = 0)
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
        void insertAt(int value,int index)
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
        void insertRange(List l,int index = 0)   //will insert one list into another list
        {
            if (index == 0)
            {
                l.end()->next=this->start;
                start = l.start;
                this->count = l.count + this->count;
            }
            else if (index == 1)
            {
                end()->next=l.start;
                this->count = l.count + this->count;
            }
            else
            {
                std::cout<<"INVALID POSITION CODE"<<std::endl;
            }
            
        } 
        void insertRangeAt(List l,int index)
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
        node* findItem(uint item)   //wil return pointer to the node preceding the target node
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
        void remove(uint item)
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
        void getridOf(uint item)
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
                        getridOf(item);
                    }
                    else
                    {return;}   
                }
            }
            else
            {
                return;
            }
            
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
            std::cout<<"\n";
        }
        ~List(){}
};