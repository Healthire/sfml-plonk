#include "Shape.h"
#include "Rectangle.h"

bool Shape::Intersect(Shape* shape){
	switch(shape->Type){
	case Rect:
		return Intersect(static_cast<Rectangle*>(shape));
		break;
	default:
		return false;
		break;
	}
}