#include <iostream>
#include <fstream>
#include <sstream>

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
        int lowest;
        int highest;
        int temp;
        std::stringstream iss(line);
        iss >> lowest;
        highest = lowest;
        while(iss >> temp) {
            if(temp < lowest) {
                lowest = temp;
            }
            else if(temp > highest) {
                highest = temp;
            }
        }
        checksum += highest - lowest;
    }
    inFile.close();
    std::cout << std::endl;
    return checksum;
}