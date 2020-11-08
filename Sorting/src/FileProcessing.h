#pragma once

#include <string>
#include <map>
#include <vector>

#include "Utilities.h"

std::string outFileName(std::string sortAlg, std::string state, int size);
void writeArrSorted(int arr[], int n, std::string fileName);
void writeResult(std::map<SortAlgorithm, std::string> sortAlg, std::map<State, std::string> state, std::vector<int> size, std::string fileName);
