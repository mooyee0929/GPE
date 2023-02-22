#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dp[1000005];

int main(){
    int tot;
    int set_num;
    while (cin>>tot)
    {
        vector<int> stone_list;
        cin>>set_num;
        for(int i=0;i<set_num;i++){
            int n;
            cin>>n;
            stone_list.push_back(n);
        }
        sort(stone_list.begin(),stone_list.end());
        for(int i=0;i<1000005;i++){
            for(int j=0;j<stone_list.size();j++){
                if(i-stone_list[j]>=0&&dp[i-stone_list[j]]==0){
                    dp[i]=true;
                    break;
                }else{
                    dp[i]=false;
                }
            }
        }

        if(dp[tot])
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    }
    
}