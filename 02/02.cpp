#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int checkSum(std::string filename);

int main() {
    std::cout << "I'm working\n";
    std::cout << checkSum("input.txt") << endl;
    return 0;
}

int checkSum(std::string filename) {
    int checksum = 0;
    std::ifstream inFile;
    inFile.open(filename);
    for( std::string line; getline(inFile, line ); ) {
        int temp;
        vector<int> numbers;
        std::stringstream iss(line);
        while(iss >> temp) {
            numbers.push_back(temp);
        }
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = 0; j < numbers.size(); j++) {
                if(numbers[i] % numbers[j] == 0 && numbers[i] != numbers[j]) {
                    checksum += numbers[i] / numbers[j];
                    cout << numbers[i] / numbers[j] << endl;
                }
            }
        }
        numbers.clear();
    }
    inFile.close();
    std::cout << std::endl;
    return checksum;
}