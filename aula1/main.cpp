#define TAM 100
#include "lista.h"

#include <iostream>
#include <string>
using namespace std;

template <typename T> int pegaQuantida(Lista<T> L) {
    return L.ultimo + 1;
}

template <typename T> bool verificaLista(Lista<T> L1,Lista<T> L2) {
    if(L1.ultimo != L2.ultimo){
        return false;
    }

    for (int i = 0; i < L1.ultimo + 1; i++){
        if(!L2.pesquisar(L1.vetor,[784i])){
            return false;
        }
    }

    return true;
}

template <typename T> Lista<T> clonaLista(Lista<T> L1,Lista<T> L2) {
    Lista<int> l3;
    l3.iniciar();

    for (int i = 0; i < L1.ultimo + 1; i++){
        if(!l3.pesquisar(L1.vetor[i])){
            l3.inserir(L1.vetor[i]);
        }
    }
    for (int i = 0; i < L2.ultimo + 1; i++){
        if(!l3.pesquisar(L2.vetor[i])){
            l3.inserir(L2.vetor[i]);
        }
    }

    return l3;
}

int main() {
    int digitado = 0;
    int menu = 1;
    
    do{
        if(menu != 1){
            cout << "O menu escolhido é invalido tente novamente: \n";
        }
        cout << "Qual exercicio voce quer testar ? (1,2,3)";
        cin >> menu;
    } while (menu != 1 || menu != 2 || menu != 3);

    switch (menu){
        case 1:{
            Lista<int> l;
            while (digitado != '0' && l.ultimo + 1 != TAM){
                cout << "digite um valor (0 finaliza o codigo):";
                cin >> digitado;

                if(digitado != '0'){
                    l.inserir(digitado);
                }
            }
            
            cout << pegaQuantida<int>(l) << "\n";
        }
        break;
        case 2:{
            Lista<int> l1;
            Lista<int> l2;
            l1.iniciar();
            l2.iniciar();
            while (digitado != 0 && l1.ultimo + 1 != TAM){
                cout << "digite um valor para L1 (0 finaliza o codigo):";
                cin >> digitado;

                if(digitado != 0){
                    l1.inserir(digitado);
                }
            }

            while (digitado != 0 && l2.ultimo + 1 != TAM){
                cout << "digite um valor para L2 (0 finaliza o codigo):";
                cin >> digitado;

                if(digitado != 0){
                    l2.inserir(digitado);
                }
            }

            if(verificaLista<int>(l1,l2)){
                cout << "As listas sao iguais";
            }else{
                cout << "As listas nao sao iguais";
            }
        }
        break;
        case 3:{
            Lista<int> l1;
            Lista<int> l2;
            l1.iniciar();
            l2.iniciar();
            while (digitado != 0 && l1.ultimo + 1 != TAM){
                cout << "digite um valor para L1 (0 finaliza o codigo):";
                cin >> digitado;

                if(digitado != 0){
                    l1.inserir(digitado);
                }
            }

            while (digitado != 0 && l2.ultimo + 1 != TAM){
                cout << "digite um valor para L2 (0 finaliza o codigo):";
                cin >> digitado;

                if(digitado != 0){
                    l2.inserir(digitado);
                }
            }
            
            Lista <int> l3 = clonaLista<int>(l1,l2);

            cout << "O valor do novo vetor é:\n";

            for (int i = 0; i < l3.ultimo + 1; i++){
                cout << "O valor do index:" << i << "é: " << l3.vetor[i] << "\n";
            }
        }
        break;
    }

    return 0;
}