#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

namespace Korbo {
    class Main {
    public:
        Main();

        virtual ~Main();

        static int runKorbo(int argc, char *argv[]);
    };
}

#endif //PROJECT_MAIN_H
