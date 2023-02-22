#include<iostream>
#include<vector>
#define max 10005

using namespace std;

bool prime[max];
int dp[max*max];
int pre_sum[max];
vector<int> p;

void find_prime(){
    for(int i=0;i<max;i++){
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<max;i++){
        if(prime[i]){
            for(int j=2*i;j<max;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<max;i++){
        if(prime[i])
            p.push_back(i);
    }
};


void pre(){
    pre_sum[0]=p[0];
    for(int i=1;i<p.size();i++)
    {
        pre_sum[i]=pre_sum[i-1]+p[i]; //p[i]表示前i个素数的和
    }
};


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    find_prime();
    pre();
    for(int i=0;i<p.size();i++)
    {
        for(int j=i;j<p.size();j++)
        {
            int x=pre_sum[j]-pre_sum[i-1];
            dp[x]++;
        }
    }
    int i;
    while(cin>>i&&i!=0)
        cout<<dp[i]<<endl;
    return 0;
}