#define TAM 100
#include "lista.h"

#include <iostream>
#include <string>
using namespace std;

template <typename T> int pegaQuantida(Lista<T> L) {
    return L.ultimo + 1;
}

template <typename T> bool saoIguais(Lista<T> L) {
    // return L.ultimo + 1;
}

int main() {
    int digitado = 0;
    int menu = 1;
    
    // do{
    //     if(menu != 1){
    //         cout << "O menu escolhido é invalido tente novamente: \n";
    //     }
    //     cout << "Qual exercicio voce quer testar ? (1,2,3)";
    //     cin >> menu;
    // } while (menu != 1 || menu != 2 || menu != 3);

    // switch (menu){
    //     case 1:{
    //         Lista<int> l;
    //         while (digitado != '0' && l.ultimo + 1 != TAM){
    //             cout << "digite um valor (0 finaliza o codigo):";
    //             cin >> digitado;

    //             if(digitado != '0'){
    //                 l.inserir(digitado);
    //             }
    //         }
            
    //         cout << pegaQuantida<int>(l) << "\n";
    //     }
    //     break;
    //     case 2:{
            
    //     }
    //     break;
    //     case 3:{

    //     }
    //     break;
    // }



     
    Lista<int> l1;
    Lista<int> l2;

    l1.inserir(1);
    l1.inserir(2);
    l1.inserir(3);
    l1.inserir(4);
    l1.inserir(5);

    l2.inserir(5);
    l2.inserir(2);
    l2.inserir(4);
    l2.inserir(3);
    l2.inserir(1);

    



    return 0;
}