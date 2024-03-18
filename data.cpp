#include <iostream>
#include "data.h"

using namespace std;

Data::Data() {
  
}

Data::~Data() {
  
}

void Data::setDia(string dia) {
  m_dia = dia;
}

void Data::setMes(string mes) {
  m_mes = mes;
}

void Data::setAno(string ano) {
  m_ano = ano;
}

string Data::getDia() {
  return m_dia;
}

string Data::getMes() {
  return m_mes;
}

string Data::getAno() {
  return m_ano;
}
