## Linked List Problem Manager

### Program Description
This C program manages a set of problems and their related data using a linked list. It also provides user interaction functionalities, including displaying a warning, a menu, and input prompts.

### Code Structure
The program consists of the following elements:
1. **Struct Definition**: 
   - A struct named "node" is defined to store information about each problem. It includes fields for the problem description, two answers, and corresponding values for people, court, and treasury.
2. **Functions**:
   - `openning()`: Displays a warning message.
   - `enter_name()`: Accepts and stores a user's name (not used in the provided code).
   - `menu()`: Displays a menu and accepts user input to start a new game, load a game, view the scoreboard, or quit.
   - `clear()`: Clears the console screen.
   - `get_problems()`: Reads problem data from a file, stores it in a linked list, and returns a pointer to the list.

### How to Use
To use this program, follow these steps:
1. Compile the code using a C compiler.
2. Ensure that a file named "CHOICES.txt" is present in the program's directory, containing the problem data in the specified format.
3. Run the compiled program.
4. Follow the on-screen instructions to interact with the program, such as starting a new game, loading a game, viewing the scoreboard, or quitting.

### Additional Notes
- The program expects problem data to be stored in a file named "CHOICES.txt" in a specific format.
- The provided code does not include the implementation for starting a new game, loading a game, or viewing the scoreboard. These functionalities would need to be added to the program.

This README provides an overview of the provided C program and how to use it. For detailed information about each function and the program's behavior, refer to the code implementation.
