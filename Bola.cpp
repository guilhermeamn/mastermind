#include "Bola.h"

template <typename T>
Bola<T>::Bola(){

}

template <typename T>
Bola<T>::Bola(const T &cor){
	setCor(cor);
}

template <typename T>
void Bola<T>::setCor(T cor){
	m_cor = cor;
}

template <typename T>
T Bola<T>::getCor() const{
	return m_cor;
}

template <typename T>
Bola<T>::~Bola(){

}

template class Bola <string>;