#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <array>
#include <cstdlib>
#include<math.h>

using namespace std;


void ausgabe(time_t * ttz)
    {
        struct tm stx = *localtime(ttz);

        cout << setfill('0');
        cout << setw(2) << stx.tm_mday << ".";
        cout << setw(2) << stx.tm_mon + 1 << ".";
        cout << stx.tm_year + 1900 << " ";
        cout << setw(2) << stx.tm_hour << ":";
        cout << setw(2) << stx.tm_min << ":";
        cout << setw(2) << stx.tm_sec << endl;
    };



int main(int argc, char const *argv[])
{
    time_t jetzt;
    struct tm jetztLokal;

    jetzt = time(0);
    cout << jetzt << "Sek seit 1970 UTC" << endl;
    jetztLokal = *localtime(&jetzt);

    cout << setfill('-');
    cout << setw(2) << jetztLokal.tm_mday << ".";
    cout << setw(2) << jetztLokal.tm_mon + 1 << ".";
    cout << setw(2) << jetztLokal.tm_year + 1900 << ".";
    cout << setw(2) << jetztLokal.tm_hour << ".";
    cout << setw(2) << jetztLokal.tm_min << ".";
    cout << setw(2) << jetztLokal.tm_zone << ".";
    cout << setw(2) << jetztLokal.tm_sec << endl;

    cout << "Tag im Jahr: " << jetztLokal.tm_yday + 1 << endl;

    array<string, 7> tagFeld = {"SO", "MO", "DI", "MI", "DO", "FR", "SA"};

    cout << tagFeld.at(jetztLokal.tm_wday) << endl;

    //Zeit messen;

    clock_t clockStart, clockEnde;
    int wert = 1;
    double anzahl = 690e6, differenz, durchlauf;

    for (size_t k = 0; k < 5; k++)
    {
        clockStart = clock();
        for (size_t i = 0; i < 1; i++)
        {
            wert = -wert;
            clockEnde = clock();
            differenz = 1.0 * (clockEnde - clockStart) / CLOCKS_PER_SEC;
            durchlauf = differenz / anzahl * 1e9;

            cout << "Gesamt" << differenz << "s." << endl;
            cout << "Durchlauf" << durchlauf << "ns." << endl;
        }
    }

    //MakeTime Object

    

    struct tm st;
    time_t tt;

    st.tm_mday = 01;
    st.tm_mon = 4;
    st.tm_year = 120;
    st.tm_hour = 22;
    st.tm_min = 55;
    st.tm_sec = 30;

    tt = mktime(&st);
    cout << tt << endl;

    ausgabe(&tt);


    //Random

    cout << RAND_MAX << endl;

    srand((unsigned int)time(0));

    for (size_t i = 0; i < 10; i++)
    {
        cout << rand() % 6 + 1 << "";
        cout << endl;
    }

    //Check if char is a number or a string

    double zahl1,zahl2;

    cout << "Bitte eine summe eingebe?" << endl;
    cin >> zahl1;
    cout << "Bitte eine summe eingebe?" << endl;
    cin >> zahl2;

    cout << fabs(zahl1) << endl;
    



    

    return 0;
}

