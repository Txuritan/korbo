#include "PreferencesDialog.hpp"
#include "json.hpp"

#include <fstream>

namespace Korbo {
    namespace KUI {
        PreferencesDialog::PreferencesDialog() {

            nlohmann::json i18n_json;
            std::ifstream i18n_ifstream("i18n.json");
            i18n_ifstream >> i18n_json;
            i18n_ifstream.close();

            nlohmann::json settings_json;
            std::ifstream settings_ifstream("settings.json");
            settings_ifstream >> settings_json;
            settings_ifstream.close();

            std::string i18n = settings_json["korbo"]["interface"]["language"].get<std::string>();

            set_title(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["title"].get<std::string>()));
            set_size_request(600, 400);

            get_vbox()->pack_start(m_preferences_notebook, TRUE, TRUE);
            m_preferences_notebook.set_tab_pos(Gtk::PositionType::POS_LEFT);

            m_preferences_notebook.append_page(m_tab_korbo_scrolled_window, m_tab_korbo_label);
            m_tab_korbo_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["left"]["labels"]["korbo"].get<std::string>()));
            m_tab_korbo_scrolled_window.add(m_korbo_notebook);

            m_korbo_notebook.append_page(m_tab_korbo_features_box, m_tab_korbo_features_label);
            m_tab_korbo_features_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
            m_tab_korbo_features_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["top"]["labels"]["features"].get<std::string>()));

            m_tab_korbo_features_box.pack_start(m_tab_korbo_features_update_frame, FALSE, TRUE);
            m_tab_korbo_features_update_frame.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["update-settings"]["title"].get<std::string>()));
            m_tab_korbo_features_update_frame.set_margin_bottom(4);
            m_tab_korbo_features_update_frame.add(m_tab_korbo_features_update_grid);
            m_tab_korbo_features_update_grid.set_column_spacing(4);
            m_tab_korbo_features_update_grid.attach(m_tab_korbo_features_update_enable_label, 0, 0, m_tab_korbo_features_update_enable_label.get_width(), m_tab_korbo_features_update_enable_label.get_height());
            m_tab_korbo_features_update_enable_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["update-settings"]["labels"]["check-for-updates"].get<std::string>()));
            m_tab_korbo_features_update_grid.attach(m_tab_korbo_features_update_enable_check_button, 1, 0, m_tab_korbo_features_update_enable_check_button.get_width(), m_tab_korbo_features_update_enable_check_button.get_height());
            m_tab_korbo_features_update_enable_check_button.set_hexpand(TRUE);
            m_tab_korbo_features_update_enable_check_button.set_active(settings_json["korbo"]["features"]["update"]["check"].get<bool>() ? TRUE : FALSE);
            m_tab_korbo_features_update_grid.attach(m_tab_korbo_features_update_mode_label, 0, 1, m_tab_korbo_features_update_mode_label.get_width(), m_tab_korbo_features_update_mode_label.get_height());
            m_tab_korbo_features_update_mode_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["update-settings"]["labels"]["update-branch"].get<std::string>()));
            m_tab_korbo_features_update_grid.attach(m_tab_korbo_features_update_mode_combo_box, 1, 1, m_tab_korbo_features_update_mode_combo_box.get_width(), m_tab_korbo_features_update_mode_combo_box.get_height());
            m_tab_korbo_features_update_mode_combo_box.set_hexpand(TRUE);

            m_tab_korbo_features_box.pack_start(m_tab_korbo_features_multimc_frame, FALSE, TRUE);
            m_tab_korbo_features_multimc_frame.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["multimc-settings"]["title"].get<std::string>()));
            m_tab_korbo_features_multimc_frame.set_margin_bottom(4);
            m_tab_korbo_features_multimc_frame.add(m_tab_korbo_features_multimc_grid);
            m_tab_korbo_features_multimc_grid.set_column_spacing(4);

            m_tab_korbo_features_box.pack_start(m_tab_korbo_features_ftb_frame, FALSE, TRUE);
            m_tab_korbo_features_ftb_frame.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["ftb-settings"]["title"].get<std::string>()));
            m_tab_korbo_features_ftb_frame.set_margin_bottom(4);
            m_tab_korbo_features_ftb_frame.add(m_tab_korbo_features_ftb_grid);
            m_tab_korbo_features_ftb_grid.set_column_spacing(4);

            m_tab_korbo_features_box.pack_start(m_tab_korbo_features_folders_frame, FALSE, TRUE);
            m_tab_korbo_features_folders_frame.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["title"].get<std::string>()));
            m_tab_korbo_features_folders_frame.add(m_tab_korbo_features_folders_grid);
            m_tab_korbo_features_folders_grid.set_column_spacing(4);
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_downloads_label, 0, 0, m_tab_korbo_features_folders_downloads_label.get_width(), m_tab_korbo_features_folders_downloads_label.get_height());
            m_tab_korbo_features_folders_downloads_label.set_text(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["labels"]["downloads-folder"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_downloads_entry, 1, 0, m_tab_korbo_features_folders_downloads_entry.get_width(), m_tab_korbo_features_folders_downloads_entry.get_height());
            m_tab_korbo_features_folders_downloads_entry.set_hexpand(TRUE);
            m_tab_korbo_features_folders_downloads_entry.set_text(Glib::ustring(settings_json["korbo"]["features"]["folders"]["downloads"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_downloads_button, 2, 0, m_tab_korbo_features_folders_downloads_button.get_width(), m_tab_korbo_features_folders_downloads_button.get_height());
            m_tab_korbo_features_folders_downloads_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["..."].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_java_label, 0, 1, m_tab_korbo_features_folders_java_label.get_width(), m_tab_korbo_features_folders_java_label.get_height());
            m_tab_korbo_features_folders_java_label.set_text(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["labels"]["java-folder"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_java_entry, 1, 1, m_tab_korbo_features_folders_java_entry.get_width(), m_tab_korbo_features_folders_java_entry.get_height());
            m_tab_korbo_features_folders_java_entry.set_hexpand(TRUE);
            m_tab_korbo_features_folders_java_entry.set_text(Glib::ustring(settings_json["korbo"]["features"]["folders"]["java"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_java_button, 2, 1, m_tab_korbo_features_folders_java_button.get_width(), m_tab_korbo_features_folders_java_button.get_height());
            m_tab_korbo_features_folders_java_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["..."].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_libraries_label, 0, 2, m_tab_korbo_features_folders_libraries_label.get_width(), m_tab_korbo_features_folders_libraries_label.get_height());
            m_tab_korbo_features_folders_libraries_label.set_text(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["labels"]["libraries-folder"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_libraries_entry, 1, 2, m_tab_korbo_features_folders_libraries_entry.get_width(), m_tab_korbo_features_folders_libraries_entry.get_height());
            m_tab_korbo_features_folders_libraries_entry.set_hexpand(TRUE);
            m_tab_korbo_features_folders_libraries_entry.set_text(Glib::ustring(settings_json["korbo"]["features"]["folders"]["libraries"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_libraries_button, 2, 2, m_tab_korbo_features_folders_libraries_button.get_width(), m_tab_korbo_features_folders_libraries_button.get_height());
            m_tab_korbo_features_folders_libraries_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["..."].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_mods_label, 0, 3, m_tab_korbo_features_folders_mods_label.get_width(), m_tab_korbo_features_folders_mods_label.get_height());
            m_tab_korbo_features_folders_mods_label.set_text(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["labels"]["mods-folder"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_mods_entry, 1, 3, m_tab_korbo_features_folders_mods_entry.get_width(), m_tab_korbo_features_folders_mods_entry.get_height());
            m_tab_korbo_features_folders_mods_entry.set_hexpand(TRUE);
            m_tab_korbo_features_folders_mods_entry.set_text(Glib::ustring(settings_json["korbo"]["features"]["folders"]["mods"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_mods_button, 2, 3, m_tab_korbo_features_folders_mods_button.get_width(), m_tab_korbo_features_folders_mods_button.get_height());
            m_tab_korbo_features_folders_mods_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["..."].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_profiles_label, 0, 4, m_tab_korbo_features_folders_profiles_label.get_width(), m_tab_korbo_features_folders_profiles_label.get_height());
            m_tab_korbo_features_folders_profiles_label.set_text(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["labels"]["profiles-folder"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_profiles_entry, 1, 4, m_tab_korbo_features_folders_profiles_entry.get_width(), m_tab_korbo_features_folders_profiles_entry.get_height());
            m_tab_korbo_features_folders_profiles_entry.set_hexpand(TRUE);
            m_tab_korbo_features_folders_profiles_entry.set_text(Glib::ustring(settings_json["korbo"]["features"]["folders"]["profiles"].get<std::string>()));
            m_tab_korbo_features_folders_grid.attach(m_tab_korbo_features_folders_profiles_button, 2, 4, m_tab_korbo_features_folders_profiles_button.get_width(), m_tab_korbo_features_folders_profiles_button.get_height());
            m_tab_korbo_features_folders_profiles_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["frames"]["folder-settings"]["..."].get<std::string>()));

            m_korbo_notebook.append_page(m_tab_korbo_interface_box, m_tab_korbo_interface_label);
            m_tab_korbo_interface_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["top"]["labels"]["interface"].get<std::string>()));

            m_korbo_notebook.append_page(m_tab_korbo_console_box, m_tab_korbo_console_label);
            m_tab_korbo_console_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["top"]["labels"]["console"].get<std::string>()));

            m_korbo_notebook.append_page(m_tab_korbo_analytics_box, m_tab_korbo_analytics_label);
            m_tab_korbo_analytics_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["top"]["labels"]["analytics"].get<std::string>()));

            m_preferences_notebook.append_page(m_tab_minecraft_scrolled_window, m_tab_minecraft_label);
            m_tab_minecraft_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["left"]["labels"]["minecraft"].get<std::string>()));

            m_preferences_notebook.append_page(m_tab_java_scrolled_window, m_tab_java_label);
            m_tab_java_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["left"]["labels"]["java"].get<std::string>()));

            m_preferences_notebook.append_page(m_tab_accounts_scrolled_window, m_tab_accounts_label);
            m_tab_accounts_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["notebooks"]["left"]["labels"]["accounts"].get<std::string>()));

            add_button(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["ok"].get<std::string>()), 1);
            add_button(Glib::ustring(i18n_json[i18n]["korbo"]["dialog"]["preferences"]["cancel"].get<std::string>()), 0);
        }

        PreferencesDialog::~PreferencesDialog() {

        }
    }
}