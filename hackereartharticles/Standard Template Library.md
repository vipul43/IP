## Standard Template Library
----------------------------
Article Name: Standard Template Library <br>
Article Link: https://www.hackerearth.com/practice/notes/standard-template-library/

### String `string`
------------------
> string is a container class in Standard Template Library

| Operation | Function | Time Complexity | Remarks |
|-----------|----------|-----------------|---------|
| `size()` | returns length of the string | O(1) | `length()` is also equivalent |
| `append()`| appends new string to the end | O(N) where N is the length of new string | `+` or `+=` is also equivalent |
| `at()` | returns character at particular position | O(1) | `[]` is also equivalent |
| `find()` | returns first occurence of the search string in parent string | O(N) where N is the length of the parent string | - |
| `insert()` | inserts additional characters into a particular position of the string | O(N) where N is the length of the new string | - |
| `begin()` | returns iterator pointing to the first character | O(1) | - |
| `end()` | returns iterator pointing to the last character | O(1) | - |
| `empty()` | returns boolean values(true if string is empty else false) | O(1) | - |
| `clear()` | clears entire string | O(1) | - |
| `erase()` | erases substring of the string | O(N) where N is the length of new string | - |
| `substr()` | returns copy of substring of parent string | O(N) where N is the length of substring | - |
| `replace()` | replaces particular portion of the string | O(N) where N is the length of the new string | - |
| `compare()` | compares string with another string(returns 0 if both the strings are identical) | O(N+M) where N is length of one string and M is length of other string | - |
| `c_str()` | converts string into C-style and returns pointer to the first character | O(1) | - |

### Vector `vector<typename T>`
------------------------------
> Vectors are dynamic arrays.

| Operation | Function | Time Complexity | Remarks |
|-----------|----------|-----------------|---------|
| `size()` | returns length of the vector | O(1) | - |
| `push_back()` | inserts new element at the end of vector | O(1) | `emplace_back()` is also equivalent |
| `pop_back()` | removes element from the end of vector | O(1) | - |
| `at()` | returns element at particular position | O(1) | `[]` is also equivalent |
| `insert()` | inserts additional elements into particular position of the vector | O(N+M) where N is the number of elements inserted and M is the number of elements moved | - |
| `begin()` | returns iterator pointing to the first element | O(1) | - |
| `end()` | returns iterator pointing to the last element | O(1) | - |
| `empty()` | returns boolean values(true if vector is empty else false) | O(1) | - |
| `erase()` | erases subvector of the vector | O(N+M) where N is the number of elements erased and M is the number of elements moved | - |

### List `list<typename T>`
---------------------------
> List is implemented as Doubly Linked List.

| Operation | Function | Time Complexity | Remarks |
|-----------|----------|-----------------|---------|
| `size()` | returns length of the list | O(1) | - |
| `push_back()` | inserts new element at the end of list, after its current last element | O(1) | `emplace_back()` is also equivalent |
| `push_front()` | inserts new element at the start of list, before its current first element | O(1) | `emplace_front()` is also equivalent |
| `pop_back()` | removes element from the end of list | O(1) | - |
| `pop_front()` | removes element from the start of list| O(1) | - |
| `at()` | returns element at particular position | O(1) | `[]` is also equivalent |
| `insert()` | inserts additional elements into particular position of the list | O(N) where N is the number of elements inserted | - |
| `begin()` | returns iterator pointing to the first element | O(1) | - |
| `end()` | returns iterator pointing to the last element | O(1) | - |
| `empty()` | returns boolean values(true if list is empty else false) | O(1) | - |
| `erase()` | erases sublist of the list | O(N) where N is the number of elements erased | - |
| `remove()` | removes all elements from the list which are equivalent to particular element | O(N) | - |
| `reverse()` | reverses the order of elements in the list | O(N) where N is the length of the list | - |

### Set `set<typename T>`
-------------------------
> Unique values, ordered storing(ascending or descending), elements cannot be modified. They are implemented using Binary Search Trees.

| Operation | Function | Time Complexity | Remarks |
|-----------|----------|-----------------|---------|
| `size()` | returns length of the set | O(1) | - |
| `insert()` | inserts new element into the set | O(log(N)) | - |
| `clear()` | clears entire set | O(N) where N is the size of the set | - |
| `find()` | finds and returns iterator pointing to particular element. If element not found returns iterator pointing to the end of the set | O(log(N)) where N is the size of the set | - |
| `begin()` | returns iterator pointing to the first element | O(1) | - |
| `end()` | returns iterator pointing to the last element | O(1) | - |
| `empty()` | returns boolean values(true if set is empty else false) | O(1) | - |
| `erase()` | deletes element or range of elements from the set | O(N) where N is the number of elements in the delete range | - |
| `count()` | returns 1 if particular element is present else 0 | O(log(N)) where N is the size of the set | - |

### Map `map<typename T, typename U>`
-------------------------------------
> Implemented using Red Black Tree.

| Operation | Function | Time Complexity | Remarks |
|-----------|----------|-----------------|---------|
| `size()` | returns length of the map | O(1) | - |
| `insert()` | inserts new element or range of elements into the map | O(log(N)) | - |
| `at()` | returns reference to element at particular position | O(log(N)) | `[]` is also equivalent |
| `clear()` | clears entire map | O(N) where N is the size of the map | - |
| `find()` | finds particular element in keys and returns iterator pointing to particular element. If element not found returns iterator pointing to the end of the map | O(log(N)) where N is the size of the set | - |
| `begin()` | returns iterator pointing to the first element | O(1) | - |
| `end()` | returns iterator pointing to the last element | O(1) | - |
| `empty()` | returns boolean values(true if map is empty else false) | O(1) | - |
| `erase()` | deletes element or range of elements from the map | - | - |
| `count()` | returns number of matches of particular element with values of the map(if there is no key corresponding to the particular element as value then returns 0) | O(log(N)) | - |
| `swap()` | swap contents of one map with another | - | - |

### Stack `stack<typename T>`
----------------------------

### Queue `queue<typename T>`
----------------------------

### Priority Queue `priority_queue<typename T>`