#include <iostream>
#ifndef DATA_H  
#define DATA_H

using namespace std;

class Data {

  private:

    string m_dia, m_mes, m_ano;

  public:

    Data();
    ~Data();

    void setDia(string dia);
    void setMes(string mes);
    void setAno(string ano);
    string getDia();
    string getMes();
    string getAno();

};

#endif 