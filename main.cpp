#include "Wrapper.h"
#include "Engine.h"
#include "Subject.h"


int main()
{
    Subject subj;
    Subject subj1;
    Subject subj2;

    Wrapper wrapper(&subj,&Subject::f3, {{"arg1",0}, {"arg2", 0}, {"arg3", 0}});
    Engine engine;
    engine.register_command(&wrapper, "command1");
    std::cout << engine.execute("command1",{{"arg1",4},{"arg2",5}}) << std::endl;

    Wrapper wrapper1(&subj1,&Subject::f1, {{"arg1",0}});
    Engine engine1;
    engine1.register_command(&wrapper1, "command2");
    std::cout << engine1.execute("command2",{{"arg1",4}}) << std::endl;

    Wrapper wrapper2(&subj2,&Subject::f2, {{"arg1",0},{"arg2",0}});
    Engine engine2;
    engine2.register_command(&wrapper2, "command3");
    std::cout << engine2.execute("command3",{{"arg1",4},{"arg2",3}}) << std::endl;


    return 0;
}