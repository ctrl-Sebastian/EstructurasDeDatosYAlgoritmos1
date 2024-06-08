#include <iostream>

bool esPrimo(int n) {
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; // Divisible por 2 y 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

int main() {
    int number;
    std::cout << "Entre el numero: ";
    std::cin >> number;

    if (esPrimo(number)) {
        std::cout << number << " es numero primo.\n";
    } else {
        std::cout << number << " no es numero primo.\n";
    }

    return 0;
}
