/*
********** GROUP DETAILS **********
Parth Krishna Sharma - 2017B3A70907H
Prajjwal Vijaywargiya - 2017B3A70954H
Piyush Pathak - 2017B3A70425H
Siddhi Burse - 2017B3A70972H
***********************************
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    string tk_name;
    string value;
    int line_no;
};
vector<Node> ans;

vector<string> keyword_dict = {"int","float","bool","array","rakho","shuru","khatam",
                                "sahi","galat","waapas","AND",
                                "OR","jab_tak","tab_tak","todo","agar","ya_phir","ya","dikhao","padho"
                            };

vector<string> token_key = {"TK_TYPE","TK_TYPE","TK_TYPE","TK_TYPE","TK_INCLUDE","TK_START","TK_FINISH",
                            "TK_TRUE","TK_FALSE","TK_RETURN", "TK_AND",
                            "TK_OR","TK_WHILE","TK_TILL","TK_BREAK","TK_COND_IF","TK_ELSE_IF", "TK_ELSE","TK_PRINT","TK_INPUT"
                        };
                        

int isKeyword(string k){
    for (int i = 0; i < keyword_dict.size(); i++){
        if(k.compare(keyword_dict[i])==0)
            return i;
    }
    return -13;
}

void insert_token(string tk_name, string token, int line_number){
    Node *temp = new Node();
    temp->tk_name = tk_name;
    temp->value = token;
    temp->line_no = line_number;
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
                    insert_token("TK_MULT", "*", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='/'){
                    forward_pointer++;
                    state = 8;
                    break;
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
                    insert_token("TOK_AND", "&", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='{'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_CURLY_BO", "{", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='}'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_CURLY_BC", "}", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='('){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_RND_BO", "(", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]==')'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_RND_BC", ")", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]=='['){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_SQBO  ", "[", line_number);
                    state = 0;
                }
                else if (line[forward_pointer]==']'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_SQBC  ", "]", line_number);
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
                }
                else if(line[forward_pointer]=='"'){
                    forward_pointer++;
                    state = 4;
                }
                else if(line[forward_pointer]==' '||line[forward_pointer]=='\t'){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                }else{
                    string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning+1);
                    insert_token("INVALID_TOKEN", val, line_number);
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                }
                break;
            case 1:
                if (line[forward_pointer]=='='){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_EQUALITY", "==", line_number);
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
                    insert_token("TK_GR_EQ", ">=", line_number);
                    state = 0;
                }
                else{
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_GR_T", ">", line_number);
                    state = 0;      
                }
                break;
            case 3:
                if (line[forward_pointer]=='='){
                    forward_pointer++;
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_LE_T", "<=", line_number);
                    state = 0;
                }
                else{
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_LE_T", "<", line_number);
                    state = 0;      
                }
                break;
            case 4:
                if(line[forward_pointer]!='"'){
                    forward_pointer++;
                    state = 4;
                }
                else{
                    forward_pointer++;
                    string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    insert_token("TK_STRING", val, line_number);
                    state = 0;
                }
                if(forward_pointer>=line.size()){
                    string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                    insert_token("String_error", val, line_number);
                    state = 13;
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
                    insert_token("TK_INTEGER",val,line_number);
                }
                break;
            case 7:
                if (isdigit(line[forward_pointer])){
                    forward_pointer++;
                    state = 7;
                }
                else{
                    if(line[forward_pointer]==' '){
                        if(line[forward_pointer-1]=='.'){
                            state = 0;
                            string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                            lexeme_beginning = forward_pointer;
                            insert_token("Float_error",val, line_number);
                        }
                        else{
                            state = 0;
                            string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                            lexeme_beginning = forward_pointer;
                            insert_token("TK_FLOAT",val,line_number);
                        }
                    }else{
                        state = 0;
                        string val = line.substr(lexeme_beginning,forward_pointer-lexeme_beginning);
                        lexeme_beginning = forward_pointer;
                        insert_token("Float_error",val,line_number);
                    }
                }
                break;
            case 8:
                if(line[forward_pointer]=='/'){
                    state = 13;
                }else{
                    lexeme_beginning = forward_pointer;
                    insert_token("TK_DIVISION", "/", line_number);
                    state = 0;
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
