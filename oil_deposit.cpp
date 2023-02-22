#include<iostream>

using namespace std;
int m,n;
char map[100][100];
int d[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

void dfs(int a,int b){
    if(a>=0&&a<m&&b>=0&&b<n&&map[a][b]=='@'){
        map[a][b]='*';
        for(int i=0;i<8;i++){
            dfs(a+d[i][0],b+d[i][1]);
        }
    }
}

int main(){

    while(cin>>m>>n&&m){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]=='@'){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}