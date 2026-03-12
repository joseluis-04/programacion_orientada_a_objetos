#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0)); 

    int jugador, computadora;

    cout << "🥊 PIEDRA, PAPEL O TIJERA 🥊\n";
    cout << "1 = Piedra\n2 = Papel\n3 = Tijera\n";
    cout << "Elige una opcion: ";
    cin >> jugador;

    computadora = rand() % 3 + 1;

    cout << "La computadora eligio: " << computadora << endl;

    if (jugador == computadora) {
        cout << "Empate!\n";
    }
    else if ((jugador == 1 && computadora == 3) ||
             (jugador == 2 && computadora == 1) ||
             (jugador == 3 && computadora == 2)) {
        cout << "Ganaste!\n";
    }
    else {
        cout << "Perdiste!\n";
    }

    return 0;
}