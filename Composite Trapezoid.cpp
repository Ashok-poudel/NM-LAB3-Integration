#include<iostream>
#include<cmath>
using namespace std;


int main(){
	float a ,b ,fa,fb,result,x,n,h;
   	float fx = exp(-x);
       n =4;
       b = 5;
       a = 1;
     fa = exp(-a);
     fb = exp(-b);
     float sum = fa + fb;
     h = (b-a)/n;
    float x0 = h ;
    float x1 = x0 + h ;
   float fx1 = exp(-x1);
    float x2= x1+h;
    float fx2 =exp(-x2);
    float x3 = x2 + h;
    float fx3 = exp(-x3);
    float I = h/2 *(sum + 2 *(fx1+fx2+fx3));
    cout <<"The Value of I is :"<<I<<endl;
    return 0;
}
