#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

typedef struct sPerson
{
  string name;
  string vorname;
  int persid;
  double gehalt;
  string geburtstag;
} Person;

enum Weiter
{
  N,
  J
};

bool weiter()
{
  string tmpweiter;
  string decision;
  bool weiter;
Dateneingabe:
  cout << "Datensatz eingeben (J/N)";
  getline(cin, tmpweiter);
  decision = tmpweiter.substr(0, 1);
  if ((decision == "J" || "j") || (decision == "N" || "n"))
  {
    if (decision == "J")
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    goto Dateneingabe;
  }
};

string eingabeString(const string flname)
{
  string eingabe, name;
getName:
  cout << "Bitte " << flname << " eingeben" << endl;
  getline(cin, eingabe);

  //cout<< eingabe.length();
  if (eingabe.empty() || eingabe.length() < 2)
  {
    goto getName;
  }
  else
  {

    return eingabe;
  }
}

int eingabeInt()
{
  int persid = 0;
  string PersID = eingabeString("PersID");
  stringstream streameingabe(PersID);
  streameingabe >> persid;
  return persid;
}

double eingabeDouble()
{
  double gehalt = 0.0;
  string Gehalt = eingabeString("Gehalt");
  stringstream streameingabe(Gehalt);
  ostringstream os;
  os.str("");
  os.precision(4);
  os << fixed << streameingabe.str();
  streameingabe.str(os.str());
  streameingabe >> gehalt;
  return gehalt;

  
}

string eingabeDatum()
{
  string datum, dot1, dot2;
geburtsretry:
  string geburtsdt = eingabeString("Geburtstag");
  stringstream streameingabe(geburtsdt);
  streameingabe >> geburtsdt;
  dot1 = geburtsdt.substr(2, 1);
  dot2 = geburtsdt.substr(5, 1);
  if (dot1 == "." && dot2 == ".")
  {
    return geburtsdt;
  }
  else
  {
    goto geburtsretry;
  }
}

void ausgabe(const Person &person)
{
  ostringstream os;
  string ausgabePerson;
  os.str("");
  os << left << setw(20) << person.name << setw(30) << person.vorname << setw(30) << person.persid << setw(20) << person.gehalt << setw(20) << person.geburtstag << endl;
  cout << os.str();
  os.clear();
}

void ausgabeTabelle(const vector<Person> &person)
{
  ostringstream os;
  os.str("");
  os << endl;
  os << left << setw(20) << "Name" << setw(30) << "Vorname" << setw(30) << "PersID" << setw(20) << "Gehalt" << setw(20) << "GeburtsTag"  << endl << endl;
  cout << os.str();
  os.clear();
  for (const Person &p : person)
  {
    ausgabe(p);
  }
}

int main(int args,char *argv[])
{

  Weiter w = J;
  bool decision = argv[1];
  vector<Person> person;

  decision = weiter();
  cout << endl;
  if (decision == true)
  {
    w = J;
  }
  else
  {
    goto finished;
  }

  while (w == J)
  {

  createPerson:
    string name, vorname, geburtd;
    int persid;
    double gehalt;

    name = eingabeString("Name");
    vorname = eingabeString("Vorname");
    persid = eingabeInt();
    gehalt = eingabeDouble();
    geburtd = eingabeString("Geburtstag");
    person.push_back({name, vorname, persid, gehalt, geburtd});
    decision = weiter();
    decision == true ? w = J : w = N;
  }
  ausgabeTabelle(person);
  

  finished:
  cout << "List end" << endl;
}