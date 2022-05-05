#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class multiply {
private:
	int n;
	vector <vector <int>> matrix;
	vector<int> column;
	vector <vector <int>> m;
	vector<int> M;
	vector <vector <int>> s;
	vector<int> S;
public:
	void Read(string fname) {
		ifstream f;
		f.open(fname);
		if (!f.is_open()) throw "File not opened";
		f >> n;
		int x, y;
		M.resize(n,INT_MAX);
		S.resize(n, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++)
			{
				f >> x;
				column.push_back(x);
			}
			matrix.push_back(column);
			column.clear();
		}
		for (int i = 0; i < n; i++) {
			m.push_back(M);
			s.push_back(S);
		}
	}

	void Multiplication() {
		for (int i = 0; i < n; i++) {
			m[i][i] = 0;
		}
		
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				int temp = i + j;
				for (int k = j; k < temp; k++)
				{
					if (m[j][k] + m[k + 1][temp] + (matrix[j][0] * matrix[k][1] * matrix[temp][1]) < m[j][temp])
					{
						m[j][temp] = m[j][k] + m[k + 1][temp] + (matrix[j][0] * matrix[k][1] * matrix[temp][1]);
						s[j][temp] = k;
					}
				}
			}
		}
	}

	void Print() {
		cout << "Solve: " << m[0][n - 1] << endl << endl;

		cout << "Visualization: " << result(s, 0, n - 1) << endl;
		cout << endl;
	}

	string result(vector<vector<int>>& s, int k1, int k2)
	{
		if (k1 == k2)
		{
			return string(1, 'A' + k1);
		}

		int split = s[k1][k2];

		return "(" + result(s, k1, split) + " * " + result(s, split + 1, k2) + ")";
	}
};