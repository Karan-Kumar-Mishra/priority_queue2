#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef class priority_queue
{
    int fornt;
    int rear;
    int capacity;
    int *arr;
public:
    int isfull()
    {
        if(fornt==0 && rear ==capacity-1)
            return 1;
        else
            return 0;
    }
    int isempty()
    {
        if(fornt==0 && rear==-1)
            return 1;
        else
            return 0;
    }
    int max()
    {
        int max=arr[0];
        for(int i=1; i<capacity; i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        for(int i=0; i<capacity; i++)
        {
            if(max==arr[i])
            {
                return i;
            }
        }
    }
    void creat(int key)
    {
        fornt=0;
        rear=-1;
        capacity=key;
        arr= new int[capacity];
    }
    void insert(int data)
    {
        if(isfull())
        {
            cout<<"database is full ?"<<endl;
            getch();
            return ;
        }
        rear++;
        arr[rear]=data;
    }
    void remove()
    {
        if(isempty())
        {
            cout<<"database is empty ?"<<endl;
            getch();
            return ;
        }
        for(int i=max(); i<capacity; i++)
        {
            arr[i]=arr[i+1];
        }
        rear--;
    }
    void display()
    {
        for(int i=fornt; i<=rear; i++)
        {
            cout<<"  "<<arr[i];
        }
        getch();
    }
} queue;
int main()
{
    queue q1;
    int cmd,c,data;
    while(1)
    {
        clrscr();
        cout<<"+--------------------------------+"<<endl;
        cout<<"|  +--------------------------+  |"<<endl;
        cout<<"|  [    ~priority_queue~      ]  |"<<endl;
        cout<<"|  +--------------------------+  |"<<endl;
        cout<<"+--------------------------------+"<<endl;
        cout<<"1.creat the queue"<<endl;
        cout<<"2.insert the data"<<endl;
        cout<<"3.remove the data"<<endl;
        cout<<"4.display"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"enter the command =>>"<<endl;
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            cout<<"enter the capacity=>"<<endl;
            cin>>c;
            q1.creat(c);
            break;
        case 2:
            cout<<"enter the data=>"<<endl;
            cin>>data;
            q1.insert(data);
            break;
        case 3:
            q1.remove();
            break;
        case 4:
            q1.display();
            break;
        case 5:
            return 0;
            break;
        default:
            cout<<"command is not found ?"<<endl;
            break;

        }
        getch();
    }
    return 0;
}