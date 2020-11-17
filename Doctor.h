#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include<cstdlib>
#include <iostream>
#include<winsock.h>
#include"mysql.h"
#include<windows.h>
#include<stack>
#include<sstream>
#include<string>
#include<iomanip>
MYSQL*conn;
using namespace std;


class Doctor
{
    string id;
    string dept;
public:
    int login(MYSQL*conn,string,string);
    string display_appointments(MYSQL*conn);
    stack <string>print(MYSQL*conn);
    string getid(){
    return id;}
    string getdept(){
    return dept;}
    void reset(MYSQL*conn);

};

void Doctor::reset(MYSQL*conn)
{
    MYSQL_RES*res;
    MYSQL_ROW row;
    //run this loop for all slots from 1 to 5
    for(int i=1;i<=5;i++)
    {
        stringstream s;
        s<<"update Booking set Slot"<<i<<"='None';";
        string str=s.str();
        int qstate=mysql_query(conn,str.c_str());
        if(qstate!=0)
        {

            mysql_close(conn);
            exit(0);
        }
        res=mysql_store_result(conn);
    }

}





int Doctor::login(MYSQL*conn,string email,string pass)
{



    MYSQL_ROW row;
    MYSQL_RES* res;

    stringstream s;
    s<<"select * from Doctors where (email,pass)=("<<"'"<<email<<"','"<<pass<<"');";
    string qs=s.str();
    int qstate=mysql_query(conn,qs.c_str());

    if(qstate==0)
    {
         res = mysql_store_result(conn);
         int i=0;
        while(row = mysql_fetch_row(res))
        {
            i=1;
            cout<<endl<<endl<<setw(62)<<" "<<"-----Welcome-----"<<endl;
            cout<<setw(62)<<" "<<setw(30)<<left<<row[0]<<setw(20)<<row[1]<<setw(20)<<row[2];
            id=row[0];
            dept=row[2];
            return 1 ;
        }
        if(i==0)
        {
            cout<<setw(62)<<" "<<"Incorrect password or email....Try Again\n";

            return(0);
        }

    }
    else
    {
        cout<<setw(62)<<" "<<"Error in login ..please try again\n";

        return(0);
    }
}


//this function will return a string
//each line on string will contain information about the appointment
string Doctor::display_appointments(MYSQL*conn)
{     system("cls");
    cout<<setw(62)<<setfill('_')<<" "<<setfill(' ')<<"YOUR APPOINTMENTS";
    cout<<setw(50)<<setfill('_')<<" "<<setfill(' ')<<endl;

    //string stream whose string will be returned
    stringstream final_stream;
    int success=0;
        stringstream s;
        s.clear();
        s.str("");
        s<<"Select * from Booking where Department='"<<dept<<"';";
         string q=s.str();

        int qstate=mysql_query(conn,q.c_str());
        if(qstate!=0)
        {
            cout<<setw(62)<<" "<<mysql_error(conn);
            mysql_close(conn);

        }
        MYSQL_RES *result=mysql_store_result(conn);
        MYSQL_ROW row;
        int i=0;
        while(row=mysql_fetch_row(result))
        {

            for(int k=2;k<=6;k++)
            {
                if(strcmp(row[k],"None")!=0)
                {
                    i++;
                    stringstream temp;
                    temp<<row[7]<<":"<<" "<<"["<<k-1<<"]  "<<row[k];
                    final_stream<<temp.str()<<endl;
                }
            }
        }
        if(i==0)
        {
            return string("No Appointments\n");
        }

    return final_stream.str();
}


stack<string>Doctor::print(MYSQL*conn)
{
    system("cls");
    stack <string>s1,s2,s3;
    stringstream s;
   s<<"Select * from Booking where Department='"<<dept<<"';";
    string q=s.str();
        int qstate=mysql_query(conn,q.c_str());
        if(qstate!=0)
        {
            cout<<setw(62)<<" "<<"Error..please try again\n";
            mysql_close(conn);
            exit(0);
        }
        MYSQL_RES *result=mysql_store_result(conn);
        MYSQL_ROW row;
        int i=0;
        while(row=mysql_fetch_row(result))
        {

            for(int k=2;k<=6;k++)
            {
                if(strcmp(row[k],"None")!=0)
                {
                    i++;
                    stringstream temp;
                    s2.push(row[k]);
                }
            }
        }
        while(s2.empty()==0)
        {
            string str=s2.top();
            s2.pop();
            s.clear();
            s.str("");
            s<<"Select * from patients where email='"<<str<<"';";
            q=s.str();
            qstate=mysql_query(conn,q.c_str());
            if(qstate!=0)
            {

                cout<<"Error..Try again\n";
                mysql_close(conn);
                exit;
            }
            result=mysql_store_result(conn);
            while(row=mysql_fetch_row(result))
            {

                stringstream temp;
                temp<<"Patient ID: "<<row[0]<<"\tAGE:"<<row[2]<<"\tGENDER:"<<row[3];
                s1.push(temp.str());
            }


        }
        return s1;

}

#endif // DOCTOR_H_INCLUDED
