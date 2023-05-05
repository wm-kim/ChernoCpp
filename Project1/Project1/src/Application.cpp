#include <iostream>
#include <future>
#include <chrono>

// multhreading in c++ std::async
// one of the hardest part of making run in parallel is trying to figure out dependency
// send independant tasks to worker thread and have them asynchronously 

// However, you should also be cautious about potential issues 
// like race conditions and deadlocks when working with concurrent programming.

// C# has parallel for loop but c++ doesn't
// Debug > window > parallel stacks

// Define a simple function
int compute_sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a time-consuming task
    return a + b;
}

int main() {
    // Start an asynchronous task to compute the sum
    std::future<int> sum_future = std::async(std::launch::async, compute_sum, 5, 7);

    // Do other tasks while waiting for the sum computation to complete
    std::cout << "Performing other tasks..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Still working on other tasks..." << std::endl;

    // Wait for the sum computation to finish and get the result
    // get method will block the calling thread until the result is available.
    int sum = sum_future.get();
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}