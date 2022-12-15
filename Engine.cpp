#include "Engine.h"

void Engine::register_command(Wrapper* wrapper, std::string const& command_name) {
    if(wrapper == nullptr){
        throw std::runtime_error("Engine: command isn't exist");
    }
    if(commands.empty()) {
        commands.insert({command_name, wrapper});
    }
    else {
        for(auto& item: commands) {
            auto another_item = commands.find(command_name);
            if(another_item == commands.end()) {
                commands.insert({command_name, wrapper});
                break;
            }
            else {
                throw std::runtime_error("Engine: This command already exist");
            }
        }
    }
}

int Engine::execute(std::string const& command_name, std::map<std::string, int> const& params) {
    for(auto& it: commands) {
        if(it.first == command_name) {
            std::vector<int> result_vec;
            for(auto& item: it.second->parameters) {
                auto another_item = params.find(item.first);
                if(another_item != params.end()) {
                    result_vec.emplace_back(another_item->second);
                }
                else {
                    result_vec.emplace_back(item.second);
                }
            }
            return it.second->func(result_vec);
        }
        }
    throw std::runtime_error("Engine: This command is not registered");
}
