#include "JogoX1.h"
#include <fstream>
#include <stdio.h>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
JogoX1<T>::JogoX1(const int &qtd, const T &n) : Jogo<T>(qtd,n) {

}

/* Modo de jogo Jogador contra Jogador, com cores repetidas.
 * O jogador 2 (quem irá advinhar a senha) digita seus palpites e em seguida o Jogador 1 (quem criou a senha) dá a resposta pelos pinos.
 * PARAMETROS: -Quantidade de cores do jogo;
 *             -Tamanho da senha;
 *             -Lista de cores
 */
template <typename T>
void JogoX1<T>::jogar_com_cores_repetidas(int intervalo, int tam, Lista <string> &l1){
	Tabuleiro <int> resposta(Tabuleiro<T>::getQtdadeBolas(),Tabuleiro<T>::getNumeroJogadas());

	cout << "\nINSIRA AS TENTATIVAS: \n";
	string jogada = " ";
	for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++) Tabuleiro<T>::preenche(jogada,i);
	cout << *this;		//sobrecarga
	for(T j = 0; j < Tabuleiro<T>::getNumeroJogadas(); j++){
		cout << "Insira as cores: \n";
		for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++){
			while(1){
				cin >> jogada;
				if(l1.lista_pertence(jogada) == false) cout << "Cor indisponivel!\nEscolha outra\n\n";
				else break;
			}
			Tabuleiro<T>::preenche(jogada,i);
			Tabuleiro<T>::preenche_matriz(jogada,i,j);
		}

		system("clear");
		cout << "----------------------------------------------------------";
		cout << "\nCores disponiveis: \n";
		l1.imprime();
		cout << "\n----------------------------------------------------------\n";
		cout << *this;
		resposta.printa_Pinos();

		int soma = 0;
		cout << "Resposta: \n";
		for(int i = 0; i < resposta.getQtdadeBolas(); i++){
			cin >> jogada;
			while(jogada != "Preto" && jogada != "Branco" && jogada != "Cinza"){
				cout << "Inválido.\n(Preto,Branco ou Cinza)\n";
				cin >> jogada;
			}
			resposta.preenche(jogada,i);
			resposta.preenche_matriz(jogada,i,j);
			if(jogada == "Preto") soma++;
		}

		system("clear");
		cout << "----------------------------------------------------------";
		cout << "\nCores disponiveis: \n";
		l1.imprime();
		cout << "\n----------------------------------------------------------\n";
		cout << *this;
		resposta.printa_Pinos();

		if(soma == Tabuleiro<T>::getQtdadeBolas()){
			cout << "\nJOGADOR GANHOU!!!\n";
			imprimeResposta();
			return;
		}
	}

	cout << "\nJOGADOR PERDEU :(\n\n";
	imprimeResposta();
}

/* Modo de jogo Jogador contra Jogador, sem cores repetidas.
 * O jogador 2 (quem irá advinhar a senha) digita seus palpites, sempre verificando se não está digitando cores repetidas,
 * e em seguida o Jogador 1 (quem criou a senha) dá a resposta pelos pinos.
 * PARAMETROS: -Quantidade de cores do jogo;
 *             -Tamanho da senha;
 *             -Lista de cores
 */
template <typename T>
void JogoX1<T>::jogar_sem_cores_repetidas(int intervalo, int tam, Lista <string> &l1){
	Tabuleiro <int> resposta(Tabuleiro<T>::getQtdadeBolas(),Tabuleiro<T>::getNumeroJogadas());

	cout << "\nINSIRA AS TENTATIVAS: \n";
	string jogada = " ";
	for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++) Tabuleiro<T>::preenche(jogada,i);
	cout << *this;		//sobrecarga
	for(T j = 0; j < Tabuleiro<T>::getNumeroJogadas(); j++){
		cout << "Insira as cores (uma por linha): \n";
		for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++){
			while(1){
				cin >> jogada;
				if(l1.lista_pertence(jogada) == false) cout << "Cor indisponivel!\nEscolha outra\n\n";
				else break;
			}
			for(int k = 0; k < Tabuleiro<T>::getQtdadeBolas(); k++){   //Verifica se a cor digitada ja foi escolhida
				while(jogada == Tabuleiro<T>::getBolas()[k].getCor()){
					cout << "Cor repetida.\n";
					cin >> jogada;
				}
			}
			Tabuleiro<T>::preenche(jogada,i);
			Tabuleiro<T>::preenche_matriz(jogada,i,j);
		}

		system("clear");
		cout << "----------------------------------------------------------";
		cout << "\nCores disponiveis: \n";
		l1.imprime();
		cout << "\n----------------------------------------------------------\n";
		cout << *this;
		resposta.printa_Pinos();

		int soma = 0;
		cout << "Resposta: \n";
		for(int i = 0; i < resposta.getQtdadeBolas(); i++){
			cin >> jogada;
			while(jogada != "Preto" && jogada != "Branco" && jogada != "Cinza"){
				cout << "Inválido.\n(Preto,Branco ou Cinza)\n";
				cin >> jogada;
			}
			resposta.preenche(jogada,i);
			resposta.preenche_matriz(jogada,i,j);
			if(jogada == "Preto") soma++;
		}

		system("clear");
		cout << "----------------------------------------------------------";
		cout << "\nCores disponiveis: \n";
		l1.imprime();
		cout << "\n----------------------------------------------------------\n";
		cout << *this;
		resposta.printa_Pinos();

		if(soma == Tabuleiro<T>::getQtdadeBolas()){
			cout << "\nJOGADOR GANHOU!!!\n";
			imprimeResposta();
			return;
		}

		for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++) Tabuleiro<T>::preenche(" ",i);
	}

	cout << "\nJOGADOR PERDEU :(\n\n";
	imprimeResposta();
}

/* Função auxiliar que lê um arquivo .txt que contem a resposta criada pelo Jogador 1(quem criou a senha). */
void imprimeResposta(){
	std::ifstream is ("resposta.txt", std::ifstream::binary);

	if (is) {
		// pega o tamanho do arquivo
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char *buffer = new char[length];

		// le o arquivo em blocos
		is.read(buffer,length);

		if (is)
			cout << "Resposta: " << buffer << endl;
		else
			cout << "ERRO!!\n";

		is.close();

		//buffer contem o arquivo inteiro

		delete[] buffer;
	}
}

template <typename T>
JogoX1<T>::~JogoX1(){

}

template class JogoX1 <int>;