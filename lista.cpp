#include "lista.h"

template <typename T>
Lista<T>::Lista(){
    cabeca = 0;
    cauda = 0;
    tamanho = 0;
}

template <typename T>
int Lista<T>::vazia() const{
    if(tamanho == 0) return 1;
    else return 0;
}

template <typename T>
int Lista<T>::getTamanho() const{
    return tamanho;
}

template <typename T>
void Lista<T>::setTamanho(int tam){
    tamanho = tam;
}

template <typename T>
Celula <T> *Lista<T>::getCabeca() const{
    if(vazia() == 1) return nullptr;
    else return cabeca;
}

template <typename T>
void Lista<T>::setCabeca(Celula <T> *head){
    cabeca = head;
}

template <typename T>
Celula <T> *Lista<T>::getCauda() const{
    if(vazia() == 1) return nullptr;
    else return cauda;
}

template <typename T>
void Lista<T>::setCauda(Celula <T> *tail){
    cauda = tail;
}

template <typename T>
T Lista<T>::lista_dado(const Celula <T> *c){
    return c->getDado();
}

template <typename T>
T Lista<T>::lista_dado_AUXILIAR(int posicao){
    Celula <T> *aux = cabeca;
    while(posicao != 1 && aux != 0){
        aux = aux->prox;
        posicao--;
    }
    return aux->getDado();
}

template <typename T>
int Lista<T>::lista_eh_cabeca(const Celula <T> *c){
    if(vazia() == 1) return -1;
    if(c == cabeca) return 1;
    else return 0;
}

template <typename T>
int Lista<T>::lista_eh_cauda(const Celula <T> *c){
    if(vazia() == 1) return -1;
    if(c == cauda) return 1;
    else return 0;
}

template <typename T>
int Lista<T>::insere_proximo(Celula <T> *c, const T &elem){    
    Celula <T> *nova = new Celula<T>(elem);

    nova->prox = 0;
    nova->ant = 0;
    
    if(vazia() == 1){
        cabeca = nova;
        cauda = nova;
    }
    
    else if(lista_eh_cauda(c) == 1){
        nova->ant = cauda;
        cauda->prox = nova;
        cauda = nova;
    }
    
    else{
        nova->prox = c->prox;
        nova->ant = c;
        c->prox->ant = nova;
        c->prox = nova;
    }
    
    tamanho++;
    return 1;
}

template <typename T>
int Lista<T>::remove(Celula <T> *c){
    if(vazia()) return 0;
    
    if(tamanho == 1){
        cabeca = 0;
        cauda = 0;
    }
    
    else if(lista_eh_cabeca(c) == 1){
        cabeca = c->prox;
        c->prox->ant = 0;
        c->prox = 0;
    }
    
    else if(lista_eh_cauda(c) == 1){
        cauda = c->ant;
        c->ant->prox = 0;
        c->ant = 0;
    }
    
    else{
        c->ant->prox = c->prox;
        c->prox->ant = c->ant;
        c->prox = 0;
        c->ant = 0;
    }
    
    delete c;
    tamanho--;
    return 1;
}

template <typename T>
bool Lista<T>::lista_pertence(T dado){
    Celula <T> *aux = cabeca;
    while(aux != 0){
        if(aux->getDado() == dado) return true;
        aux = aux->prox;
    }
    return false;
}

template <typename T>
void Lista<T>::imprime(){
    if(vazia() == 1){
        std::cout << "LISTA VAZIA\n";
        return;
    }
    
    Celula <T> *aux = cabeca;
    
    while(aux != 0){
        if(aux->prox != 0) std::cout << aux->dado << " ";
        else std::cout << aux->dado;
        aux = aux->prox;
    }
}

template <typename T>
Lista<T>::~Lista(){
    if(vazia() == 0){
        Celula <T> *atual = cabeca;
        Celula <T> *tmp;
        while(atual != 0){
            tmp = atual;
            atual = atual->prox;
            delete tmp;
        }
    }
}

template class Lista <std::string>;
