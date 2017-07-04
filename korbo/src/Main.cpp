#include "Main.hpp"

#include <KorboWindow.hpp>
#include <StartUp.hpp>

#include <gtkmm.h>

namespace Korbo {
    Main::Main() {

    }

    Main::~Main() {

    }

    int Main::runKorbo(int argc, char *argv[]) {

        Korbo::KLogc::StartUp startUp = Korbo::KLogc::StartUp();
        startUp.run();

        Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.github.txuritan.korbo");

        Korbo::KUI::KorboWindow korboWindow;
        korboWindow.set_default_size(600, 400);

        return app->run(korboWindow);
    }
}

int main(int argc, char *argv[]) {
    return Korbo::Main::runKorbo(argc, argv);
}