#ifndef _BASIC_VIEW
#define _BASIC_VIEW

/** BasicView.h
 
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

class BasicView {

    public:
        virtual void draw() {};

        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }

	protected:
        int width;
        int height;
        int x;
        int y;
};

#endif
