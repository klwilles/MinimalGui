/** MinimalBackground.cpp
 
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

#include "MinimalBackground.h"

MinimalBackground::MinimalBackground() {
    setup(0,0,100,100);
}
void MinimalBackground::setup(int _x, int _y, int _width, int _height) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    setTransparency(35); // set default percentage
}
void MinimalBackground::setTransparency(float percentage){
    float p = percentage/100;
    p = ofClamp(p, 0.0f, 1.0f);
    transparency = (int)(255*p);
}

void MinimalBackground::draw() {
    // draw transparent background
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, transparency);
    ofRect(x, y, width, height);
    ofDisableAlphaBlending();
}
