#ifndef PROJECT_FILESETTINGS_H
#define PROJECT_FILESETTINGS_H

#include <string>
#include "KFile.hpp"

namespace Korbo {
    namespace KFile {
        class FileSettings : public Korbo::KFile::KFile  {
        public:
            virtual ~FileSettings();

            std::string getFileName() {
                return "settings.json";
            }

            std::string getFileString() {
                return ("{\n"
                        "    \"java\": {\n"
                        "        \"commands\": {\n"
                        "            \"post-exit\": \"\",\n"
                        "            \"pre-launch\": \"\",\n"
                        "            \"wrapper\": \"\"\n"
                        "        },\n"
                        "        \"memory\": {\n"
                        "            \"allocation\": {\n"
                        "                \"max\": 1024,\n"
                        "                \"min\": 512\n"
                        "            },\n"
                        "            \"perm\": 128\n"
                        "        },\n"
                        "        \"runtime\": {\n"
                        "            \"arguments\": \"\",\n"
                        "            \"path\": \"\"\n"
                        "        }\n"
                        "    },\n"
                        "    \"minecraft\": {\n"
                        "        \"window\": {\n"
                        "            \"height\": 1346,\n"
                        "            \"width\": 757\n"
                        "        }\n"
                        "    },\n"
                        "    \"korbo\": {\n"
                        "        \"analytics\": {\n"
                        "            \"enabled\": true\n"
                        "        },\n"
                        "        \"console\": {\n"
                        "            \"font\": {\n"
                        "                \"name\": \"\",\n"
                        "                \"size\": 14\n"
                        "            }\n"
                        "        },\n"
                        "        \"features\": {\n"
                        "            \"folders\": {\n"
                        "                \"downloads\": \"$root/downloads\",\n"
                        "                \"java\": \"$root/java\",\n"
                        "                \"libraries\": \"$root/libraries\",\n"
                        "                \"mods\": \"$root/mods\",\n"
                        "                \"profiles\": \"$root/profiles\"\n"
                        "            },\n"
                        "            \"ftb\": {\n"
                        "                \"path\": \"$root/ftb\",\n"
                        "                \"track\": false\n"
                        "            },\n"
                        "            \"multimc\": {\n"
                        "                \"path\": \"$root/multimc\",\n"
                        "                \"track\": false\n"
                        "            },\n"
                        "            \"update\": {\n"
                        "                \"check\": true,\n"
                        "                \"mode\": \"release\"\n"
                        "            }\n"
                        "        },\n"
                        "        \"interface\": {\n"
                        "            \"language\": \"en_us\",\n"
                        "            \"status-bar\": {\n"
                        "                \"new\": true,\n"
                        "                \"stats\": true\n"
                        "            }\n"
                        "        }\n"
                        "    }\n"
                        "}");
            }
        };
    }
}

#endif //PROJECT_FILESETTINGS_H
