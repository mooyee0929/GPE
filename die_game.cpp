#include<iostream>
#include<string>
using namespace std;

int dice [6] = {1,2,3,4,5,6};

void north(){
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
}
void west(){
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
}
void east(){
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
}
void south(){
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
}

int main(){
    int n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            if(s=="north"){
                north();
            }else if(s=="west"){
                west();
            }else if(s=="east"){
                east();
            }else if(s=="south"){
                south();
            }
        }
        cout<<dice[0]<<endl;
        for(int i=0;i<6;i++){
            dice[i]=i+1;
        }
    }
}