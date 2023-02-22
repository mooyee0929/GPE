#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    map<string,int> bonus;
    for(int i=0;i<m;i++){
        string map1;
        int map2;
        cin>>map1>>map2;
        bonus[map1] = map2;
    }
    string s;

    while (n--)
    {   
        long long sum = 0;
        while (cin>>s&&s!=".")
        {
            if(bonus[s]){
                sum+=bonus[s];
            }
        }
        cout<<sum<<endl;
            
    }
    
}