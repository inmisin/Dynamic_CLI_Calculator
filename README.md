# Dynamic CLI Calculator

Dynamic CLI Calculator is a command-line-based calculator developed in C that utilizes dynamic memory allocation. Instead of predicting the length of the mathematical expression entered by the user or using a fixed buffer size, it reads the input character-by-character and expands the memory at runtime.

## 🚀 Features

* **Dynamic Memory Management:** No fixed `char` array (buffer) size is defined for user input; memory is dynamically expanded using `realloc` to prevent buffer overflow risks.
* **Command-Line Interface (CLI):** Lightweight, fast, and operates directly within the terminal.
* **Error Handling:** Safely checks for invalid operator inputs and memory allocation failures.
* **Basic Mathematical Operations:** Supports Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`).

## 🛠️ How It Works

The project is built around three core architectural components:

1.  **`FindSize` (Dynamic Input Handling):** Reads the input from the terminal dynamically using `getchar()`. For every new character, it resizes the memory with `realloc` and automatically appends the null terminator (`\0`) at the end of the string.
2.  **`CLI_Calculator` (String Parsing):** Parses the dynamically received string expression using `sscanf` to separate the operands (numbers) and the operator.
3.  **`ChooseOperator` (Math Engine):** Executes the corresponding mathematical operation in linear time using a `switch-case` structure based on the parsed operator.

## 📋 Usage Example

After running the program, you can enter standard mathematical expressions directly into the terminal:

```text
Bir hesaplama yazınız: 
15.5 + 4.5
Calculation is: 20.00 

Bir hesaplama yazınız: 
10 * 3
Calculation is: 30.00
