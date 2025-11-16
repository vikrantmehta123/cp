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

-  There are multiple implementations of DFS. Avoid recursive implementation as it can lead to stack overflows. In iterative implementation as well, there is color-based implementation and a regular implementation. The color-based one is most efficient for finding cycles.

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

- Single source shortest path algorithm

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

### Floyd-Warshall Algorithm

- All pairs shortest path algorithm

```cpp
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF)); // Distance matrix init to infinity
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // Read edges (undirected)
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c; // (source, dest, weight)

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd–Warshall: O(n^3)
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            // Small optimization: skip impossible i->k
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == INF) continue;
                long long through = dist[i][k] + dist[k][j];
                if (through < dist[i][j]) {
                    dist[i][j] = through;
                }
            }
        }
    }
```

### Topological Sort

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    // Compute indegree
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Detect cycle: if not all nodes are processed
    if (order.size() != n) {
        throw runtime_error("topological sort impossible.");
    }

    return order;
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



## Number Theory

### Sieve of Eratosthenes

- Preprocessing algorithm that computes the prime numbers up to a certain limit L.

```cpp
ll L = 1e8 + 1;
vector<bool> sieve;


void buildSieve(){
    sieve[0] = false;
    sieve[1] = false;  

    for (int p = 2; p * p <= L; p++) {
        if (sieve[p]) {
            // Mark multiples of p starting from p*p
            for (long long multiple = 1LL * p * p; multiple <= L; multiple += p) {
                sieve[multiple] = false;
            }
        }
    }
}

int main(){
    sieve.assign(L, true);
    buildSieve();
    vector<ll> primes;
    for(int i=0; i < sieve.size(); i++){
        if (sieve[i]){
            primes.push_back(i);
        }
    }
}

vector<long long> factorize(long long n, const vector<int>& primes) {
    vector<long long> factors;

    for (int p : primes) {
        if (1LL * p * p > n) break;     // stop once p > sqrt(n)

        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1) factors.push_back(n);     // remaining part is prime
    return factors;
}
```

### 2-Adic Decomposition or Fundamental Decomposition

Every positive integer can be written as: 
    $n = 2^k + m $

Where, `n` is a positive integer, $k \ge 0 $, and `m` is an odd number. 

The interpretation of this result is:

After removing all factors of 2:
    - If the remaining value m > 1, then m is an odd divisor > 1 of the original number.
    - If the remaining value m = 1, then the original number was a pure power of 2 (like 2, 4, 8, 16, ...), meaning it has no odd divisors > 1.

### Prime Factorization Properties

We can use the sieve of eratosthenes to get the prime factors. But assuming that we have the prime factors and how many times it comes, we can arrive at some very interesting conclusions.

1. The number of factors of a number n the product of (powers + 1). For example, for the number 84, the prime factorization is as follows: $2^2 \cdot 3^1 \cdot 7^1 $. Then the total number of factors of 84 is: $ 3 \cdot 2 \cdot 2 = 12 $

2. There also exists a formula to arrive at the sum of factors and product of factors, but you can look it up later.

3. A number n is called a perfect number if n equals the sum of its factors between 1 and n−1. For example, 28 is a perfect number, because 28 = 1+2+4+7+14.

4. Let us we have a set of primes: ${P_1, P_2, ..., P_n}$. We can construct the next prime as: $P_1 \cdot P_2 ... \cdot P_n + 1$

5. If a number n is not prime, it can be represented as a product $a \cdot b$, where $a\le \sqrt{n}$ or $b\le \sqrt{n}$, so it certainly has a factor between 2 and $\lfloor{\sqrt{n}\rfloor}$.

### Diophantine Equations

A Diophantine equation is of the form: $ax + by = c$, where $x$ and $y$ need to be found and the values of $a, b, c$ are known. We can use Euclid's GCD algorithm to solve this.

A Diophantine equation can be solved if c is divisible by gcd(a,b), and otherwise it cannot be solved. A solution to a Diophantine equation is not unique. For example, solve: $15x + 21y = 6$. The GCD is: gcd(15, 21) = 3. Here, c is divisible by 3, hence there are solutions to this. Arriving at a solution using this is slightly involved and I didn't understand it fully. But this could come in handy.

### Euclid's Algorithm

