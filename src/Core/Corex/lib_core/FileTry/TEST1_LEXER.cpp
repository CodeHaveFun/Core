#include <iostream>

using namespace std;
string AnalysisString(string INPUT_TOKEN){
    return "["+ INPUT_TOKEN + "]";
}
string LexerToken(string CodeTextLine){
    string TokenTemp;
    string CodeOUTPUT;
    for(char Token : CodeTextLine){
        if(!isspace(Token)){
            TokenTemp += Token;
        }else{
            CodeOUTPUT += AnalysisString(TokenTemp);
            TokenTemp.clear();
        }
    }
    if(!TokenTemp.empty()) CodeOUTPUT += AnalysisString(TokenTemp);
    return CodeOUTPUT;
}                   

int main(){
    string INPUT = "IF A == B";
    cout << LexerToken(INPUT) << endl;
}