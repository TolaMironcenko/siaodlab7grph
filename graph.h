//
// Created by Анатолий Миронченко
//

#ifndef SIAODLAB7_SCREEN_H
#define SIAODLAB7_SCREEN_H

#include <iostream>
#include "list.h"

using namespace std;

class Graph {
private:
	int k; // колическтво вершин
	List *graphtable; // список смежности
public:
	Graph(); // конструктор по умолчанию
	Graph(int k, int **lst); // конструктор с заданными значениями k - количество вершин lst - матрица смежности
	~Graph(); // деструктор
	void wirte_graph_int(); // функция для забивания значений в граф
	void print_constr_tree();
	friend std::ostream& operator<<(std::ostream &out, const Graph graph1); // переопределение метода cout
};

#endif