#pragma once
#include "../../include/includes.hpp"

class DNI {
  std::string dato;
  // Modificacion
  char letra;
  std::string nombre;
  std::string apellido;
public:
  DNI(bool = false, std::string = "0", std::string = "N/A", std::string = "N/A");

  // Modificacion
  std::string getNombre();
  std::string getKey() const;

  bool operator ==(const DNI&) const;
  bool operator ==(const int&) const;
  bool operator ==(const std::string&) const;
  bool operator > (DNI&);
  bool operator >= (DNI&);
  bool operator < (DNI&);
  bool operator <= (DNI&);
  operator unsigned long();

};

std::ostream& operator<<(std::ostream&, const DNI&);
