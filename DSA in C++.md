# DSA in C++

## Miscellaneous

### Efficient Looping

If you use the loop as follows, `x` is a copy. Making this copy causes additional overhead. 

```cpp
for (auto x : arr) {
    x *= 2;
}
```

Very often, when doing CP a better ways would be to use a loop as:
```cpp
for(int i=0; i < n; i++){
    int x = arr[i];
    x *= 2;
}
```

Or:

```cpp
for (auto& x : arr) {
    x *= 2;
}
```

## Algorithms in C++

### BFS

```cpp
queue<int> q;
vector<bool> visited(graph.size(), false);

visited[start] = true;
q.push(start);

while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(int neigh : graph[node]) {
        if(!visited[neigh]) {
            visited[neigh] = true;
            q.push(neigh);
        }
    }
}
```

### DFS

```cpp
stack<int> st;
vector<bool> visited(graph.size(), false);

st.push(start);

while(!st.empty()) {
    int node = st.top();
    st.pop();

    if(visited[node]) continue;
    visited[node] = true;

    // Push neighbors in reverse to maintain natural left-to-right order
    for(int i = graph[node].size() - 1; i >= 0; i--) {
        int neigh = graph[node][i];
        if(!visited[neigh]) {
            st.push(neigh);
        }
    }
}
```

### Dijkstra

```cpp
vector<long long> dijkstra(int n, int src, vector<vector<pair<int,int>>> &adj) {
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<long long,int>, 
                   vector<pair<long long,int>>, 
                   greater<pair<long long,int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;  // stale entry

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```


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

### 3. Map

- Map is a key-value pair which is again implemented as a Red-Black tree. Hence the worst-case performance is Log(n)

| Operation / Method | Complexity | Description |
|--------------------|-------------|--------------|
| `m.insert({key, value})` | O(log n) | Inserts a key-value pair. Does nothing if the key already exists. |
| `m[key]` | O(log n) | Accesses or inserts the element with the given key (creates a default value if key doesn’t exist). |
| `m.at(key)` | O(log n) | Accesses the element with the given key. Throws `out_of_range` if key not found. |
| `m.find(key)` | O(log n) | Returns an iterator to the key if found, otherwise `m.end()`. |
| `m.count(key)` | O(log n) | Returns 1 if the key exists, else 0 (since keys are unique). |
| `m.erase(key)` | O(log n) | Removes the element with the specified key. |
| `m.erase(iterator)` | O(log n) | Removes the element at the given iterator. |
| `m.size()` | O(1) | Returns the number of elements in the map. |
| `m.empty()` | O(1) | Returns true if the map is empty. |
| `m.clear()` | O(n) | Removes all elements from the map. |
| `m.begin()` / `m.end()` | O(1) | Returns iterator to the first / past-the-end element (sorted order). |
| `m.lower_bound(key)` | O(log n) | Returns iterator to the first element **not less than** the given key. |
| `m.upper_bound(key)` | O(log n) | Returns iterator to the first element **greater than** the given key. |
| `m.equal_range(key)` | O(log n) | Returns a pair of iterators: `{lower_bound(key), upper_bound(key)}`. |
| `m.emplace(key, value)` | O(log n) | Constructs element in place (faster than insert, avoids copy). |
| `m.swap(other)` | O(1) | Swaps contents with another map. |

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

### 5. Priority Queue

It's python Heapq equivalent. By default, it implements a max-heap ( whereas in Python it is min-heap by default ). You can convert a max-heap into a min-heap as follows: `priority_queue<int, vector<int>, greater<int>> pq;`. The syntax is: `priority_queue<Type, Container, Comparator>`. 

You can do the regular operations of: `.push(num)`, `.pop()`, `.top()`.