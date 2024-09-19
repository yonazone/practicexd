#include <iostream>
#include <chrono>
#include <ctime>  // for std::localtime, std::time_t
#include <iomanip> // for std::put_time

int main() {
    // Get the current time point from the system clock
    auto now = std::chrono::system_clock::now();

    // Convert it to time_t which represents the time in seconds since the epoch
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t to local time (broken down into year, month, day, etc.)
    std::tm* localTime = std::localtime(&currentTime);

    // Output the time in a human-readable format using std::put_time
    std::cout << "Current time: " << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << std::endl;

    return 0;
}
