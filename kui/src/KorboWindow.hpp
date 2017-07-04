#ifndef PROJECT_KORBOWINDOW_H
#define PROJECT_KORBOWINDOW_H

#include <gtkmm.h>

namespace Korbo {
    namespace KUI {
        class KorboWindow : public Gtk::Window {
        public:
            KorboWindow();

            virtual ~KorboWindow();
        protected:
            Gtk::Box m_top_level_box;
            Gtk::MenuBar m_menu_bar;
            Gtk::MenuItem m_menu_bar_file_item;
            Gtk::Menu m_menu_bar_file_menu;
            Gtk::MenuItem m_menu_bar_file_quit_item;
            Gtk::MenuItem m_menu_bar_tools_item;
            Gtk::Menu m_menu_bar_tools_menu;
            Gtk::MenuItem m_menu_bar_tools_preferences_item;
            Gtk::MenuItem m_menu_bar_help_item;
            Gtk::Menu m_menu_bar_help_menu;
            Gtk::MenuItem m_menu_bar_help_check_for_updates_item;
            Gtk::SeparatorMenuItem m_menu_bar_help_check_about_separator_item;
            Gtk::MenuItem m_menu_bar_help_about_item;
            Gtk::Paned m_top_bottom_paned;
            Gtk::Paned m_top_left_right_paned;
            Gtk::Box m_top_left_box;
            Gtk::Box m_top_left_top_box;
            Gtk::Label m_profile_label;
            Gtk::ComboBoxText m_profile_combo_box;
            Gtk::Button m_profile_options_button;
            Gtk::Menu m_profile_options_menu;
            Gtk::Button m_profile_backup_button;
            Gtk::Button m_profile_restore_button;
            Gtk::ScrolledWindow m_mod_list_scrolled_window;
            Gtk::TreeView m_mod_list_tree_view;
            Gtk::Box m_top_left_bottom_box;
            Gtk::ComboBoxText m_filter_combo_box;
            Gtk::Entry m_search_filter_entry;
            Gtk::Box m_top_right_box;
            Gtk::Box m_top_right_top_box;
            Gtk::ComboBoxText m_mode_combo_box;
            Gtk::Button m_play_button;
            Gtk::Notebook m_notebook;
            Gtk::Label m_archives_tab_label;
            Gtk::Box m_archives_tab_box;
            Gtk::ScrolledWindow m_archives_tab_scrolled_window;
            Gtk::TreeView m_archives_tab_tree_view;
            Gtk::Label m_downloads_tab_label;
            Gtk::Box m_downloads_tab_box;
            Gtk::ScrolledWindow m_downloads_tab_scrolled_window;
            Gtk::ScrolledWindow m_console_scrolled_window;
            Gtk::TextView m_console_text_view;
            Gtk::Statusbar m_status_bar;

            Glib::RefPtr<Gtk::TreeStore> m_archives_tree_store;

            class ArchiveModelColumns : public Gtk::TreeModel::ColumnRecord {
            public:
                ArchiveModelColumns() {
                    add(m_name_column);
                }

                Gtk::TreeModelColumn<Glib::ustring> m_name_column;
            };

            ArchiveModelColumns m_archives_model_columns;

            Glib::RefPtr<Gtk::TreeStore> m_mods_tree_store;

            class ModsModelColumns : public Gtk::TreeModel::ColumnRecord {
            public:
                ModsModelColumns() {
                    add(m_enabled_column);
                    add(m_name_column);
                    add(m_version_column);
                }

                Gtk::TreeModelColumn<bool> m_enabled_column;
                Gtk::TreeModelColumn<Glib::ustring> m_name_column;
                Gtk::TreeModelColumn<Glib::ustring> m_version_column;
            };

            ModsModelColumns m_mods_model_columns;

            void on_menu_bar_file_quit_click();

            void on_menu_bar_tools_preferences_click();

            void on_menu_bar_help_about_click();
        };
    }
}

#endif //PROJECT_KORBOWINDOW_H
