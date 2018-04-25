#include "Funciones.hpp"

template <class Clave>
void insercion (std::vector<Clave>& v, int t) {
  // std::cout << "Funcion insercion" << '\n';
  for(int i=1; i<t; i++) {
    int j=0;
    CURRENT++;
    while((v[i]>v[j]) && (j<i)) { j++; CURRENT++; }  //  Se selecciona la posicion en la que insertar el elemento
    if(DEMO) showVector(v, i, j);
    v.insert(v.begin()+j, v[i]);                 //  Se inserta el elemento en la posicion
    v.erase(v.begin()+i+1);                      //  Se elimina de la posicion anterior
  }
}

template <class Clave>
void burbuja (std::vector<Clave>& v, int t) {
  // std::cout << "Funcion burbuja" << '\n';
  for(int i=1; i<t; i++) {
    for(int j=t-1; j>=i; j--) {
      CURRENT++;
      if(v[j] < v[j-1]) {
        if(DEMO) showVector(v, j, j-1);
        auto x = v[j-1];
        v[j-1] = v[j];
        v[j]   = x;
      }
    }
  }
}

template <class Clave>
void heapsort (std::vector<Clave>& v, int t) {
  // std::cout << "Funcion heapsort" << '\n';
  for (int i=t/2; i>=0; i--) {
    baja(i, v, t);
  }
  for(int i=t-1; i>0; i--) {
    if(DEMO) showVector(v, i, 0);
    auto x = v[0];
    v[0] = v[i];
    v[i] = x;
    baja(0, v, i-1);
  }
}

template <class Clave>
void baja(int i, std::vector<Clave>& v, int t) {
  // std::cout << "Funcion baja" << '\n';
  // std::cout << "i = " << i << '\n';
  auto x = v[i]; int h;
  while(2*i < t-1) {
    int h1 = 2*i;
    int h2 = h1+1;
    CURRENT++; CURRENT++;
    // std::cout << "h1 = " << h1 << ", h2 = " << h2 << '\n';
    if (h1 == t) {
      h = h1;
      CURRENT--;
    } else if (v[h1] > v[h2]) {
      h = h1;
    } else {
      h = h2;
    }
    // std::cout << "h = " << h << '\n';
    CURRENT++;
    if(v[h] <= x) break;
    else  {
      if(DEMO) showVector(v, i, h);
      v[i] = v[h];
      v[h] = x;
      i = h;
    }
  }
}

template <class Clave>
void quicksort (std::vector<Clave>& v, int t) {
  // std::cout << "Funcion quicksort" << '\n';
  qsort(v, 0, t-1);
}
template <class Clave>
void qsort (std::vector<Clave>& v, int ini, int fin) {
  int i = ini, f = fin;
  auto p = v[(i+f)/2];
  while(i <= f) {
    while(v[i] < p) i++;
    while(v[f] > p) f--;
    CURRENT++;
    if(i <= f) {
      if(DEMO) showVector(v, i, f);
      auto x = v[i];
      v[i] = v[f];
      v[f] = x;
      i++; f--;
    }
  }
  if (ini < f)  qsort(v, ini, f);
  if (i < fin)  qsort(v, i, fin);
}

template <class Clave>
void shellsort (std::vector<Clave>& v, int t) {
  // std::cout << "Funcion shellsort" << '\n';
  float a = 1/3;
  int del = t;
  CURRENT++;
  while(del > 0) {
    CURRENT++;
    del = del*a;
    // std::cout << "del = " << del << '\n';
    deltasort(del, v, t);
  };
}
template <class Clave>
void deltasort (int d, std::vector<Clave>& v, int t) {
  for (int i=d; i<t; i++) {
    auto x = v[i];
    int j = i;
    CURRENT++;
    while((j >= d) && (x < v[j-d])) {
      CURRENT++;
      if(DEMO) showVector(v, j, j-d);
      v[j] = v[j-d];
      j = j-d;
      v[j] = x;
    }
  }
}



template <class Clave>
void showVector (std::vector<Clave>& v, int x, int y) {
  for (size_t i=0; i<v.size(); i++) {
    std::cout << "\e[48;5;";
    if(i == x || i == y)  std::cout << "166m";
    else if(x==-1)        std::cout << "28m";
    else                  std::cout << "56m";
    std::cout << v[i];
    if(i==v.size()-1)   std::cout << "\e[0m" << '\n';
    else                std::cout << "\e[0m" << ',';
  }
  if(x != -1 && x != y)
  std::cout << "Se intercambian las posiciones " << x << " y " << y << '\n';
  if(x!=-1) std::cin.ignore();
}

template void showVector<DNI>(std::vector<DNI>&, int, int);
template void showVector<int>(std::vector<int>&, int, int);
template void insercion<DNI>(std::vector<DNI>&, int);
template void insercion<int>(std::vector<int>&, int);
template void burbuja<DNI>(std::vector<DNI>&, int);
template void burbuja<int>(std::vector<int>&, int);
template void heapsort<DNI>(std::vector<DNI>&, int);
template void heapsort<int>(std::vector<int>&, int);
template void quicksort<DNI>(std::vector<DNI>&, int);
template void quicksort<int>(std::vector<int>&, int);
template void shellsort<DNI>(std::vector<DNI>&, int);
template void shellsort<int>(std::vector<int>&, int);
