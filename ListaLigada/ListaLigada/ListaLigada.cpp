#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;
int quantidadeElementos = 0;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);

int main() {
    menu();
}

void menu() {
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op) {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }
        system("pause"); // somente no windows
    }
}

void inicializar() {
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }
    primeiro = NULL;
    quantidadeElementos = 0;
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {
    cout << "Quantidade de elementos: " << quantidadeElementos << endl;
}

void exibirElementos() {
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    cout << "Elementos: \n";
    NO* aux = primeiro;
    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento() {
    int valor;
    cout << "Digite o elemento: ";
    cin >> valor;

    if (posicaoElemento(valor) != NULL) {
        cout << "Elemento ja existe na lista!\n";
        return;
    }

    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
    }
    else {
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    quantidadeElementos++;
}

void buscarElemento() {
    int numero;
    cout << "Digite o elemento a buscar: ";
    cin >> numero;
    if (posicaoElemento(numero) != NULL) {
        cout << "ENCONTRADO\n";
    }
    else {
        cout << "ELEMENTO NAO ENCONTRADO\n";
    }
}

void excluirElemento() {
    int numero;
    cout << "Digite o elemento a excluir: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "ELEMENTO NAO ENCONTRADO\n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    quantidadeElementos--;

    cout << "Elemento excluido com sucesso!\n";
}

NO* posicaoElemento(int numero) {
    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
