#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;


enum Weiter
{
  N,
  J
};

class personType
{

private:
  string _name;
  string _vorname;
  int _persid;
  double _gehalt;
  string _geburtstag;

public:
  personType(){};
  personType(string name, string lname,int idnmbr,double salary,string birthday){
    _name = name;
    _vorname = lname;
    _persid = idnmbr;
    _gehalt = salary;
    _geburtstag = birthday;

  }
  
  static bool weiter();
  string eingabeNameVorname(const string &);
  int eingabePersIDNr();
  double eingabeGehalt();
  string eingabeDatum();
  friend ostream& operator<< (ostream& os,const personType &person);
  void ausgabeTabelle(const vector<personType> &person);

};




 bool personType::weiter()
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

string personType::eingabeNameVorname(const string &flname)
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
};

int personType::eingabePersIDNr()
{
  int persid = 0;
  string PersID = eingabeNameVorname("PersID");
  stringstream streameingabe(PersID);
  streameingabe >> persid;
  return persid;
}

double  personType::eingabeGehalt()
{
  double gehalt = 0.0;
  string Gehalt = eingabeNameVorname("Gehalt");
  stringstream streameingabe(Gehalt);
  ostringstream os;
  os.str("");
  os.precision(4);
  os << fixed << streameingabe.str();
  streameingabe.str(os.str());
  streameingabe >> gehalt;
  return gehalt;
}

string personType::eingabeDatum()
{
  string datum, dot1, dot2;
  geburtsretry:
  string geburtsdt = eingabeNameVorname("Geburtstag");
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


ostream& operator<<(ostream& os,const personType &person)
{
  
  os << left << setw(20) << person._name << setw(30) << person._vorname << setw(30) << person._persid << setw(20) << person._gehalt << setw(20) << person._geburtstag << endl;
  return os;
}

void personType::ausgabeTabelle(const vector<personType> &person)
{
  ostringstream os;
  os.str("");
  os << endl;
  os << left << setw(20) << "Name" << setw(30) << "Vorname" << setw(30) << "PersID" << setw(20) << "Gehalt" << setw(20) << "GeburtsTag" << endl
     << endl;
  cout << os.str();
  os.clear();
  for (const personType &p : person)
  {
    cout << p;
  }
}

int main(int args, char *argv[])
{

  Weiter w = J;
  vector<personType> personListe;

  personType person;

  personType::weiter();


  if (person.weiter() == true)
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
    personType p1 = {person.eingabeNameVorname("Name"),person.eingabeNameVorname("Vorname"),person.eingabePersIDNr(),person.eingabeGehalt(),person.eingabeDatum()};
    personListe.push_back(p1);
    person.weiter() == true ? w = J : w = N;
  }
    person.ausgabeTabelle(personListe);

finished:
  cout << "List end" << endl;
}