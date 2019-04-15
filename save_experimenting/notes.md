# Experimenting with File Saving

- Can mess around with using the `write` command on an `ofstream` object to write variables and such
- [This](https://stackoverflow.com/questions/5506645/how-to-read-write-a-struct-in-binary-files) seems to be a useful page
  - It includes code which demonstrates reading and writing binary data from a struct to a file and then recalling it!!
  - And it works! Okay, it seems to core dump somewhere around the destructor, but still!
  - And I've tested it on an ENTIRE CLASS and it works!!!

- [This](http://www.cplusplus.com/reference/cstdio/remove/) is a good source for how to delete a file; it's pretty easy.
- [This](https://stackoverflow.com/questions/478075/creating-files-in-c) is a good source for how to save a file; it's even easier