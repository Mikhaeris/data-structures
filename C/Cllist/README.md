# What is it?

This is simple generic linked list in C.

# How use it?
    
1) Read documentation or read code:)

2) Check some simple examples

# How build code in library?

1) Create folder

```
mkdir build
cd build
```

2) Build library

```
cmake -S .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j
sudo cmake --install .
sudo ldconfig
```

# Documentatin

## Constructor and Destructor

### Constructor

#### Definition:
```
Cllist *llist_init(size_t data_size);
```

#### Parameters:
size_t data_size_ - size of data type

#### Explanation
llist_dinit - linked list default initialization

Create struct vector with fields:
    size_t size_      - current size
    size_t data_size_ - size of data type
    Node *head_       - pointer to head node
    Node *tail_       - pointer to tail node

#### Example:
```
Cllist *llist = llist_init(10, sizeof(int))
```
### Destructor

#### Definition:
```
void llist_destruct(Cllist **llist);
```

#### Parameters:
Cllist **llist - pointer to pointer to struct

#### Explanation
llist_destruct - linked list destruct

Destruct all nodes and free allocated memory for pointer to data in nodes

Pointer to pointer to struct, because pointer to struct may means arr of structs

!!!Always use this function, because llist_dinit allocate memory!!!

#### Example:
```
llist_destruct(&llist);
```

## Capacity

### Check empty

#### Definition:
```
uint8_t llist_empty(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

Return 1 if llist empty or 0 if llist not empty

#### Example:
```
printf("%s\n", (llist_empty(llist)) ? "llist empty" : "llist not empty");
```

### Get size

#### Definition:
```
size_t llist_size(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

Return count elements(nodes) in llist

#### Example:
```
size_t size = llist_size(llist);
```

### Get data size

#### Definition:
```
size_t llist_datasize(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

Return size of type elements stored in Cllist

#### Example:
```
size_t datasize = llist_datasize(llist);
```

## Element access

### Get front iterator

#### Definition:
```
llist *llist_front(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct  

#### Explanation

llist_front - llist front iterator

Return void pointer to iterator(Node)

#### Example:
get iterator
```
iter front_it = llist_front(llist);
```

### Get back iterator

#### Definition:
```
llist *llist_back(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct  

#### Explanation

llist_back - llist back iterator

Return void pointer to iterator(Node)

#### Example:
get iterator
```
iter back_it = llist_back(llist);
```

### Get/Set element in node

#### Definition:
```
void *llist_val(iter it);
```

#### Parameters:
iter it - pointer to Node in linked list

#### Explanation

llist_val - val in Node in linked list

Return void pointer to element

#### Example:
get element
```
iter it = llist_front(llist);
printf("%d\n", *(int *)llist_val(it);
```
set element
```
*(int *)llist_val(it) = 7;
```

### Get node by index

#### Definition:
```
llist *llist_atp(Cllist *llist, size_t pos);
```

#### Parameters:
Cllist *llist - pointer to struct  
size_t pos - index of Node

#### Explanation

llist_atp - node of linked list at position

Return void pointer to iterator(Node)

#### Example:
get iterator
```
iter it = llist_atp(llist, 2);
```

### Get prev Node

#### Definition:
```
llist *llist_prev(Cllist *llist, iter it);
```

#### Parameters:
Cllist *llist - pointer to struct  
iter it - pointer to Node

#### Explanation

llist_prev - node prev node

Return void pointer to iterator(Node)

#### Example:
get iterator
```
iter back_it = llist_back(llist);
iter it = llist_prev(back_it);
```

### Get next Node

#### Definition:
```
llist *llist_next(Cllist *llist, iter it);
```

#### Parameters:
Cllist *llist - pointer to struct  
iter it - pointer to Node

#### Explanation

llist_next - node next node

Return void pointer to iterator(Node)

#### Example:
get iterator
```
iter front_it = llist_front(llist);
iter it = llist_next(front_it);
```

## Modifiers

### Clear llist

#### Definition:
```
void llist_clear(Cllist *llist);
```

#### Parameters:
Cvector *vec - pointer to struct  
size_t pos  - position to insert

#### Explanation

llist_clear - llist clear all elemants

#### Example:
```
llist_clear(llist);
```

### Insert element

#### Definition:
```
void *llist_insert(Cllist *llist, size_t pos);
```

#### Parameters:
Cllist *llist - pointer to struct  
size_t pos - position to insert

#### Explanation

llist_insert - llist insert element

Return pointer to position where insert element.

size increases by one

#### Example:
```
*(int *)llist_insert(llist, 1) = 10;
```

### Erase element

#### Definition:
```
void llist_erase(Cllist *llist, size_t pos);
```

#### Parameters:
Cllist *llist - pointer to struct  
size_t pos  - position to erase

#### Explanation

llist_erase - llist erase Node

size decreases by one

#### Example:
```
llist_erase(llist, 1);
```

### Push back element

#### Definition:
```
void *llist_push_back(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

llist_push_back - llist push element to end

creates node and set val in this node

size increases by one

#### Example:
```
*(int *)llist_push_back(llist) = 4;
```

### Pop back element

#### Definition:
```
void llist_pop_back(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

llist_pop_back - llist pop last Node

size decreases by one

#### Example:
```
llist_pop_back(llist);
```

### Push front element

#### Definition:
```
void *llist_push_front(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

llist_push_front - llist push element to front

creates node and set val in this node

size increases by one

#### Example:
```
*(int *)llist_push_front(llist) = 4;
```

### Pop back element

#### Definition:
```
void llist_pop_front(Cllist *llist);
```

#### Parameters:
Cllist *llist - pointer to struct

#### Explanation

llist_pop_front - llist pop front Node

size decreases by one

#### Example:
```
llist_pop_front(llist);
```
