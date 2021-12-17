#include "Commands.h"

Commands::Commands() {

}

Commands::~Commands() {
}

vector <string> Commands::GetInput() {
    string temp_input;
    cin.clear();
    getline(cin, temp_input);
    istringstream iss{temp_input};

    while (getline(iss, temp_input, ' '))
        input.push_back(temp_input);

    //input.shrink_to_fit();
    return input;
}
