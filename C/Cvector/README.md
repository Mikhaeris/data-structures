# What is it?

This is simple dynamic array in C, like C++ vector.

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
cmake -S .. -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
sudo cmake --install build
sudo ldconfig
```

# Documentatin

## Constructor and Destructor

### Constructor

#### Definition:
```
Cvector *vec_dinit(size_t size, size_t data_size);
```

#### Parameters:
size      - start size
data_size - size of data type (like int)

#### Explanation
vec_dinit - vector default initialization

Create struct vector with fields:
    size_t size_      - current size
    size_t capacity_  - size of allocated memory
    size_t data_size_ - size of data type
    void* data_       - pointer to arr of data

#### Example:
```
Cvector *vec = vec_dinit(10, sizeof(int))
```

### Destructor

#### Definition:
```
void vec_destruct(Cvector **vec);
```

#### Parameters:
**vec - pointer to pointer to struct

#### Explanation
vec_destruct - vector destruct

Free allocated memory for data and free memory for struct Cvector

Pointer to pointer to struct, because pointer to struct may means arr of structs

!!!Always use this function, because vec_dinit allocate memory!!!

#### Expamle:
```
vec_destruct(&vec);
```

## Capacity

### Check empty

#### Definition:
```
uint8_t vec_empty(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

Return 1 if vec empty or 0 if vec not empty

#### Expamle:
```
printf("%s\n", (vec_empty(vec)) ? "vector empty" : "vector not empty");
```

### Get size

#### Definition:
```
size_t vec_size(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

Return count elements in vector

#### Expamle:
```
size_t size = vec_size(vec);
```

### Get capacity

#### Definition:
```
size_t vec_capacity(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

Returns how many elements can be inserted before reallocation

#### Expamle:
```
size_t capacity = vec_capacity(vec);
```

### Get data size

#### Definition:
```
size_t vec_datasize(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

Return size of type elements that stored in vector

#### Expamle:
```
size_t datasize = vec_datasize(vec);
```

## Element access

### Get/Set element in position

#### Definition:
```
void *vec_at(Cvector *vec, size_t pos);
```

#### Parameters:
*vec - pointer to struct  
pos  - position of the element to return

#### Explanation

vec_at - vector at position

Return void pointer to element

#### Expamle:
get element
```
printf("%d\n", *(int *)vec_at(vec, 1));
```
set element
```
*(int *)vec_at(vec, 1) = 7;
```

### Get pointer to front of data in vector

#### Definition:
```
void *vec_front(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

Return void pointer to front of data

#### Expamle:
```
printf("%d\n", *(int *)vec_front(vec));
```

### Get pointer to back of data in vector

#### Definition:
```
void *vec_back(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

Return void pointer to last element

#### Expamle:
```
printf("%d\n", *(int *)vec_back(vec));
```

## Modifiers

### Insert element

#### Definition:
```
void *vec_insert(Cvector *vec, size_t pos);
```

#### Parameters:
*vec - pointer to struct
pos  - position to insert

#### Explanation

vec_insert - vector insert element

Return pointer to position where insert element.

Shifts all elements to the right from the position,
snd set element in this position to zero

size increases by one

if the size becomes equal to capacity,
vector reallocate all data to the new position with doubled capacity 

#### Expamle:
```
*(int *)vec_insert(vec, 1) = 10;
```

### Erase element

#### Definition:
```
void vec_erase(Cvector *vec, size_t pos);
```

#### Parameters:
*vec - pointer to struct
pos  - position to erase

#### Explanation

vec_erase - vector erase element

Delete element in this position

Shifts all elements to the left from the position,
snd set last element to zero

size decreases by one

#### Expamle:
```
vec_erase(vec, 1);
```

### Push element

#### Definition:
```
void *vec_push(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

vec_push - vector push element to end

Push element to the end

size increases by one

if the size becomes equal to capacity,
vector reallocate all data to the new position with doubled capacity 

#### Expamle:
```
*(int *)vec_push(vec) = 4;
```

### Pop element

#### Definition:
```
void vec_pop(Cvector *vec);
```

#### Parameters:
*vec - pointer to struct

#### Explanation

vec_pop - vector pop last element

Pop last element

size decreases by one

#### Expamle:
```
vec_pop(vec);
```
