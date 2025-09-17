#include <iostream>
#include <vector>

#define KEY_SIZE 256

unsigned int hashKey(std::string key_string);
std::vector<int> generateKey();
void printKey(std::vector<int> &key);
int checkKey(std::vector<int> &key);


