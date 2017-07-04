#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H

#include <fstream>

namespace Korbo {
    namespace KIO {
        class File {
        public:
            File();

            virtual ~File();

            static bool is_empty(const std::string &pFile);

            static int create_file();
        };
    }
}

#endif //PROJECT_FILE_H
