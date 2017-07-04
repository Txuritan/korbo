#include "File.hpp"

namespace Korbo {
    namespace KIO {
        File::File() {

        }

        File::~File() {

        }

        std::ifstream::pos_type file_size(const std::string &filename) {
            std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
            std::ifstream::pos_type tmp_pos = in.tellg();
            in.close();
            return tmp_pos;
        }

        bool File::is_empty(const std::string &pFile) {
            return file_size(pFile) == 0;
        }

        int File::create_file() {
            return 0;
        }
    }
}