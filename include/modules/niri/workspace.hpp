#pragma once

#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <json/value.h>
#include "modules/niri/backend.hpp"

namespace waybar::modules::niri {

  class Workspaces; 
  
  class Workspace {
  public:
  
    Workspace(const Json::Value& data, Workspaces& manager);
  
    Gtk::Button& button() { return button_; }
  
    void update(const Json::Value& data, const Json::Value& all_windows);
  
    uint64_t id() const { return id_; }
  
  private:
    void updateTaskbar(const Json::Value& my_windows);
    
    Workspaces& manager_;
    uint64_t id_;
  
  
    Gtk::Button button_;
    Gtk::Box box_;          
    Gtk::Label label_;       
    Gtk::Box taskbar_box_;
  };

}