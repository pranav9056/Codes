#include <iostream>
#include<fstream>
using namespace std;
struct node
{
    int value;
    int counts;
    struct node * child,* sibling;
};
void display(struct node * temp);
int main()
{
    ifstream myfile("data.txt",ios::in);
    string line;
    int counter=0,no_of_q,flag=0,flag2=0;
    while ( getline (myfile,line) )
    {
      counter++;
    }
    myfile.close();

    ifstream myfil("data.txt",ios::in);
    struct node* head = new struct node;
    head->child=NULL;
    head->sibling=NULL;
    no_of_q=int(line.length());
    struct node* temp,*next,*found;
    for(int i=0;i<counter;i++)
    {
        getline (myfil,line);

        for(int j=0;j<no_of_q;j++)
        {
            if(flag==0)
            {

                if(int(line[j])==49)
                {
                   temp=new  struct node;
                   temp->value=j+1;
                   temp->counts=1;
                   temp->child=NULL;
                   temp->sibling=NULL;
                   next=head;
                   while(next->child!=NULL)
                   {
                       next=next->child;
                   }
                      //cout<<temp->value<<':'<<temp->counts<<" "<<j<<'\t';
                   next->child=temp;
                }
                if(j==(no_of_q - 1))
                {
                    flag=1;
                }
            }
            else
            {
                if(int(line[j])==49)
                {
                    if(flag2==0)
                    {
                        next=head->child;
                        while((j+1)!=next->value && next->sibling!=NULL)
                        {
                            next=next->sibling;
                        }
                        if((j+1)==next->value)
                        {
                            next->counts++;
                            found=next;
                        }
                        else
                        {
                            temp=new struct node;
                            temp->value=j+1;
                            temp->counts=1;
                            temp->child=NULL;
                            temp->sibling=NULL;
                            next->sibling=temp;
                            found=temp;
                        }
                        flag2 = 1;
                    }
                    else
                    {
                        if(found->child==NULL)
                        {
                            temp=new struct node;
                            temp->value=j+1;
                            temp->counts=1;
                            temp->child=NULL;
                            temp->sibling=NULL;
                            next->child=temp;
                            found=temp;
                        }
                        else
                        {
                            next=found->child;
                            while((j+1)!=next->value && next->sibling!=NULL)
                            {
                                next=next->sibling;
                            }
                            if((j+1)==next->value)
                            {
                                next->counts++;
                                found=next;
                            }
                            else
                            {
                                temp=new struct node;
                                temp->value=j+1;
                                temp->counts=1;
                                temp->child=NULL;
                                temp->sibling=NULL;
                                next->sibling=temp;
                                found=temp;
                            }
                        }

                    }
                }
                if(j==(no_of_q - 1))
                {
                    flag2=0;
                }
            }
        }
    }
  //  cout<<line[0]<<line[1];

    myfil.close();
    cout<<"genrated pc tree\n\n\n";
    temp=head->child;
     while(temp!=NULL)
    {
        display(temp);
        cout<<endl<<endl<<endl;
        temp=temp->sibling;
    }
    return 0;
}
void display(struct node* temp)
{
       int flag=0;
       struct node* temp2=temp;
       while(temp2!=NULL)
       {
           while(temp!=NULL)
           {
                cout<<temp->value<<':'<<temp->counts<<"\t\t";
                temp=temp->sibling;
                if(flag==0)
                {
                    flag=1;
                    break;
                }
           }
           cout<<endl;
           temp=temp2->child;
           temp2=temp;
       }




}
