---
title: embed::static_memory_resource
summary: The static_memory_resource is the polymorphic memory resource allocator that allows libembeddedhal's libraries to use a C++ standard container such as std::pmr::vector, std::pmr::string, std::pmr::unordered_map, and more without requiring dynamic memory allocation from the heap. It provides a simple way to create an allocator with built in storage, with its size indicated by a single template parameter. It also provides statistics regarding the amount of memory allocated such that developers can determine if they need to reduce or increase the size of the buffer. Memory statistics can also give programs the insight into how much memory space is available and make decisions based on that. In the event that the memory of the static allocator is exceeded, a std::bad_alloc excpetion is thrown.  

---

**embed::static_memory_resource Class Reference**

The [static_memory_resource]() is the polymorphic memory resource allocator that allows libembeddedhal's libraries to use a C++ standard container such as std::pmr::vector, std::pmr::string, std::pmr::unordered_map, and more without requiring dynamic memory allocation from the heap. It provides a simple way to create an allocator with built in storage, with its size indicated by a single template parameter. It also provides statistics regarding the amount of memory allocated such that developers can determine if they need to reduce or increase the size of the buffer. Memory statistics can also give programs the insight into how much memory space is available and make decisions based on that. In the event that the memory of the static allocator is exceeded, a std::bad_alloc excpetion is thrown.  [More...](#detailed-description)


`#include <static_memory_resource.hpp>`

Inherits from std::pmr::memory_resource

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[static_memory_resource](classes/classembed_1_1static__memory__resource/#function-static-memory-resource)**() |
| constexpr std::size_t | **[capacity](classes/classembed_1_1static__memory__resource/#function-capacity)**() const |
| std::size_t | **[memory_used](classes/classembed_1_1static__memory__resource/#function-memory-used)**() const |
| int | **[memory_available](classes/classembed_1_1static__memory__resource/#function-memory-available)**() const |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| void * | **[do_allocate](classes/classembed_1_1static__memory__resource/#function-do-allocate)**(std::size_t bytes, std::size_t alignment) override<br>Implemenation of the [do_allocate()]() method for std::pmr::memory_resource.  |
| void | **[do_deallocate](classes/classembed_1_1static__memory__resource/#function-do-deallocate)**(void * address, std::size_t bytes, std::size_t alignment) override<br>Implemenation of the [do_deallocate()]() method for std::pmr::memory_resource.  |
| bool | **[do_is_equal](classes/classembed_1_1static__memory__resource/#function-do-is-equal)**(const std::pmr::memory_resource & other) const override<br>Implemenation of the [do_is_equal()]() method for std::pmr::memory_resource.  |

## Detailed Description

```cpp
template <size_t BufferSize>
class embed::static_memory_resource;
```

The [static_memory_resource]() is the polymorphic memory resource allocator that allows libembeddedhal's libraries to use a C++ standard container such as std::pmr::vector, std::pmr::string, std::pmr::unordered_map, and more without requiring dynamic memory allocation from the heap. It provides a simple way to create an allocator with built in storage, with its size indicated by a single template parameter. It also provides statistics regarding the amount of memory allocated such that developers can determine if they need to reduce or increase the size of the buffer. Memory statistics can also give programs the insight into how much memory space is available and make decisions based on that. In the event that the memory of the static allocator is exceeded, a std::bad_alloc excpetion is thrown. 

**Template Parameters**: 

  * **BufferSize** number of bytes to statically allocate for the memory resource. 


USAGE:

// Make a memory resource with 1kB buffer static_memory_resource<1024> memory_resource; std::pmr::unordered_map<int, const char*> id_name_map(&memory_resource);

## Public Functions Documentation

### function static_memory_resource

```cpp
inline static_memory_resource()
```


### function capacity

```cpp
inline constexpr std::size_t capacity() const
```


**Return**: constexpr std::size_t - the total number of bytes that this allocator can allocate before throwing a std::bad_alloc exception. 

### function memory_used

```cpp
inline std::size_t memory_used() const
```


**Return**: std::size_t number of bytes that have already been allocated. 

### function memory_available

```cpp
inline int memory_available() const
```


**Return**: int Bytes that have yet to be allocated from this allocator. 

## Protected Functions Documentation

### function do_allocate

```cpp
inline void * do_allocate(
    std::size_t bytes,
    std::size_t alignment
) override
```

Implemenation of the [do_allocate()]() method for std::pmr::memory_resource. 

**Parameters**: 

  * **bytes** number of bytes to allocate 
  * **alignment** alignment limit for the allocation 


**Return**: void* address of the newly allocated buffer 

### function do_deallocate

```cpp
inline void do_deallocate(
    void * address,
    std::size_t bytes,
    std::size_t alignment
) override
```

Implemenation of the [do_deallocate()]() method for std::pmr::memory_resource. 

**Parameters**: 

  * **address** address of space to be deallocated 
  * **bytes** number of bytes to allocate 
  * **alignment** alignment limit for the allocation 


### function do_is_equal

```cpp
inline bool do_is_equal(
    const std::pmr::memory_resource & other
) const override
```

Implemenation of the [do_is_equal()]() method for std::pmr::memory_resource. 

**Parameters**: 

  * **other** another memory resource to 


**Return**: 

  * true are equal 
  * false are not equal 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000