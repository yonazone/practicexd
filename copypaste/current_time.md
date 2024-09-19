# How to display current time using std chrono lib in C++

To display the current time using the chrono library in C++:
* Use `std::chrono` for dealing with time points
* Use `std::time_t` or `std::strftime` from `<ctime>` library to format the output in a human-readable way

## Explanation
* `std::chrono::system_clock::now()` retrieves the current time as a `time_point` from the system clock.
* `std::chrono::system_clock::to_time_t(now)` converts that `time_point` into a `time_t`, which is a simple representation of time as the number of seconds since the Unix epoch.
* `std::localtime(&currentTime)` converts the `time_t` into a tm struct representing the local time (broken down into components like year, month, hour, etc.).
* `std::put_time(localTime, "%Y-%m-%d %H:%M:%S")` formats the `tm` struct into a human-readable string, where `%Y` is the year, `%m` is the month, `%d` is the day, `%H` is the hour, `%M` is the minute, and `%S` is the second.

## Output
```
Current time: 2024-09-19 14:45:30
```

This will give you the current time in the format `YYYY-MM-DD HH:MM:SS`.

