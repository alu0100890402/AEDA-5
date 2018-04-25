#include "../DNI/DNI.hpp"

template <class Clave>
void insercion (std::vector<Clave>&, int);

template <class Clave>
void burbuja (std::vector<Clave>&, int);

template <class Clave>
void heapsort (std::vector<Clave>&, int);
template <class Clave>
void baja (int, std::vector<Clave>&, int);

template <class Clave>
void quicksort (std::vector<Clave>&, int);
template <class Clave>
void qsort (std::vector<Clave>&, int, int);

template <class Clave>
void shellsort (std::vector<Clave>&, int);
template <class Clave>
void deltasort (int, std::vector<Clave>&, int);

template <class Clave>
void showVector(std::vector<Clave>&, int=-1, int=-1);
