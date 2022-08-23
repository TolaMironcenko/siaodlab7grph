//
// Created by Анатолий Миронченко
//

#include "graph.h"
#include <iostream>
#include "list.h"
#include <queue>

using namespace std;

Graph::Graph() { // конструктор по умолчанию
	this->k = 0;
	this->graphtable = new List[10];
}

Graph::Graph(int k, int **lst) { // конструктор с заданными значениями
	this->k = k;
	this->graphtable = new List[k];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (lst[i][j] == 1) {
				this->graphtable[i].append(j); // если значение lst[i][j] = 1 то доюавляем вершину в список смежности
			}
		}
	}
}

Graph::~Graph() { // деструктор
    delete[] graphtable;
}

void Graph::wirte_graph_int() { // функция для забивания значений в граф
	for (int i = 0; i < 10; i++) {
		this->graphtable[i].append(i);
	}
	for (int i = 0; i < 10; i+=2) {
		this->graphtable[i].append(i);
	}
}

void Graph::print_constr_tree() { // функция построения и вывода в терминал стягивающего дерева методом обхода в ширину
    int* Mark = new int[k](); // нулёвый массив отметок
    queue<int> q; // очередь вершин (см. обход в ширину)
    q.push(0); // начальная вершина произвольна, рассмотреть вариант её передачи в качестве аргумета (поставить аргумент по умолчанию)
    Mark[0] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graphtable[v].size(); ++i) {
            int w = graphtable[v].readPos(i);
            if (Mark[w] == 0) {
                q.push(w);
                Mark[w] = 1;
                cout << "(" << v << "," << w << "), ";
            }
        }
    }
    cout << "\b\b \b";
    delete[] Mark;
}

std::ostream &operator<<(std::ostream &out, const Graph graph1) { // переопределение метода cout
	for (int i = 0; i < graph1.k; i++) {
		cout << "[" << i << "] ";
		graph1.graphtable[i].display();
	}
	return out;
}