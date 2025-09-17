#include <iostream>
#include <vector>


#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3


void testFuntion();

void greenChannelScramble(int index, std::vector<unsigned char> &image);
// void templateScramble(int index, std::vector<unsigned char> &image);
void keyScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key);
void keyUnScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key);
void keyScramble2(int index, std::vector<unsigned char> &image, std::vector<int> &key);
void keyUnScramble2(int index, std::vector<unsigned char> &image, std::vector<int> &key);
void threeKeyScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key1, std::vector<int> &key2, std::vector<int> &key3);
void threeKeyUnScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key1, std::vector<int> &key2, std::vector<int> &key3);




int getChannel(int index);