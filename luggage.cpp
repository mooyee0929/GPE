#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.get();
        for(int i=0;i<n;i++){
            string s;
            stringstream ss;
            
            
            getline(cin,s);
            ss<<s;
            int w;
            int sum = 0;
            vector<int> weight;
            while(ss>>w){
                weight.push_back(w);
                sum += w;
            }
            if(sum%2){
                cout<<"NO\n";
                continue;
            }
            sort(weight.begin(),weight.end());
            vector<bool> dp (sum+1,false);
            dp[0]=true;
            for(int j=0;j<weight.size();j++){
                for(int k =sum;k-weight[j]>=0;k--){
                    if(dp[k-weight[j]]){
                        dp[k] = true;
                    }
                }
            }
            if(dp[sum/2]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
}