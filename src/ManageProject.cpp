#include "ManageProject.h"
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<cstdio>
#include<regex>
#include "ModifyData.h"
#include "Login.h"
#include "Report.h"
using namespace std;
#define LEN 50
ManageProject::ManageProject()
{
    //ctor
}
/*class ManageProject1:ManageProject{
  public :
 int PId;//Project ID number(4) auto increment
int EId;//Created By number(4) = Employee ID of login Employee
string Description;//Project Description string(50)
char date[80];//Create Date date (DD/MM/YYYY format) = today’s date
int duration;//Project Duration int(2) = number of months
string Depat;//Department string(50)
string Group;//Group string(50)
ManageProject1(){
 PId=1000;
}
int c=1000;
int get_id();
void getdata(int empid);
void showdata();
 void Add(int empid);
 void Modify();
 void Delete();
 void option();
};

*/
int inputnum();
string inputstr();
int ManageProject::get_id()
{
    const string filename = "projects.txt";
    string l;
    ifstream fs(filename);
    if(fs.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }
    if(fs.is_open())
    {
        while(!fs.eof())
        {
            getline(fs,l);
            c++;
        }
        fs.close();
        //  cout<<"number of count"<<c<<endl;
    }
    else
    {
        cout<<"cant open\n";
    }


    ifstream list;
    string readFile, id2;
    if(list.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }
    list.open("projects.txt", ios::app);
    if (list.is_open())
    {
        while (getline(list, readFile))
        {
            int pos = readFile.find(',');
            id2 = readFile.substr(0, pos);
            if (to_string(c)== id2)
            {
                //cout<<c;
                c=c+1;
                // return c+1;
            }
        }
    }
    list.close();

    return c;
}
//Description include,argument list return type
void ManageProject:: getdata(int empid)
{
    //Login l;
    //cout<<"kk:"<<kk<<endl;
    cout<<"=====================Project id is created====================="<<endl;
    PId=get_id();
    cout<<PId<<endl;
    EId= empid;
    cout<<"=================Your Employee id is taken from login==========="<<endl;
    cout<<EId<<endl;;
    cout<<"====================Enter Description================="<<endl;
    //cin.ignore();
    Description=inputstr();
    cout<<"====================Current date is taken==============="<<endl;
    time_t tmNow = time(0);
    strftime(date, 80, "%d/%m/%Y", localtime(&tmNow));
    cout<<"====================Enter duration========================"<<endl;
    duration= inputnum();
    cout<<"===================Enter Department===================="<<endl;
    //cin.ignore();
    Depat=inputstr();
    cout<<"===================Enter Group======================"<<endl;
    Group=inputstr();
    ofstream outfile("projects.txt",ios::out|ios::app);
    cout<<"Project id is created"<<endl;
    outfile<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
    cout<<"\n"<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
    outfile.close();
}
void ManageProject:: showdata()
{
    string str;
    ifstream infile("projects.txt",ios::in);
    if(infile.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }
    cout<<"\n data from file"<<endl;
    // cout<<"\n"<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
    while(!infile.eof())
    {
        getline(infile,str);
        cout<<""<<str<<"\n";
    }

}

void ManageProject::Add(int empid)
{
    getdata(empid);
    showdata();
}
void ManageProject::Modify()
{
}

