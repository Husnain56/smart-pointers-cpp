/*
Shared Pointers: std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.
Several shared_ptr objects may own the same object. 

The object is destroyed and its memory deallocated when either of the following happens:
the last remaining shared_ptr owning the object is destroyed;
the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().

In simple word: A shared_ptr is a smart pointer that allows multiple owners to share ownership of the same dynamically allocated object. 
It keeps a reference count, and deletes the object only when the last shared_ptr pointing to it is destroyed.
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

     // Ways to Create a Shared pointer:

    std::shared_ptr<int> s_ptr1(new int(5)); //Not recommended as shared pointer has another block of memory called control block
                                             //where it stores that reference count, then if you pass new entitiy -> that's 2 allocations 
    
    std::shared_ptr<int> s_ptr = std::make_shared<int>(5); //a lot more efficient as allocates both the object and the control block in one memory block.

    // Demonstration:

    {   //Now if debug and see the output when the inner block ends "Object Deleted" doesnt appear in output means object is not deleted
        std::shared_ptr<Entity> s_ptr2;
        {
            std::shared_ptr<Entity> s_ptr3 = std::make_shared<Entity>();
            s_ptr2 = s_ptr3; //Valid 
        }
    }  //"Object Deleted" would appear in output after outer block ends



/*
Always prefer std::make_shared<T>() unless you need:

A custom deleter, or

To construct the object in a special way that make_shared can’t support
*/




    return 0;
}