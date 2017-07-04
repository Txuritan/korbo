#ifndef PROJECT_ABOUTDIALOG_H
#define PROJECT_ABOUTDIALOG_H

#include <gtkmm.h>

namespace Korbo {
    namespace KUI {
        class AboutDialog : public Gtk::Dialog {
        public:
            AboutDialog();
            virtual ~AboutDialog();

        protected:
            Gtk::Notebook m_about_notebook;

            Gtk::Label m_tab_about_label;
            Gtk::Box m_tab_about_box;
            Gtk::Label m_about_name_label;
            Gtk::Label m_about_version_label;
            Gtk::Label m_about_about_label;
            Gtk::Label m_about_link_label;
            Gtk::Label m_about_copyright_label;

            Gtk::Label m_tab_credits_label;
            Gtk::ScrolledWindow m_tab_credits_scrolled_window;
            Gtk::TextView m_tab_credits_text_view;

            Gtk::Label m_tab_license_label;
            Gtk::ScrolledWindow m_tab_license_scrolled_window;
            Gtk::TextView m_tab_license_text_view;
        };
    }
}

#endif //PROJECT_ABOUTDIALOG_H