void delete_line(const string& idNr)
{
    ifstream list;
    ofstream outFile("temp.txt");
    string readFile, id1;
    if(list.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    if(outFile.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }
    list.open("projects.txt", ios::app);
    if (list.is_open())
    {
        while (getline(list, readFile))
        {
            int pos = readFile.find(',');
            id1 = readFile.substr(0, pos);
            if (idNr != id1)
            {
                outFile << readFile;
                outFile<<"\n";
            }
        }
    }
    list.close();
    outFile.close();
    remove("projects.txt");
    rename("temp.txt","projects.txt");
}

void ManageProject::Delete(int idx)
{
//Report r;
//int id,k;
  //  cout<<"ENTER PROJECT ID: \n";
    //cin>>id;
   // k=id;
//bool chkpid= r.CheckPid(k);
//cout <<chkpid<<"id\n";
//if(chkpid==1){
  //   cout<<"CAN NOT DELETE TICKED IS RAISED FOR THIS"<<endl;

//}
  // else{

    int PId1;//Project ID number(4) auto increment
    int EId1;//Created By number(4) = Employee ID of login Employee
    char Description1[50];//Project Description string(50)
    char date1[80];//Create Date date (DD/MM/YYYY format) = today’s date
    int duration1;//Project Duration int(2) = number of months
    char Depat1[50];//Department string(50)
    char Group1[50];
    //int id;
    //cout<<"ENTER PROJECT ID: \n";
    //cin>>id;
    ifstream read;
        string ch;
    read.open("projects.txt");

    if(read.fail())
    {
        cout<<"Status of the failbuilt \n Can't open file"<<endl;
    }

    bool flag=0;
   // cout<<id<<"check";
    while(!read.eof())
    {//cout<<id<<"check";
        getline(read,ch);
        while(sscanf(ch.c_str(),"%d,%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",&PId1,&EId1,Description1,date1,&duration1,Depat1,Group1)==7)
        {
           // getline(read,ch);
            if (PId1 == idx)
            {
                cout<<idx<<" : Id  is Deleted "<<endl;
                read.close();
                flag=1;
                delete_line(to_string(idx));

                break;
            }

            getline(read,ch);
        }
    }
    if(flag==1)
    {
        cout<<"Deleted"<<endl;
    }
    else
    {
        cout<<"ID does not exist can't delete !! "<<endl;
    }

 read.close();
//}

  //  read.close();
//return 0;
}
void ManageProject::option()
{
b:
    cout<<"  -------------------------- Login---------------------------"<<endl;
    Login l;
    int empid=l.Lid();
    ModifyData md;
//     md.CheckPId(empid);
    if(empid!=0)
    {

box:
        cout<<"  -------------------------- Projects Menu---------------------------"<<endl;
        cout<<"1. Add Project"<<endl;
        cout<<"2. Modify Project"<<endl;
        cout<<"3. Delete Project"<<endl;
        cout<<"0. Quit"<<endl;
        int ch;
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            Add(empid);
            goto box;
            break;
        case 2:
            Modify();
            md.CheckPId(empid);
            goto box;
            break;
        case 3:
           // Delete();
            goto box;
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Invalid choice"<<endl;
            goto box;
            break;
        }
    }
    else
    {
        cout<<"Please Try again "<<endl;
        goto b;
    }
}

int inputnum()
{
    string str;
    regex regex_int("0[1-9]|[0-2]");
    do
    {
        cout<<"ENTER DURATION IN THE FORM OF 01 TO 12 :  ";
        getline(cin,str);
        if(str=="" || str.length()<2 || str.length()>2)
        {
            cout<<"\n--------TRY AGAIN INVALID INPUT-------\n"<<endl;
        }
    }
    while(!regex_match(str,regex_int));
    return stoi(str);
}

int ManageProject:: inputnum1()
{
    string str;
    regex regex_int("[0-9]");
    do
    {
        cout<<"ENTER YOUR CHOICE \n";
        // cin.ignore();
        getline(cin,str);
        if(str=="" || str.length()>=6)
        {
            cout<<"\n--------TRY AGAIN INVALID INPUT-------\n"<<endl;
        }
    }
    while(!regex_match(str,regex_int));
    return stoi(str);
}

string inputstr()
{
    string str;
    regex regex_int("^.{1,50}$");
    do
    {
        cout<<"ENTER DATA  : \n ";
        getline(cin,str);
        if(str=="" || str.length()>=50)
        {
            cout<<"\n--------TRY AGAIN INVALID INPUT-------"<<endl;
        }
    }
    while(!regex_match(str,regex_int));
    return str;
}
/*
int main(){
  //  Login l;
  //int kk= l.Lid();
 // cout<<"kk:"<<kk<<endl;
    ManageProject p;

   p.option();
    return 0;
}
*/
