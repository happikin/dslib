#define BEG beg
#define END end

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
        void insert(int a,int index = 0)
        {
            node *temp;
            temp = new node;
            temp->data = a;
            temp->next = start;
            start = temp;
            count++;
        }
        void insertRange(List l,int index = 0)   //will insert one list into another list
        {
            if (index = 0)
            {
                l.end()->next=this->start;
                start = l.start;
                this->count = l.count + this->count;
            }
            else
            {
                end()->next=l.start;
                this->count = l.count + this->count;
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
        }
        ~List(){}
        int getCount(){return count;}
        node * end()
        {
            node *loc=start;
            while(loc->next!=NULL){loc=loc->next;}
            return loc;
        }

};