#include <iostream>

using namespace std;

class FilaSeq {
private:
    int *dados;       // array para armazenar os elementos
    int capacidade;   // capacidade máxima da fila
    int inicio;       // índice do elemento no início da fila
    int fim;          // índice do próximo slot livre no fim da fila
    int qtde;         // quantidade atual de elementos

public:
    FilaSeq(int cap = 100) {
        capacidade = cap;
        dados = new int[capacidade];
        inicio = 0;
        fim    = 0;
        qtde   = 0;
    }

    ~FilaSeq() {
        delete[] dados;
    }

    // verifica se está vazia
    bool vazia() const {
        return qtde == 0;
    }

    // verifica se está cheia
    bool cheia() const {
        return qtde == capacidade;
    }

    // insere no fim
    // lança runtime_error se cheia
    void enfileirar(int x) {
        if (cheia()) {
            throw runtime_error("Erro: fila cheia!");
        }
        dados[fim] = x;
        fim = (fim + 1) % capacidade;
        qtde++;
    }

    // remove do início e retorna o elemento removido
    // lança runtime_error se vazia
    int desenfileirar() {
        if (vazia()) {
            throw runtime_error("Erro: fila vazia!");
        }
        int valor = dados[inicio];
        inicio = (inicio + 1) % capacidade;
        qtde--;
        return valor;
    }

    // consulta o elemento no início sem remover
    // lança runtime_error se vazia
    int frente() const {
        if (vazia()) {
            throw runtime_error("Erro: fila vazia!");
        }
        return dados[inicio];
    }
};

int main() {
    FilaSeq fila(5);  

    cout << "Inserindo 10, 20, 30 na fila...\n";
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);

    cout << "Frente da fila: " << fila.frente() << "\n";

    cout << "Removendo um elemento: "
         << fila.desenfileirar() << "\n";

    cout << "Frente da fila agora: " << fila.frente() << "\n";

    cout << "Inserindo 40 e 50...\n";
    fila.enfileirar(40);
    fila.enfileirar(50);

    cout << "A fila está cheia? "
         << (fila.cheia() ? "Sim" : "Não") << "\n";

    try {
        cout << "Tentando inserir 60...\n";
        fila.enfileirar(60);
    } catch (const exception &e) {
        cout << e.what() << "\n";
    }

    cout << "Esvaziando a fila:\n";
    while (!fila.vazia()) {
        cout << "  Removido: " << fila.desenfileirar() << "\n";
    }

    cout << "A fila está vazia? "
         << (fila.vazia() ? "Sim" : "Não") << "\n";

    return 0;
}
