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

### Misc notes
- Emphasize that our application is relatively small-scale but is constructed in a way that would perform well with larger data sets
