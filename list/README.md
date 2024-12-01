# List Task

This folder contains the implementation of a linked list data structure and related operations.

## Files

- `list.hpp`: Contains the class definition and implementation of the `List` and `Node` classes, along with various methods such as `append`, `insert`, `delete`, `search`, and others.

## Classes

- **Node**: Represents a single element in the list, holding data and a pointer to the next node.
- **List**: Implements a linked list with methods to manipulate the list such as adding, removing, and searching for elements.

## Key Methods

- `append(int data)`: Adds an element to the end of the list.
- `insert(int data, int index)`: Inserts an element at the specified index.
- `delete(int index)`: Removes an element from the specified index.
- `search(int value)`: Searches for a node with the specified value.

## Usage

To use the list, include `list.hpp` in your project and create an instance of the `List` class. You can then call its methods to perform various operations on the list.

## Example

```cpp
#include "list.hpp"

int main() {
    List list;
    list.append(10);
    list.append(20);
    list.insert(15, 1);
    list.print(); // Outputs: 10 15 20
    return 0;
}
```

## License

This project is licensed under the MIT License.
