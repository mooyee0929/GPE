#include<iostream>
#include<vector>
using namespace std;
int preIndex = 0;

int search(vector<char> arr,int start, int end, char value){
    for (int i = start; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

void Post(vector<char> in, vector<char> pre, int left, int right){
    if(left>right) return;
    int index = search(in,left,right,pre[preIndex++]);
    Post(in,pre,left,index-1);
    Post(in,pre,index+1,right);
    cout<<in[index]<<" ";
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        vector<char> inorder(m);
        vector<char> preorder(m);
        for(int i=0;i<m;i++){
            cin>>preorder[i];
        }
        for(int i=0;i<m;i++){
            cin>>inorder[i];
        } 
        Post(inorder,preorder,0,m-1);
        cout<<endl;
        preIndex = 0;
    }
}