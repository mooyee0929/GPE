#include<iostream>
#include<vector>
using namespace std;

int px, py;

void f1()
{
	px--;
	py++;
}
void f2()
{
	px--;
}
void f3()
{
	py--;
} 
void f4()
{
	px++;
	py--;
}
void f5()
{
	px++;
}
void f6()
{
	py++;
}




int main(){
    int n;
    while (cin>>n && n != EOF)
    {
        int sum = 0;
        int pw = 0;
        while(sum<n)
		{
			pw++;
			sum+=pw*6;		
		}
		
		sum-=pw*6;	
		n=n-sum;

        if(n==1){
            cout<<pw-1<<" 0"<<endl;
        }else{
            px=pw;
			py=0;
			n--;
			int t=pw;
            while(n && t)
			{
				n--;t--;
				f1();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f2();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f3();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f4();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f5();
			}
				
			t=pw;
			while(n && t)
			{
				n--;t--;
				f6();
			}
            cout<<px<<" "<<py<<endl;
        }
        
    }
    
    


}