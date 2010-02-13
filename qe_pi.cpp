
/*34x^2+-117x+32 : 3.14159 : 183*/
/*
 What kind of quadratic equation's solution become pi.
 I want ax^2+bx+c that |a|+|b|+|c| is min.

 My Answer is 34x^2-117x+32. This is |a|+|b|+ |c|= 183
 and pi near 5.
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define ESP 3.14159
#define MAX_NUM 1000
#define SOLUTION(a,b,c) (-b+sqrt(b*b-4*a*c))/(2*a)
#define WEIGHT(a,b,c) (abs(a)+abs(b)+abs(c))

double check(int a,int b, int c, int &w){
  double s = 0;// SOLUTION(a,b,c);
  int g,m,n;
  cout<<"("<<a<<","<<b<<","<<c<<")"<<endl;
  for( g = -1; g < 2 ;g += 2){
    for(m=-1;m < 2; m += 2){
      for(n = -1; n < 2; n+=2){
	s = SOLUTION(g*a,b*m,c*n);
	if( ESP < s && s <ESP + 0.00001){
	  //w = WEIGHT(a,b,c);
	  cout<<g*a<<"x^2+"<<m*b<<"x+"<<n*c<<" : "<<s<<" : "<<WEIGHT(a,b,c)<<endl;
	}
      }
    }
  }
  return SOLUTION(g*a,m*b,n*c);
}
double RSolution(int a, int b, int c){
  double t = SOLUTION(a,b,c),s = 0;
  int i,j,k;
  if (t  < 0) t =0;
  for (i = -1;  i < 2; i+=2){
    for (j = -1; j < 2; j+=2){
      for (k = -1; k < 2; k+=2){
	s = SOLUTION(i*a,j*b,k*c);
	if(t >= 0 && s >= 0 && abs(t - ESP) > abs(s - ESP)){
	  t = s;
	}
      }
    }
  }
  return t;
}
int main(int argc, char *argv[]){
  int a,b,c;
  int cs,cc,ce;
  int w = MAX_NUM;
  double s = 0,e=0;
  for (a = 34; a < 36; a++){//MAX_NUM; a++){
    for (b = 1; b < MAX_NUM; b++){
      ce = (int)b*b/(4*a);
      cs = 0;
      while(ce >= cs && cs < MAX_NUM && ce < MAX_NUM){
	//	s = SOLUTION(a,b,cs);
	//	e = SOLUTION(a,b,ce);
	s = RSolution(a,b,cs);
	e = RSolution(a,b,ce);
	if(abs(s -ESP) < abs(e-ESP)){
	  ce = (cs+ce)/2;
	  cout<<"cEnd"<<flush;
	  cout<<e<<flush;
	  check(a,b,ce,w);
	}else if(abs(s -ESP) > abs(e-ESP)){
	  cs = (cs+ce)/2;
	  cout<<"cStart"<<flush;
	  cout<<s<<flush;
	  check(a,b,cs,w);
	}else if(abs(s -ESP) == abs(e-ESP)){
	  break;
	}
      }
    }
  }
  return 0;
}
