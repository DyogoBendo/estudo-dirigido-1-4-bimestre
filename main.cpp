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
void Inicio();

int main() {

    Inicio();
   

    return 0;
}

// Passando as instruções para as funções

void Inicio()
{
    int modalidade;
    system("cls");
    cout << setw(25) << "SEJA BEM-VINDO AO SORTEADOR DE LOTERIA" << endl << endl;
    cout << "Escolha uma modalidade:" << endl << endl;
    cout << "[1] Mega Sena" << endl <<
         "[2] Quina" << endl <<
         "[3] Lotomania" << endl <<
         "[4] Lotofacil" << endl; 
    cin >> modalidade; 
    
    if (modalidade == 1)
    {
        MegaSena();   
    }
    
    else if (modalidade == 2)
    {
        Quina();
    }
    
    else if (modalidade == 3)
    {
        Lotomania();   
    }
    
    else if (modalidade == 4)
    {
        Lotofacil();    
    }
    
    else
    {
        Inicio();
    }
    
}

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

        for(int j = 6; j<=15; j++){
            if(opcao == j){
                GeradorAleatorios(numerosAleatorios,j, 60);
                imprimirNumeros(numerosAleatorios);
                precoPagar += calcularPreco(j, listaDePrecos);
                break;
            }
        
        numerosAleatorios.clear();
    }

    cout << "A valor a ser pago = R$ " << precoPagar << endl;
}
