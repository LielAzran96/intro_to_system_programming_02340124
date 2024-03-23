
#include <string>
#include <iostream>


#include <fstream>

#include "Mtmchkin.h"

using std::string;
using std::cout;
using std::endl;
using std::exception;

static const int REQUIRED_PARAMS_COUNT = 3;
static const int DECK_PATH_INDEX = 1;
static const int PLAYERS_PATH_INDEX = 2;

int main(int argc, char** argv) {
    if (argc != REQUIRED_PARAMS_COUNT) {
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: mtmchkin <deck_file_path> <players_file_path>" << endl;
    }


    string deckPath = argv[DECK_PATH_INDEX];
    string playersPath = argv[PLAYERS_PATH_INDEX];
        /***Check*****/
    std::ofstream outputFile("outputCheck.txt"); // Create an ofstream object for writing to a file
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(); // Save the original cout buffer
    std::cout.rdbuf(outputFile.rdbuf());
    /***************/
    try {
        Mtmchkin game(deckPath, playersPath);
        game.play();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    std::cout.rdbuf(originalCoutBuffer);
}
