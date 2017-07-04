#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

namespace Korbo {
    namespace KUpdt {
        class Main {
        public:
            Main();

            virtual ~Main();

            static int runUpDt(int argc, char *argv[]);
        };
    }
}

#endif //PROJECT_MAIN_H
