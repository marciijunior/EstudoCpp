#include <iostream>
#include <string>
using namespace std;

int centena[100];
string centenaModificada[100];

int main() {
	int numero = 1;
	
	cout << "A lista antes de ser modificada: " << endl;
	
	for (int i = 0; i < 100; i++) {
		centena[i] = numero;
		numero++;
		cout << "[ " << centena[i] << " ]" << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < 100; i++) {
		if (centena[i] % 3 == 0) {
			centenaModificada[i] = "Fizz";
		}
		else if (centena[i] % 5 == 0) {
			centenaModificada[i] = "Buzz";
		}
		else if (centena[i] % 15 == 0) {
			centenaModificada[i] = "FizzBuzz";
		}
		else {
			centenaModificada[i] = to_string(centena[i]);
		}
	}

	cout << "A lista apos ser modificada: " << endl;
	for (int i = 0; i < 100; i++) {
		cout << "[ " << centenaModificada[i] << " ]" << " ";
	}

	return 0;
}