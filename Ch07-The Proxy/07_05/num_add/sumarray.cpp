#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main(){
    int array[] = {0, 0, 0};
    int array_length = sizeof(array) / sizeof(array[0]);

    std::vector<int> result;
    int increment = 1;
    int sum = 0;

    for(int i = 0; i < array_length; i++){
        sum += array[i] * pow(10, array_length - i - 1);
    }
    std::cout << "Starting number: " << sum << std::endl;
    int sum_incremented = sum + increment;
    std::string sum_as_string = std::to_string(abs(sum_incremented));
    
    for(char digit : sum_as_string){
        result.push_back(digit);
        std::cout << digit << "";
    }

    return 0;
}