# DSA in C++

## Data Structures in C++

### 1. Vectors

- Python-like list. So the list size grows dynamically and inserts (i.e. appends) are amortized O(1). No need to give size upfront.
- **Methods:**
| Operation        | Complexity     | Notes                                                                  								|
| ---------------- | -------------- | ----------------------------------------------------------------------------------------------------------------------------------|
| Access `v[i]`    | O(1)           | Random access is constant time.                                        								|
| `push_back(x)`   | Amortized O(1) | Occasionally O(n) when resizing happens. `push_back` creates the object outside of the vector and then copies it in the vector.   |
| `pop_back()`     | O(1)           | Removes last element.                                                  								|
| `insert(pos, x)` | O(n)           | Elements after `pos` are shifted.                                      								|
| `erase(pos)`     | O(n)           | Elements after `pos` are shifted.                                      								|
| `size()`         | O(1)           | Returns number of elements.                                            								|
| `empty()`        | O(1)           | Checks if vector is empty.                                             								|
| `clear()`        | O(n)           | Destroys all elements.                                                 								|
| `emplave_back(x)`| Amortized O(1) | `emplace_back` creates the object itself in the vector and thus no copying is required. 						| 

---

### 2. Unordered Map, Unordered Set

- Map is a key-value pair, Set is just keys.

### 3. Map, Set

- Map is a key-value pair, Set is just keys.

