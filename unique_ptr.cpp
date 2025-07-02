/*
Unique Pointers: std::unique_ptr is a smart pointer that owns (is responsible for)
and manages another object via a pointer and subsequently delete that object when the unique_ptr goes out of scope.

The object is disposed of, using the associated deleter, when either of the following happens:
the managing unique_ptr object is destroyed.
the managing unique_ptr object is assigned another pointer via operator= or reset().

In simple terms: std::unique_ptr ensures that only one unique owner exists for the object.
It deletes the object automatically when it goes out of scope.
*/

#include <iostream>
#include <memory> //To access smart pointers

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

int main()
{

    // Ways to Create a unique pointer:

    // std::unique_ptr<int> u_ptr1 = new int; // Throws Error -> Invalid cuz The compiler doesn’t allow implicit conversion from int* to unique_ptr<int>

    std::unique_ptr<int> u_ptr2(new int(10)); // Valid way but not safer though

    // Preferred way:
    std::unique_ptr<int> u_ptr3 = std::make_unique<int>(5); // Slightly safer if the constructor happens to throw an exception,you wouldn't
                                                            // end up having a dangling pointer and that's a memory leak if it happens :(

    // Now it can be used like a normal pointer and you don't need to worry about using new or delete keywords :)
    *u_ptr2 = 4;
    std::cout << "u_ptr2 pointing to: " << *u_ptr2 << "\n";
    std::cout << "u_ptr3 pointing to: " << *u_ptr3 << "\n";

    /* { // Comment this block as It would cause undefined behavior
          int a = 10;
          std::unique_ptr<int> u_ptr(&a); // That’s dangerous, because unique_ptr will try to delete a stack variable — causing undefined behavior.
      }
      // Remember: Smart Pointers should only manage heap-allocated memory(created using new or make_unique/make_shared)
  */


    // Problems with unique_pointer: It can't be shared or copied or passed in functions without reference
    // E.g:
    
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();

  //  std::unique_ptr<Entity> e0 = entity // -> Compilation Error

        /*
            So, When to use unique pointers:
            1. You Want Exclusive Ownership
            2. You Want Automatic Cleanup -> preventing memory leaks.


            When Not to use:
            1. Multiple parts of your program need to share ownership
            2. You want to manage stack-allocated memory → unique_ptr is for heap only.
        */

        return 0;
}