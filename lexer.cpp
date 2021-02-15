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

vector<string> keyword_dict = {"int","float","bool","shuru","khatam",
                "declare","module","driver","program",
                "get_value","print","use","with","parameters","true",
                "false","takes","input","returns","AND","OR","for","in",
                "switch","case","break","default","while"
                };       

vector<string> token_key = {"TK_TYPE","TK_TYPE","TK_TYPE","TK_START",
                        "TK_END","DECLARE","MODULE","DRIVER","PROGRAM","GET_VALUE",
                        "PRINT","USE","WITH","PARAMETERS","TRUE","FALSE","TAKES","INPUT","RETURNS",
                        "AND","OR","FOR","IN","SWITCH","CASE","BREAK","DEFAULT","WHILE"};
                        

int isKeyword(string k){
    for (int i = 0; i < keyword_dict.size(); i++){
        if(k.compare(keyword_dict[i])==0)
            return i;
    }
    return -13;
}

void insert_token(string tk_name, string token, int line_number){
    // cout << token << endl;
    Node *temp = new Node();
    temp->tk_name = tk_name;
    temp->value = token;
    temp->line_no = line_number;
    // cout << "a" << endl;
    ans.push_back(*temp);
}


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
                else if (line[forward_pointer]=='+'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_PLUS", "+", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='-'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_MINUS", "-", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='*'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_MUL", "*", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='/'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_DIV", "/", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='%'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_MOD", "%", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]==';'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_SEMICOLON", ";", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]==','){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_COMMA", ",", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='&'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_AND", "&", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='{'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_CBO", "{", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='}'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_CBC", "}", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='('){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_RBO", "(", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]==')'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_RBC", ")", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='['){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_SBO", "[", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]==']'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_SBC", "]", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='='){
                    forward_pointer++;
                    state = 1;
                }
                else if (line[forward_pointer]=='>'){
                    forward_pointer++;
                    state = 2;
                }
                else if (line[forward_pointer]=='<'){
                    forward_pointer++;
                    state = 3;
                }
                else if(isalpha(line[forward_pointer])){
                    forward_pointer++;
                    state = 5;
                }
                else if(isdigit(line[forward_pointer])){
                    forward_pointer++;
                    state = 6;
                }else{
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                }
                break;
            case 1:
                if (line[forward_pointer]=='='){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_EQ", "==", line_number);
                    state = 0;
                }
                else{
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_ASSIGNMENT", "=", line_number);
                    state = 0;                      
                }
                break;
            case 2:
                if (line[forward_pointer]=='='){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_GE", ">=", line_number);
                    state = 0;
                }
                else{
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_GT", ">", line_number);
                    state = 0;      
                }
                break;
            case 3:
                if (line[forward_pointer]=='='){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_LE", "<=", line_number);
                    state = 0;
                }
                else{
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_LT", "<", line_number);
                    state = 0;      
                }
                break;
            case 5:
                if (isalnum(line[forward_pointer])||line[forward_pointer]=='_'){
                    forward_pointer++;
                    state = 5;
                }
                else{
                    string str = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    int val = isKeyword(str);
                    if(val==-13)
                        insert_token("IDENTIFIER",str,line_number);
                    else
                        insert_token(token_key[val],str,line_number);
                    lexeme_beginning = forward_pointer;
                    state = 0;      
                }
                break;
            case 6:
                if (isdigit(line[forward_pointer])){
                    forward_pointer++;
                    state = 6;
                }
                else if(line[forward_pointer]=='.'){
                    forward_pointer++;
                    state = 7;
                }else{
                    state = 0;
                    string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_INT",val,line_number);
                }
                break;
            case 7:
                if (isdigit(line[forward_pointer])){
                    forward_pointer++;
                    state = 7;
                }
                else{
                    state = 0;
                    string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_FLOAT",val,line_number);
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


