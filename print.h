#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <iostream>
#include <fstream>
#include<experimental/filesystem>
#include <unistd.h>


using namespace std;

void print_pres(string patient,string doc,string dept) {
    char cwd[10000];//this finds the path of .cpp file (absolute)
    getcwd(cwd, sizeof(cwd));
    cout<<cwd;
    string path_of_file = "";
    int i=0;
    while(cwd[i]!='\0'){    //converts array to string


        path_of_file += cwd[i];
        i++;
    }
    cout<<endl<<"path of file jado string ch leli"<<path_of_file<<endl;//random checks ::Jai Punjabi
  // Create and open a text file
  ofstream MyFile("print_reciept.py");//file opened in filestream


string text =  //python used
"import os\n"
"from docx import Document\n"
"from docx.shared import Inches\n"
"from docx.enum.text import WD_ALIGN_PARAGRAPH\n"
"from docx.shared import Pt\n"
"from datetime import date\n"

"today = date.today()\n"
"today=today.strftime('%m/%d/%Y, %H:%M:%S')\n"
"doc =  Document()\n"
"doc.add_heading('Hospital',0)\n"
"thanks =doc.add_paragraph()\n"

"thanks.add_run('Your Health Our Priority \\n').bold = True\n"
"doc_para = doc.add_paragraph()\n"
"doc_para.alignment = WD_ALIGN_PARAGRAPH.LEFT\n"
"doc_para.add_run('"+patient +" \\n').font.size = Pt(16)\n"
"doc_para.add_run('Prescription : \t\t').font.size = Pt(14)\n"

"doc_para.add_run('\\n\\n\\n\\n\\n\\n\\n\\n\\n').font.size = Pt(14)\n"





"#doc_para.add_run(txn.rjust(16)).font.size = Pt(14)\n"



"footer = doc.add_paragraph()\n"
"footer.alignment = WD_ALIGN_PARAGRAPH.RIGHT\n"
"footer.add_run('"+dept+"  \\n ')\n"
"footer.add_run(' Doctor email : "+doc+"   \\n')\n"
"#footer.add_run(' Ph: 99#######,91########\\n')\n"

"doc.save('printreceipt.docx')\n"

"os.startfile('printreceipt.docx', 'print')\n";






  // Write to the file
  MyFile << text;

  // Close the file
  MyFile.close();
  cout<<"file was written";

    string filename = path_of_file+"\\print_reciept.py";//absolute path of file containing email script in python
    string command = "python -u ";
    command += filename;
    system(command.c_str()); // sending a command in python for execution



}
#endif
