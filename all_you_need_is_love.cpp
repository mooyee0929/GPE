#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}

int main(){
    int n;
    int round=1;
    cin>>n;
    while (n--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int num1 = 0;
        int num2 = 0;
        for(int i=s1.size()-1;i>=0;i--){
            num1+=(s1[i]-'0')*pow(2,s1.size()-i-1);
        }
        for(int i=s2.size()-1;i>=0;i--){
            num2+=(s2[i]-'0')*pow(2,s2.size()-i-1);
        }
        cout<<num1<<" "<<num2<<endl;
        if(GCD(num1, num2) != 1){
            cout << "Pair #" << round++ << ": All you need is love!\n";
        } else{
            cout << "Pair #" << round++ << ": Love is not all you need!\n";
        }
    }
    
}