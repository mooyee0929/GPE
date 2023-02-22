#include<iostream>

using namespace std;

int main(){
    long long m,n;
    while (cin>>m>>n&&m!=EOF)
    {
        long long num = m;
        while (num<n)
        {
            m++;
            num += m;
        }
        cout<<m<<endl;
        
    }
    
}