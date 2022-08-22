// Напишите программу, которая с помощью метода поиска в ширину,
// cтроит стягивающее дерево для произвольного связного неориентированного графа. 
// Для представления графа в программе использовать списки смежности. 
// Данные о графе вводятся из файла. 
// Программа должна вывести ребра графа, вошедшие в стягивающее дерево. 
// После завершения работы с динамическими структурами данных необходимо 
// освободить занимаемую ими память.

#include <iostream>
#include "graph.h"
#include <fstream>

using namespace std;

int main() {
	int size_mass = 5; // количество точек крафа
	int** graph_matrix = new int*[size_mass]; // выделение памяти для матрицы смежности
	for (int i = 0; i < size_mass; i++) { 
		graph_matrix[i] = new int[size_mass]; // выделение памяти для матрицы смежности
	}
	ifstream inputfile("input.txt");
	for (int i = 0; i < size_mass; i++) {
		for (int j = 0; j < size_mass; j++) {
			inputfile >> graph_matrix[i][j];
		}
	}
	// for (int i = 0; i < size_mass; i++) {
	// 	for (int j = 0; j < size_mass; j++) {
	// 		cout << graph_matrix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	Graph graph1(size_mass, graph_matrix);
	for (int i = 0; i < size_mass; i++) {
		delete[] graph_matrix[i];
	}
	delete[] graph_matrix;
	// graph1.wirte_graph_int();
	cout << graph1 << endl;
	graph1.print_constr_tree();
	return 0;
}



// 0-1-2-4   0-1
// |   |     0-3
// 3---|     1-2
//           2-4