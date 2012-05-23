/** MinimalCheckBox.cpp
 
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

#include "MinimalCheckBox.h"

MinimalCheckBox::MinimalCheckBox(){
   width = 20;
   height = 20;
}
MinimalCheckBox::~MinimalCheckBox(){

}
void MinimalCheckBox::setup(bool _checked, int _x, int _y){
    setup(_checked,_x,_y,width,height);
}
void MinimalCheckBox::setup(bool _checked, int _x, int _y, int _width, int _height){

    // background size
    x = _x;
    y = _y;
    width = _width;
    height = _height;

    // setup checkmark slightly smaller than background
    checked = _checked;
    check_mark.x = (float) (x+2);
    check_mark.y = (float) (y+2);
    check_mark.width = (float) (width-2);
    check_mark.height = (float) (height-2);

}
bool MinimalCheckBox::getCheckedState(){
    return checked;
}
void MinimalCheckBox::checkBox(){
    checked = true;
}
void MinimalCheckBox::uncheckBox(){
    checked = false;
}
void MinimalCheckBox::draw(){

    ofSetColor(139,0,0); // dark red
    ofRect(x, y, width, height);

    // checkbox
    if(checked==true){
        ofSetColor(255,255,255); // white
        ofLine(check_mark.x, check_mark.y, x+check_mark.height, y+check_mark.width);
    }

}
