# SMART POINTERS

## NOTES
* Can use the following for quick block-comments.
#if 0
... code
#endif

## WHAT ARE THEY?
* "Using smart pointers is like putting on 40kg of medieval armror just to walk through a construction site."
* A smart pointer is a templated class. You wrap a real pointer within an instantiated class.
	* When this object (in which the real pointer is wrapped within) is deleted, the memory that was allocated to the pointer is also delted.

## HOW DO WE USE THEM?
* unique_ptr<class_name> r = new class_name();
	* However, they are called unique for a reason. We cannot make another instance of them.
	* A unique_ptr cannot be set equal to another unique_ptr.
* unique_ptr(class_name> s = std::move(r);
	* std::move() allows us to 'rename', or copy, the unique_ptr to another unique_ptr, thus removing all memory from the unqiue_ptr being moved. 

## SHARED POINTERS?
* Keep track of reference counting (how many we have), unlike smart pointers.
* shared_ptr<class_name> r(new class_name());
* The deconstructor handles all 'references' of these shared pointers.
