#include "Commands.h"

Commands::Commands() {

}

Commands::~Commands() {
    input->clear();
}

void Commands::GetInput() {
    string temp_input;
    cin.clear();
    getline(cin, temp_input);
    //Todo: Separar as palavras e colocar no vetor input

    int j = 0;
    for (int i = 0; i < temp_input.length(); ++i)
        if (temp_input.at(i) != ' ')
            *(input + i + j) = temp_input; //Todo: Resovler Problema
        else
            j++;

    for (auto & i : *this->input) {
        cout << i << endl;
    }

    if (!Validator())
        cout << "Nao conheco esse comando!"<< endl;
    else
        cout << "Comando executado!" << endl;
}

bool Commands::Validator() { //Verifica se o comando e valido
    int i = 0;
    if (input[i] == "cons") {
        i++;
        if(input[i] == "minaf")
        return true;
    } else if (input[i] == "liga"){
        return true;
    } else if (input[i] == "des"){
        return true;
    } else if (input[i] == "move"){
        return true;
    } else if (input[i] == "vende"){
        i++;
        if(input[i] == "ferro")
        return true;
    } else if (input[i] == "cont"){
        i++;
        if(input[i] == "miner")
        return true;
    } else if (input[i] == "list"){
        return true;
    } else if (input[i] == "vende"){
        return true;
    } else if (input[i] == "next")
        return true;
    } else if (input[i] == "save"){
        return true;
    } else if (input[i] == "load"){
        return true;
    } else if (input[i] == "apaga"){
        return true;
    } else if (input[i] == "config"){
        return true;
    } else if (input[i] == "debcash"){
        return true;
    } else if (input[i] == "debed"){
        return true;
    } else if (input[i] == "debkil") {
        return true;
    }


    return false;
}
