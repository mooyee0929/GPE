#include<iostream>
#include<vector>

using namespace std;

int cnt;

void print_list(vector<int> list, vector<vector<int>> next, int index,vector<int>print,int max){
    print.push_back(list[index]);
    if(print.size()==max){
        for(int i=0;i<print.size();i++){
            cout<<print[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<next[index].size();i++){
        print_list(list, next, next[index][i],print,max);
    }
};

void howmuch(vector<int> list, vector<vector<int>> next, int index,vector<int>print,int max){
    print.push_back(list[index]);
    if(print.size()==max){
        cnt++;
        return;
    }
    for(int i=0;i<next[index].size();i++){
        howmuch(list, next, next[index][i],print,max);
    }
};

int main(){
    int m;
    cin>>m;
    while (m--)
    {
        cnt = 0;
        int n;
        cin>>n;
        vector<int> list(n);
        vector<int> mark(n,1);
        vector<vector<int>> next(n);
        for(int i=0;i<n;i++){
            cin>>list[i];
        }
        int maxline = 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(list[j]>list[i]){
                    mark[j] = max(mark[i]+1,mark[j]);
                    next[i].push_back(j);
                    if(maxline < mark[j]){
                        maxline = mark[j];
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                vector<int>print;
                howmuch(list,next,i,print,maxline);
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                vector<int>print;
                print_list(list,next,i,print,maxline);
            }
        }

    }
    
}