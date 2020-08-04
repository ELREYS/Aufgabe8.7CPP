#ifndef CRAUMSCHIFF_H
#define CRAUMSCHIFF_H

#include <iostream>
 using namespace std;


class CRaumschiff{
        
        public :
        int _m_xPos;
        int _m_yPos;
        int _m_Energie;
        float _m_fGeschwindigkeit;

        CRaumschiff();
        CRaumschiff(int m_xPos,int m_yPos);
        ~CRaumschiff();
};

#endif //CRAUMSCHIFF_H

