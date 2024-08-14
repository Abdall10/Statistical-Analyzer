#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits> // For numeric limits
using namespace std;

// Function to calculate the mean
double calculateMean(const vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return static_cast<double>(sum) / numbers.size();
}

// Function to calculate the median
double calculateMedian(vector<int> numbers) {
    sort(numbers.begin(), numbers.end()); // Sort the numbers
    int n = numbers.size();
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        return numbers[n / 2];
    }
}

// Function to calculate the mode
int calculateMode(const vector<int>& numbers) {
    map<int, int> frequency;
    for (int num : numbers) {
        frequency[num]++;
    }
    
    int mode = numbers[0];
    int maxCount = 0;
    for (auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}

// Function to calculate the range
int calculateRange(const vector<int>& numbers) {
    int minNum = *min_element(numbers.begin(), numbers.end());
    int maxNum = *max_element(numbers.begin(), numbers.end());
    return maxNum - minNum;
}

// Function to validate numeric input
int getValidNumber() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail()) { // Check if the input is not a number
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the rest of the input line
            break; // Valid input, exit the loop
        }
    }
    return num;
}

int main() {
    char choice;

    do {
        int n;
        cout << "Enter the number of elements: ";
        n = getValidNumber(); // Get valid number of elements

        if (n <= 0) {
            cout << "Number of elements must be greater than zero." << endl;
            continue;
        }

        vector<int> numbers(n);
        cout << "Enter the elements: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Element " << i + 1 << ": ";
            numbers[i] = getValidNumber(); // Get valid number for each element
        }

        double mean = calculateMean(numbers);
        double median = calculateMedian(numbers);
        int mode = calculateMode(numbers);
        int range = calculateRange(numbers);

        cout << "\nResults:" << endl;
        cout << "Mean: " << mean << endl;
        cout << "Median: " << median << endl;
        cout << "Mode: " << mode << endl;
        cout << "Range: " << range << endl;

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the program!" << endl;

    return 0;
}
