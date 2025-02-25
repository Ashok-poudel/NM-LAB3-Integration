#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float fun(int x){
	return exp(-x);
}

int main(){
		 float I,h,b,a;
		
		cout<<"Enter the upper limit and lower limit :";
		cin>>b>>a;
		
			h=(b-a)/2;
			I=(h/3.0)*(fun(b)+(4.0*fun(a+h))+fun(a));
		
		cout<<"The integration of given fx=exp(-x) is "<<setprecision(2)<<I;
		
		
	return 0;
}
