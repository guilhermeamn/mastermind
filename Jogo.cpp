#include "Jogo.h"

using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
#include <ctime>

template <typename T>
Jogo<T>::Jogo(const int &qtd, const T &n) : Tabuleiro<T>(qtd,n) {

}

/* Modo de jogo Jogador contra Computador, com cores repetidas.
 * Um número aleatório é gerado e usado como posição na lista de cores. Usuário digita seus palpites e o método "compara()"
 * é chamado para checar se o jogador ganhou ou não. Caso tenha ganhado, a função encerra o jogo. Caso contrário o usuário entra
 * com um novo palpite até acabar sua quantidade de tentativas.
 * PARAMETROS: -Quantidade de cores do jogo, usada como intervalo para o gerador de números aleatórios;
 *             -Tamanho da senha;
 *             -Lista de cores
 */
template <typename T>
void Jogo<T>::jogar_com_cores_repetidas(int intervalo, int tam, Lista <string> &l1){				//COM CORES REPETIDAS
        
	Tabuleiro <int> respostaPinos(Tabuleiro<T>::getQtdadeBolas(),Tabuleiro<T>::getNumeroJogadas());

	//GERA RESPOSTA ALEATORIA, COM CORES REPETIDAS
	srand(time(NULL));
	int valor = 0;
	string resposta[tam];
	for(int i = 0; i < tam; i++){
		valor = rand() % intervalo;
		resposta[i] = l1.lista_dado_AUXILIAR(valor+1);
	}

	//------------------------------------------------------------------//

	cout << "\nINSIRA AS TENTATIVAS: \n";
	string jogada = " ";
	int cont=0;
	for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++) Tabuleiro<T>::preenche(jogada,i);
	cout << *this;		//sobrecarga
	for(T j = 0; j < Tabuleiro<T>::getNumeroJogadas(); j++){
		cout << "Insira as cores: \n";
		for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++){
			while(1){
				cin >> jogada;
				if(cont == Tabuleiro<T>::getQtdadeBolas() - 1){
					cout << "Cores a mais do tamanho foram ignoradas." << endl;
					cin.clear();
                                        cin.ignore(1000, '\n');
				}
				cont++;
				if(l1.lista_pertence(jogada) == false){
					cout << "Cor indisponivel!\nEscolha outra\n\n";
					cont--;
				}
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
		if(compara(resposta,tam,j,respostaPinos) == Tabuleiro<T>::getQtdadeBolas()){	//quantidade de pinos pretos = quantidade de bolas, jogador ganhou
			cout << "\n\n\n           JOGADOR GANHOU!!!\n";
			for(int i = 0; i < tam; i++) cout << resposta[i] << " ";
			cout << "\n\n";
			return;
		}
		cont = 0;
	}

	cout << "\nJOGADOR PERDEU :(\n\n";

	cout << "RESPOSTA ERA: \n";
	for(int i = 0; i < tam; i++) cout << resposta[i] << " ";
	cout << "\n\n";
}

/* Modo de jogo Jogador contra Computador, sem cores repetidas.
 * Um número aleatório é gerado e usado como posição na lista de cores, sendo que esse número passa por uma verificação
 * para garantir que números repetidos não sejam usados. Usuário digita seus palpites, sem poder digitar cores repetidas,
 * e o método "compara()" é chamado para checar se o jogador ganhou ou não. Caso tenha ganhado, a função encerra o jogo. 
 * Caso contrário o usuário entra com um novo palpite até acabar sua quantidade de tentativas.
 * PARAMETROS: -Quantidade de cores do jogo, usada como intervalo para o gerador de números aleatórios;
 *             -Tamanho da senha;
 *             -Lista de cores
 */
