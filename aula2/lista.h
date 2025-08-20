using namespace std;
#include <iostream>
#include <string>

template <typename T> struct No{
    T valor;
    No <T> *next = NULL;
};

template <typename T> struct Lista{
    No <T> *comeco = NULL, *fim = NULL;
    int count = 0;

    bool iniciar(){
        comeco = NULL;
        fim = NULL;
        count = 0;
        return true;
    };

    bool inserir(T valor,bool ordenar = false ,int index = -1){
        No <T> *novo = new No<T>;
        if( novo == NULL ){
            return false
        };
        novo->valor = valor;
        novo->next = NULL;
        
        // Lista vazia
        if( comeco == NULL ){ 
            comeco = novo;
            fim = novo;
            return true;
        }
        
        // Insere no começo
        if( valor < comeco->valor ){
            novo->next = comeco;
            comeco = novo;
            return true;
        }

        // Insere no final
        if( valor > fim->valor ){
            fim->next = novo;
            fim = novo;
            return true;
        }

        // Insere no meio da lista
        No <T> *ant = comeco;
        No <T> *prox = ant->next;
        while( prox != NULL ){
            if( ant->valor < valor && valor < prox->valor ){
                ant->next = novo;
                novo->next = prox;
                return true;
            }
            ant = prox;
            prox = ant->next;
        }

        return false;
    };
    
    No <T> * pesquisar(T valor){
        No <T> *aux = comeco;

        while( aux != NULL ){
            if( aux->valor == valor ) return aux;
            aux = aux->next;
        }
        return NULL;
    };

    bool retirar(T valor){
        No <T> *ant = NULL, *aux = comeco;

        while( aux != NULL ){
            if( valor == aux->valor ) break;
            ant = aux;
            aux = aux->next;
        }
        if( aux == NULL ) return false;

        if( aux == comeco && aux == fim ){ // Unico elemento
            comeco = NULL;
            fim = NULL;
            delete aux;
            return true;
        }
        if( aux == comeco ){ // Retirando o primeiro
            comeco = aux->next;
            delete aux;
            return true;
        }
        if( aux == fim ){ // Retirando o ultimo
            ant->next = NULL;
            fim = ant;
            delete aux;
            return true;
        }
        // Retirando do meio
        ant->next = aux->next;
        delete aux;
        return true;
    };

    bool mostrar(){
        No <T> *aux = comeco;

        while( aux != NULL ){
            cout << aux->valor << ((aux->next != NULL) ? "," : "\n");
            aux = aux->next;
        }
        return true;
    }

    int comprimento(){
        No <T> *aux = comeco;
        int count = 0;

        while( aux != NULL ){
            aux = aux->next;
            count++;
        }
    }
    
};
