#include "../entities/Funciones/Funciones.hpp"

int MAX=0, MIN=1000000, CURRENT=0;
bool DEMO = false;

float* func(void(*fp)(std::vector<DNI>&, int), std::vector<DNI>*, int);
void estadisticas (float*, float*, float*, float*, float*);

int main() {

  int N, modo, nPruebas;
  std::cout << "Bienvenido al programa de Algoritmos de ordenacion" << '\n';
  std::cout << "Elije el modo de ejecución:\n0. Demostracion\n1. Estadistica\t";
  std::cin >> modo;
  std::cout << "Elije el numero de elementos del vector: ";
  std::cin >> N;
  if(modo == 0) DEMO = true;
  if(!DEMO) {
    std::cout << "Selecciona el numero de pruebas: ";
    std::cin >> nPruebas;
    std::vector<DNI> vIns[nPruebas];
    std::vector<DNI> vBur[nPruebas];
    std::vector<DNI> vHeap[nPruebas];
    std::vector<DNI> vQuick[nPruebas];
    std::vector<DNI> vShell[nPruebas];
    srand(time(NULL));
    for (size_t j=0; j<nPruebas; j++) {
      for (size_t i=0; i<N; i++) {
        vIns[j].push_back(DNI(true));
        vBur[j].push_back(DNI(true));
        vHeap[j].push_back(DNI(true));
        vQuick[j].push_back(DNI(true));
        vShell[j].push_back(DNI(true));
      }
    }
    float *rIns = func(insercion, vIns, nPruebas);
    float *rBur = func(burbuja, vBur, nPruebas);
    float *rHeap = func(heapsort, vHeap, nPruebas);
    float *rQuick = func(quicksort, vQuick, nPruebas);
    float *rShell = func(shellsort, vShell, nPruebas);
    estadisticas(rIns, rBur, rHeap, rQuick, rShell);
  }
  else {
    if(nPruebas > 25) nPruebas = 25;
    std::vector<DNI> v;
    srand(time(NULL));
    for (size_t i=0; i<N; i++) {
      v.push_back(DNI(true));
    }
    int opcion;
    std::cout << "Seleccion el algoritmo a ejecutar:" << '\n';
    std::cout << "0. Insercion\n1. Burbuja\n2. Heapsort\n3. Quicksort\n4. Shellsort\t";
    std::cin >> opcion;
    std::cin.ignore();
    switch(opcion) {
      case 1: burbuja<DNI>(v, v.size()); break;
      case 2: heapsort<DNI>(v, v.size()); break;
      case 3: quicksort<DNI>(v, v.size()); break;
      case 4: shellsort<DNI>(v, v.size()); break;
      default:insercion<DNI>(v, v.size()); break;
    }
    showVector(v);
  }

  return 0;
}

void estadisticas (float *rIns, float *rBur, float *rHeap, float *rQuick, float *rShell) {
    std::cout << '\n' << "\tNumero de Comparaciones\n";
    std::cout << "\tMinimo\tMedio\tMaximo" << '\n';
    std::cout << "Insercion: " << rIns[0] << "\t" << rIns[2] << "\t" << rIns[1] << '\n';
    std::cout << "Burbuja:   " << rBur[0] << "\t" << rBur[2] << "\t" << rBur[1] << '\n';
    std::cout << "Heapsort:  " << rHeap[0] << "\t" << rHeap[2] << "\t" << rHeap[1] << '\n';
    std::cout << "Quicksort: " << rQuick[0] << "\t" << rQuick[2] << "\t" << rQuick[1] << '\n';
    std::cout << "Shellsort: " << rShell[0] << "\t" << rShell[2] << "\t" << rShell[1] << '\n';
}

float* func(void(*fp)(std::vector<DNI>&, int), std::vector<DNI>* v, int nPruebas) {
  float *resultados = new float[3];
  MAX=0; MIN=1000000; CURRENT=0; float media = CURRENT;
  for (size_t i=0; i<nPruebas; i++) {
    fp(v[i], v[i].size());
    // showVector(v[i]);
    if(CURRENT > MAX) MAX = CURRENT;
    if(CURRENT < MIN) MIN = CURRENT;
    media += CURRENT;
    CURRENT = 0;
  }
  resultados[0] = MIN;
  resultados[1] = MAX;
  resultados[2] = (media/nPruebas);
  return resultados;
}
