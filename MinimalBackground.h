#ifndef MINIMALBACKGROUND_H_INCLUDED
#define MINIMALBACKGROUND_H_INCLUDED

/** MinimalBackground.h
 
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

#include "ofMain.h"
#include "BasicView.h"

class MinimalBackground : public BasicView {

	public:
		MinimalBackground();
		void setup(int _x, int _y, int _width, int _height);
		void setTransparency(float percentage);
		void draw();
    private:
        int transparency;
};

#endif // MINIMALBACKGROUND_H_INCLUDED
