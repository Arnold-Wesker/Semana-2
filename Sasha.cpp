// En este caso use el bubble sort, ya que al tener los elementos en orden ascendente, las diferencias entre los elementos consecutivos
// se minimizan. Luego, cree una funcion llamada calcularBeauty en la que como su nombre dice calculé la beauty del array sumando las 
// diferencias entre los elementos cercanos en el vector. Por ultimo, use la funcion main para los casos de prueba y para estos
// use el bubble sort y calculé su beauty. 
#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& g) {
    bool intercambio;
    do {
        intercambio = false;
        for(size_t i=0; i<g.size()-1; i++) {
            if(g[i] > g[i+1]) {
                swap(g[i], g[i+1]);
                intercambio = true;
            }
        }
    } while(intercambio);
}

int calcularBeauty(vector<int>& g) {
    int beauty = 0;
    for(size_t i=1; i<g.size(); i++)
        beauty += g[i] - g[i-1];
    return beauty;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int caso=0; caso<t; caso++) {
        int longitud;
        cin >> longitud;
        vector<int> a(longitud);
        for(int i=0; i<longitud; i++)
            cin >> a[i];
        bubbleSort(a);
        cout << calcularBeauty(a) << "\n";
    }
    return 0;
}


