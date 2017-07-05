#include "KorboWindow.hpp"
#include "AboutDialog.hpp"
#include "PreferencesDialog.hpp"
#include "json.hpp"

#include <fstream>

namespace Korbo {
    namespace KUI {
        KorboWindow::KorboWindow() {

            nlohmann::json i18n_json;
            std::ifstream i18n_ifstream("i18n.json");
            i18n_ifstream >> i18n_json;

            nlohmann::json settings_json;
            std::ifstream settings_ifstream("settings.json");
            settings_ifstream >> settings_json;

            std::string i18n = settings_json["korbo"]["interface"]["language"].get<std::string>();

            set_title(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["title"].get<std::string>()));
            set_icon(Gdk::Pixbuf::create_from_file("korbo.png"));
            set_size_request(800, 600);

            m_top_level_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
            m_top_level_box.pack_start(m_menu_bar, FALSE, TRUE, 0);

            m_menu_bar.append(m_menu_bar_file_item);
            m_menu_bar_file_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["file"]["name"].get<std::string>()));
            m_menu_bar_file_item.set_submenu(m_menu_bar_file_menu);
            m_menu_bar_file_menu.append(m_menu_bar_file_quit_item);
            m_menu_bar_file_quit_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["file"]["quit"].get<std::string>()));
            m_menu_bar_file_quit_item.signal_activate().connect(sigc::mem_fun(*this, &on_menu_bar_file_quit_click));

            m_menu_bar.append(m_menu_bar_tools_item);
            m_menu_bar_tools_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["tools"]["name"].get<std::string>()));
            m_menu_bar_tools_item.set_submenu(m_menu_bar_tools_menu);
            m_menu_bar_tools_menu.append(m_menu_bar_tools_preferences_item);
            m_menu_bar_tools_preferences_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["tools"]["preferences"].get<std::string>()));
            m_menu_bar_tools_preferences_item.signal_activate().connect(sigc::mem_fun(*this, &on_menu_bar_tools_preferences_click));

            m_menu_bar.append(m_menu_bar_help_item);
            m_menu_bar_help_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["help"]["name"].get<std::string>()));
            m_menu_bar_help_item.set_submenu(m_menu_bar_help_menu);
            m_menu_bar_help_menu.append(m_menu_bar_help_check_for_updates_item);
            m_menu_bar_help_check_for_updates_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["help"]["check-for-updates"].get<std::string>()));
            m_menu_bar_help_menu.append(m_menu_bar_help_check_about_separator_item);
            m_menu_bar_help_menu.append(m_menu_bar_help_about_item);
            m_menu_bar_help_about_item.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["menu"]["help"]["about"].get<std::string>()));
            m_menu_bar_help_about_item.signal_activate().connect(sigc::mem_fun(*this, &on_menu_bar_help_about_click));

            m_top_bottom_paned.set_orientation(Gtk::ORIENTATION_VERTICAL);
            m_top_bottom_paned.set_wide_handle(TRUE);
            m_top_bottom_paned.set_margin_start(2);
            m_top_bottom_paned.set_margin_end(2);
            m_top_bottom_paned.pack1(m_top_left_right_paned, TRUE, TRUE);
            m_top_left_right_paned.set_wide_handle(TRUE);

            m_top_left_right_paned.add1(m_top_left_box);
            m_top_left_box.set_orientation(Gtk::ORIENTATION_VERTICAL);

            m_top_left_box.pack_start(m_top_left_top_box, FALSE, TRUE, 0);

            m_top_left_top_box.pack_start(m_profile_label, FALSE, TRUE, 0);
            m_profile_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["labels"]["profile"].get<std::string>()));
            m_profile_label.set_margin_end(3);

            m_top_left_top_box.pack_start(m_profile_combo_box, TRUE, TRUE, 0);

            m_top_left_top_box.pack_start(m_profile_options_button, FALSE, TRUE, 0);
            m_profile_options_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["buttons"]["options"].get<std::string>()));

            m_top_left_top_box.pack_start(m_profile_backup_button, FALSE, TRUE, 0);
            m_profile_backup_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["buttons"]["backup"].get<std::string>()));

            m_top_left_top_box.pack_start(m_profile_restore_button, FALSE, TRUE, 0);
            m_profile_restore_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["buttons"]["restore"].get<std::string>()));

            m_top_left_box.pack_start(m_mod_list_scrolled_window, TRUE, TRUE, 0);
            m_mod_list_scrolled_window.add(m_mod_list_tree_view);
            m_mod_list_tree_view.unset_model();
            m_mods_tree_store = Gtk::TreeStore::create(m_mods_model_columns);
            m_mod_list_tree_view.append_column(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["table"]["mods"]["enabled"].get<std::string>()), m_mods_model_columns.m_enabled_column);
            m_mod_list_tree_view.append_column(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["table"]["mods"]["name"].get<std::string>()), m_mods_model_columns.m_name_column);
            m_mod_list_tree_view.append_column(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["table"]["mods"]["version"].get<std::string>()), m_mods_model_columns.m_version_column);
            m_mod_list_tree_view.set_model(m_mods_tree_store);

            m_top_left_box.pack_start(m_top_left_bottom_box, FALSE, TRUE, 0);
            m_top_left_bottom_box.pack_end(m_filter_combo_box, FALSE, TRUE, 0);
            m_filter_combo_box.set_size_request(200, m_filter_combo_box.get_height());
            m_top_left_bottom_box.pack_end(m_search_filter_entry, FALSE, TRUE, 0);

            m_top_left_right_paned.pack2(m_top_right_box, TRUE, TRUE);
            m_top_right_box.set_orientation(Gtk::ORIENTATION_VERTICAL);

            m_top_right_box.pack_start(m_top_right_top_box, FALSE, TRUE);
            m_top_right_top_box.pack_start(m_mode_combo_box, TRUE, TRUE);
            m_top_right_top_box.pack_start(m_play_button, FALSE, TRUE);
            m_play_button.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["buttons"]["play"].get<std::string>()));

            m_top_right_box.pack_start(m_notebook, TRUE, TRUE);

            m_notebook.append_page(m_archives_tab_box, m_archives_tab_label);
            m_archives_tab_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["notebooks"]["mods"]["labels"]["archives"].get<std::string>()));
            m_archives_tab_box.pack_start(m_archives_tab_scrolled_window, TRUE, TRUE);
            m_archives_tab_scrolled_window.add(m_archives_tab_tree_view);
            m_archives_tab_tree_view.unset_model();
            m_archives_tree_store = Gtk::TreeStore::create(m_archives_model_columns);
            m_archives_tab_tree_view.append_column(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["table"]["archives"]["name"].get<std::string>()), m_archives_model_columns.m_name_column);
            m_archives_tab_tree_view.set_model(m_archives_tree_store);

            m_notebook.append_page(m_downloads_tab_box, m_downloads_tab_label);
            m_downloads_tab_label.set_label(Glib::ustring(i18n_json[i18n]["korbo"]["window"]["notebooks"]["mods"]["labels"]["downloads"].get<std::string>()));
            m_downloads_tab_box.pack_start(m_downloads_tab_scrolled_window, TRUE, TRUE);

            m_top_bottom_paned.pack2(m_console_scrolled_window, TRUE, TRUE);
            m_console_scrolled_window.add(m_console_text_view);
            m_console_text_view.set_editable(FALSE);

            m_top_level_box.pack_start(m_top_bottom_paned, TRUE, TRUE, 0);
            m_top_level_box.pack_start(m_status_bar, FALSE, TRUE, 0);

            add(m_top_level_box);

            show_all_children();
        };

        KorboWindow::~KorboWindow() {

        };

        void KorboWindow::on_menu_bar_file_quit_click() {
            exit(1);
        }

        void KorboWindow::on_menu_bar_tools_preferences_click() {
            Korbo::KUI::PreferencesDialog preferencesDialog;
            preferencesDialog.set_transient_for(*this);
            preferencesDialog.show_all_children();
            int result = preferencesDialog.run();
            switch (result) {
                case 1:
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        }

        void KorboWindow::on_menu_bar_help_about_click() {
            Korbo::KUI::AboutDialog aboutDialog;
            aboutDialog.set_transient_for(*this);
            aboutDialog.show_all_children();
            aboutDialog.run();
        }
    }
}