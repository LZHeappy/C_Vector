# C_Vector
Function:
```C++
vector_init(Vector** vec);
vector_free(Vector* vec);
vector_push_back(Vector* vec, void* value);
vector_pop_back(Vector* vec)
vector_set(Vector* vec, size_t index, void* value);
vector_get(Vector* vec, size_t index);
```
Vector Set:
```C++
typedef struct tagVector {
    void** data;
    size_t size;
};
```
Use:
```C++
#include "vector.h"
#include <stdio.h>

int main() {
    Vector* vec;
    vector_init(&vec);
    vector_push_back(vec, (void*)2);
    vector_push_back(vec, (void*)3);
    printf("%d\n", (int*)vector_get(vec, 0));
    printf("%d\n", (int*)vector_get(vec, 1));
    vector_free(vec);
    return 0;
}
