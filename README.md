# Retail Micro-Manager (Rewrite/Backup Edition)

## To run
Just type `make`, and `./retailmicromanager`

## To test with screen erasing
Open `src/menu.cpp` in a text editor. Near the top of the file, there will be a macro like this:

```c++
#define DEBUG true
```

Set this macro to `false`, then follow instructions in "To run" to test out the screen erasing.

## To test the day one setup...
In order to trigger the program to see it hasn't been set up and see the day one setup process, just delete any or all 
files in `/data`. I would recommend not deleting `data/items`, because you do not add an item
in the day one set up proccess.