#include "types.hpp"
#include <algorithm>
#include <string>
#include <vector>

inline b8 IsStringInVector(const std::string& str, std::vector<std::string>& vec) {
	return std::find(vec.begin(), vec.end(), str) != vec.end();
}
