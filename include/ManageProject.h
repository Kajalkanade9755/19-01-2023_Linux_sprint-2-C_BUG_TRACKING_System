#ifndef MANAGEPROJECT_H
#define MANAGEPROJECT_H
#include<string>
#include<cstdio>
using namespace std;
class ManageProject
{
public:
    ManageProject();
    int inputnum1();
//string inputstr();
    //public :
    int PId;//Project ID number(4) auto increment
    int EId;//Created By number(4) = Employee ID of login Employee
    string Description;//Project Description string(50)
    char date[80];//Create Date date (DD/MM/YYYY format) = today’s date
    int duration;//Project Duration int(2) = number of months
    string Depat;//Department string(50)
    string Group;//Group string(50)
    int c=1000;
    int get_id();
    void getdata(int empid);
    void showdata();
    void Add(int empid);
    void Modify();
    void Delete(int idx);
    void option();
};

#endif // MANAGEPROJECT_H