- Efficient algorithm to compute the GCD.
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
```

- You can use this for LCM as well, since LCM and GCD are related as follows:$lcm(a, b) = \dfrac{ab}{gcd(a,b)}$
- Two numbers are said to be coprimes if their GCD = 1. 
- Euler's Totient function gives a algorithm to compute the number of coprimes between 1 to n.
- GCD of consecutive integers is 1.
- If n is divisible by a, b, c => then n is divisible by LCM of a, b, c; as well as the GCD.
- gcd(gcd(a, b), c) = gcd(a, gcd(b, c))


### Modular Arithmetic

Think about what modular arithmetic means: we want to limit the set of numbers to ${1, 2, ... m-1}$. How do we ensure this to happen if we have a bunch of computations to do? For example, let's say you want to take products or exponentiate. Then how do you ensure that the number never exceeds the modulo, even while computing?!

- $(x+ y) \mod m = (x \mod m+ y \mod m) \mod m$
- $(x− y) \mod m = (x \mod m− y \mod m) \mod m$
- $(x · y) \mod m = (x \mod m· y \mod m) \mod m$
- $x^n \mod m = (x \mod m)^n \mod m$

Often we need to compute: $x^n \mod m$. We can do this in logn time using recursion.

```cpp
int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}
```

- Fermat's theorem and Euler's theorems are there to give some additional properties when x and m are coprimes in $x^m$. Fermat's Theorem: $x^{m-1} \mod m = 1$, when x and m are coprimes.

Here’s a **compact Markdown + LaTeX list** of the essential congruence properties:

### **Congruence Properties**

1. **Definition**
   $
   a \equiv b \pmod{k} \iff k \mid (a-b)
   $

2. **Remainder Equality**
   $
   a \equiv b \pmod{k} \iff a \bmod k = b \bmod k
   $

3. **Addition / Subtraction**
   $
   \begin{aligned}
   a \equiv b \pmod{k} &\implies a+c \equiv b+c \pmod{k} \
   &\implies a-c \equiv b-c \pmod{k}
   \end{aligned}
   $

4. **Multiplication**
   $
   a \equiv b \pmod{k} \implies ac \equiv bc \pmod{k}
   $

5. **Powers**
   $
   a \equiv b \pmod{k} \implies a^n \equiv b^n \pmod{k}
   $

6. **Transitivity**
   $
   (a \equiv b \pmod{k},; b \equiv c \pmod{k}) \implies a \equiv c \pmod{k}
   $

7. **Division (only when allowed)**
   $
   ac \equiv bc \pmod{k},\ \gcd(c,k)=1 \implies a \equiv b \pmod{k}
   $

8. **Difference Rule**
   $
   a \equiv b \pmod{k} \iff a-b \equiv 0 \pmod{k}
   $

9. **Negatives**
   $
   a \equiv b \pmod{k} \iff -a \equiv -b \pmod{k}
   $

### AM-GM Inequality

For positive integers:
$$\frac{a_1 + a_2 + \cdot \cdot \cdot + a_k}{k} \ge \sqrt[k]{a_1 \cdot a_2 \cdot \cdot \cdot a_k}$$

This is to say that the arithmetic mean is always greater than or equal to the geometric mean. They are only equal when all the numbers $a_i$ are the same.

### Some Theorems:

- Lagrange's Theorem: Every positive integer can be represented as the sum of four squares: $a^2 + b^2 + c^2 + d^2$.
- Zeckendorf's Theorem: every positive integer has a unique representation as a sum of Fibonacci numbers such that no two numbers are equal or
consecutive Fibonacci numbers.


## Bit Manipulation


### AND

- We can check if a number x is even because $x \& 1 = 0$ if x is even, and $x \& 1 = 1$ if x is odd. More generally, x is divisible by $2^k$ exactly when $x \& (2^k −1) = 0$.

### OR

- The **or** operation `x | y` produces a number that has one bits in positions where at least one of x and y have one bits.

### XOR

- The xor operation `x ^ y` produces a number that has one bits in positions where exactly one of x and y have one bits.

### NOT

The not operation $\sim x$ produces a number where all the bits of x have been inverted. The formula $\sim x = −x−1$ holds, for example, $\sim 29 = −30$.

### Bit Shifts

The left bit shift $x << k$ appends k zero bits to the number, and the right bit shift x >> k removes the k last bits from the number. For example, 14 << 2 = 56, because 14 and 56 correspond to 1110 and 111000. Similarly, 49 >> 3 = 6, because 49 and 6 correspond to 110001 and 110. $x << k$ corresponds to multiplying x by $2^k$ , and x >> k corresponds to dividing x by $2^k$ rounded down to an integer.

You can set / manipulate bits based using bit shifts and the bitwise operations. For example, the formula x | (1 << k) sets the kth bit of x to one, the formula x & ~(1 << k) sets the kth bit of x to zero, and the formula x ^ (1 << k) inverts the kth bit of x.

- __builtin_clz(x): the number of zeros at the beginning of the number
- __builtin_ctz(x): the number of zeros at the end of the number
- __builtin_popcount(x): the number of ones in the number
- __builtin_parity(x): the parity (even or odd) of the number of ones. 1 is odd. 0 is even.

- We can use bit shifts and the bitwise operators to efficiently perform set operations of intersection, union, complement and difference.
- Every subset of a set {0,1,2,...,n−1} can be represented as an n bit integer whose one bits indicate which elements belong to the subset.

The actual running time is much lower when we use bit operations (while the complexity remains the same) because bitwise operators are much faster. For example, Hamming distances:
```cpp
int hamming(int a, int b) {
    return __builtin_popcount(a^b);
}
```

This could work if `a` is a 32 bit number.