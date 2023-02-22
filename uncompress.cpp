#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> word_list;
    string buffer;
    while (getline(cin,buffer)&&buffer[0]!='0')
    {
        string s;
        int value;
        for(int i=0;buffer[i];i++){
            if(isalpha(buffer[i])){
                s = "";
                while(isalpha(buffer[i])){
                    s.push_back(buffer[i]);
                    i++;
                }
                word_list.push_back(s);
                i--;
                cout<<s;

            }else if(isdigit(buffer[i])){
                value = 0;
                s = "";
                while(isdigit(buffer[i])){
                    value = value*10 + (buffer[i]-'0');
                    i++;
                }
                i--;
                s = word_list[word_list.size()-value];
                word_list.erase(word_list.end()-value);
                word_list.push_back(s);
                cout<<s;
            }else{
                cout<<buffer[i];
            }
        }
        puts("");
    }
    return 0;
}