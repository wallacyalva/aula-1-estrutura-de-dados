#ifndef TAM
#define TAM 50
#endif
using namespace std;
#include <iostream>
#include <string>
#include <type_traits>

template <typename T> struct No{
    T valor;
    No proximo = NULL;
};

template <typename T> struct Lista{
    T vetor(int index){

    };
    int ultimo = -1;
    int quantidade = 0;

    bool iniciar(){
        ultimo = -1;

        return true;
    };

    void reOrdenar(int indexBase = 0){
        int index = indexBase;

        while (index < ultimo) {
            vetor[index] = vetor[index + 1];
            index++;
        }
        ultimo--;
    };
    bool inserir(T valor,bool ordenar = false ,int index = -1){
        if (index < 0){
            index = ultimo + 1;
        }

        if(ordenar){
            int ultimoIndex = ultimo;
            while(ultimoIndex != -1){
                if(vetor[ultimoIndex] > valor){
                    vetor[ultimoIndex + 1] = vetor[ultimoIndex];
                    ultimoIndex--;
                }else{
                    vetor[ultimoIndex + 1] = valor;
                    ultimoIndex = -1;
                }
            }
        }else{
            vetor[index] = valor;
        }

        ultimo = index;

        return true;
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
        reOrdenar(index);

        return true;
    };
    bool mostrar(){
        for (int i = 0; i <= ultimo; i++){
            cout << vetor[i] << ((i != ultimo) ? "," : "\n");
        }
        return true;
    }
};
