#include<iostream>
#include<iomanip>

using namespace std;

int coins[11] = {10000, 5000, 2000, 1000, 500 , 200 , 100 , 50, 20, 10 ,5};
long long dp[30005];


int main(){
    dp[0]=1;
    for(int i=10;i>=0;i--){
        for(int j=coins[i];j<30005;j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    double w;
    while(cin>>w&&w){
        cout<<setw(6)<<fixed<<setprecision(2)<<w<<setw(17)<<dp[int(w * 100 + 0.2)]<<endl;
    }
}