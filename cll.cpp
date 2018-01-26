#include<iostream>
using namespace std;
class node//creating class called node.
    {
        public:
        int data;
        node *next;
        node()//constructor for class node.
            {
                data=0;
                next=NULL;
            }
    };
class cll
    {
    private:
        node *head;
        node *tail;
        int n;
    public:
        cll()//constructor for cll nlass.
            {
                head=NULL;
                tail=NULL;
                n=0;
            }
//declaring functions for class cll.
        void insertx(int number);
        void insertat(int pos,int number);
        void deletex();
        void deleteat(int pos);
        void countitems();
        void display();
    };
void cll::insertx(int number)//defining insertx function.
{
    node *temp=new node;
    if(head==NULL)
        {
            tail=temp;
            head=temp;
            temp->data=number;
            tail->next=head;
            n++;
        }
    else
        {
            tail->next=temp;
            temp->next=head;
            temp->data=number;
            tail=temp;
            n++;
        }
}
void cll::insertat(int pos,int number)//defining insertat function.
{
    node *temp=new node;
    if(pos==1)
        {
            temp->next=head;//temp's next is head.
            tail->next=temp;//tail's next is temp.
            temp->data=number;//Number is stored as temp' data.
            head=temp;//temp is the new head.
            n++;
        }
    else if(pos==2)
        {
            temp->next=head->next;//temp's next is head's next.
            head->next=temp;//head now points to temp.
            temp->data=number;//number is stored as temp's data.
            n++;
        }
    else if(pos==n+1)
        {
            insertx(number);//insertion as in case of the first function.
        }
    else if((pos>1) && (pos<n+1))
        {
            node *slider1=head;//creating a slider node to get at the desired location.
            for(int i=1;i<pos-1;i++)//starting the loop to go to the position just behind the desired location.
                {
                    slider1=slider1->next;
                }
            temp->next=slider1->next;//temp'next points to slider's next.
            slider1->next=temp;//slider's next points to temp.
            temp->data=number;//number is stored as temp's data.
            n++;
        }
    else
        cout<<"LINKED LIST DOES NOT HAVE THAT MANY ELEMENTS"<<endl;
}
void cll::deletex()//defining deletex function.
    {
        if(head==NULL)
            {
                cout<<"List does not have that many elements"<<endl;
            }
        else if(head->next==NULL)
            {
                head=NULL;
                tail=NULL;
                n--;
            }
        else
            {
                node *slider2=head;//creating a slider to go to the desired location.
                for(int j=1;j<=n-2;j++)//running the loop to go to the desired location.
                    {
                        slider2=slider2->next;//starting a loop to get to the node just behind the tail.
                    }
                slider2->next=head;//tail's previous node points to head.
                tail->next=NULL;//the initial tail points to null.
                tail=slider2;//the node just before the tail is the new tail.
                n--;
            }
    }
void cll::deleteat(int pos)//defining deleteat function.
    {
        //for different values of pos,different conditions.
        if(pos==1)
            {
                tail->next=head->next;//tail now points to the second node.
                head->next=NULL;//head now points to NULL.
                delete head;//The initial head is deleted.
                head=tail->next;//the temp is the new head.
                n--;
            }
        else if(pos==n)
            {
                deletex();//simple deletion.
            }
        else if((pos>1) && (pos<n))
            {
                node *slider3=head;//creating slider.
                for(int k=1;k<=n-1;k++)
                    {
                        slider3=slider3->next;
                    }
                slider3->next=(slider3->next)->next;
                n--;
            }
        else
            cout<<"Invalid position"<<endl;
    }
void cll::countitems()
    {
        node *slider5=head;
        int count1=1;
        if(head==0)//no nodes are present initially.
            count1=0;
        while(slider5->next!=head)//starting the while loop
        {
            count1++;
            slider5=slider5->next;
        }
        cout<<"CLL HAS "<<count1<<" ELEMENTS"<<endl;
    }
void cll::display()
    {
        node *slider6=head;
        for(int k=1;k<n;k++)
        {
                cout<<slider6->data;
                cout<<"->";
                slider6=slider6->next;//moving the slider.
        }
        cout<<tail->data<<endl;;
    }
int main()
{
    cll list1;
    list1.insertx(45);
    list1.insertx(54);
    list1.insertx(786);
    list1.insertx(532);
    list1.insertx(987);
    list1.insertx(78);
    list1.insertx(877);
    list1.display();
    //making it a bit more user oriented.
    char ch='y';
    int cho;
    int pos1,num1;
    while(ch!='n')
        {
            cout<<"1-Insert,2-Inserat,3-Delete,4-Deleteat,5-Countitems,6-Display"<<endl;
            cout<<"Enter your choice"<<endl;
            cin>>cho;
            switch(cho)//starting the switch case.
                {
                    case 1:
                        cout<<"Enter the num"<<endl;
                        cin>>num1;
                        list1.insertx(num1);
                        list1.display();
                    break;
                    case 2:
                        cout<<"Enter pos and num respectively"<<endl;
                        cin>>pos1>>num1;
                        list1.insertat(pos1,num1);
                        list1.display();
                    break;
                    case 3:
                        list1.deletex();
                        list1.display();
                    break;
                    case 4:
                        cout<<"Enter pos"<<endl;
                        cin>>pos1;
                        list1.deleteat(pos1);
                        list1.display();
                    break;
                    case 5:
                        list1.countitems();
                    break;
                    case 6:
                        list1.display();
                    break;
                    default:
                        cout<<"Invalid choice"<<endl;
                }
                cout<<"Do you want to continue,if no,press n,if yes,press any char"<<endl;
                cin>>ch;
            }
            if(ch=='n')
            cout<<"The job is done"<<endl;
    return 0;
}

