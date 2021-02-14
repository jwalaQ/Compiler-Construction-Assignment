#include <fstream>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    string tk_name;
    string value;
    int line_no;
};
vector<Node> ans;

vector<string> keyword_dict = {"integer","real","boolean","of",
                "array","start","end","declare","module","driver","program",
                "get_value","print","use","with","parameters","true",
                "false","takes","input","returns","AND","OR","for","in",
                "switch","case","break","default","while"};       

vector<string> token_key = {"INTEGER","REAL","BOOLEAN","OF","ARRAY","START",
                        "END","DECLARE","MODULE","DRIVER","PROGRAM","GET_VALUE",
                        "PRINT","USE","WITH","PARAMETERS","TRUE","FALSE","TAKES","INPUT","RETURNS",
                        "AND","OR","FOR","IN","SWITCH","CASE","BREAK","DEFAULT","WHILE"};

void token_extract(string line,int line_number){
    string token;
    int state = 0;
    int lexeme_beginning=0, forward_pointer = 0;
    int flag = 1;
    while(flag){
        switch (state){
            case 0:
                if(forward_pointer == line.size())
                    state = 13;
                else if (line[forward_pointer]=='p'){
                    forward_pointer++;
                    state = 1;
                }
                else if(line[forward_pointer]=='s'){
                    forward_pointer++;
                    state = 2;
                }
                break;
            case 1:
                if (line[forward_pointer]=='p'){
                    forward_pointer++;
                    state = 1;
                }
                else{
                    token = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    state = 0;
                    // cout << token << endl;
                    Node *temp = new Node();
                    temp->tk_name = "Parth";
                    temp->value = token;
                    temp->line_no = line_number;
                    // cout << "a" << endl;
                    ans.push_back(*temp);
                    lexeme_beginning = forward_pointer;
                    token.clear();       
                }
                break;
            case 2:
                if (line[forward_pointer]=='s'){
                    forward_pointer++;
                    // cout << forward_pointer <<  endl;
                    state = 2;
                }
                else{
                    token = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    state = 0;
                    // cout << "burse burse" << endl;
                    Node *temp = new Node();
                    temp->tk_name = "Burse";
                    temp->value = token;
                    temp->line_no = line_number;
                    lexeme_beginning = forward_pointer;
                    // cout << token << endl;
                        
                    // cout << forward_pointer << " " << line.size() << endl;
                    // cout << "b+" << " " << "n++1" << "\n";
                    // cout << "n" << "\n";
                    ans.push_back(*temp);
                    // cout << ans.size() << endl;
                    token.clear();
                }
                break;
            case 13:
                flag=0;
                break;
        }
    }
}
vector<Node> get_ans(){
    return ans;
}


