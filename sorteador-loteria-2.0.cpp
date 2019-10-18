#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <random>
#include <locale.h>


using namespace std;

random_device rd;
mt19937 mt(rd());

bool validarRepeticao(vector <int> valores, int tamanho, int valor);
void GeradorAleatorios(vector <int> &numeros, int qtdNumeros, int Limite);
void imprimirOpcoes(int inicio, int final, vector <double> listaPrecos);
void imprimirNumeros(vector <int> numeros);
double calcularPreco( int QTDNumeros, vector <double> listaPrecos, int inicio);
void MegaSena();
char menu();
void Quina();
void Lotomania();
void Lotofacil();

int main() {

     cout << setw(25) << "SEJA BEM-VINDO(A) AO SORTEADOR DE LOTERIA" << endl << endl;

    do{
        char modalidade = menu();
        switch(modalidade){
            case 'M':
                MegaSena();
                break;
            case 'Q':
                Quina();
                break;
            case 'L':
                Lotomania();
                break;
            case 'F':
                Lotofacil();
                break;
            case 'S':
                exit(0);
        }
    }while(true);
    return 0;
}

// Passando as instruções para as funções


void imprimirOpcoes(int inicio, int final, vector <double> listaPrecos){

    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "QTD DE DEZENAS: " << setw(11) << "|" << setw(28) << "PREÇO: " <<endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for(int i = inicio, j = 0; i<=final; i++, j++){
        if(i < 10){
            cout << i << setw(26) << "|" << setw(23) << "R$ " << listaPrecos[j] << endl;
        }
        else {
            cout << i << setw(25) << "|" << setw(23) << "R$ " << listaPrecos[j] <<  endl;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
}
void imprimirNumeros(vector <int> numeros){

    setlocale(LC_ALL, "Portuguese");

    cout << "Numeros para jogar: | ";
    for(int i = 0; i<(int)numeros.size(); i++){
       if(i < (numeros.size()/2)){
           if(i == (numeros.size()/2)-1){
               cout << numeros[i] << setw(2) << "|" << endl << setw(22)<<"| ";
           }
           else {
               cout << numeros[i] << ", ";
           }
       }
       else {
           if(i == numeros.size() - 1){
               cout << numeros[i] << setw(2) << "|";
           }
           else {
               cout << numeros[i] << ", ";
           }

       }
    }
    cout << endl << endl;
}

double calcularPreco( int QTDNumeros, vector <double> listaPrecos, int inicio){
    double preco = 0;
    double QTDNumeros1 = QTDNumeros - inicio;
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
            if(tamanho != 1) {
                return true;
            }
        }
    }
    return false;
}
void GeradorAleatorios(vector <int> &numeros, int qtdNumeros, int Limite){

    vector <int> teste;
    teste.clear();
    int valor;
    string testenado = "rd";
    std::uniform_int_distribution<int> dist(1.0,Limite);


    for(int i=0; i<qtdNumeros; i++){

        valor = dist(mt);
        teste.push_back(valor);

        while(validarRepeticao(teste,i,valor)){

            valor = dist(mt);
        }
        numeros.push_back(valor);
    }
}
void MegaSena(){

    system("cls");

    cout << setw(50) << "SEJA BEM-VINDO(A) AO SORTEADOR DA MEGA-SENA" << endl;

    vector <double> listaDePrecos = {3.50, 24.50, 90.00, 294.00, 735.00, 1617.00, 3243.00, 6006.00, 10510.00, 17517.00};
    vector <int> numerosAleatorios;
    numerosAleatorios.clear();
    int opcao, cartelas;
    double precoPagar = 0;

    imprimirOpcoes(6,15, listaDePrecos);
    cout << endl << "Escolha quantos cartelas deseja jogar: ";
    cin >> cartelas;

    for(int i = 0; i<cartelas; i++){
        cout << "Escolha quantos dezenas deseja jogar: ";
        cin >> opcao;
        while (opcao < 6 || opcao > 15)
        {
            cout << "Digite um valor válido: ";
            cin >> opcao;
        }

        GeradorAleatorios(numerosAleatorios,opcao, 60);
        imprimirNumeros(numerosAleatorios);
        precoPagar += calcularPreco(opcao, listaDePrecos, 6);

        numerosAleatorios.clear();

    }

    cout << "A valor a ser pago = R$ " << precoPagar << endl;
    system("pause");
    system("cls");
}

