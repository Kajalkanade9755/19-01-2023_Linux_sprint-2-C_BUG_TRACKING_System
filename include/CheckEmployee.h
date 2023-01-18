#ifndef CHECKEMPLOYEE_H
#define CHECKEMPLOYEE_H


class CheckEmployee
{
    public:
        CheckEmployee();
           public:
 int EmployeeID;// number(4)
    char password[10];//Employee Password string(10)
    char Name[50];//Employee Name string(50)
    char Dep[10];//Department string(10)
    long Mobile;//Mobile Number number(10)
    char email[30];//email string(30)
    char Skype[20];//Skype ID string(20)
   // int loginid;
    int chkEmply();
};

#endif // CHECKEMPLOYEE_H
