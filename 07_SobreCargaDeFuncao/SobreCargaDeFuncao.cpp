#include <iostream>
using namespace std;

int soma(int x, int y);

double soma(double x, double y);

int main() {
	cout << soma(2, 7) << endl;
	cout << soma(5.5, 5.3) << endl;

	return 0;
}

int soma(int x, int y = 10) {
	return x + y;
}

double soma(double x, double y) {
	return x + y;
}