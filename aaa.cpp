#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

const int ITERATIONS = 1000;

void test_endl(std::ostream& out) {
    for (int i = 0; i < ITERATIONS; ++i) {
        out << "Hello world" << std::endl;
    }
}

void test_newline(std::ostream& out) {
    for (int i = 0; i < ITERATIONS; ++i) {
        out << "Hello earth\n";
    }
    out.flush();
}

int main() {
    std::ofstream file("output.txt");
    std::ostream& out = file; // Use file instead of std::cout

    auto start = std::chrono::steady_clock::now();
    test_endl(out);
    auto end = std::chrono::steady_clock::now();
    auto duration_endl = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    start = std::chrono::steady_clock::now();
    test_newline(out);
    end = std::chrono::steady_clock::now();
    auto duration_n = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    std::cout << std::fixed << std::setprecision(9);
    std::cout << "Time taken with std::endl: " << duration_endl.count() << " seconds\n";
    std::cout << "Time taken with \\n: " << duration_n.count() << " seconds\n";

    return 0;
}
