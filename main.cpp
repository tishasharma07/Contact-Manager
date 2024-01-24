#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
#include "mycontacts.cpp"
mycontacts obj;//global object create
void search_email()
{
    char e[50];
    bool flag=false;
    cout<<endl<<"Enter email::";
    cin>>e;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.email,e)==0)
            {
                cout<<endl<<"Record exists by this email";
                cout<<endl<<"Name::"<<obj.name;
               cout<<"\t"<<"Mobile no::"<<obj.mobile;
               cout<<"\t"<<"Email::"<<obj.email;
               cout<<"\t"<<"Insta::"<<obj.insta;
               cout<<"\t"<<"Twitter::"<<obj.twitter;

               flag=true;
            }}
         if(flag==false)
           {
           cout<<endl<<"Record does n't exists";}
    rd.close();
    wr.close();
 }
void search_mobile()
{
    char m[50];
    bool flag=false;
    cout<<endl<<"Enter mobile no. ::";
    cin>>m;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.mobile,m)==0)
            {
                cout<<endl<<"Record exists by this mobile no";
                cout<<endl<<"Name::"<<obj.name;
               cout<<"\t"<<"Mobile no::"<<obj.mobile;
               cout<<"\t"<<"Email::"<<obj.email;
               cout<<"\t"<<"Insta::"<<obj.insta;
               cout<<"\t"<<"Twitter::"<<obj.twitter;
               flag=true;
            }}
         if(flag==false)
            cout<<endl<<"Record does n't exists";
    rd.close();
    wr.close();
}
void search_name()
{
    char n[50];
    bool flag=false;
    cout<<endl<<"Enter full name ::";
    cin>>n;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.name,n)==0)
            {
                cout<<endl<<"Record exists by this name";
                cout<<endl<<"Name::"<<obj.name;
               cout<<"\t"<<"Mobile no::"<<obj.mobile;
               cout<<"\t"<<"Email::"<<obj.email;
               cout<<"\t"<<"Insta::"<<obj.insta;
               cout<<"\t"<<"Twitter::"<<obj.twitter;
               flag=true;
            }}
         if(flag==false)
        {
           cout<<endl<<"Record does n't exists";
        }
    rd.close();
    wr.close();
}
void remove_contacts()
{
     char n[50];
     bool flag=false;
    cout<<endl<<"Enter Name->";
    cin>>n;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(stricmp(obj.name,n)==0)
        {
            cout<<endl<<"record removed";
        }
        else
        {
         wr.write((char*)&obj,sizeof(obj));
        }
        flag=true;
    }
    if(flag=false)
    {
        cout<<endl<<"Record not found";
    }
    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt","mydatafile.txt");
}
void read_contacts()
{
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
        rd.seekg(0,ios::beg);
        cout<<"--------------------------------------------------------------------------------------------------------------------------";
        cout<<endl;
        cout<<left;
        cout<<setw(25);
        cout<<"Name"<<"|";
        cout<<setw(30);
        cout<<"Email Address"<<"|";
        cout<<setw(24);
        cout<<"Mobile Number"<<"|";
        cout<<setw(20);
        cout<<"Instagram"<<"|";
        cout<<setw(20);
        cout<<"Twitter";
        cout<<endl<<"--------------------------------------------------------------------------------------------------------------------";


    for(int i=1;i<=s;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        obj.display();
    }
       cout<<endl<<"---------------------------------------------------------------------------------------------------------------------";
      rd.close();
    }
void add_contacts()
{//char namec[50];
char n[50];
bool flag=false;
cout<<endl<<"enter name->";
cin>>n;
//strcpy(name,namec);
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
        {
        rd.read((char *)&obj,sizeof(obj));

        if(stricmp(obj.name,n)==0)
        {
            cout<<endl<<"duplicate element/names are not allowed";
            cout<<endl<<"enter valid name";
            flag=true;
        }
        }


if(flag==false)
{//cout<<endl<<"contact available";
strcpy(obj.name,n);
  obj.accept();
    fstream wr;
    wr.open("mydatafile.txt",ios::app);
    wr.write((char *)&obj,sizeof(obj));
    wr.close();
    cout<<endl<<"File Written";
   rd.close();
  }
}


void update_contacts()
{    char n[50];
bool flag=false;
    cout<<endl<<"Enter Name->";
    cin>>n;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(stricmp(obj.name,n)==0)
        {
            cout<<endl<<"record matched";
            cout<<endl<<"enter details you want to update";
            strcpy(obj.name,n);
            obj.accept();
            flag=true;
        }
            wr.write((char*)&obj,sizeof(obj));
    }

    rd.close();
    wr.close();
    if(flag==false)
    {
          cout<<endl<<"record not found";
    }
    remove("mydatafile.txt");
    rename("tempfile.txt","mydatafile.txt");
}
int main()

{int ch;

do{cout<<endl<<"*****MENU*****";
    cout<<endl<<"press 1 to add contacts";
    cout<<endl<<"press 2 to read contacts";
    cout<<endl<<"press 3 to update contacts";
    cout<<endl<<"press 4 to delete contacts";
    cout<<endl<<"press 5 to search by name";
    cout<<endl<<"press 6 to search by mobile";
    cout<<endl<<"press 7 to search by email";
    cout<<endl<<"press 8 to exit";

    cout<<endl<<"enter your choice b/w (1-8):";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                add_contacts();
                break;
            }
          case 2:
            {
                read_contacts();
                  break;
            }
           case 3:
            {
                update_contacts();
                  break;
            }
           case 4:
            {
                remove_contacts();
                  break;
            }
           case 5:
            {search_name();
              break;

            }
           case 6:
            {search_mobile();
              break;

            }
           case 7:
            {search_email();
              break;
            }
            case 8:
            { cout<<endl<<"-------------------------------------END OF PROGRAM-------------------------------------------------";
             exit(0);
                  break;

            }
            default:
               cout<<endl<<"invalid character";
            }
    }while(ch!=8);

}
