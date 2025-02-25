
//Write a program to calculate integration using Trapezoidal rule. 

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float fun(int a){
	
	return exp(-a);
}

int main(){
		float I, a,b;
		
		cout<<"Enter the upper limit and lower limit :";
		cin>>b>>a;
		I=((b-a)/2.0)*(fun(b)+fun(a));
		
		cout<<"The integration of given fx=exp(-x) is "<<setprecision(2)<<I;
		
		
	return 0;
}
