#include <iostream>

using namespace std;

struct No {
    int data;
    No *next;
};

void exibirLista(No *head){
    No *p = head;
    cout << "\n[ ";
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "]";
}

void contar(No* head, int &cont){
    No *p = head;
    cont = 0;
    while(p != NULL) {
        cont += 1;
        p = p->next;
    }
}

void inserir(No *&head, int numero) {
    No * novoNo = new No;
    novoNo->data = numero;
    novoNo->next = NULL;
    if(head == NULL) {
        head = novoNo;
        return;
    }
    No * aux = head;
    while(aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = novoNo;	
}

void removerPosicaoN(No *&head, int posicao) {
    if (posicao == 0) {
        No* temp = head;
        head = head->next;
        delete temp;
    } else {
        No* temporario = head;
        No* anterior = NULL;
        for (int i = 0; i < posicao; i++) {
            anterior = temporario;
            temporario = temporario->next;
        }
        anterior->next = temporario->next;
        delete temporario;
    }
}

void simplesParaCircular(No*& head) {
    if (head == NULL) {
    	cout << "Lista vazia. Insira elementos para continuar." << endl;
    	return;
	}
    
    No* temporario = head;
    while (temporario -> next != NULL) {
        temporario = temporario -> next;
    }

    temporario -> next = head; 
}

int acharMaior(No* head) {
    if (head == NULL) {
        cout << "Lista vazia!" << endl;
        return INT_MIN; // Ou outro valor indicando erro.
    }

    int maior = head->data;
    No* temporario = head->next;

    while (temporario != NULL) {
        if (temporario -> data > maior) {
            maior = temporario -> data;
        }
        temporario = temporario -> next;
    }

    return maior;
}

int main() {
    int numero, cont, maior;
    int opcao = -1;
    
    No *head = NULL;
    
	inserir(head, 10);
    inserir(head, 11);
    inserir(head, 12);
    inserir(head, 13);
    inserir(head, 14);
    inserir(head, 15);
    
	cout << "Lista inicial:";
    exibirLista(head);
    cout << endl;
    
    while (opcao != 0) {
        cout << "\n1. Contar elementos\n";
        cout << "2. Remover por posicao\n";
        cout << "3. Encontre o valor do meio da lista e mostre na tela.\n";
        cout << "4. Escreva um programa que transforme uma lista ligada em uma lista circular.\n";
        cout << "5. Escreva um programa que encontre o maior nó em uma lista duplamente encadeada.\n";
        cout << "6. Escreva um programa que recebe uma lista duplamente encadeada e ordena ela utilizando o Merge Sort.\n";
        cout << "0. Sair\n";
        cout << "Digite o numero da questao escolhida: ";
        cin >> opcao;
    
	    switch (opcao) {
            case 1:
                contar(head, cont);
                cout << "A lista tem " << cont << " numeros!\n";
                break;
                
            case 2:{
            	cont = 0;
                contar(head, cont);
                cout << "Digite a posicao na lista que deseja remover: ";
                cin >> numero;
                
                if(numero < 0 || numero > (cont - 1)){
                	cout << "A lista vai da posicao 0 a " << cont - 1 << endl;
                	break;
				}
                
                removerPosicaoN(head, numero);
                cout << "Lista atualizada:";
                exibirLista(head);
                cout << endl;
                break;}
                
            case 3: {
			    cont = 0;
                contar(head, cont);
                int posicaoMeio = (cont - 1) / 2;
                No* p = head;
                for (int i = 0; i < posicaoMeio; i++) {
                    p = p->next;
                }
                cout << "O valor do meio da lista e  " << p->data << "\n";
                break;
            }
            
            case 4: {
   				simplesParaCircular(head);
    			cout << "Lista transformada em circular com sucesso!" << endl;
    			break;
    		}
			
			case 5: {
				maior = acharMaior(head);
				cout << "O maior valor na lista duplamente encadeada e " << maior << endl;
				}
			
            case 0: {
                cout << "Tchau\n";
                break;
        	}
            default: {
                cout << "Opcao invalida!\n";
                break;
        	}
		}
    }
    return 0;
}
