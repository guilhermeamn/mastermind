OBJS = mainFinal.o Bola.o Jogo.o JogoX1.o pino.o  Tabuleiro.o celula.o lista.o
all: mastermind
mastermind: $(OBJS)
	g++ $(OBJS) -o $@
mainFinal.o: mainFinal.cpp
	#g++ -c mainFinal.cpp -o mainFinal.o -Wall
	g++ -c $< -o $@ -Wall -std=c++17 -g
Bola.o: Bola.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
Jogo.o: Jogo.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
JogoX1.o: JogoX1.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
pino.o: pino.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
Tabuleiro.o: Tabuleiro.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
celula.o : celula.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
lista.o: lista.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
clean:
	rm *.o mastermind
