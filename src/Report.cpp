#include "Report.h"
#include<fstream>
#include<string>
#include<iostream>
#include<regex>
using namespace std;
Report::Report()
{
    //ctor
}

void Report:: H(){

 ifstream read1;
    read1.open("tickets.txt");
    remove("sortticket.txt");
    ofstream read2;
    read2.open("sortticket.txt",ios::app);
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

            if( strcmp(Priority,"H")==0  || strcmp(Priority,"h")==0)
            {
                cout<<ch1<<endl;
                read2<<ch1;
                read2<<"\n";
                flag1=1;
                break;
            }
            getline(read1,ch1);
            // if(read1.eof()){
              //  break;
            //}
        }
    }

    if(flag1==1){}
    else{
        cout<<"NO DATA IS AVAILABLE"<<endl;
    }
    read2.close();
    read1.close();
}

void Report::  M(){

 ifstream read1;
    read1.open("tickets.txt");
    ofstream read2;
    read2.open("sortticket.txt",ios::app);
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

            if( strcmp(Priority,"M")==0  || strcmp(Priority,"m")==0)
            {
                cout<<ch1<<endl;
                read2<<ch1;
                read2<<"\n";
                flag1=1;
                break;
            }
            getline(read1,ch1);
             if(read1.eof()){
                break;
            }
        }
    }

    if(flag1==1){}
    else{
        cout<<"NO DATA IS AVAILABLE"<<endl;
    }
    read1.close();
    read2.close();
}
void Report:: L(){

 ifstream read1;
    read1.open("tickets.txt");
    ofstream read2;
    read2.open("sortticket.txt",ios::app);
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

            if( strcmp(Priority,"L")==0  || strcmp(Priority,"l")==0)
            {
                cout<<ch1<<endl;
                read2<<ch1;
                read2<<"\n";
                flag1=1;
                break;
            }
            getline(read1,ch1);
            if(read1.eof()){
                break;
            }
        }
    }

    if(flag1==1){}
    else{
        cout<<"NO DATA IS AVAILABLE"<<endl;
    }
    read1.close();
    read2.close();
}

bool Report::PriorityCheck(){

   cout<<"ALL TICKETS : \n";
    H();
    M();
    L();
return 0;

}


void Report::Assigned(int empid){

    cout<<"ASSIGNED TICKETS : \n";
    ifstream read1;
    read1.open("sortticket.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {
            if(Eid==empid)
            {
                cout<<ch1<<endl;
                 flag1=1;
                break;

            }
           getline(read1,ch1);
           if(read1.eof()){
            break;
           }
        }
    }
    read1.close();
if( flag1==1){}
else{
    cout<<"NO ASSIGNED TICKET IS AVAILABLE"<<endl;
}

}



void Report::Closed()
{

    cout<<"NOT CLOSED TICKETS : \n";
    ifstream read1;
    read1.open("sortticket.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    /*int ProjectID;// number(4)
    int TicketID;// number(4) auto increment
    char Priority[1];// char(1) = (L)ow, (M)edium, (H)igh, (S)evere
    int Eid;//Created By number(4) = Employee ID of login Employee
    string Description;//Bug Description string(50)
    char date[80];//Create Date date (DD/MM/YYYY format) = today’s date (initially)
    int AEid;//Assigned To number(4) = Employee ID of login Employee (initally)
    char Cdate[80];//Closed on date (DD/MM/YYYY format)
    char Status[2];//Status char(1) = (O)pen, (A)ssigned, (F)ixed, (S)ubmitted, (Q)uality checked, (C)lose
    int ETime;//Estimated Fix Time int(2) = number of hours required to fix bug
    string Note;//Note string(540)
    string CodeSnip;//Code Snippet string(540)
    */
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

            if( strcmp(Status,"S")==0  || strcmp(Status,"s")==0)
            {
                cout<<ch1<<endl;
                flag1=1;
                break;// read1.close();
            }
            else if( strcmp(Status,"O")==0  || strcmp(Status,"o")==0)
            {
                cout<<ch1<<endl;
                 flag1=1;
                break;// read1.close();
            }
            else if( strcmp(Status,"A")==0  || strcmp(Status,"a")==0)
            {
                cout<<ch1<<endl;
                 flag1=1;
                break;// read1.close();
            }
            else if( strcmp(Status,"Q")==0  || strcmp(Status,"q")==0)
            {
                cout<<ch1<<endl;
                 flag1=1;
                break;// read1.close();
            }
            else if( strcmp(Status,"F")==0  || strcmp(Status,"f")==0)
            {
                cout<<ch1<<endl;
                 flag1=1;
                break;// read1.close();
            }
            getline(read1,ch1);
            // if(read1.eof()){
            //break;
           //}
        }
    }

    if(flag1==1){}
    else{
        cout<<"NO DATA IS AVAILABLE"<<endl;
    }
    read1.close();
}


