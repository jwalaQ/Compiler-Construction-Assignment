#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include "lexer.h"
// struct Node{
//     string tk_name;
//     string value;
//     int line_no;
// };
//vector<Node> ans;
void print(vector<Node> ans)
{   
        for(auto it : ans){
        cout << "+";
        cout  << "TOKEN NAME IS -- " << it.tk_name << "\n"; 
        cout << "lexeme is --- " << it.value << "\n";
        cout << "line number ---" << it.line_no << "\n";
        cout << "++++++++++++" <<"\n";
    }
}
int main(int argc, char* argv[]){
    
    string line;
    ifstream myfile (argv[1]);
    int line_number = 1;
    int lexeme_beginning=0, forward_pointer=0;
    
    if(myfile.is_open()){
        while(getline(myfile,line)){
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




