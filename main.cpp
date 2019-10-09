#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

bool validarRepeticao(vector <int> valores, int tamanho, int valor);
void GeradorAleatorios(vector <int> &numeros, int qtdNumeros, int Limite);
void imprimirOpcoes(int inicio, int final, vector <double> listaPrecos);
void imprimirNumeros(vector <int> numeros);
double calcularPreco( int QTDNumeros, vector <double> listaPrecos);
void MegaSena();
void Quina();
void Lotomania();
void Lotofacil();

int main() {

    MegaSena();

    return 0;
}

// Passando as instruções para as funções

void imprimirOpcoes(int inicio, int final, vector <double> listaPrecos){
    cout << "QTD DE JOGADAS: " << setw(50) << "PREÇO: " << endl;
    cout << fixed << setprecision(2);
    for(int i = inicio, j = 0; i<=final; i++, j++){
        cout << i << setw(50) << "R$ " << listaPrecos[j] << endl;
    }
}
void imprimirNumeros(vector <int> numeros){
    cout << "Numeros para jogar: {";
    for(int i = 0; i<numeros.size(); i++){
        if(i == (numeros.size()-1)){
            cout << numeros[i] << " }";
        }
        else {
            cout << numeros[i] << ",";
        }
    }
    cout << endl;
}
double calcularPreco( int QTDNumeros, vector <double> listaPrecos){
    double preco = 0;
    double QTDNumeros1 = QTDNumeros - 6;
    for(int i = 0; i< QTDNumeros; i++){
        if(QTDNumeros1 == i){
            preco = listaPrecos[i];
        }
    }

    return preco;
}
bool validarRepeticao(vector <int> valores, int tamanho, int valor){

    for (int i=0; i<tamanho; i++){
        if(valores[i] == valor) {
            return true;
        }
    }
    return false;
}
void GeradorAleatorios(vector <int> &numeros, int qtdNumeros, int Limite){

    srand(time(NULL));
    int v;
    for(int i=0; i<qtdNumeros; i++){

         v = rand() % Limite;

        while(validarRepeticao(numeros,i,v)){

            v = rand() % Limite;

        }
        numeros.push_back(v);
    }
}
void MegaSena(){

    system("cls");
    cout << setw(25) << "SEJA BEM-VINDO AO SORTEADOR DA MEGA-SENA" << endl << endl;

    vector <double> listaDePrecos = {3.50, 24.50, 90.00, 294.00, 735.00, 1617.00, 3243.00, 6006.00, 10510.00, 17517.00};
    vector <int> numerosAleatorios;
    numerosAleatorios.clear();
    int opcao, cartelas;
    double precoPagar = 0;

    imprimirOpcoes(6,15, listaDePrecos);
    cout << endl << "Escolha quantos cartelas deseja jogar: ";
    cin >> cartelas;

    for(int i = 0; i<cartelas; i++){
        cout << "Escolha quantos numeros deseja jogar: ";
        cin >> opcao;

        switch(opcao){
            case 6:
                GeradorAleatorios(numerosAleatorios, 6, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(6 , listaDePrecos);
                break;
            case 7:
                GeradorAleatorios(numerosAleatorios, 7, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(7, listaDePrecos);
                break;
            case 8:
                GeradorAleatorios(numerosAleatorios, 8, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(8, listaDePrecos);
                break;
            case 9:
                GeradorAleatorios(numerosAleatorios, 9, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(9, listaDePrecos);
                break;
            case 10:
                GeradorAleatorios(numerosAleatorios, 10, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(10, listaDePrecos);
                break;
            case 11:
                GeradorAleatorios(numerosAleatorios, 11, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(11, listaDePrecos);
                break;
            case 12:
                GeradorAleatorios(numerosAleatorios, 12, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(12, listaDePrecos);
                break;
            case 13:
                GeradorAleatorios(numerosAleatorios, 13, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(13, listaDePrecos);
                break;
            case 14:
                GeradorAleatorios(numerosAleatorios, 14, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(14, listaDePrecos);
                break;
            case 15:
                GeradorAleatorios(numerosAleatorios, 15, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(15, listaDePrecos);
                break;
        }
        numerosAleatorios.clear();
    }

    cout << "A valor a ser pago = " << precoPagar << endl;
}