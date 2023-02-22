#include<iostream>

using namespace std;

int milk_list[10000005];

int main(){
    int m,n;
    while (cin>>m>>n&&m!=EOF)
    {
        int left = 0;
        int right = 0;
        for(int i=0;i<m;i++){
            cin>>milk_list[i];
            if(milk_list[i]>left) left = milk_list[i];
            right+=milk_list[i];
        }
        while(left<right){
            int mid = (left+right)/2;
            int sum = 0;
            int amount = 0;
            for(int i=0;i<m;i++){
                sum+=milk_list[i];
                if(sum>mid){
                    amount++;
                    sum=milk_list[i];
                }else if(sum==mid){
                    amount++;
                    sum = 0;
                }
            }
            if (sum>0) amount++;
            if(amount>n){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        cout<<left<<endl;
    }
    
}