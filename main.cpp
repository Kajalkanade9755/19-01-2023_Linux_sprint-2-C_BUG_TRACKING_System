#include <iostream>
#include "ManageProject.h"
#include "Login.h"
#include "ModifyData.h"
#include "Report.h"
#include "WelcomePage.h"
#include<windows.foundation.h>
#include<exception>
using namespace std;

int main()
{
    WelcomePage w;
    w.Welcome_screen();
    ManageProject m;
    Report c;
    bool chkpid;
    int choic,ch4;
    //Report r;
    int idx;

b:
    cout<<"  -------------------------- Login---------------------------"<<endl;
    Login l;
    try
    {
        int empid=l.Lid();
        // if(empid==0) throw "TRy Again";
        ModifyData md;

        if(empid==0)
        {
            throw "PLEASE TRY AGAIN"; //goto b;
            cout<<"PLEASE TRY AGAIN"<<endl;
        }
        else
        {
//     md.CheckPId(empid);
menu:
            system("cls");
            w.ClearConsoleToColors(4,15);
            cout<<"***************************************************************************************"<<endl;
            cout<<"1. FOR MANAGE PROJECT \n2. FOR MANAGE TICKET \n3. FOR REPORT \n0. FOR QUIT"<<endl;
            cout<<"***************************************************************************************"<<endl;
//cout<<"ENTER YOUR CHOICE \n";
            cin.ignore();
            choic=m.inputnum1();
            switch(choic)
            {
            case 1:

                if(empid!=0)
                {

box:
                    system("cls");
                    w.ClearConsoleToColors(2,14);
                    cout<<"***************************************************************************************"<<endl;
                    cout<<"  -------------------------- Projects Menu---------------------------"<<endl;
                    cout<<"1. Add Project"<<endl;
                    cout<<"2. Modify Project"<<endl;
                    cout<<"3. Delete Project"<<endl;
                    cout<<"0. Quit"<<endl;
                    cout<<"***************************************************************************************"<<endl;
//cin.ignore();
                    int ch=m.inputnum1();
//cout<<"Enter your choice\n";
//cin>>ch;
                    switch(ch)
                    {
                    case 1:
                        system("cls");
                        m.Add(empid);
                        cout<<"PLEASE WAIT IN THE PROCESS \n";
                        for(int i=0; i<3; i++)
                        {
                            Sleep(1000);
                            cout<<".........."<<endl;
                        }
                        //  Sleep(5000);
                        getchar();
                        goto box;
                        break;
                    case 2:
                        system("cls");
                        m.Modify();
                        md.CheckPId(empid);
                        cout<<"PLEASE WAIT IN THE PROCESS \n";
                        for(int i=0; i<3; i++)
                        {
                            Sleep(1000);
                            cout<<".........."<<endl;
                        }
                        //Sleep(5000);
                        getchar();
                        goto box;
                        break;
                    case 3:

                        system("cls");
                        cout<<"ENTER PROJECT ID: \n";
                        cin>>idx;
                        chkpid= c.CheckPid(idx);
//cout <<chkpid<<"id\n";
                        if(chkpid==1)
                        {
                            cout<<"CAN NOT DELETE TICKED IS RAISED FOR THIS"<<endl;
                        }
                        else
                        {
                            m.Delete(idx);
                        }
                        //Sleep(5000);
                        cout<<"PLEASE WAIT IN THE PROCESS \n";
                        for(int i=0; i<3; i++)
                        {
                            Sleep(1000);
                            cout<<".........."<<endl;
                        }

                        //  m.Delete();
                        getchar();
                        goto box;
                        break;

                    case 0:

                        Sleep(2000);
                        system("cls");
                        //getchar();
                        goto menu;
                        break;
                    default:
                        cout<<"Invalid choice"<<endl;
                        Sleep(2000);
                        system("cls");
                        //getchar();
                        goto box;
                        break;
                    }
                }
                else
                {
                    cout<<"Please Try again "<<endl;
                    goto b;
                }
                break;
            case 2:

//cout<<"Enter your choice\n";
//cin>>ch2;
                if(empid!=0)
                {

tbox:
                    cout<<"***************************************************************************************"<<endl;
                    cout<<"  -------------------------- Ticket Menu---------------------------"<<endl;
                    cout<<"1. Add Ticket"<<endl;
                    cout<<"2. Modify Ticket"<<endl;
                    cout<<"3. Close Ticket"<<endl;
                    cout<<"0. Quit"<<endl;
                    cout<<"***************************************************************************************"<<endl;
//  cin.ignore();
                    int ch2=m.inputnum1();
//int ch;
//cout<<"Enter your choice\n";
//cin>>ch;
                    switch(ch2)
                    {
                    case 1:
                        // function
                        goto tbox;
                        break;
                    case 2:
                        //function
                        goto tbox;
                        break;
                    case 3:
                        //function
                        goto tbox;
                        break;
                    case 0:
                        goto menu;
                        break;
                    default:
                        cout<<"Invalid choice"<<endl;
                        goto tbox;
                        break;
                    }
                }
                else
                {
                    cout<<"Please Try again "<<endl;
                    goto b;
                }

                break;
            case 3:

rbox:
                system("cls");
               // w.ClearConsoleToColors(6,7);
                w.ClearConsoleToColors(1,13);
                cout<<"***************************************************************************************"<<endl;
                cout<<"  -------------------------- Report Menu---------------------------"<<endl;
                cout<<"1. Prioritywise list of tickets which are not Closed for given project"<<endl;
                cout<<"2. Prioritywise list of tickets which assigned by logged in employee"<<endl;
                cout<<"3. Prioritywise list of tickets created by logged in employee"<<endl;
                cout<<"4. Prioritywise list of tickets which are Closed for given project"<<endl;
                cout<<"5. Prioritywise list of projects for which ticket is raised"<<endl;
                cout<<"6. Prioritywise list of projects"<<endl;
                cout<<"0. Quit"<<endl;
                cout<<"***************************************************************************************"<<endl;
                ch4=m.inputnum1();

                switch(ch4)
                {
                case 1:
                    system("cls");
                    c.Closed();
                    cout<<"PLEASE WAIT IN THE PROCESS \n";
                    for(int i=0; i<3; i++)
                    {
                        Sleep(1000);
                        cout<<".........."<<endl;
                    }
                    getchar();
                    goto rbox;
                    break;
                case 2:
                    system("cls");
                    c.Assigned(empid);
                    cout<<"PLEASE WAIT IN THE PROCESS \n";
                    for(int i=0; i<3; i++)
                    {
                        Sleep(1000);
                        cout<<".........."<<endl;
                    }
                    getchar();
                    goto rbox;
                    break;
                case 3:
                    system("cls");
                    c.Created(empid);
                    cout<<"PLEASE WAIT IN THE PROCESS \n";
                    for(int i=0; i<3; i++)
                    {
                        Sleep(1000);
                        cout<<".........."<<endl;
                    }
                    getchar();
                    goto rbox;
                    break;

                case 4:
                    system("cls");
                    c.NotClosed();
                    cout<<"PLEASE WAIT IN THE PROCESS \n";
                    for(int i=0; i<3; i++)
                    {
                        Sleep(1000);
                        cout<<".........."<<endl;
                    }
                    getchar();
                    goto rbox;
                    break;
                case 5:
                    system("cls");
                    c.Listproject();
                    //c.PriorityCheck();
                    cout<<"PLEASE WAIT IN THE PROCESS \n";
                    for(int i=0; i<3; i++)
                    {
                        Sleep(1000);
                        cout<<".........."<<endl;
                    }
                    getchar();
                    goto rbox;
                    break;
                case 6:
                    system("cls");
                    m.showdata();
                    cout<<"PLEASE WAIT IN THE PROCESS \n";
                    for(int i=0; i<3; i++)
                    {
                        Sleep(1000);
                        cout<<".........."<<endl;
                    }
                    goto rbox;
                    getchar();
                    break;
                case 0:
                    system("cls");
                    c.PriorityCheck();
                    getchar();
                    goto menu;
                    break;
                default:
                    cout<<"INVALID INPUT"<<endl;
                    goto rbox;
                    getchar();
                    break;

                }

                break;
            case 0:
                exit(0);
            default:
                cout<<"INVALID INPUT TRY AGAIN PLEASE !!"<<endl;
                goto menu;
            }

        }

    }

    catch(const char *e)
    {
        cerr<<e;
        goto b;
    }
    return 0;

}