template <typename T>
void Jogo<T>::jogar_sem_cores_repetidas(int intervalo, int tam, Lista <string> &l1){  //SEM CORES REPETIDAS

	Tabuleiro <int> respostaPinos(Tabuleiro<T>::getQtdadeBolas(),Tabuleiro<T>::getNumeroJogadas());

	//GERA NUMEROS ALEATORIOS SEM REPETIR
	srand(time(NULL));
	int valor = 0;
	int cont=0;
	int vetor[tam];
	string resposta[tam];
	for(int i = 0; i < tam; i++){
		valor = rand() % intervalo;
		while(Existe(vetor,i,valor)){
			valor = rand() % intervalo;
		}
		vetor[i] = valor;
		resposta[i] = l1.lista_dado_AUXILIAR(valor+1);
	}

	//---------------------------------------


	cout << "\nINSIRA AS TENTATIVAS: \n";
	string jogada = " ";
	for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++) Tabuleiro<T>::preenche(jogada,i);
	cout << *this;
	for(T j = 0; j < Tabuleiro<T>::getNumeroJogadas(); j++){
		cout << "Insira as cores (Digite uma por linha): \n";
		for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++){
			while(1){
				cin >> jogada;
				if(cont == Tabuleiro<T>::getQtdadeBolas() -1){
					cin.clear();
                                        cin.ignore(1000, '\n');
				}
				cont++;
				if(l1.lista_pertence(jogada) == false){
					cout << "Cor indisponivel!\nEscolha outra\n\n";
					cont--;
				}
				else break;
			}
			for(int k = 0; k < Tabuleiro<T>::getQtdadeBolas(); k++){   //Verifica se a cor digitada ja foi escolhida
				while(jogada == Tabuleiro<T>::getBolas()[k].getCor()){
					cout << "Cor repetida.\n";
					while(1){
						cin >> jogada;
						if(cont == Tabuleiro<T>::getQtdadeBolas() - 1){
							cout << "Cores a mais do tamanho foram ignoradas." << endl;
							cin.clear();
                                                        cin.ignore(1000, '\n');
						}
						cont++;
						if(l1.lista_pertence(jogada) == false){
							cout << "Cor indisponivel!\nEscolha outra\n\n";
							cont--;
						}
						else break;
					}
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
		if(compara(resposta,tam,j,respostaPinos) == Tabuleiro<T>::getQtdadeBolas()){
			cout << "\n\n\n       JOGADOR GANHOU!!!\n";
			for(int i = 0; i < tam; i++) cout << resposta[i] << " ";
			cout << "\n\n";
			return;
		}
		for(int i = 0; i < Tabuleiro<T>::getQtdadeBolas(); i++) Tabuleiro<T>::preenche(" ",i); //zera tudo para nao dar erro com a tentativa anterior
	}

	cout << "\nJOGADOR PERDEU :(\n";

	cout << "RESPOSTA ERA: \n";
	for(int i = 0; i < tam; i++) cout << resposta[i] << " ";
	cout << "\n\n";
}

/* Método que faz o cálculo da quantidade de pinos pretos, brancos e cinzas.
 * Retorna a quantidade de pinos pretos.
 * PARAMETROS: -Vetor de string com a resposta da senha;
 *             -Tamanho do código;
 *             -Posição da linha no vetor;
 *             -Tabuleiro das respostas preenchido com as tentativas
 */
template <typename T>
int Jogo<T>::compara(string resposta[], int tam, int linha, Tabuleiro <T> &respostaPinos){

	Pino <string> preto("Preto",0); //template
	Pino <string> branco("Branco",0);

	string estado[tam];


	for(int i = 0; i < tam; i++){
		estado[i] = "c";
	}

	for(int i = 0; i < tam; i++){
		if(Tabuleiro<T>::getBolas()[i].getCor() == resposta[i]){
			estado[i] = "p";
			preto.setQuantidade(preto.getQuantidade() + 1);
		}
	}

	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			if((i != j) && (Tabuleiro<T>::getBolas()[i].getCor() == resposta[j]) && (estado[j] == "c") && (Tabuleiro<T>::getBolas()[j].getCor() != resposta[j]) && (Tabuleiro<T>::getBolas()[i].getCor() != resposta[i])){
				estado[j] = "b";
				branco.setQuantidade(branco.getQuantidade() + 1);
				j = tam;
			}
		}
	}

	int k = 0;
	for(int i = 0; i < preto.getQuantidade(); i++){
		respostaPinos.preenche_matriz(preto.getCor(),k,linha);
		k++;
	}
	for(int i = 0; i < branco.getQuantidade(); i++){
		respostaPinos.preenche_matriz(branco.getCor(),k,linha);
		k++;
	}
	for(int i = 0; i < (tam - branco.getQuantidade() - preto.getQuantidade()); i++){
		respostaPinos.preenche_matriz("Cinza",k,linha);
		k++;
	}

	respostaPinos.printa_Pinos();

	return preto.getQuantidade();		//retorna quantidade de pinos pretos
}

/* Sobrecarga do operador << */
template <typename T>
std::ostream &operator << (std::ostream &output, const Jogo <T> &jogo){
	for(T j = 0; j < jogo.getNumeroJogadas(); j++){
		output << "\n                   [  ";
		for(int i = 0; i < jogo.getQtdadeBolas(); i++){
			output << "(" << jogo.getMatriz()[i][j].getCor() << ")  ";
		}
		output << "]\n\n";
	}
	return output;
}

template <typename T>
Jogo<T>::~Jogo(){

}

/* Função auxiliar para gerar números aleatórios sem repetir. Verifica se o valor passado como parâmetro pertence ao vetor.
 * PARAMETROS: -Vetor de int com os números gerados;
 *             -Tamanho do vetor;
 *             -Valor inteiro
 */
bool Existe(int valores[], int tam, int valor){		
	for(int i = 0; i < tam; i++){
		if(valores[i] == valor) return true;
	}
	return false;
}

template class Jogo <int>;
