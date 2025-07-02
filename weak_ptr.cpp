/*
std::weak_ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr.
It must be converted to std::shared_ptr in order to access the referenced object.

So it doesnt increase the ref count
great for if you kind of don't want to take ownership of the entity
*/

#include<iostream>
#include<memory> //To access smart pointers

class Entity
{

public:
    Entity()
    {
        std::cout << "Object Created" << "\n";
    }
    ~Entity()
    {
        std::cout << "Object Deleted" << "\n";
    }

    void print() {}
};

int main(){

    
    // Demonstration:

    {   //Now if debug and see the output when the inner block ends "Object Deleted" appears in output means object is deleted after inner block ends

        std::weak_ptr<Entity> s_ptr2;
        {
            std::shared_ptr<Entity> s_ptr3 = std::make_shared<Entity>();
            s_ptr2 = s_ptr3; //Valid 
        }
    }  



    return 0;
}