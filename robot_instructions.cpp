//WA

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(){

    int round;
    cin>>round;
    cin.get();
    while(round--){
        int ins;
        cin>>ins;
        cin.get();
        vector<string> instruction_list;
        int value = 0;
        while (ins--)
        {
            string buffer;
            getline(cin,buffer);
            if(buffer[0]=='L'){
                value--;
                instruction_list.push_back("LEFT");
            }else if(buffer[0]=='R'){
                value++;
                instruction_list.push_back("RIGHT");
            }else{
                int idx = buffer[8]-'0';
                if(instruction_list[idx-1]=="LEFT"){
                    value--;
                    instruction_list.push_back("LEFT");
                }else if(instruction_list[idx-1]=="RIGHT"){
                    value++;
                    instruction_list.push_back("RIGHT");
                }
            }
        }
        cout<<value<<endl;
        
    }
    return 0;
}