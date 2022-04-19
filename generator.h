#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class word{
public:
	int Size_word; 
	string Word;
	word(int Size_word, string Word) : Size_word(Size_word), Word(Word)
	{
	}
};

class NVP {
private:
	vector<word> vect_words;
	vector<word> answer_defoult;
	vector<word> answer_same;
	int* d = new int[n];
	int* prev = new int[n];
	int n;
public:
	void Read(string fname) {
		ifstream f;
		f.open(fname);
		if (!f.is_open()) throw "File not opened";
		f >> n;
		string Word;
		for (int i = 0; i < n; i++) {
			f >> Word;
			vect_words.emplace_back(Word.size(), Word);
		}
	}

	void Print()
	{
		cout << "______condition_____" << endl;
		for (auto& s : vect_words) {
			cout << s.Word << "_(" << s.Size_word << ")" << endl;
		}
		cout << endl;
		cout << "______NVP_____" << endl;
		for (auto& s : answer_defoult) {
			cout << s.Word << "_(" << s.Size_word << ")" << endl;
		}
		cout << endl;
		cout << "______same_char_____" << endl;
		for (auto& s : answer_same) {
			cout << s.Word << "_(" << s.Size_word << ")" << endl;
		}
	}

	void subsequence()
	{

		for (int i = 0; i < n; i++) {
			d[i] = 1;
			prev[i] = -1;
			for (int j = 0; j < i; j++) {
				if (vect_words[j].Size_word < vect_words[i].Size_word && d[j] + 1 > d[i]) {
					d[i] = d[j] + 1;
					prev[i] = j;
				}
			}
		}
		int pos = 0;
		int length = d[0];
		for (int i = 0; i < n; i++) {
			if (d[i] > length) {
				pos = i;
				length = d[i];
			}
		}
		while (pos != -1) {
			answer_defoult.emplace_back(vect_words[pos].Size_word, vect_words[pos].Word);
			pos = prev[pos];
		}
		std::reverse(std::begin(answer_defoult), std::end(answer_defoult));
		delete[] d;
		delete[] prev;
	}

	void same_char(char s)
	{
		for (int i = 0; i < n; i++) {
			if (vect_words[i].Word[0] == s) {
				answer_same.emplace_back(vect_words[i].Size_word, vect_words[i].Word);
				same_char(vect_words[i].Word[vect_words[i].Size_word-1]);
			}
		}
	}

};