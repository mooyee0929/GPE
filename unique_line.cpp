//unnknown
#include<iostream>
#include<vector>
#include<set>

#define inf 10000000.0
using namespace std;


pair<double,double> get_md(int x, int y, int x0, int y0){
    double dx = x-x0;
    double dy = y-y0;
    if(dx==0){
        return make_pair(x,inf);
    }else{
        double m = dy/dx;
        double d = y - m*x;
        return make_pair(m,d);
    }
}

int main(){
    int n;
    cin>>n;
    while (n--)
    {
        vector<int> dx;
        vector<int> dy;
        int p;
        cin>>p;
        for(int i=0;i<p;i++){
            int x,y;
            cin>>x>>y;
            dx.push_back(x);
            dy.push_back(y);
        }

        set<pair<double, double>> md;
        int lines = 0;
        for(int i=0;i<p;i++){
            for(int j=i+1;j<p;j++){
                pair<double, double> tmp;
                tmp = get_md(dx[j],dy[j],dx[i],dy[i]);
                
                if (md.find(tmp) == md.end())
                {
                    //cout<<tmp.first<<" "<<tmp.second<<endl;
                    md.insert(tmp);
                    lines++;
                }
            }
        }
        cout<<lines<<endl;
    }
    
}