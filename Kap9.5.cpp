#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;


int main(int anzahl, char *para[])
{

cout << "Anzahl: " << anzahl << endl;

for (size_t i = 0; i < anzahl; i++)
{
  cout << i << para[i] << endl;
}

string commando = "ls -l s*.cpp";
system(commando.c_str());
commando.at(6) = 'u';
system(commando.c_str());



return 0;
}