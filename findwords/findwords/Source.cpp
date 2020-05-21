#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "Node.h"
using namespace std;


void inputText(map<string, int, less<>> whale, multimap<int, string, greater<>> &M) {
	string word;
	vector<string> dictionary;
	pair<map<string, int>::iterator, bool> current;
	ifstream OpendFile("largedictionary.txt");
	while (OpendFile >> word) {
		dictionary.push_back(word);
	}
	OpendFile.close();

	ifstream OpenFile("whale.txt");
	while (OpenFile >> word) {
		current = whale.insert(pair<string, int>(word, 1));
		if (!current.second)
			current.first->second++;
	}
	ofstream outFile("wordcount.txt");
	for (auto &L : whale) {
		if (!binary_search(dictionary.begin(), dictionary.end(), L.first)) {
			outFile << "(fake word) " << L.first << " " << L.second << endl;
			M.insert(pair<int,string>(L.second, L.first));
		}
		else
			outFile << L.first << " " << L.second << endl;
	}
	OpenFile.close();
}


void printmap(multimap<int, string, greater<>> M) {
	ofstream outFile("topMistakes.txt");
	int c = 0;
	for (auto &L : M) {
		if (c == 100)
			return;
		outFile << L.second << " " << L.first << endl;
		c++;
	}
}

int main() {
	multimap<int, string, greater<>> M;
	map<string, int, less<>> whale;
	inputText(whale,M);
	printmap(M);
	system("pause");
	return 0;
}