#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    int n;
    while (cin>>n&&n!=0)
    {
        map<string, int> course;
        int max_num = 0;
		int total = 0;
        while (n--)
        {
            vector<string> class_num;
	        string input, line;
            for(int i=0;i<5;i++){
                cin>>input;
                class_num.push_back(input);
            }
            sort(class_num.begin(), class_num.end());
			for (int i = 0; i < 5; ++i){
                line += class_num[i];
            }
            ++course[line];
        }
        // for (auto it = course.begin(); it != course.end(); ++it){
        //     cout<<it->first<<" "<<it->second<<endl;
        // }
        for (auto it = course.begin(); it != course.end(); ++it)
			if (it->second > max_num) max_num = it->second;
        for (auto it = course.begin(); it != course.end(); ++it)
            if (it->second == max_num) total += max_num;
			
		cout << total << endl;
        
        
    }
    
}