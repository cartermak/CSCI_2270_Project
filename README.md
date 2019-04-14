# CSCI 2270 Project
Carter Mak and William Walker

### Macro
- Inventory spare parts
- Identify things in the inventory
  - Sort by machine/type/whatever/part number
  - Search by all of the above
- Simple command line interface (or HTML?)
- Track inidividual machines and the parts they contain

### Shit to maybe use
- Ultralight UI for integrating HTML UI with C++


### File Saving
- 
- Store a file for each struct instance and its properties
- Come up with some system for file naming, e.g. 1x109140151x12345 -> *machine 1* *part #109140151* *request identifier 12345*
- Need to construct the naming system to form a clear file heiarchy
- Only save the specific files being edited

### UI Flowchart
![mainMenu](https://user-images.githubusercontent.com/49076171/56089190-a1683f80-5e4c-11e9-978e-d68eb0ae0f72.png)

---
**Carter, 13 April**
- Copied functions `hashFunction` and `editPart` to the `Connection.cpp` file, moved original files to `/deprecated`
- Edited the `Request` struct to have a `count` field for storing number of parts to order
- Edited the way parts are stored in the hash table. Instead of the hash table containing pointers to one part, then vectors to other parts after that, the table is now simply a table of vectors of parts. This involved editing:
  - `addPart`
  - `searchPart`
  - Constructor function
  - header file
- Edited `mainMenu.cpp`:
  - Moved the menu printing to a separate function for cleanliness
  - Built cases for adding a part, adding an order, and viewing a part
  - Added functions for printing the contents of a part and adding a part
- New functions in `Connection.cpp`/`project.hpp`:
  - orderPart: adds a part order (`Request` struct). Initializes the ordered and fulfilled dates to 0, and sets the request date based on the current time. Set the accessors such that if these fields are zero, the part hasn't been ordered/fulfilled (as opposed to printing that they were ordered Jan 1, 1970)
