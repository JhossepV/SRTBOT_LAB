#include <iostream>
using namespace std;

int main(){
  //Try 5 -_-
  int m, n, t;

  // Leemos casos hasta EOF
  while (cin >> m >> n >> t)
  {
    // Array para programación dinámica
    int dp[10001];

    // Inicializamos el array con -1
    for (int i = 0; i <= t; i++)
    {
      dp[i] = -1;
    }
    dp[0] = 0; // Caso base: 0 minutos = 0 hamburguesas

    // Calculamos la cantidad máxima de hamburguesas para cada minuto
    for (int tiempo = 0; tiempo <= t; tiempo++)
    {
      if (dp[tiempo] != -1)
      {
        // Intentamos agregar una hamburguesa que toma m minutos
        if (tiempo + m <= t)
        {
          if (dp[tiempo + m] < dp[tiempo] + 1)
          {
            dp[tiempo + m] = dp[tiempo] + 1;
          }
        }

        // Intentamos agregar una hamburguesa que toma n minutos
        if (tiempo + n <= t)
        {
          if (dp[tiempo + n] < dp[tiempo] + 1)
          {
            dp[tiempo + n] = dp[tiempo] + 1;
          }
        }
      }
    }

    // Buscamos la mejor solución de atrás hacia adelante
    int maxBurgers = 0;
    int tiempoSobrante = 0;

    for (int tiempo = t; tiempo >= 0; tiempo--)
    {
      if (dp[tiempo] != -1)
      {
        maxBurgers = dp[tiempo];
        tiempoSobrante = t - tiempo;
        break;
      }
    }

    // Print del resultado
    if (tiempoSobrante == 0)
    {
      cout << maxBurgers << endl;
    }
    else
    {
      cout << maxBurgers << " " << tiempoSobrante << endl;
    }
  }

  return 0;
}