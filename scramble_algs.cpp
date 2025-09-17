#include "scramble_algs.hpp"

using namespace std;


void testFuntion() {
    cout << "Success" << endl;
}

int getChannel(int index) {
    return index % 4;
}

// void templateScramble(int index, vector<unsigned char> &image) {
//     int channel = getChannel(index);
//     if (channel == RED) {
//     } else if (channel == BLUE) {
//     } else if (channel == GREEN) {
//     } else if (channel == ALPHA) {
//     }
// }   

void greenChannelScramble(int index, vector<unsigned char> &image) {
    int channel = getChannel(index);
    if (channel == RED) {
        image[index] = 0;
    } else if (channel == BLUE) {
        image[index] = 0;
    } else if (channel == GREEN) {

    } else if (channel == ALPHA) {
        // image[i] = 255;
    }
    // image[index] = 0;
}    

void keyScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key) {
    // cout << "index: " << (int) index << endl;
    // cout << "    OG VALUE: " << (int) image[index] << endl;
    // cout << "    New Value: " << key[image[index]] << endl;
    if (getChannel(index) != ALPHA) {
        image[index] = key[image[index]];
    }
}

void keyUnScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key) {

    auto it = find(key.begin(), key.end(), image[index]);
    int ogValue = it - key.begin();

    if (getChannel(index) != ALPHA) {
        image[index] = ogValue;
    }
}

void keyScramble2(int index, std::vector<unsigned char> &image, std::vector<int> &key) {
    int skew = index % 31;
    // cout << "index: " << (int) index << endl;
    // cout << "    OG VALUE: " << (int) image[index] << endl;
    // cout << "    Skew: " << skew << endl;
    // cout << "    New Value: " << key[(image[index] + skew) % 256] << endl;
    if (getChannel(index) != ALPHA) {
        image[index] = key[(image[index] + skew) % 256];
    }
}

void keyUnScramble2(int index, std::vector<unsigned char> &image, std::vector<int> &key) {
    

    auto it = find(key.begin(), key.end(), image[index]);
    int ogValue = it - key.begin();
    
    int skew = index % 31;

    int target = (ogValue - skew) % 256;

    if (getChannel(index) != ALPHA) {
        image[index] = target;
    }
}

void threeKeyScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key1, std::vector<int> &key2, std::vector<int> &key3) {
    int channel = getChannel(index);
    if (channel == RED) {
        image[index] = key1[image[index]];
    } else if (channel == BLUE) {
        image[index] = key2[image[index]];
    } else if (channel == GREEN) {
        image[index] = key3[image[index]];
    }
}

void threeKeyUnScramble(int index, std::vector<unsigned char> &image, std::vector<int> &key1, std::vector<int> &key2, std::vector<int> &key3) {
    int channel = getChannel(index);
    int ogValue = -1;
    if (channel == RED) {
        auto it = find(key1.begin(), key1.end(), image[index]);
        ogValue = it - key1.begin();
    } else if (channel == BLUE) {
        auto it = find(key2.begin(), key2.end(), image[index]);
        ogValue = it - key2.begin();
    } else if (channel == GREEN) {
        auto it = find(key3.begin(), key3.end(), image[index]);
        ogValue = it - key3.begin();    
    }

    if (getChannel(index) != ALPHA) {
        image[index] = ogValue;
    }
}
