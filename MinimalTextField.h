#ifndef MINIMALTEXTFIELD_H_INCLUDED
#define MINIMALTEXTFIELD_H_INCLUDED

/** MinimalTextField.h
 
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

class MinimalTextField : public BasicView {

	public:

        MinimalTextField();
		~MinimalTextField();

        void setup(string _str, int _x, int _y, int _font_size);

		void draw();
		void setPosition(int _x,int _y);
		void setText(string _str);
		void setText(string _str, bool _bold);
		void setTextBold();
		void setTextNormal();

		string getText();

    protected:
        int * font_color;
        bool bold;
        int font_size;
        string text;
        ofTrueTypeFont font;
		ofTrueTypeFont font_bold;

};

#endif // MINIMALTEXTFIELD_H_INCLUDED
