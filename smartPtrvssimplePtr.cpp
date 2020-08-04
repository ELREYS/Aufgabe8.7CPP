#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

typedef struct Persona{
  string name;
  string eta;
} Person;

int main(int argc, char const *argv[])
{
  Person p1,p2;
  Person *p3;

  vector<Person> *vettore[2];

  p1.name = "Giuseppe";
  p1.eta = "41";

  

  p2 = p1;

  cout << &p1 << endl;
  cout << &p2 << endl;

   p3 = new Person();
   cout << typeid(p3).name() << endl;
   p3->name = "Marco";

   cout << p3 << endl;
   Person *p4 = p3;
   cout << typeid(p4).name() << endl;
   

   cout << p3 << endl;

   cout << &p4 << endl;

  

   



  /* code */
  return 0;
}
