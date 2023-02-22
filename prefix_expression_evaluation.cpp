#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;

int main(){
    string c;
    while (getline(cin,c)&&c!=".")
    {
        //cout<<c;
        bool error =false;
        stack<int> Stack;
        for(int i=c.size()-1;i>=0;i--){
            if(isdigit(c[i])){
                int j=i-1;
                int value = c[i]-'0';
                
                while (isdigit(c[j]))
                {
                    value+=(c[j]-'0') * pow(10,(i-j));
                    j--;
                }
                i=j+1;
                Stack.push(value);

            }else if (c[i]==' '){
                continue;
            }else{
                if(Stack.size()<2){
                    error = true;
                    break;
                }
                int o1 = Stack.top();
                Stack.pop();
                int o2 = Stack.top();
                Stack.pop();
                switch (c[i]) {
                case '+':
                    Stack.push(o1 + o2);
                    break;
                case '-':
                    Stack.push(o1 - o2);
                    break;
                case '*':
                    Stack.push(o1 * o2);
                    break;
                case '/':
                    Stack.push(o1 / o2);
                    break;
                case '%':
                    Stack.push(o1 % o2);
                    break;
                }
            }
        }
        if(error){
            cout<<"illegal"<<endl;
        }
        else{
            cout<<Stack.top()<<endl;
        }
    }
    
}