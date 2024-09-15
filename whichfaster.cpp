#include <iostream>
#include <chrono>
#include <iomanip>

int main()
{
    // Demonstrating endl
    auto start = std::chrono::steady_clock::now();
    std::cout << "Hello world" << std::endl;
    auto end = std::chrono::steady_clock::now();
    auto duration_endl = std::chrono::duration_cast<std::chrono::duration<float>>(end - start);
    
    // Demonstrating \n
    start = std::chrono::steady_clock::now();
    std::cout << "Hello earth\n";
    end = std::chrono::steady_clock::now();
    auto duration_n = std::chrono::duration_cast<std::chrono::duration<float>>(end - start);
    
    // Displaying results
    std::cout << std::fixed << std::setprecision(9);
    std::cout << "Time taken with std::endl: " << duration_endl.count() << " seconds\n";
    std::cout << "Time taken with \\n: " << duration_n.count() << " seconds\n";
    
    return 0;
}
