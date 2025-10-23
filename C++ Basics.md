### Standard Library

- All of the code in the standard library is just C++ code that makes life much simpler as a programmer ( except some machine code for context switching ). In principle, you can derive everything from scratch.

---

### Immutability

C++ supports two notions of immutability:
- const: meaning roughly ‘‘I promise not to change this value’’ (§7.5). This is used primarily to specify interfaces, so that data can be passed to functions without fear of it being modified. The compiler enforces the promise made by const.
- constexpr: meaning roughly ‘‘to be evaluated at compile time’’ (§10.4). This is used primarily to specify constants, to allow placement of data in memory where it is unlikely to be corrupted, and for performance.

### Pointers, Addresses, and References

- Pointers are defined as `int* p = &a;`, where `int*` tells the compiler that this is a pointer to an integer. 
- **Prefix** as `&` takes the memory location of the variable `a` and returns that. `&a` returns the memory address of the variable.
- **Suffix** as `&` is a reference. It's like giving another name to the same object:
	```cpp
	int x = 10;
	int y = 20;
	int& r = x;   // r is another name for x. That is r and x are the same objects, same memory locations. References cannot be made to point to some other objects after initialization.
	```
- `nullptr` is a special pointer that compiler recognizes. We have a `nullptr` because we want to make sure that the dereferencing of the pointer is always valid, and `nullptr` is a way of saying that you cannot dereference this. 

### Abstraction Mechanisms in C++

- Structs, Classes, Enumerations, namespaces, templates are abstraction mechanisms in C++. 
- Namespaces are just meant to isolate names so that they don't clash. In large projects, namespaces become important.

##### Structures

- C like *structs* are possible in C++. 
- Dot notation is used to access the attributes if you have access to the object directly, or you use `->` if you have access to the object pointer. For example, 
	```cpp
	Point p1;
	p1.y = 25; // Since p1 is an object, we can use the dot notation.
	Point* p2 = &p1; // p1 is a Point object.
	p2->x = 30; // Since p2 is a pointer to a Point object, we use -> notation to access its fields.
	```

##### Classes

- Structs are good. Because they let us decouple methods and data. But more often than not, in practical situations, we want the data to be fairly tightly coupled with the data. That is, you'd want data and ops defined on that data to be packed into one unit. That's why we use classes.
- A program built out of a well chosen set of classes is far easier to understand and get right than one that builds everything directly in terms of the built-in types.

##### 1. Concrete Classes

A concrete type in C++ is a class that:
- Has a well-defined representation (data members are part of the object itself). So the class handles all the interaction with them.
- Can be used just like a built-in type (int, double, etc.).
- Is complete: you can create it, copy it, destroy it, all without extra indirection.

Think of std::vector, std::string, or std::complex: You can declare them as local variables. You can pass them by value. They initialize properly when constructed. They clean up after themselves when they go out of scope.

- In several languages, we need to do `new` or `delete` to allocate / deallocate memory. In C++, it's much simpler. You define constructors and destructors. With constructors, memory is allocated. With destructors, memory is deallocated. Due to this structure, we don't use `new` / `delete` and the code is more readable / less error prone / throws less memory leaks. After the scope of the variable ends, the destructor is called and the memory is deallocated.

```code
class Vector{
	Vector() // constructor
	~Vector( ... ) // Destructor. It should have the cleanup logic in it.
}
```

##### 2. Abstract Classes

- An abstract class is a class which has at least one pure virtual function. `virtual` means that it can be defined by the subclasses that inherit from this. A `pure virtual` function means it *must* be defined by the subclasses. These cannot be instantiated, there are typically no local variables, and they just contain the interface and not the implementation. The whole idea of this is to allow for polymorphism or dynamic dispatch.
- Now think from the compiler / language's perspective: How will the memory allocation happen? How does the compiler / runtime know which class's methods to call?
	- At the time of compilation, compiler wouldn't know how much memory to allocate to an instance of an abstract class- because they don't contain any data. The data/representation is supposed to be in the concrete implementation of this. If the compiler wants to allocate memory to the object on the stack, it needs to know how much memory to allocate. This is not the case with abstract classes. So instead, the compiler just instantiates a pointer on the stack- this pointer points to a memory address on the heap, where the actual object will be instantiated at runtime.
	- In polymorphism we do:
		```code
		void use(Container& c) { c.some_func(); };
		void f() {
			VectorContainer c;
			use(c);
		}
		```
	here, how does a compiler know that the in `use` method, we need to call the `some_func` method of the `VectorContainer` class? This method is called at runtime, and not at compile time. That is, dynamic dispatch happens at runtime and not at compile time.
	At compile time, the compiler will generate a virtual function table `vtbl` **for each class with virtual functions** ( that means for each of the concrete classes that implement an abstract class). In each of these classes, there's a pointer `vptr` to this `vtbl`. At compile time, the compiler sees `c.some_func()` and knows `c` is a `Container&`. It doesn’t know which derived type `c` really refers to. So it generates the code as follows:
	`(* (c.vptr[INDEX_FOR_SOME_FUNC]))()`;
	That's how dynamic dispatch is achieved.

