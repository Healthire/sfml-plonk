#include "GameObject.h"

GameObject::GameObject(void)
{
	isDrawable = false;
	isUpdatable = false;
	dying = false;

}


bool GameObject::isDying(){
	return dying;
}

void GameObject::Remove(){
	dying = true;
}
