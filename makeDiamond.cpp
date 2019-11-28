#include <iostream>
using namespace std;

void diamond(int k);

int main() {
	int t = 0;

	int size = 15;
	diamond(size);
	
	return 0;
}
void diamond(int k) {
	for (int i = 1; i <= k / 2; i++) {
		for (int j = 1; j <= k; j++) {
			int m = k / 2 + 1;
			if (m - i < j && j < m + i) {
				cout << "+";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	
	for (int i = 0; i < k; i++) {
		cout << "+";
	}
	cout << endl;

	for (int i = k / 2; i > 1 / 2; i--) {
		for (int j = k; j >= 1; j--) {
			int m = k / 2 + 1;
			if (m - i < j && j < m + i) {
				cout << "+";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
}
/*
void diamondMiddlePart(int k) {
	for (int i = 0; i < k; i++) {
		cout << "+" ;
	}
	cout << endl;
}

void diamondUpperPart(int k) {
	
	for (int i = 1; i <= k/2; i++) {
		for (int j = 1; j <= k; j++) {
			int m = k / 2 + 1;
			if (m-i < j && j < m+i) {
					cout << "+";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
}

void diamondBottomPart(int k) {
	for (int i = k/2; i > 1 / 2; i--) {
		for (int j = k; j >= 1; j--) {
			int m = k / 2 + 1;
			if (m - i < j && j < m + i) {
				cout << "+";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
}
*/