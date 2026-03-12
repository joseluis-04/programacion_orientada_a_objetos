#include <iostream>
using namespace std;

bool EsBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        return true;
    return false;
}
int ObtenerDiasDelMes(int mes, int anio) {

    if (mes == 2) { 
        if (EsBisiesto(anio))
            return 29;
        else
            return 28;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    return 31; 
}

bool EsFechaValida(int dia, int mes, int anio) {

    if (mes < 1 || mes > 12)
        return false;

    int maxDias = ObtenerDiasDelMes(mes, anio);

    if (dia < 1 || dia > maxDias)
        return false;

    return true;
}

void EjecutarSimulacion(int cantidadRondas) {

    int exitos = 0;

    for (int i = 0; i < cantidadRondas; i++) {

        int dia, mes, anio;
        cin >> dia >> mes >> anio;

        if (EsFechaValida(dia, mes, anio)) {
            cout << "Salto temporal completado" << endl;
            exitos++;
        } else {
            cout << "Falla catastrofica: Fecha inexistente" << endl;
        }
    }

    cout << "Saltos exitosos: "
         << exitos << " / "
         << cantidadRondas << endl;
}
int main() {

    int N;
    cin >> N;

    EjecutarSimulacion(N);

    return 0;
}