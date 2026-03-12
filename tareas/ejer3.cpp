#include <iostream>
using namespace std;
bool EsTrio(int d1, int d2, int d3) {
    return (d1 == d2 && d2 == d3);
}
bool EsEscalera(int d1, int d2, int d3) {
    return (d1 + 1 == d2 && d2 + 1 == d3);
}
int CalcularPuntaje(int d1, int d2, int d3) {
    if (EsTrio(d1, d2, d3)) {
        return 50;
    }
    else if (EsEscalera(d1, d2, d3)) {
        return 25;
    }
    else {
        return d1 + d2 + d3;
    }
}
void ImprimirMarcador(int ronda, int puntosRonda, int puntosAcumulados) {
    cout << "Ronda " << ronda
         << " | Puntos ganados: " << puntosRonda
         << " | Total acumulado: " << puntosAcumulados
         << endl;
}
void JugarPartida(int cantidadRondas) {

    int puntajeTotal = 0;

    for (int i = 1; i <= cantidadRondas; i++) {

        int d1, d2, d3;

        cout << "\nRonda " << i << endl;
        cout << "Ingrese 3 dados ordenados (d1 <= d2 <= d3): ";
        cin >> d1 >> d2 >> d3;

        int puntos = CalcularPuntaje(d1, d2, d3);

        puntajeTotal += puntos;

        ImprimirMarcador(i, puntos, puntajeTotal);
    }

    cout << "\n🎉 Puntaje final de la partida: "
         << puntajeTotal << endl;
}

int main() {

    cout << "🎲 Bienvenido al Mini-Cacho 🎲" << endl;

    int rondas;

    cout << "¿Cuántas rondas deseas jugar? ";
    cin >> rondas;

    JugarPartida(rondas);

    return 0;
}