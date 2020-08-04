#include <iostream>
#include <typeinfo>

#include "modul/CRaumschiff.hpp"
using namespace std;

void xchng(int &x, int &y){
  int tmp = x;
  x = y;
  y = tmp;

};

int main(int argc, char const *argv[])
{




  CRaumschiff ruam(45,45);


  int var = 34;
  auto myDouble = 4.321f+ var;
  
  
  int a,b;
  a = 23;
  b = 45;
  cout << a << b << endl;
  xchng(a,b);
  cout << a << b << endl;
  

  cout << typeid(myDouble).name() << endl;



  return 0;
}
