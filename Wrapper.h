#ifndef WRAPPER_ENGINE_WRAPPER_H
#define WRAPPER_ENGINE_WRAPPER_H
#include <iostream>
#include <map>
#include <functional>
#include <vector>

class Wrapper
        {
    friend class Engine;

    std::map<std::string, int> parameters;
    std::function<int(std::vector<int>)> func;
    template<class T, class ...Args, size_t ...I>
    int call_fun(T* instance, int(T::*fun)(Args...), std::vector<int> const& par, std::index_sequence<I...>){
        return  (instance->*fun)(par[I]...);
    }

public:

    Wrapper() = delete;
    ~Wrapper() = default;
    Wrapper& operator=(Wrapper const&) = delete;
    Wrapper(Wrapper&&) = default;
    Wrapper& operator=(Wrapper&&) = default;



    template<class T, class ...Args>
    Wrapper(T* instance, int(T::*fun)(Args...), std::vector<std::pair<std::string, int>> const& params) {
        if(!instance || !fun){
            throw std::exception();
        }
        for(auto& item: params) {
            auto another_item = parameters.find(item.first);
            if(another_item == parameters.end()) {
                parameters.insert(item);
            }
            else {
                throw std::runtime_error("Wrapper: invalid argument");
            }
        }
        func = [instance, fun, this] (std::vector<int> const& par) -> int {
            return call_fun(instance, fun, par, std::make_index_sequence<sizeof...(Args)>{});
        };
    }
};


#endif