void Report::Created(int empid)
{
    cout<<"CREATED TICKETS : \n";
    ifstream read1;
    read1.open("sortticket.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag=0;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

            if(Eid==empid)
            {

                flag=1;
                cout<<ch1<<endl;
                break;

            }

            getline(read1,ch1);
             if(read1.eof()){
            break;
           }
        }
    }
    read1.close();
    if( flag==1){}
    else{
        cout<<"YOU HAVEN'T CREATED ANY TICKET"<<endl;
    }
}



int Report::CheckPid(int pid)
{

    // int chkid;
    // cout<<"ENTER ID :"<<endl;
    //   cin>>chkid;
    //cout<<"CREATED TICKETS : \n";
    ifstream read1;
    read1.open("sortticket.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
//cout<<"File";
    bool flag=0;
    while(!read1.eof())
    {
        //  cout<<"File";

        getline(read1,ch1);

        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",&ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

        //getline(read1,ch1);
            if(ProjectID==pid)
            {
                read1.close();
                flag=1;
                //oo=oo+1;
                //cout<<ch1;
                cout<<"Sorry can't delete . Ticket is available for this id"<<endl;

                //cout<<ch1<<endl;
                break;

            }
             getline(read1,ch1);
             if(read1.eof()){
                break;
             }
        }
    }

  // cout<<flag;
    read1.close();

    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
   // return flag;
}






void Report::NotClosed()
{

    cout<<"CLOSED TICKETS : \n";
    ifstream read1;
    read1.open("sortticket.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    /*int ProjectID;// number(4)
    int TicketID;// number(4) auto increment
    char Priority[1];// char(1) = (L)ow, (M)edium, (H)igh, (S)evere
    int Eid;//Created By number(4) = Employee ID of login Employee
    string Description;//Bug Description string(50)
    char date[80];//Create Date date (DD/MM/YYYY format) = today’s date (initially)
    int AEid;//Assigned To number(4) = Employee ID of login Employee (initally)
    char Cdate[80];//Closed on date (DD/MM/YYYY format)
    char Status[2];//Status char(1) = (O)pen, (A)ssigned, (F)ixed, (S)ubmitted, (Q)uality checked, (C)lose
    int ETime;//Estimated Fix Time int(2) = number of hours required to fix bug
    string Note;//Note string(540)
    string CodeSnip;//Code Snippet string(540)
    */
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

            if( strcmp(Status,"C")==0  || strcmp(Status,"c")==0)
            {
                cout<<ch1<<endl;
                 flag1=1;
                break;// read1.close();
            }
            getline(read1,ch1);
             if(read1.eof()){
            break;
           }
        }
    }
    if(flag1==1){}
    else{
        cout<<"NO CLOSE TICKETS AVAILABLE"<<endl;
    }
    read1.close();
}




void Report::Listproject()
{

    cout<<"TICKETS REPORT: \n";
    ifstream read1;
    read1.open("sortticket.txt");
    if(read1.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    string ch1;
    bool flag1=0;
    while(!read1.eof())
    {
        getline(read1,ch1);
        while(sscanf(ch1.c_str(),"%d,%d,%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",
                     &ProjectID,&TicketID,Priority,&Eid,Description,date,&AEid,Cdate,Status,&ETime,Note,CodeSnip)==12)
        {

                cout<<ch1<<endl;
                break;// read1.close();
            getline(read1,ch1);
        }
    }
    read1.close();
}
