---
title: embed::can_network::node_t


---

**embed::can_network::node_t Class Reference**

 [More...](#detailed-description)


`#include <can_network.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[node_t](classes/classembed_1_1can__network_1_1node__t/#function-node-t)**()<br>Default constructor.  |
| [node_t](classes/classembed_1_1can__network_1_1node__t/) & | **[operator=](classes/classembed_1_1can__network_1_1node__t/#function-operator=)**(const [node_t](classes/classembed_1_1can__network_1_1node__t/) & node)<br>Node assignment operator.  |
| | **[node_t](classes/classembed_1_1can__network_1_1node__t/#function-node-t)**(const [node_t](classes/classembed_1_1can__network_1_1node__t/) & node)<br>Copy constructor.  |
| [can::message_t](classes/structembed_1_1can_1_1message__t/) | **[secure_get](classes/classembed_1_1can__network_1_1node__t/#function-secure-get)**() |

## Detailed Description

```cpp
class embed::can_network::node_t;
```


The node stored in the [can_network](classes/classembed_1_1can__network/) map. Holds the latest CAN message and contains methods for updating and retreiving can messages in a thread-safe manner that does not invoke OS locks.

Updating the CAN message data is completely lock free. Retrieving data is NOT lock free, but instead uses atomics to poll for when the update() function has completed in some other thread. This asymmetry in locking is to reduce latency for write case rather than than read case. Storing a CAN message is typically done via an interrupt service routine or a thread that MUST NOT block in anyway or the system can lock up. Where as reading data typically is done by a userspace thread which can typically wait a few cycles to get its data. 

## Public Functions Documentation

### function node_t

```cpp
inline node_t()
```

Default constructor. 

### function operator=

```cpp
inline node_t & operator=(
    const node_t & node
)
```

Node assignment operator. 

### function node_t

```cpp
inline node_t(
    const node_t & node
)
```

Copy constructor. 

### function secure_get

```cpp
inline can::message_t secure_get()
```


Return a CAN message, but only do so if the CAN message of this node is not currently be modified by another thread that is using the update() method. 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000