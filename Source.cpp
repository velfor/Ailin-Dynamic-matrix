#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void alloc_mem(int**& mas, int n, int m);
void input_matrix(int** mas, int n, int m, char* file_name);
void print_matrix(int** mas, int n, int m);
void calc_avg(int** mas, int n, int m, double* avg);
void print_array(double* avg, int n);
void output_array(double* avg, int n, char* file_name);

int main() {
	int n = 5;
	int m = 5;
	char input_file_name[] = "input.txt";
	char output_file_name[] = "output.txt";
	int** matrix;

	double* avg = new double[n];

	alloc_mem(matrix, n, m);
	input_matrix(matrix, n, m, input_file_name);
	print_matrix(matrix, n, m);
	calc_avg(matrix, n, m, avg);
	print_array(avg, n);
	output_array(avg, n, output_file_name);

	return 0;
}
void alloc_mem(int**& mas, int n, int m) {
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
}
void input_matrix(int** mas, int n, int m, char* file_name) {
	ifstream fin(file_name);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> mas[i][j];
		}
	}
	fin.close();
}
void print_matrix(int** mas, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << mas[i][j];
		}
		cout << endl;
	}
}
void calc_avg(int** mas, int n, int m, double* avg) {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum = sum + mas[i][j];
		}
		avg[i] = double(sum) / m;
	}
}
void print_array(double* avg, int n) {
	for (int i = 0; i < n; i++) {
		cout << avg[i] << ' ';
	}
	cout << endl;
}
void output_array(double* avg, int n, char* file_name) {
	ofstream fout(file_name);
	for (int i = 0; i < n; i++) {
		fout << avg[i] << ' ';
	}
	fout.close();
}