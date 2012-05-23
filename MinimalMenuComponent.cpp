/** MinimalMenuComponent.cpp
 
 Copyright (C) 2010  Kenneth Willes
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 */

#include "MinimalMenuComponent.h"

MinimalMenuComponent::MinimalMenuComponent(){
   menutype = 2; // label type by default
    // 768 wide screen, create width with 10 pixels on each side
    width = 768-20;
    height = 20;
    label_font_size = 10;
    default_background_transparency = 35;
}
MinimalMenuComponent::~MinimalMenuComponent(){

}
void MinimalMenuComponent::setupAsCheckbox(string _label, bool _checked, int _x, int _y){

    menutype = 0;

    x = _x;
    y = _y;

    background.setup(x,y,width,height);

    int checkbox_x_placement = (x+width) - checkbox.getWidth();
    checkbox.setup(_checked, checkbox_x_placement, y);

    label_x_offset = x+2;
    label_y_offset = y+label_font_size+2;
    label.setup(_label, label_x_offset, label_y_offset, label_font_size);

}
void MinimalMenuComponent::setupAsSlider(string _label, float _min, float _value, float _max, int _x, int _y){

    menutype = 1;

    x = _x;
    y = _y;

    int slider_x_placement = (x+width) - slider.getWidth();
    background.setup(x,y,width,height);
    slider.setup(_value, _min, _max, slider_x_placement, y);

    label_x_offset = x+2;
    label_y_offset = y+label_font_size+2;
    label.setup(_label, label_x_offset, label_y_offset, label_font_size);

}
void MinimalMenuComponent::setupAsLabel(string _label, int _x, int _y){

    menutype = 2;

    x = _x;
    y = _y;

    background.setup(x,y,width,height);
    background.setTransparency(100); // not background essentially

    label_x_offset = x+2;
    label_y_offset = y+label_font_size+2;
    label.setup(_label, label_x_offset, label_y_offset, label_font_size);

}
int MinimalMenuComponent::getMenuType(){
    return menutype;
}
string MinimalMenuComponent::getMenuLabel(){
    return label.getText();
}
void MinimalMenuComponent::updateCheckbox(bool _checked){
    if(menutype==0){
        if(_checked==true){
            checkbox.checkBox();
        } else {
            checkbox.uncheckBox();
        }
    }
}
void MinimalMenuComponent::updateSlider(float _value){
    if(menutype==1){
        slider.updateValue(_value);
    }
}
void MinimalMenuComponent::updateLabel(string _label){
    if(menutype==2){
        label.setText(_label);
    }
}
void MinimalMenuComponent::focus(){
    if(menutype==2){
        label.setTextBold();
    } else {
        background.setTransparency(65);
    }
}
void MinimalMenuComponent::unFocus(){
    if(menutype==2){
        label.setTextNormal();
    } else {
        background.setTransparency(default_background_transparency);
    }
}

void MinimalMenuComponent::draw(){

    background.draw();

    label.draw();

    if(menutype==0){
        checkbox.draw();
    } else if(menutype==1){
        slider.draw();
    }

}
