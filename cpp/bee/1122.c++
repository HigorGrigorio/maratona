// # A FCC (Fundação de Combate à Corrupção) desmontou um grande esquema de corrupção na Nlogônia. Durante a operação, foram apreendidos diversos cadernos e livros com anotações documentando as transações ilícitas realizadas pelo esquema.

// # Vários desses livros contém páginas com os valores de várias transações em nilogos (a moeda local da Nlogônia, cujo símbolo é N$) e o fluxo de caixa resultante dessas transações. Por exemplo, se em uma página foi registrada uma entrada de N$ 7, uma entrada de N$ 2, uma saída de N$ 3, uma entrada de N$ 1 e outra saída de N$ 11, o fluxo de caixa nesta página é 7 + 2 − 3 + 1 − 11 = −4.

// # No entanto, para dificultar o trabalho da polícia, os contraventores não anotaram em seus livros qual o tipo de cada transação. No exemplo acima, as anotaçõs na página seriam apenas 7, 2, 3, 1 e 11 (sem indicação se elas são entradas ou saídas). O fluxo de caixa de cada página sempre é anotado normalmente, com o sinal (no caso, -4).

// # Para obter a condenação dos contraventores, os promotores precisam poder afirmar com certeza se cada operação foi uma entrada ou uma saída. No exemplo acima, a transação de N$ 7 certamente foi uma entrada, e a transação de N$ 11 certamente foi uma saída. Mas, não se pode afirmar nada sobre as transações de N$ 2, N$ 3, e N$ 1. As transações de N$ 2 e N$ 1 poderiam ter sido entradas e a transação de N$ 3 uma saída, ou N$ 2 e N$ 1 poderiam ter sido saídas e a transação de N$ 3 uma entrada.

// # Muitos cadernos possuem números relativamente grandes, com muitas transações, então é difícil para a polícia reconstruir o histórico de operações. Por isso, eles precisam de um programa que o faça de forma eficiente.
// # Entrada

// # A entrada consiste de vários casos de teste. A primeira linha da entrada contém dois inteiros N e F, indicando respectivamente o número de operações na página (2 ≤ N ≤ 40) e o fluxo de caixa para esta página (−16000 ≤ F ≤ 16000). Cada uma das N linhas seguintes contém um inteiro Ti indicando o valor da i-ésima transação (1 ≤ Ti ≤ 1000).

// # O ultimo caso de teste é seguido por uma linha que contém apenas dois zeros separados por espaços em branco.
// # Saída

// # Para cada caso de teste da entrada seu programa deve imprimir uma única linha com N caracteres. O i-ésimo caractere deve ser ‘+’, se for possível afirmar com certeza que a i-ésima operação foi uma entrada, ‘-’, se for possível afirmar com certeza que a i-ésima operação foi uma saída, e ‘?’, se não for possível determinar com certeza qual o tipo da operação.

// # Caso não exista uma sequência de entradas e saídas que totalize o fluxo de caixa indicado, imprima uma única linha contendo o caractere ‘*’.

#include <queue>
#include <list>
#include <iostream>
#include <memory.h>

using namespace std;

bool process(queue<int> inputs, int total, int sum, bool* keys, int* values, int height)
{
    if (sum == total && inputs.empty())
    {
        return true;
    }

    if (inputs.empty())
        return false;

    int val = inputs.front();
    inputs.pop();
    int pos = height;

    bool result = process(inputs, total, sum + val, keys, values, height + 1);

    if(result) {
        if(values[pos] == 0) {
            values[pos] = val;
        } else {
            keys[pos] = bool (keys[pos] & (val == values[pos]));
        }
    }

    bool result1 = process(inputs, total, sum - val, keys, values, height + 1);

    if(result1) {
        if(values[pos] == 0) {
            values[pos] = -val;
        } else {
            keys[pos] = bool (keys[pos] & (-val == values[pos]));
        }
    }

    return result || result1;
}

int get_n(std::list<int>::iterator it, int pos) {
    std::advance(it, pos);
    return *it;
}

int main()
{
    while (true)
    {
        queue<int> in;

        int n, f;

        cin >> n >> f;

        if (n == 0 && f == 0)
            break;

        int* vet = new int[n];

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            vet[i] = val;
            in.push(val);
        }

        bool* keys = new bool[n];
        memset(keys, true, n);
        int* values = new int[n];

        for(int i = 0; i < n; i++) {
            values[i] = 0;
        }

        if(process(in,  f, 0, keys, values, 0)) {
            cout << '*' << endl;
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(!keys[i]) {
                cout << '?';
            } else {
                cout << ((vet[i] >= 0) ? '+' : '-');
            }
        }

        cout << endl;
    }
    return 0;
}