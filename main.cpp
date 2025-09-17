#include <iostream>
#include <fstream>
#include "lodepng.h"
#include "scramble_algs.hpp"
#include "key_generator.hpp"


using namespace std;

int main(int argc, char* argv[]) {


    ///////////////// INITIALIZATION PHASE ////////////////
    string filename = "";
    string keyphrase = "";
    int algorithm = -1;
    int a = 1;
    int layers = 1;

    bool encode = true;
    while (a < argc) {
        if (((string)argv[a]).compare("--filename") == 0) {
            a++;
            filename = argv[a];
        } else if (((string)argv[a]).compare("--layers") == 0) {
            a++;
            layers = stoi(argv[a]);
        }else if (((string)argv[a]).compare("--keyphrase") == 0) {
            a++;
            keyphrase = argv[a];
        } else if (((string)argv[a]).compare("--decode") == 0) {
            encode = false;
        } else if (((string)argv[a]).compare("--alg") == 0) {
            a++;
            if (((string)argv[a]).compare("green") == 0) {
                algorithm = 1;
            } else if (((string)argv[a]).compare("key") == 0) {
                algorithm = 2;
            } else if (((string)argv[a]).compare("key2") == 0) {
                algorithm = 3;
            } else if (((string)argv[a]).compare("3key") == 0) {
                algorithm = 4;
            } else {
                cout << "Invalid algorithm name!" << endl;
                return -1;
            }
        } else {
            cout << "Invalid arguments!" << endl;
            return -1;
        }
        a++;
    }
    
    cout << "File: " << filename << endl;
    cout << "Keyphrase: " << keyphrase << endl;
    cout << "Algorithm: " << algorithm << endl;

    unsigned int hash = hashKey(keyphrase);
    srand(hash);
    vector<int> key = generateKey();
    vector<int> key2 = generateKey();
    vector<int> key3 = generateKey();
    // printKey(key);
    cout << "Keycheck: " << checkKey(key) << endl;

    ///////////////// DECODING PHASE ////////////////
    vector<unsigned char> image; //the raw pixels
    unsigned width, height;
    unsigned error = lodepng::decode(image, width, height, filename);
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    ///////////////// SCRAMBLE PHASE ////////////////
    for (int j = 0; j < layers; j++) {
        for (int i = 0; i < (int)image.size(); i++) {
            if (encode) {
                if (algorithm == 1) {
                    greenChannelScramble(i, image);
                } else if(algorithm == 2) {
                    keyScramble(i, image, key);
                } else if(algorithm == 3) {
                    keyScramble2(i, image, key);
                } else if(algorithm == 4) {
                    threeKeyScramble(i, image, key, key2, key3);
                } else {
                    cout << "No algorithm provided!" << endl;
                    return -1;
                }
            } else {
                if (algorithm == 2) {
                    keyUnScramble(i, image, key);
                } else if (algorithm == 3) {
                    keyUnScramble2(i, image, key);
                } else if (algorithm == 4) {
                    threeKeyUnScramble(i, image, key, key2, key3);
                } else {
                    cout << "No algorithm provided!" << endl;
                    return -1;
                }
            }
            // cout << (int)image[i] << " ";
            // if (i % 4 == 3) cout << endl;
        }
    }

    ///////////////// ENCODING PHASE ////////////////
    error = lodepng::encode(filename, image, width, height);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;


}
