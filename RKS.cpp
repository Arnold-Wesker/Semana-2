// Primeramente diseñé una estructura para guardar cada número junto con su frecuencia y la posición de su 
// primera aparición. Luego, use el bubble sort para ordenar los números según su frecuencia y posicion,
// esto garantiza que los números con mayor frecuencia salgan primero y, si llega a haber un empate, 
// los números que aparecen primero en el input también salen primero en el output.
#include <iostream>
#include <vector>

struct Numero {
    int valor;
    int cantidad;
    int primera_aparicion;
};

void bubbleSort(std::vector<Numero>& numeros) {
    for (int i = 0; i < numeros.size(); i++) {
        for (int j = 0; j < numeros.size() - i - 1; j++) {
            if (numeros[j].cantidad < numeros[j + 1].cantidad || 
                (numeros[j].cantidad == numeros[j + 1].cantidad && numeros[j].primera_aparicion > numeros[j + 1].primera_aparicion)) {
                Numero temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> entradas(N);
    std::vector<Numero> numeros;

    for (int i = 0; i < N; i++) {
        std::cin >> entradas[i];
        bool identificado = false;
        for (auto &num : numeros) {
            if (num.valor == entradas[i]) {
                num.cantidad++;
                identificado = true;
                break;
            }
        }
        if (!identificado) {
            numeros.push_back({entradas[i], 1, i});
        }
    }

    bubbleSort(numeros);

    for (const auto &num : numeros) {
        for (int i = 0; i < num.cantidad; i++) {
            std::cout << num.valor << " ";
        }
    }

    return 0;
}