##### 3. Class Hierarchies

### Invariants and Preconditions

- Whenever we write code, we make some assumptions about the inputs.
- A precondition is a condition that must be true before a function is called, for that function to make sense. Preconditions are assumptions the function makes about its input. The caller is responsible for satisfying them.
- A class invariant is a condition that must always hold true for objects of that class—except possibly temporarily inside member function bodies while updating state. If these ever become false, then every member function becomes unsafe. The constructor is responsible for establishing the invariant. Every member function must preserve it (so when the function exits, the invariant still holds).
- Think of functions and classes as contracts. These contracts shouldn't be broken to avoid any unexpected errors.


## Concurrency in C++

### Tasks and Threads

We call a computation that can potentially be executed concurrently with other computations a task. That is, we can imagine task as a function that we want to execute. A thread is the system-level representation of a task in a program. A task to be executed concurrently with other tasks is launched by constructing a std::thread (found in <thread>) with the task as its argument. So a thread executes the tasks it is assigned concurrently.

To "join" means to "wait for the thread to terminate." Threads of a program share a single address space (virtual memory address space). In this, threads differ from processes, which generally do not directly share data. Since threads share an address space, they can communicate through shared objects. Such communication is typically controlled by locks or other to prevent data races (uncontrolled concurrent access to a variable).

When defining tasks(functions that we want run concurrently) of a concurrent program, our aim is to keep tasks completely separate except where they communicate in simple and obvious ways. The simplest way of thinking of a concurrent task is as a function that happens to run concurrently with its caller. For that to work, we just have to pass arguments, get a result back, and make sure that there is no use of shared data in between (no data races). Typically, we need to pass parameters to threads.

Think in terms of concurrent tasks, rather than threads.


## Fundamental Data Types in C++

### bool

- All non-zero nums are True ( including negatives ), only zero is False.
- `nullptr` is False, all other pointers are True.

### char

- Each character has a corresponding integer value that depends on the implementation of C++ Character Set ( don't go too much here ). 
- Now, let's assume that a character is implemented as 8 bits. These 8 bits can be interpreted as -127 to 127 ( C++ doesn't allo -128 because of some one's complement thing) or 0 to 255. Which representation to take? C++ might have some defaults based on implementations (either it will behave as signed or unsigned), but to make this explicit signed and unsigned chars are there. More often than not, this doesn't matter. But still.
	- `signed char`: -127 to 127 in above example
	- `unsigned char`: 0 to 255 in above example

	All the three types `char`, `signed char`, `unsigned char` are distinct. So you can't use them / their pointers interchangeably. And some issues can come up due to this when you try to create some characters that are out of range to the number of bits, etc.

- C++ makes a distinction between character literal and a character. A character is just integer representation i.e. one number. But a character literal is an alphabet / hex / octal, etc.

### int

- Same signed, unsigned, and int as char.
- C++ allows you to specify aliases as follows:	`using age_t = unsigned int; age_t x = 25;`. There is a standard library `#include <cstdint>` which has defined some aliased around integer types. This allows us to be much more precise when defining integers. For example, do we want 32 bit integer, 64 bit, at least 16 bits, etc, etc. Look up docs whenever you come across this.
- There's more types for integers than chars: 
	- `short`: >= 16 bits
	- `long`: >= 32 bits. The exact number of bits used will depend on underlying computer architecture.
	- `long long`: >= 64 bits. 

	These types can be combined with signed, unsigned, or int.

### double

- Similar to integers, this also has float (single precision), double(double precision), and long double(extended precision). Look up docs. Default is double.
- There are some suffixes that C++ recognizes to assign types. For example, f in `2.9e−3f` will be treated as float. Similarly, L is for long double.

### void

`void` can be used only as part of a more complicated type; there are no objects of type void. It is used either to specify that a function does not return a value or as the base type for pointers to objects of unknown type.

void x; // error: there are no void objects
void& r; // error: there are no references to void
void f(); // function f does not return a value (§12.1.4)
void∗ pv; // pointer to object of unknown type (§7.2.1)

**IMPORTANT:** Size of int, etc aspects are dependent on the implementation of C++. So it's always a good practice to look at the `sizeof` before making any assumptions about the sizes of data types. Especially, if your code is to be run on many different machines. All those additional types exist because they let programmers take advantage of the knowledge they might have about their code requirements and about their hardware.