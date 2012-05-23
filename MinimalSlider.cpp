/** MinimalSlider.cpp
 
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

#include "MinimalSlider.h"

MinimalSlider::MinimalSlider(){
    width = 300;
    height = 20;
    default_font_size = 8;
    float_precision = 4;
}
MinimalSlider::~MinimalSlider(){

}
void MinimalSlider::setup(float _value, float _min, float _max, int _x, int _y){
    setup( _value, _min, _max, _x, _y, width, height);
}
void MinimalSlider::setup(float _value, float _min, float _max, int _x, int _y, int _width, int _height){

    value = _value;
    min = _min;
    max = _max;

    // this is the slider [][][][][][][][][][][][]
    x = _x;
    slider.x = (float) x;
    y = _y;
    slider.y = (float) y;
    width = _width;
    slider.width = (float) width;
    height = _height;
    slider.height = (float) height;

    // label setup
    int half_width = (int)(width/2);
    int y_label_offset = y+default_font_size+4;
    int x_decimal_offset = 50;
    value_label.setup(ofToString(value, float_precision), (x+half_width-20), y_label_offset, default_font_size);
    min_label.setup(ofToString(min, float_precision), x+2, y_label_offset, default_font_size);
    max_label.setup(ofToString(max, float_precision), (width+x-x_decimal_offset), y_label_offset, default_font_size);

    updatePercentageFromValue();

}
void MinimalSlider::updateValue(float _newvalue){
    value = _newvalue;
    value_label.setText(ofToString(value, float_precision));
    updatePercentageFromValue();
}

void MinimalSlider::updatePercentageFromValue(){
    if(value<=max || value>=min){
        percent = ofNormalize(value, min, max);
    } else {
        percent = 1.0f;
    }
    slider.width = width * percent;
}
void MinimalSlider::draw(){

    ofSetColor(255,140,0); // dark orange
    ofRect(slider.x, slider.y, slider.width, slider.height);

    // draw outline of box
    ofNoFill();
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,150); // gray, transparent
    ofRect(x, y, width, height);
    ofDisableAlphaBlending();
    ofFill();

    value_label.draw();
    min_label.draw();
    max_label.draw();

}
