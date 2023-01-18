#include "CheckPID.h"
using namespace std;
#include<string>
#include<iostream>
#include<fstream>
CheckPID::CheckPID()
{
    //ctor
}
int CheckPID::CheckPId()
{
    int PId;//Project ID number(4) auto increment
    int EId;//Created By number(4) = Employee ID of login Employee
    char Description[50];//Project Description string(50)
    char date[80];//Create Date date (DD/MM/YYYY format) = today’s date
    int duration;//Project Duration int(2) = number of months
    char Depat[50];//Department string(50)
    char Group[50];
  L:
  int id;
    cout<<"ENTER PROJECT ID : \n";
    cin>>id;
    ifstream read;
    read.open("projects.txt");
    if(read.fail())
    {
       cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch;
    bool flag=0;
    while(!read.eof())
    {
        getline(read,ch);
        while(sscanf(ch.c_str(), "%d,%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",&PId,&EId,Description,date,&duration,Depat,Group)==7)
        {
            getline(read,ch);
            if (PId == id)
            {
                cout<<id<<"Id "<<endl;
                flag=1;
                read.close();
                break;
            }

        }
    }
    read.close();

    if(flag==1)
    {
return id;
        // cout<<"Updated"<<endl;
    }
    else
    {
        cout<<"SORRY  PROJECT ID DOES NOT EXISTS !!"<<endl;
        goto L;
       // fun();
    }
//return 0;
}

int CheckPID:: Ticketid(){

 B:
      ifstream read1;
    read1.open("tickets.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag=0;

        int tid;
    cout<<"Enter ticket id "<<endl;
    cin>>tid;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {
           // getline(read1,ch1);

            if(TicketID==tid)
            {

                flag=1;
                cout<<ch1<<endl;
                break;

            }

            getline(read1,ch1);

        }
    }
    read1.close();
    if( flag==1){
        return tid;
    }
    else{
        cout<<"NO TICKET AVAILABLE"<<endl;
        goto B;
    }

}
