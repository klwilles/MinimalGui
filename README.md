MinimalGui
==========

Minimal Gui for OpenFrameworks

I created a menu component framework that has sliders, check boxes, and labeling. This came out of a desire to have something super simple to control the Interactive Wall of Spirituality. In my main OF class, I hooked it up to the arrow keys--up and down would highlight a row in the menu and left and right would change the value. It was not designed to be a mouse-based GUI. I've released the guts of the system in case anybody could benefit from it. In the future I would like to add an event based architecture around it and a higher level class that handles adding and removing menu component elements as well as an xml manager that also taps into function pointers and class properties. 