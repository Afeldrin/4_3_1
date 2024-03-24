#include <iostream>
#include <vector>
#include<list>
#include<string>

using namespace std;

vector<list<int>> hash_insert(vector<list<int>> hash_table, vector<int> val) { // Функция заполнения хэш-таблицы

	for (auto i = val.begin(); i != val.end(); ++i) {
		int a = *i % 5;


		hash_table[a].push_front(*i);

		cout << "element " << *i << " inserted at " << a << endl;

	}

	return hash_table;
}

bool find(vector<list<int>> hash_table, int elem) { // функция поиска элекмента в таблице, возвращает True или False в зависимости от наличия элемента в таблице
	
	int a = elem % 5;

	for (auto i = hash_table[a].begin(); i != hash_table[a].end(); ++i) {

		if (*i == elem) {
			return true;
		}
	}

	return false;
}

void print_hash(vector<list<int>> hash_table) { // функция для печати таблицы

	for (int i = 0; i != 5; ++i) {
		cout << i << "   ";
		for (auto j = hash_table[i].begin(); j != hash_table[i].end(); ++j) {
			cout << *j << " ";
		}
		cout << endl;
	}
}

int main()
{

	vector<list<int>> table; // создаем хэш таблицу

	table.resize(5); // задаём размер таблицы согласно хэш функции (в этом случае хэш функция - остаток от деления на 5)

	vector<int> input = {12, 14, 15, 23, 54, 24, 16}; // Задаем массив элементов, которые загрузим в хэш таблицу

	table = hash_insert(table, input); // заполняем таблицу

	print_hash(table); // печатаем таблицу

	cout << find(table, 12) << endl; //ищем элемент


}
