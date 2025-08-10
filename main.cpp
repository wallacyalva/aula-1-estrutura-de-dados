#define TAM 100
#include "lista.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    Lista<string> l;
    l.iniciar();

    // opcional: marcar como vazia se sua Lista usa ultimo = 0 como "ocupado"
    // se você preferir que uma lista vazia tenha ultimo = -1, descomente:
    // l.ultimo = -1;

    // inserir alguns valores
    l.inserir("um");
    l.inserir("dois");
    l.inserir("tres", 1); // insere "tres" na posição 1 (desloca lógica depende da sua implementação)

    cout << "Conteúdo da lista: ";
    l.mostrar();

    int pos = l.pesquisar("tres");
    if (pos != -1)
        cout << "\"tres\" encontrado na posição " << pos << "\n";
    else
        cout << "\"tres\" não encontrado\n";

    // remover e mostrar de novo
    if (l.retirar("tres")) {
        cout << "Depois de retirar \"tres\": ";
        l.mostrar();
    } else {
        cout << "Não foi possível retirar \"tres\" (não encontrado)\n";
    }

    return 0;
}