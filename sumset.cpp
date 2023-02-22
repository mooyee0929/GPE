#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    while (cin>>n&&n)
    {
        vector<int> list(n);
        for(int i=0;i<n;i++){
            cin>>list[i];
        }
        sort(list.begin(),list.end());
        bool flag = false;
        int ans;
        for (int d = list.size() - 1; d >= 0&& !flag; --d) // find the largest d
            for (int a = 0; a < list.size()&& !flag; ++a)
                for (int b = a + 1; b < list.size()&& !flag; ++b)
                    for (int c = b + 1; c < list.size()&& !flag; ++c)
                        if ( (list[d] == list[a] + list[b] + list[c]) &&a != d && b != d && c != d){
                            flag = true;
                            ans = list[d];
                        }

        if(flag)cout<<ans<<endl;
        else cout<<"no solotion\n";
    }
    
}