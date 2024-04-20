#include "celula.h"

template <typename T>
Celula<T>::Celula(const T &info){
    dado = info;
    prox = 0;
    ant = 0;
}

template <typename T>
void Celula<T>::setDado(T info){
    dado = info;
}

template <typename T>
T Celula<T>::getDado() const{
    return dado;
}

template <typename T>
bool operator == (const Celula <T> &c1, const Celula <T> &c2){
    return ( (c1.prox == c2.prox) && (c1.ant == c2.ant) && (c1.dado == c2.dado) );
}

template <typename T>
Celula<T>::~Celula(){
    
}

template class Celula <std::string>;