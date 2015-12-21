#include <iostream>
#include<string>
using namespace std;
class encoder
{
    char * pt, * key, * ct;
    int np,nk,nc;
    public:
    encoder()
    {
        nk=3;
        key =new char[nk+1];
        strcpy(key,"abc");
        pt='\0';
        ct='\0';
    }
    void go();
    void getpt();
    void getct();
    void encode();
    void setkey();
    void decode();
    ~encoder()
    {
        delete[]pt;
        delete[]ct;
        delete[]key;
    }
};
void encoder::getct()
{
    cout<<"enter size of string(cipher text)\n";
    cin>>nc;
    ct = new char[nc+1];
    cout<<"enter the string to encode\n";
    cin>>ct;

}

void encoder::setkey()
{
    cout<<"enter size of string(key)\n";
    cin>>nk;
    key = new char[nk+1];
    cout<<"enter the key\n";
    cin>>key;

}
void encoder::getpt()
{
    cout<<"enter size of string(plain text)\n";
    cin>>np;
    pt = new char[np+1];
    cout<<"enter the string to encode\n";
    cin>>pt;

}
void encoder::decode()
{
    int i=0,j=0,q=0;
    if(ct=='\0')
    {
        cout<<"no cipher to decode\n";
        return;
    }
    pt=new char[np+1];
    while(ct[i]!='\0')
    {

        if(key[j]=='\0')
        {
            j=0;

        }

        pt[i]=key[j];
        j++;
        i++;
    }
    pt[i]='\0';
    i=0;
    while(pt[i]!='\0')
    {
        q=((int(ct[i])-97)-(int(pt[i])-97))%26;
        q=q+97;
        pt[i]=char(q);
        i++;
    }
    cout<<"encoded text  :"<<ct<<endl;
    cout<<"plain text    :"<<pt<<endl;

}

void encoder::encode()
{
    int i=0,j=0,q=0;
    if(pt=='\0')
    {
        cout<<"enter plain text first\n";
        return;
    }
    ct=new char[np+1];
    while(pt[i]!='\0')
    {

        if(key[j]=='\0')
        {
            j=0;

        }

        ct[i]=key[j];
        j++;
        i++;
    }
    ct[i]='\0';
    i=0;
    while(ct[i]!='\0')
    {
        q=((int(ct[i])-97)+(int(pt[i])-97))%26;
        q=q+97;
        ct[i]=char(q);
        i++;
    }
    cout<<"plain text    :"<<pt<<endl;
    cout<<"encoded text  :"<<ct<<endl;

}
int main()
{

    encoder a;
    int q;
    for(;;)
    {
        cout<<"1)encode\t 2)enter plain text\t 3)change key\n4)enter cipher text\t 5)decode\t 6)exit\n";
        cout<<"enter choice\n";
        cin>>q;
        if(q==1)
        {
            a.encode();
        }
        else if(q==2)
        {
            a.getpt();
        }
        else if(q==3)
        {
            a.setkey();
        }

        else if(q==4)
        {
            a.getct();
        }

        else if(q==5)
        {
            a.decode();
        }
        else if(q==6)
        {
            break;
        }
        else
        {
            cout<<"enter correct choice\n";
        }
    }
}



















