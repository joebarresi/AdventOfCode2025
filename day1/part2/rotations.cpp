#include <vector>
#include <iostream>
#include <fstream>
#include <string>


std::vector<int> file_as_rotations(std::string file_path) {
  std::ifstream inputFile(file_path); 
  std::string line;
  std::vector<int> directions;

  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) { //
      if(line.at(0) == 'L') {
        directions.push_back(-1 * std::stoi(line.substr(1)));
      } else {
        directions.push_back(std::stoi(line.substr(1)));
      }
    }
    inputFile.close();
  } else {
    std::cerr << "Unable to open file: example.txt" << std::endl;
  }

  return directions;
};

int get_number_of_zeroes(std::vector<int> rots) {
  int curSpot = 50;
  int num_zeroes = 0;

  for (int i=0; i < rots.size(); i++) {
    int fullRotation = rots.at(i);
    if (fullRotation > 0) {
      for (int j=1; j < fullRotation + 1; j++) {
        if (((curSpot + j) % 100) == 0) {
          num_zeroes += 1;
        }
      }
    } else {
      for (int j=1; j < -1 * fullRotation + 1; j++) {
        if (((curSpot - j) % 100) == 0) {
          num_zeroes += 1;
        }
      }
    }

    curSpot += rots.at(i);
  }

  return num_zeroes;
}

int main() {
  std::vector<int> rots = file_as_rotations("rotos.md");

  std::cout << "Num Zeroes: " << get_number_of_zeroes(rots) << std::endl;

  return 0;
}