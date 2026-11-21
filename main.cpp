#include <iostream>
#include <fstream>

using namespace std;

char matrice[729][729];

void Sierpinski(int ordin, int rand, int coloana) {
	if (ordin == 0) {
		matrice[rand][coloana] = 0;
		return;
	} // verificare daca ordin == 0; 

	int pas = 1;
	for (int i = 0; i < ordin - 1; ++i) {
		pas *= 3;
	} 
//determin marimea subpatratelor

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) {
				for (int di = 0; di < pas; ++di) {
					for (int dj = 0; dj < pas; ++dj) {
						matrice[rand + i * pas + di][coloana + j * pas + dj] = 1;
					}
				}
			} else {
				Sierpinski(ordin - 1, rand + i * pas, coloana + j * pas);
			}
		}
	}
}

int main() {
	ifstream fin("sierpinski.in");
	ofstream fout("sierpinski.out");
       //creez .in, .out
	int n;
	if (!(fin >> n)) return 0;

	int dimensiune = 1;
	for (int i = 0; i < n; ++i) {
		dimensiune *= 3;
	}
     // determin dimensiunea matricei
	Sierpinski(n, 0, 0);

	for (int i = 0; i < dimensiune; ++i) {
		for (int j = 0; j < dimensiune; ++j) {
			fout << (int)matrice[i][j];
			if (j == dimensiune - 1) {
				fout << "";
			} else {
				fout << " ";
			}
		}
		fout << "\n";
	}
	fin.close();
	fout.close();

	return 0;
}