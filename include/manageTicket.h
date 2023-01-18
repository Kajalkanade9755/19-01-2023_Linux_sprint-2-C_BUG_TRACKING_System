#ifndef MANAGETICKET_H
#define MANAGETICKET_H
#include<string>
using namespace std;
class manageTicket
{
    public:
        manageTicket();

   // public:
    // Varible Declaration

    int PID; // Project ID number(4)
  string TID;
  int TC; // Ticket ID number(4) auto increment
 string create_EID; // Created By number(4) = Employee ID of login Employee
 string assign_EID; // Assigned to number(4) = Employee ID of login Employee
  int fixTime; // int(2) = number of hours required to fix bug
  string Priority; // char(1) = (L)ow, (M)edium, (H)igh, (S)evere
  char date[80]; // Create Date date (DD/MM/YYYY format) = today�s date
  char closeDate[80]; // Closing date of the ticket date (DD/MM/YYYY format)= closing date
  string Status; // char(1) = (O)pen, (A)ssigned, (F)ixed, (S)ubmitted, (Q)uality checked, (C)lose
  std::string bug_Description; // Bug Description string(50)
  std::string Note; // Note to the code string(540)
  std::string code_Snippet; // Code Snippet string(540)
  int c = 100;

  // Function Declaration

  int login();
  void getdata();
  void showdata();
  void Option();
  int Add(int empid);
  int Modify();
  int Close();
  int add_Note();
  int Snippet();
  void Quit();
  //manageTicket() {
    //TC = 1;
  //}
};

#endif // MANAGETICKET_H
