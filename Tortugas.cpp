#include <iostream>
using namespace std;

const int MAX_TORTUGAS = 5607;    // Máximo número de tortugas
const int PESO_MAXIMO = 10000000; // Peso muy alto para representar un límite exagerado

int peso[MAX_TORTUGAS];   // Arreglo para almacenar el peso de cada tortuga
int fuerza[MAX_TORTUGAS]; // Arreglo para almacenar la fuerza de cada tortuga
int dp[MAX_TORTUGAS + 1]; // Arreglo de DP para el peso mínimo de una pila con cierta altura

// Función para ordenar las tortugas por su fuerza usando un algoritmo de burbuja
void ordenarTortugas(int n)
{
  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = 0; j < n - i - 1; ++j)
    {
      if (fuerza[j] > fuerza[j + 1])
      {
        // Intercambiar peso de las tortugas
        int tempPeso = peso[j];
        peso[j] = peso[j + 1];
        peso[j + 1] = tempPeso;

        // Intercambiar fuerza de las tortugas
        int tempFuerza = fuerza[j];
        fuerza[j] = fuerza[j + 1];
        fuerza[j + 1] = tempFuerza;
      }
    }
  }
}

int main(){
  int p, f;
  int n = 0; // Contador de tortugas

  // Leer datos de entrada de cada tortuga
  while (cin >> p >> f)
  {
    peso[n] = p;
    fuerza[n] = f;
    ++n;
  }

  // Ordenar tortugas por su fuerza para facilitar la construcción de la pila
  ordenarTortugas(n);

  // Inicializar dp con un valor grande para representar peso imposible
  for (int i = 0; i <= n; ++i)
  {
    dp[i] = PESO_MAXIMO;
  }
  dp[0] = 0; // Peso de una pila vacía es 0

  int alturaMaxima = 0; // Máxima altura de la pila de tortugas que se puede construir

  // Intentar agregar cada tortuga a una pila
  for (int i = 0; i < n; ++i)
  {
    // Recorrer dp desde el final para evitar sobrescribir valores previos
    for (int j = alturaMaxima; j >= 0; --j)
    {
      // Verificar si podemos agregar la tortuga actual sin exceder su fuerza
      if (dp[j] <= fuerza[i] - peso[i])
      {
        // Actualizar el peso mínimo para una pila de altura j+1 si esta combinación es válida
        dp[j + 1] = (dp[j + 1] < dp[j] + peso[i]) ? dp[j + 1] : (dp[j] + peso[i]);
        // Actualizar la altura máxima alcanzada
        alturaMaxima = (alturaMaxima > j + 1) ? alturaMaxima : j + 1;
      }
    }
  }

  // Imprimir la altura máxima de la pila que se puede construir sin que la tortuga ripee
  cout << alturaMaxima << endl;

  return 0;
}
