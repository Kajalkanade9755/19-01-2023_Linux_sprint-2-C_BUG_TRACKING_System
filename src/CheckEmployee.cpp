#include "CheckEmployee.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
CheckEmployee::CheckEmployee()
{
    //ctor
}
int CheckEmployee::chkEmply()
{
  /* int EmployeeID;// number(4)
    char password[10];//Employee Password string(10)
    char Name[50];//Employee Name string(50)
    char Dep[10];//Department string(10)
    long Mobile;//Mobile Number number(10)
    char email[30];//email string(30)
    char Skype[20];//Skype ID string(20)

*/
int loginid;
   Call:
        cout<<"ENTER ID WHOM TO ASSIGN \n";
    cin>>loginid;

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

            if (EmployeeID == loginid)
            {
                flag=1;
                read.close();
                break;
            }
getline(read,ch);
        }
    }
    read.close();

    if(flag==1)
    {
        return loginid;
    }
    else
    {

        cout<<"Invalid Employee ID or password"<<endl;
        goto Call;
       // return 0;

    }
//return 0;
}
