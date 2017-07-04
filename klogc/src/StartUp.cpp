#include "StartUp.hpp"

#include <KFile.hpp>
#include <FileI18n.hpp>
#include <FileSettings.hpp>
#include <File.hpp>

#include <list>
#include <iomanip>
#include <json.hpp>

namespace Korbo {
    namespace KLogc {
        StartUp::StartUp() {

        }

        StartUp::~StartUp() {

        }

        void StartUp::run() {
            std::list<Korbo::KFile::KFile *> files = {
                    new Korbo::KFile::FileI18n(),
                    new Korbo::KFile::FileSettings()
            };

            for (auto it = files.begin(); it != files.end(); ++it) {
                std::fstream file_fstream;
                file_fstream.open((*it)->getFileName(), std::fstream::in | std::fstream::out | std::fstream::app);
                file_fstream.close();
                if (Korbo::KIO::File::is_empty((*it)->getFileName())) {

                    nlohmann::json content = nlohmann::json::parse((*it)->getFileString());

                    std::ofstream file_ofstream((*it)->getFileName());
                    file_ofstream << std::setw(4) << content << std::endl;
                    file_ofstream.close();
                }
            }
        }
    }
}