void Quina(){

    system("cls");

    cout << setw(50) << "SEJA BEM-VINDO(A) AO SORTEADOR DA QUINA" << endl;

    vector <double> listaDePrecos = {1.50, 9.00, 31.50, 84, 189, 378, 693, 1188, 1930.50, 3003, 4505.50};
    vector <int> numerosAleatorios;
    numerosAleatorios.clear();
    int opcao, cartelas;
    double precoPagar = 0;

    imprimirOpcoes(5,15, listaDePrecos);
    cout << endl << "Escolha quantos cartelas deseja jogar: ";
    cin >> cartelas;

    for(int i = 0; i<cartelas; i++){
        cout << "Escolha quantos dezenas deseja jogar: ";
        cin >> opcao;
        while (opcao < 5 || opcao > 15)
        {
            cout << "Digite um valor válido: ";
            cin >> opcao ;
        }

        GeradorAleatorios(numerosAleatorios,opcao, 80);
        imprimirNumeros(numerosAleatorios);
        precoPagar += calcularPreco(opcao, listaDePrecos, 5);

        numerosAleatorios.clear();
    }

    cout << "A valor a ser pago = R$ " << precoPagar << endl;
    system("pause");
    system("cls");
}

void Lotomania(){

    system("cls");

    cout << setw(50) << "SEJA BEM-VINDO(A) AO SORTEADOR DA LOTOMANIA" << endl;

    vector <double> listaDePrecos = {1.50};
    vector <int> numerosAleatorios;
    numerosAleatorios.clear();
    int cartelas;
    double precoPagar = 0;

    imprimirOpcoes(50,50, listaDePrecos);
    cout << endl << "Escolha quantos cartelas deseja jogar: ";
    cin >> cartelas;

    for(int i = 0; i<cartelas; i++){

        GeradorAleatorios(numerosAleatorios,50, 100);
        imprimirNumeros(numerosAleatorios);
        precoPagar += calcularPreco(50, listaDePrecos, 50);

        numerosAleatorios.clear();
    }

    cout << "A valor a ser pago = R$ " << precoPagar << endl;
    system("pause");
    system("cls");
}

void Lotofacil(){

    system("cls");

    cout << setw(50) << "SEJA BEM-VINDO(A) AO SORTEADOR DA LOTOFACIL" << endl;

    vector <double> listaDePrecos = {2, 32, 272, 1632};
    vector <int> numerosAleatorios;
    numerosAleatorios.clear();
    int opcao, cartelas;
    double precoPagar = 0;

    imprimirOpcoes(15,18, listaDePrecos);
    cout << endl << "Escolha quantos cartelas deseja jogar: ";
    cin >> cartelas;

    for(int i = 0; i<cartelas; i++){
        cout << "Escolha quantos dezenas deseja jogar: ";
        cin >> opcao;
        while (opcao < 15 || opcao > 18)
        {
            cout << "Digite um valor válido: ";
            cin >> opcao;
        }

        GeradorAleatorios(numerosAleatorios,opcao, 25);
        imprimirNumeros(numerosAleatorios);
        precoPagar += calcularPreco(opcao, listaDePrecos, 15);

        numerosAleatorios.clear();
    }

    cout << "A valor a ser pago = R$ " << precoPagar << endl << endl;
    system("pause");
    system("cls");
}
char menu(){

    char modalidade;
    cout << "Escolha uma modalidade:" << endl << endl;
    cout << "[M] Mega Sena" << endl <<
         "[Q] Quina" << endl <<
         "[L] Lotomania" << endl <<
         "[F] Lotofacil" << endl <<
         "[S] Sair" << endl;

    cin >> modalidade;

    while(modalidade != 'M' && modalidade != 'Q' && modalidade != 'L' && modalidade != 'F' && modalidade != 'F' && modalidade != 'S'){

        cout << endl << "Modalidade não encontrada, por favor escolha novamente: ";
        cin >> modalidade;
    }
    return modalidade;
}
