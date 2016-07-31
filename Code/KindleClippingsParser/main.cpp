//
//  main.cpp
//  kindleParser
//
//  Created by Ming on 9/20/15.
//  Copyright (c) 2015 mitake. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;
using namespace regex_constants;


int main(int argc, const char * argv[])
{
    string inputfile = "";
    string outputfile = "";
    string bookname = "";
    
    cout << "Please enter input file:";
    getline(cin, inputfile);
    cout << "Please enter output file:";
    getline(cin, outputfile);
    cout << "Please enter book name:";
    getline(cin, bookname);
    
    
    
    ifstream infile(inputfile);
    ofstream outfile(outputfile);
    string temp;
    string regex_str1 = "==========";
    string regex_str2 = bookname;
    string regex_str3 = "- Your Highlight ";
    string regex_str4 = "- Your Book";
    regex reg1(regex_str1, icase);
    regex reg2(regex_str2, icase);
    regex reg3(regex_str3, icase);
    regex reg4(regex_str4, icase);
    

    while (!infile.eof()) {
        getline(infile,temp);
        size_t length = temp.size();
        if(!regex_search(temp, reg1) &&
           !regex_search(temp, reg2) &&
           !regex_search(temp, reg3) &&
           !regex_search(temp, reg4) &&
           length != 1
           ) {
            outfile << temp;
            outfile << "\n";
        }

    }

    return 0;
}