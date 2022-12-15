#ifndef MAIN_CPP_ENGINE_H
#define MAIN_CPP_ENGINE_H
#include "Wrapper.h"

class Engine {
private:
    std::map<std::string, Wrapper*> commands;

public:
    void register_command(Wrapper* wrapper, std::string const& command_name);
    int execute(std::string const& command_name, std::map<std::string, int> const& params);

    Engine() = default;
};
#endif