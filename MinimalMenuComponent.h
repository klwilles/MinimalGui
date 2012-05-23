#ifndef MINIMALMENUCOMPONENT_H_INCLUDED
#define MINIMALMENUCOMPONENT_H_INCLUDED

/** MinimalMenuComponent.h
 
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
 
 This menu displays a menu item with either a checkbox, slider
 or just a label (for category title).
 
 menutype = 0 / checkbox
 menutype = 1 / slider
 menutype = 2 / label
 
 The menu font renders nicely with http://www.gnome.org/fonts/
 
 */


#include "ofMain.h" //dependent file from here http://openframeworks.cc
#include "BasicView.h"
#include "MinimalBackground.h"
#include "MinimalTextField.h"
#include "MinimalSlider.h"
#include "MinimalCheckBox.h"

class MinimalMenuComponent : public BasicView {

	public:

        MinimalMenuComponent();
		~MinimalMenuComponent();

        void setupAsCheckbox(string _label, bool _checked, int _x, int _y);
        void setupAsSlider(string _label, float _min, float _value, float _max, int _x, int _y);
        void setupAsLabel(string _label, int _x, int _y);

        int getMenuType();
        string getMenuLabel();

        void updateCheckbox(bool _checked);
        void updateSlider(float _value);
        void updateLabel(string _label);

        void focus();
        void unFocus();

		void draw();


    protected:

        // [0] - Checkbox,
        // [1] - Slider,
        // [2] - Label

        int menutype;
        int label_font_size;
        int label_y_offset;
        int label_x_offset;
        int default_background_transparency;

        MinimalBackground background;
        MinimalTextField label;
        MinimalCheckBox checkbox;
        MinimalSlider slider;

};

#endif // MINIMALMENUCOMPONENT_H_INCLUDED
