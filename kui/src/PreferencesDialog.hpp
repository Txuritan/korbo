#ifndef PROJECT_PREFERENCESDIALOG_H
#define PROJECT_PREFERENCESDIALOG_H

#include <gtkmm.h>

namespace Korbo {
    namespace KUI {
        class PreferencesDialog : public Gtk::Dialog {
        public:
            PreferencesDialog();
            virtual ~PreferencesDialog();
        protected:
            Gtk::Notebook m_preferences_notebook;

            Gtk::Label m_tab_korbo_label;
            Gtk::ScrolledWindow m_tab_korbo_scrolled_window;
            Gtk::Notebook m_korbo_notebook;

            Gtk::Label m_tab_korbo_features_label;
            Gtk::Box m_tab_korbo_features_box;
            Gtk::Frame m_tab_korbo_features_update_frame;
            Gtk::Grid m_tab_korbo_features_update_grid;
            Gtk::Label m_tab_korbo_features_update_enable_label;
            Gtk::CheckButton m_tab_korbo_features_update_enable_check_button;
            Gtk::Label m_tab_korbo_features_update_mode_label;
            Gtk::ComboBoxText m_tab_korbo_features_update_mode_combo_box;
            Gtk::Frame m_tab_korbo_features_multimc_frame;
            Gtk::Grid m_tab_korbo_features_multimc_grid;
            Gtk::Frame m_tab_korbo_features_ftb_frame;
            Gtk::Grid m_tab_korbo_features_ftb_grid;
            Gtk::Frame m_tab_korbo_features_folders_frame;
            Gtk::Grid m_tab_korbo_features_folders_grid;
            Gtk::Label m_tab_korbo_features_folders_downloads_label;
            Gtk::Entry m_tab_korbo_features_folders_downloads_entry;
            Gtk::Button m_tab_korbo_features_folders_downloads_button;
            Gtk::Label m_tab_korbo_features_folders_java_label;
            Gtk::Entry m_tab_korbo_features_folders_java_entry;
            Gtk::Button m_tab_korbo_features_folders_java_button;
            Gtk::Label m_tab_korbo_features_folders_libraries_label;
            Gtk::Entry m_tab_korbo_features_folders_libraries_entry;
            Gtk::Button m_tab_korbo_features_folders_libraries_button;
            Gtk::Label m_tab_korbo_features_folders_mods_label;
            Gtk::Entry m_tab_korbo_features_folders_mods_entry;
            Gtk::Button m_tab_korbo_features_folders_mods_button;
            Gtk::Label m_tab_korbo_features_folders_profiles_label;
            Gtk::Entry m_tab_korbo_features_folders_profiles_entry;
            Gtk::Button m_tab_korbo_features_folders_profiles_button;

            Gtk::Label m_tab_korbo_interface_label;
            Gtk::Box m_tab_korbo_interface_box;

            Gtk::Label m_tab_korbo_console_label;
            Gtk::Box m_tab_korbo_console_box;

            Gtk::Label m_tab_korbo_analytics_label;
            Gtk::Box m_tab_korbo_analytics_box;

            Gtk::Label m_tab_minecraft_label;
            Gtk::ScrolledWindow m_tab_minecraft_scrolled_window;

            Gtk::Label m_tab_java_label;
            Gtk::ScrolledWindow m_tab_java_scrolled_window;

            Gtk::Label m_tab_accounts_label;
            Gtk::ScrolledWindow m_tab_accounts_scrolled_window;
        };
    }
}

#endif //PROJECT_PREFERENCESDIALOG_H
