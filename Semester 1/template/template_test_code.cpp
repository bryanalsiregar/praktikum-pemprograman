// #include <iostream>
// #include <fstream>
// #include <string>

// // Function to generate the Fibonacci sequence as a string
// std::string fibonacci(int n) {
//     std::string result;
//     int a = 0, b = 1, next;

//     for (int i = 1; i <= n; ++i) {
//         result += std::to_string(a);
//         if (i != n) { // Avoid adding a trailing space after the last number
//             result += " ";
//         }
//         next = a + b;
//         a = b;
//         b = next;
//     }

//     return result;
// }

// int main() {
//     std::ifstream testFile("test.txt");
//     int input;
//     std::string expected_output;

//     if (!testFile) {
//         std::cerr << "Error: Could not open test.txt" << std::endl;
//         return 1;
//     }

//     int test_num = 1;
//     while (testFile >> input && std::getline(testFile >> std::ws, expected_output)) {
//         std::string output = fibonacci(input);
//         if (output == expected_output) {
//             std::cout << "Test " << test_num << " passed!" << std::endl;
//         } else {
//             std::cout << "Test " << test_num << " failed. Expected: \"" 
//                       << expected_output << "\", Got: \"" << output << "\"" << std::endl;
//         }
//         test_num++;
//     }

//     testFile.close();
//     return 0;
// }