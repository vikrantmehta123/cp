# DSA in C++

## Data Structures in C++

### 1. Vectors

- Python-like list. So the list size grows dynamically and inserts (i.e. appends) are amortized O(1). No need to give size upfront.
- **Methods:**
| Operation        | Complexity     | Notes                                                                  								|
| ---------------- | -------------- | ----------------------------------------------------------------------------------------------------------------------------------|
| Access `v[i]`    | O(1)           | Random access is constant time.                                        								|
| `push_back(x)`   | Amortized O(1) | O(n) when resizing. `push_back` creates the object outside of the vector and then copies it in the vector.   |
| `pop_back()`     | O(1)           | Removes last element.                                                  								|
| `insert(pos, x)` | O(n)           | Elements after `pos` are shifted.                                      								|
| `erase(pos)`     | O(n)           | Elements after `pos` are shifted.                                      								|
| `size()`         | O(1)           | Returns number of elements.                                            								|
| `empty()`        | O(1)           | Checks if vector is empty.                                             								|
| `clear()`        | O(n)           | Destroys all elements.                                                 								|
| `emplace_back(x)`| Amortized O(1) | `emplace_back` creates the object itself in the vector and thus no copying is required. 				| 

---

### 2. Unordered Map, Unordered Set

- Map is a key-value pair, Set is just keys.

### 3. Map, Set

- Map is a key-value pair, Set is just keys.

### 4. Multiset

- Implemented as Red-Black tree. So they take logn complexity in the worst case, as opposed to hash-bashed methods which take O(1) on average but O(n) in worst case.
- Sets don't allow duplicates. Multisets do.

- **Methods**
| Method             | Complexity          | Notes                                                               |
| ------------------ | ------------------- | ------------------------------------------------------------------- |
| `insert(x)`        | O(log n)            | Inserts element (duplicates allowed); maintains sorted order.       |
| `erase(x)`         | O(log n + count(x)) | Removes **all** occurrences of value `x`.                           |
| `erase(it)`        | O(log n)            | Removes the element pointed by iterator `it`.                       |
| `find(x)`          | O(log n)            | Returns iterator to one occurrence of `x`, or `end()` if not found. |
| `count(x)`         | O(log n + k)        | Counts how many times `x` appears (`k` = duplicates).               |
| `lower_bound(x)`   | O(log n)            | Iterator to **first element ≥ x**.                                  |
| `upper_bound(x)`   | O(log n)            | Iterator to **first element > x**.                                  |
| `begin()`, `end()` | O(1)                | Iterators to smallest and past-largest elements.                    |
| `size()`           | O(1)                | Number of elements (including duplicates).                          |
| `empty()`          | O(1)                | Checks if multiset is empty.                                        |