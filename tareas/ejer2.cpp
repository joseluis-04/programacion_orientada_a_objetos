#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int GenerarJugada() {
    return rand() % 3 + 1;
}


int DeterminarGanador(int jugador, int computadora) {

    if (jugador == computadora)
        return 0; 

    if ((jugador == 1 && computadora == 3) ||
        (jugador == 2 && computadora == 1) ||
        (jugador == 3 && computadora == 2))
        return 1; 

    return -1; 
}

void ImprimirResultado(int resultado) {

    if (resultado == 0)
        cout << "Empate!\n";
    else if (resultado == 1)
        cout << "Ganaste!\n";
    else
        cout << "Perdiste!\n";
}

void JugarPartida(int rondas) {

    int puntosJugador = 0;
    int puntosComputadora = 0;

    for (int i = 1; i <= rondas; i++) {

        int jugador;

        cout << "\nRonda " << i << endl;
        cout << "1=Piedra  2=Papel  3=Tijera: ";
        cin >> jugador;

        int computadora = GenerarJugada();

        cout << "Computadora eligio: " << computadora << endl;

        int resultado = DeterminarGanador(jugador, computadora);

        if (resultado == 1)
            puntosJugador++;
        else if (resultado == -1)
            puntosComputadora++;

        ImprimirResultado(resultado);

        cout << "Marcador -> Jugador: "
             << puntosJugador
             << " | Computadora: "
             << puntosComputadora
             << endl;
    }

    cout << "\n🏆 Resultado final:\n";
    cout << "Jugador: " << puntosJugador
         << " | Computadora: "
         << puntosComputadora
         << endl;
}

int main() {

    srand(time(0));

    cout << "🥊 PIEDRA, PAPEL O TIJERA 🥊\n";

    int rondas;

    cout << "Cuantas rondas deseas jugar? ";
    cin >> rondas;

    JugarPartida(rondas);

    return 0;
}