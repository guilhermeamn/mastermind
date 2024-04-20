#include "Tabuleiro.h"

template <typename T>
Tabuleiro<T>::Tabuleiro(const int &qtd, const T &n){
	setQtdadeBolas(qtd);
	setNumeroJogadas(n);
	bolas = new Bola<string>[qtd];  //alocacao dinamica de memoria
	matriz = new Bola<string>*[qtd];
	for(int i = 0; i < qtd; i++) matriz[i] = new Bola<string>[n];
}

template <typename T>
void Tabuleiro<T>::setNumeroJogadas(T n){
	if(n <= 0) n = 1;
	numero_jogadas = n;
}

template <typename T>
void Tabuleiro<T>::setQtdadeBolas(int qtd){
	if(qtd <= 0) qtd = 1;
	quantidade_bolas = qtd;
}

template <typename T>
T Tabuleiro<T>::getNumeroJogadas() const{
	return numero_jogadas;
}

template <typename T>
int Tabuleiro<T>::getQtdadeBolas() const{
	return quantidade_bolas;
}

template <typename T>
Bola <string> *Tabuleiro<T>::getBolas() const{
	return bolas;
}

template <typename T>
Bola <string> **Tabuleiro<T>::getMatriz() const{
	return matriz;
}

/* Preenche o vetor de bolas com a cor e a na posicao passados como parametro
 * PARAMETROS: A cor digitada na jogada atual e a posicao do vetor que sera armazenada
 */
template <typename T>
void Tabuleiro<T>::preenche(string jogada, int posicao){
	bolas[posicao].setCor(jogada);
}

/* Preenche a matriz de bolas com a cor e posicoes passadas como parametro.
 * Este método irá guardar em uma matriz todas as jogadas anteriores e atuais.
 * PARAMETROS: A cor digitada na jogada atual e a posicao em linha e coluna que sera armazenada
 */
template <typename T>
void Tabuleiro<T>::preenche_matriz(string jogada, int linha, int coluna){
	matriz[linha][coluna].setCor(jogada);
}

/* Imprime os pinos pretos, brancos e cinzas
 */
template <typename T>
void Tabuleiro<T>::printa_Pinos(){
	for(T j = 0; j < numero_jogadas; j++){
		std::cout << "\n   ";
		for(int i = 0; i < quantidade_bolas; i++){
			std::cout << "  -  Pino " << matriz[i][j].getCor() << "  -  ";
		}
		std::cout << "\n\n";
	}
}

template <typename T>
Tabuleiro<T>::~Tabuleiro(){
	delete[] bolas;
	for(int i = 0; i < getQtdadeBolas(); i++) delete[] matriz[i];
	delete[] matriz;
}

template class Tabuleiro <int>;