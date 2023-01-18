#ifndef CHECKPID_H
#define CHECKPID_H


class CheckPID
{
    public:
        CheckPID();
   int CheckPId();
   int Ticketid();
    int ProjectID;// number(4)
    int TicketID;// number(4) auto increment
    char Priority[2];// char(1) = (L)ow, (M)edium, (H)igh, (S)evere
    int Eid;//Created By number(4) = Employee ID of login Employee
    char Description[50];//Bug Description string(50)
    char date[80];//Create Date date (DD/MM/YYYY format) = today’s date (initially)
    int AEid;//Assigned To number(4) = Employee ID of login Employee (initally)
    char Cdate[80];//Closed on date (DD/MM/YYYY format)
    char Status[2];//Status char(1) = (O)pen, (A)ssigned, (F)ixed, (S)ubmitted, (Q)uality checked, (C)lose
    int ETime;//Estimated Fix Time int(2) = number of hours required to fix bug
    char Note[540];//Note string(540)
    char CodeSnip[540];//Code Snippet string(540

};

#endif // CHECKPID_H
