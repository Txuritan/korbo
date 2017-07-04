#include "Main.hpp"
#include "ui/UpdtWindow.hpp"

namespace Korbo {
    namespace KUpdt {
        Main::Main() {

        }

        Main::~Main() {

        }

        int Main::runUpDt(int argc, char **argv) {
            Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.github.txuritan.korbo.updt");

            Korbo::KUpdt::KUI::UpdtWindow updtWindow;
            updtWindow.set_default_size(400, 100);

            return app->run(updtWindow);
        }
    }
}

int main(int argc, char *argv[]) {
    return Korbo::KUpdt::Main::runUpDt(argc, argv);
}