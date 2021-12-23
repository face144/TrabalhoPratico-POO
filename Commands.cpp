#include "Commands.h"

Commands::Commands() {
    input.emplace_back("undef");
}

Commands::~Commands() {

}

int Commands::GetInput() {
    auto* cmd = new Commands;
    int i = 0;

    getline( cin, cmd->input.at(i));


    i = 0;
    int exit_code = -1;
    if ( cmd->input.at(i) == "next")
        exit_code = 2;

    else if ( cmd->input.at(i) == "cons" )
        exit_code = 1;

    else exit_code = 0;

    delete cmd;
    return exit_code;

}
