#ifndef PROJECT_FILE_HPP
#define PROJECT_FILE_HPP

#include <string>

namespace Korbo {
    namespace KFile {
        class KFile {
        public:
            virtual ~KFile() {};

            virtual std::string getFileString() { return "";};

            virtual std::string getFileName() { return "";};
        };
    }
}

#endif //PROJECT_FILE_HPP
