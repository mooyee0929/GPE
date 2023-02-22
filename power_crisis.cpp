#include<iostream>

using namespace std;

int main(){
    int n;
    while (cin>>n&&n!=0)
    {
        int i;
        n--;
        for(i=1;i<n;i++){
            int turnoff = 0;
            for(int j=1;j<=n;j++){
                turnoff = (turnoff + i) % j;
            }
            if(turnoff == 11) break;
        }
        cout<<i<<endl;
    }
    
}