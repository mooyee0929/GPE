#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
char world[20][20];
int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int m,n;
void dfs(int a, int b,char c){
    if(a>=0&&a<m&&b>=0&&b<n&&world[a][b]==c){
        world[a][b]='*';
        for(int i=0;i<4;i++){
            dfs(a+d[i][0],b+d[i][1],c);
        }
    }
}

bool cmp(pair<string, int> a,pair<string, int> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}


int main(){
    int r;
    cin>>r;
    for(int k=1;k<=r;k++){
    {
        

        cin>>m>>n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>world[i][j];
            }
        }
        int letter[26]={0};
        int maxarea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(world[i][j]!='*'){
                    char c = world[i][j];
                    maxarea = max( ++letter[world[i][j]-'a'], maxarea );
                    dfs(i,j,c);
                    
                }
            }
        }
        cout<<"World #"<<k<<"\n";
        for( int i = maxarea ; i >= 1 ; i-- )
            for( int j = 0 ; j < 26 ; j++ )
            if( letter[j] == i ){
                char tmp = i+'a';
                cout<<tmp<<": "<<i<<endl;
            }
        }
        
    }
    
}
