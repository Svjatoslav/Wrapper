#include <iostream>

class Subject
        {
public:

    Subject() = default;
    ~Subject() = default;


    int f1(int x){
        return x;
    }

    int f2(int x, int y){
        return (x + y);
    }

    int f3(int x, int y, int z){
        return (x * y * z);
    }




};


