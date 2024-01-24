#include<iostream>
using namespace std;
class mycontacts
{
private:
    char name[50],mobile[50],email[50],insta[50],twitter[50];
public:
    void accept()
    {   //cout<<endl<<"Enter Name";
       //cin>>name;
        cout<<endl<<"Enter Email ID";
        cin>>email;
        cout<<endl<<"Enter Mobile";
        cin>>mobile;
        cout<<endl<<"Enter Instagram ID";
        cin>>insta;
        cout<<endl<<"Enter Twitter ID";
        cin>>twitter;
    }
    void display()
     {  cout<<endl;
        cout<<left;
        cout<<setw(25);
        cout<<name<<"|";
        cout<<setw(30);
        cout<<email<<"|";
        cout<<setw(24);
        cout<<mobile<<"|";
        cout<<setw(20);
        cout<<insta<<"|";
        cout<<setw(20);
        cout<<twitter;
    }
    friend void remove_contacts();
    friend void update_contacts();
    friend void search_name();
    friend void search_mobile();
    friend void search_email();
    friend void add_contacts();
};
void remove_contacts();
void update_contacts();
void search_name();
void search_mobile();
void search_email();
void add_contacts();
