#include "assignment.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using std::cout;
using std::endl;
int main(int argc, char* argv[]) {
    int ex = getExerciseNumber(argc, argv);
    switch (ex){
        case 1 :
            ex1(argc, argv);
            return 0;
        case 2:
            ex2();
            return 0;
        default:
            cout << "The exercise does not exist!" << endl;
            cout << "You specified exercise: " << ex << endl;
            return 0;
    }
}
int getExerciseNumber(int argc, char* argv[]){
    if(argc <= 0 || argc > 2) {
        cout << "Illegal Usage" << endl;
        exit(-2);
    }
    if (argc == 2) {
        // Grader provided argument
        std::string str(argv[1]);
        if(str.substr(0, 3) == "-ex") {
            int num = atoi(str.substr(3).c_str());
            if (num > 0) return num;
        }
        cout << "Illegal argument" << endl;
        exit(-3);
    }
    if (argc == 1){
        // Student running without argument
        int exerciseNum = 0;
        for(;;) {
            cout << "Please input your exercise number: ";
            std::cin >> exerciseNum;
            fflush(stdin);
            if(exerciseNum > 0) return exerciseNum;
            cout << "Illegal input, try again" << endl;
        }
    }
    return -1;
}

