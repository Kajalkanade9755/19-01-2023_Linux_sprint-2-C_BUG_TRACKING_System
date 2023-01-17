#include "Login.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
using namespace std;
Login::Login()
{
}
int Login::Lid()
{
    int EmployeeID;// number(4)
    char password[10];//Employee Password string(10)
    char Name[50];//Employee Name string(50)
    char Dep[10];//Department string(10)
    long Mobile;//Mobile Number number(10)
    char email[30];//email string(30)
    char Skype[20];//Skype ID string(20)
    int loginid;
    //char pass[10];

    cout<<"############################################################"<<endl;
    cout<<"ENTER LOGIN ID\n";
    cin>>loginid;
    cout<<"ENTER PASSWORD: \n";

    char pin[100];
    int k=0;
    while(pin[k-1]!='\r') {
        pin[k]=getch();
        if(pin[k-1]!='\r') {
            cout<<"*";
        }
        k++;
    }
    pin[k-1]='\0';

    //cin>>pass;

    cout<<"\n############################################################"<<endl;

    ifstream read;
    read.open("Employees.txt");
    if(read.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }
    string ch;
    bool flag=0;
    while(!read.eof())
    {
        getline(read,ch);
        while(sscanf(ch.c_str(),"%d,%100[^,],%100[^,],%100[^,],%ld,%100[^,],%100[^,],%*[\n]",
                     &EmployeeID,password,Name,Dep,&Mobile,email,Skype)==7)

        {
            getline(read,ch);
            if (EmployeeID == loginid && (strcmp(password,pin)==0))
            {
                //cout<<loginid<<"Id "<<endl;
                // return loginid;
                flag=1;
                read.close();
                //delete_line(to_string(id));
                break;
            }

        }
    }
    read.close();

    if(flag==1)
    {

        cout<<"PLEASE WAIT IN THE PROCESS \n";
    for(int i=0;i<3;i++){
        Sleep(1000);
        cout<<".........."<<endl;
    }
        return loginid;
    }
    else
    {

        cout<<"Invalid Employee ID or password"<<endl;
        return 0;

    }
//return loginid;
}
