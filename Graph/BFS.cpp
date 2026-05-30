/*
Complexity Analysis

```cpp
vector<int> BFS(int vertices, vector<int> adjacentMatrix[], int source_node)
```

Assuming `adjacentMatrix` is actually an **adjacency list** representation (despite the name), the complexity analysis is:

---

# Time Complexity

## Initialization

```cpp
vector<bool> visited(vertices,false);
```

Creates and initializes `V` entries.

**Cost:** `O(V)`

---

## BFS Traversal

```cpp
while(!q.empty())
```

Each vertex is:

* pushed into queue once
* popped from queue once

So queue operations contribute:

**Cost:** `O(V)`

---

## Visiting Neighbors

```cpp
for(auto it : adjacentMatrix[elem])
```

Across the entire BFS:

* Every adjacency list is scanned once.
* Total number of neighbor entries scanned equals the total number of edges.

For:

### Undirected Graph

Each edge appears twice:

```
u -> v
v -> u
```

Total adjacency entries = `2E`

Still:

```
O(2E) = O(E)
```

### Directed Graph

Each edge appears once.

Total adjacency entries = `E`

**Cost:** `O(E)`

---

## Total

```text
O(V) + O(V) + O(E)
```

Therefore:

```text
Time Complexity = O(V + E)
```

where:

* `V` = number of vertices
* `E` = number of edges

---

# Space Complexity

## Visited Array

```cpp
vector<bool> visited(vertices,false);
```

Uses:

```text
O(V)
```

---

## Queue

In the worst case, the queue may contain all vertices.

Example:

```
      0
    / | \
   1  2  3
  /|\
 ...
```

Queue size can grow to `V`.

**Cost:**

```text
O(V)
```

---

## Result Vector

Stores every visited node once.

**Cost:**

```text
O(V)
```

---

## Total Auxiliary Space

```text
O(V) + O(V) + O(V)
```

Ignoring constants:

```text
Space Complexity = O(V)
```

---

# Final Complexity

| Metric             | Complexity   |
| ------------------ | ------------ |
| Time               | **O(V + E)** |
| Auxiliary Space    | **O(V)**     |
| Queue Operations   | **O(V)**     |
| Neighbor Traversal | **O(E)**     |

### Why BFS is `O(V + E)` and not `O(V * E)`?

Because each:

* vertex is processed exactly once,
* edge is examined exactly once (directed) or twice (undirected),

so the work accumulates as:

```text
Vertices work + Edge work
= O(V) + O(E)
= O(V + E)
```

This is the standard optimal complexity for BFS on an adjacency-list graph.

*/



#include <bits/stdc++.h>
#include "iostream"
#include<queue>

using namespace std;

vector<int> BFS( int vertices, vector<int> adjacentMatrix[], int source_node ) {

    vector<bool> visited(vertices,false);
    queue<int> q;
    vector<int> result;
    q.push(source_node);
    visited[source_node] = true;

    while(!q.empty()) {

        int elem = q.front();
        result.push_back(elem);
        
        q.pop();

        for( auto it : adjacentMatrix[elem]) {
            if( !visited[it]) {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    return result;
}
