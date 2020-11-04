#include <iostream>
#include <fstream>
#include<experimental/filesystem>
#include <unistd.h>
#include<string>
#include<sstream>
#include<time.h>
#include<winsock.h>
#include"mysql.h"

using namespace std;
MYSQL* conn;
string send_patient(string reciever){

    MYSQL_ROW row;
    MYSQL_RES* result;
    stringstream temp;
    //this loop is going to check for all the five slots
    for(int i=1;i<=5;i++)
    {
        stringstream s;
        s<<"select * from Booking where Slot"<<i<<"='"<<reciever<<"';";
        string str=s.str();

        int qstate=mysql_query(conn,str.c_str());
        if(qstate!=0)
        {
            cout<<"Error\n";
            exit(0);
        }
        result=mysql_store_result(conn);
        while(row=mysql_fetch_row(result))
        {
            //stream which will have:department,slot and day as bookings...
            //stringstream temp;
            temp<<row[1]<<" "<<"SLOT"<<i<<" "<<row[7];
            //return temp.str();
        }}

    string code = temp.str();
    //================================random number generated and sent to string ===========//
    char cwd[10000];//this finds the path of .cpp file (absolute)
    getcwd(cwd, sizeof(cwd));

    string path_of_file = "";
    int i=0;
    while(cwd[i]!='\0'){    //converts array to string


        path_of_file += cwd[i];
        i++;
    }
   // cout<<endl<<"path of file jado string ch leli"<<path_of_file<<endl;//random checks ::Jai Punjabi
  // Create and open a text file


  //====================================python Processing=============================================//
  ofstream MyFile("script_for_email.py");//file opened in filestream


  string text =  //python used
  "import smtplib\n"
  "from email.message import EmailMessage\n"
  "msg = EmailMessage()\n"
  "msg['Subject'] = 'From my script'\n"
  "msg['From'] = 'environmentseekersnitj@gmail.com'\n"
  "msg['To'] = '"+reciever+"'\n"
  "smtp = smtplib.SMTP_SSL('smtp.gmail.com', 465)\n"
  "smtp.login('environmentseekersnitj@gmail.com', 'fdgphlhigarggaoy')\n"
  "msg.set_content('You are booked :: "+code+"')\n"
  "smtp.send_message(msg)\n"
  "smtp.quit()";

  // Write to the file
  MyFile << text;

  // Close the file
  MyFile.close();
  //=================================python file was written======================//
 // cout<<"python wali file likhti ";

    string filename = path_of_file+"\\script_for_email.py";//absolute path of file containing email script in python
    string command = "python -u ";
    command += filename;
    system(command.c_str()); // sending a command in python for execution
    cout<<"mail_sent";
    return code;

}


int main() {
    conn  = mysql_init(0);//connecting to database
    conn =mysql_real_connect(conn,"remotemysql.com", "izbe2a6Gri","9MnXblPN0F","izbe2a6Gri",3306,NULL,0);

    if(conn==0)
    {
        cout<<"Error\n";
        mysql_close(conn);
        exit(0);
    }
    string x = send_patient("FallakBansal@gmail.com");
    cout<<endl<<"value of x is "<<x;
    return 0;

}
