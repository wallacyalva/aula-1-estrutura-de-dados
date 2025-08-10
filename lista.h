#ifndef TAM
#define TAM 50
#endif
using namespace std;
#include <iostream>
#include <string>
#include <type_traits>

template <typename T> struct Lista{
    T vetor[TAM];
    int ultimo = -1;
    T valorPadrao(){
        if constexpr (is_same<T, bool>::value) {
            return false;
        } else if constexpr (is_same<T, char>::value) {
            return ' ';
        } else if constexpr (is_same<T, int>::value) {
            return 0;
        } else if constexpr (is_same<T, string>::value) {
            return "";
        } else {
            return T{};
        }
    };
    void iniciar(){
        T valorBase = valorPadrao();

        for (int i = 0; i < TAM; i++){
            vetor[i] = valorBase;
        }
    };
    void reOrdenar(int indexBase = 0){
        int index = indexBase;
        T valorBase = valorPadrao();

        while (index < ultimo) {
            vetor[index] = vetor[index + 1];
            index++;
        }
        vetor[ultimo] = valorBase;
        ultimo--;
    };
    void inserir(T valor, int index = -1){
        if (index < 0 || index >= TAM){ 
            index = ultimo + 1;
        }

        if(index < TAM){
            vetor[index] = valor;
            if(index > ultimo){
                ultimo = index;
            }
        }
    };
    int pesquisar(T valor){
        int index = 0;
        bool achado = false;
        
        while (!achado && index <= ultimo){
            if(vetor[index] == valor){
                achado = true;
            }else{
                index ++;
            }
        }
        
        return achado ? index : -1;
    };
    bool retirar(T valor){
        int index = pesquisar(valor);
        if(index == -1){
            return false;
        }

        T valorBase = valorPadrao();

        vetor[index] = valorBase;

        reOrdenar(index);

        return true;
    };
    void mostrar(){
        for (int i = 0; i <= ultimo; i++){
            cout << vetor[i] << ((i != ultimo) ? "," : "\n");
        }
    }
};