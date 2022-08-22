//
// Created by Анатолий Миронченко
//

#include "graph.h"
#include <iostream>
#include "list.h"

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
	
}

std::ostream &operator<<(std::ostream &out, const Graph graph1) { // переопределение метода cout
	for (int i = 0; i < graph1.k; i++) {
		cout << "[" << i << "] ";
		graph1.graphtable[i].display();
	}
	return out;
}