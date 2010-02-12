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
#define MAX_NUM 500
#define SOLUTION(a,b,c) (-b+sqrt(b*b-4*a*c))/(2*a)
#define WEIGHT(a,b,c) (abs(a)+abs(b)+abs(c))

void check(int a,int b, int c, int &w){
  double s = SOLUTION(a,b,c);
  if( ESP < s && s <ESP + 0.00001){
    w = WEIGHT(a,b,c);
    cout<<a<<"x^2+"<<b<<"+x+"<<c<<" : "<<s<<" : "<<w<<endl;
  }

}

int main(int argc, char *argv[]){
  int a,b,c;
  int w = MAX_NUM;
  for (a = 0; a < MAX_NUM; a++){
    for (b = 0; b < MAX_NUM; b++){
      for(c = 0; b*b-4*a*c > 0; c++){
	if(w < WEIGHT(a,b,c))
	  break;
	check(a,b,c,w);
	check(-a,b,c,w);
	check(-a,-b,c,w);
	check(-a,b,-c,w);
	check(a,-b,c,w);
	check(a,-b,-c,w);
	check(a,b,-c,w);
	check(-a,-b,-c,w);
      }
    }
      
  }
  return 0;
}
