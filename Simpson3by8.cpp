#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float fun(float a){
	return exp(-a);
}

int main(){
			float I,h,lwr,upr;
	
		cout<<"Enter the upper limit and lower limit :";
		cin>>upr>>lwr;
		
			h=(upr-lwr)/3.0;
			I=((3.0/8.0)*h)*(fun(lwr)+(3.0*fun(lwr+h))+(3.0*fun(lwr+h+h))+fun(upr));
		
		cout<<"The integration of given fx=exp(-x) is "<<setprecision(2)<<I;
		
		
	return 0;
}
