#include "DNI.hpp"

DNI::DNI(bool random, std::string d, std::string n, std::string a) {
  dato = random ? "" : d;
  nombre = n;
  apellido = a;
  if(random) {
    for(int i=0; i<8; i++) {
      int cifra = rand() % 10;
      // std::cout << "Cifra: " << cifra << '\n';
      dato += std::to_string(cifra);
      letra =  (rand() % 25) + 65;
    }
  }
  if(d != "0") {
    dato = d;
  }
  // std::cout << "Constructor de DNI" << '\n';
  // std::cout << "Total: " << dato << '\n';
}

// Modificacion
std::string DNI::getNombre() {
  std::string r = nombre + " " + apellido;
  return r;
}

std::string DNI::getKey() const {
  return (dato + letra);
}

bool DNI::operator == (const DNI& d) const {
  return ((this->dato == d.dato) && (this->letra == d.letra));
}

bool DNI::operator == (const int& n) const {
  int r = atoi((this->dato).c_str());
  return (r == n);
}

bool DNI::operator == (const std::string& s) const {
  return (this->getKey() == s);
}

bool DNI::operator > (DNI& d) {
  unsigned long r = (unsigned long)*this;
  unsigned long s = (unsigned long)d;
  return (r > s);
}
bool DNI::operator >= (DNI& d) {
  unsigned long r = (unsigned long)*this;
  unsigned long s = (unsigned long)d;
  return (r >= s);
}
bool DNI::operator < (DNI& d) {
  return (!(*this > d));
}
bool DNI::operator <= (DNI& d) {
  return (!(*this >= d));
}

DNI::operator unsigned long() {
  int r = atoi((this->dato).c_str());
  r += (int)this->letra;
  return (unsigned long)r;
}

std::ostream& operator << (std::ostream& os, const DNI& d) {
    os << d.getKey();
    return os;
}
