#include "pino.h"

template <typename T>
Pino<T>::Pino(const T &cor, const int &qtd) : color{cor}, quantidade{qtd} {
  //setCor(cor);
}

template <typename T>
Pino<T>::Pino(){
	setQuantidade(0);
}

template <typename T>
void Pino<T>::setCor(T cor){
  color = cor;
}

template <typename T>
void Pino<T>::setQuantidade(int qtd){
	quantidade = qtd;
}

template <typename T>
T Pino<T>::getCor()const{
  return color;
}

template <typename T>
int Pino<T>::getQuantidade() const{
	return quantidade;
}

template <typename T>
Pino<T>::~Pino(){
}

//para o compilador saber interpretar o template e criar uma classe especifica (ou fazer tudo no .h)
template class Pino <string>;
/*se usasse outros teria que botar aqui tambem
 * template class Pino <float>
 * template class Pino <int>
 * etc
 */
