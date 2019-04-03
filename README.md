# CSCI 2270 Project
Carter Mak and William Walker

### Functions
- Search for available parts
- Add a part to a machine
- Remove a part from a machine
- Store the data to a file


#### Macro
- Inventory spare parts
- Identify things in the inventory
  - Sort by machine/type/whatever/part number
  - Search by all of the above
- Simple command line interface (or HTML?)
- Track inidividual machines and the parts they contain

#### Specifics
- 2 main categories: parts and machines  

###### Parts
- Use a common struct definition for parts:
  - Part number
  - Part name (string)
  - Part description (string)
  - Quantity available in stock
  - Quantity on order

###### Machines
- Struct definition for machine parts

### Shit to maybe use
- Ultralight UI for integrating HTML UI with C++


### File Saving
- 
- Store a file for each struct instance and its properties
- Come up with some system for file naming, e.g. 1x109140151x12345 -> *machine 1* *part #109140151* *request identifier 12345*
- Need to construct the naming system to form a clear file heiarchy
- Only save the specific files being edited
