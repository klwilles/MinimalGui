/** MinimalTextField.cpp
 
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

#include "MinimalTextField.h"

MinimalTextField::MinimalTextField() {
    // color
    font_color = new int[4];

    for(int i=0; i<4; i++){
        font_color[i] = 255;
    }
    setup("Minimal Text Field", 0, 0, 10);
}
MinimalTextField::~MinimalTextField() {
    delete [] font_color;
    font_color = 0;
}
void MinimalTextField::setup(string _str, int _x, int _y, int _font_size) {

    x = _x;
    y = _y;
    text = _str;
    font_size = _font_size;

    // http://www.gnome.org/fonts/
    //8, 9, 10, 11, 12, 14, 16, 18, 20, 22, 24, 26, 28, 36, 48, 72
    //Plenty of space between lines, dotted zeros, clean.
    // font name, size, anti-aliased, full character set
	font.loadFont("verafont/VeraMono.ttf",font_size, true, true);
	font.setLineHeight(15.0f);
	font_bold.loadFont("verafont/VeraMoBd.ttf",font_size, true, true);
	font_bold.setLineHeight(15.0f);

    setPosition(_x,_y);
    setText(_str,false);

}
void MinimalTextField::setPosition(int _x, int _y) {
    x = _x;
    y = _y;
}
void MinimalTextField::setText(string _str) {
    text = _str;
    bold = false;
}
void MinimalTextField::setText(string _str, bool _bold) {
    text = _str;
    bold = _bold;
}
void MinimalTextField::setTextBold() {
    bold = true;
}
void MinimalTextField::setTextNormal() {
    bold = false;
}
string MinimalTextField::getText(){
    return text;
}
void MinimalTextField::draw() {
    ofSetColor(font_color[0], font_color[1], font_color[2]);
    if(bold==true){
        font.drawString(text, x, y);
    } else {
        font_bold.drawString(text, x, y);
    }
}
