/*
********** GROUP DETAILS **********
Parth Krishna Sharma - 2017B3A70907H
Prajjwal Vijaywargiya - 2017B3A70954H
Piyush Pathak - 2017B3A70425H
Siddhi Burse - 2017B3A70972H
***********************************
*/

#include <bits/stdc++.h>
using namespace std;
#include "lexer.h"

void print(vector<Node> ans)
{   
    for(auto it : ans){
        if(it.tk_name.compare("String_error")==0){
            cout << "LEXICAL ERROR: String not terminated '"<<it.value<<"' found at Line number: "<<it.line_no<<"\n";
        }
        else if(it.tk_name.compare("Float_error")==0){
            cout << "LEXICAL ERROR: Invalid float format '"<<it.value<<"' found at Line number: "<<it.line_no<<"\n";
        }
        else if(it.tk_name.compare("INVALID_TOKEN")!=0) 
            cout<<"Lexeme: "<<it.value<<",\t\t"<<"Token: "<<it.tk_name<<",\t\t"<<"Line number: "<<it.line_no << "\n";
        else
            cout << "LEXICAL ERROR: Invalid '"<<it.value<<"' found at Line number: "<<it.line_no<<"\n";
    }
}

int main(int argc, char* argv[]){
    
    string line;
    ifstream myfile (argv[1]);
    int line_number = 1;
    int lexeme_beginning=0, forward_pointer=0;
    
    if(myfile.is_open()){
        while(getline(myfile,line)){
            if(line.size()>0)
                token_extract(line, line_number);
            line_number++;
        }
        vector<Node> ans = get_ans();
        print(ans);
    }

    else {
        cout << "Unable to open file"; 
    }
    myfile.close();

    return 0;
}
