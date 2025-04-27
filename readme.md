# Banking Management System in C (GUI Mode)

## Overview
This project is a **Banking Management System** developed in the C programming language with a graphical user interface (GUI). The system allows users to:
- **Create new accounts**
- **Deposit and withdraw money**
- **Save and load account data from a file**

## Features
- **Account Creation:** Users can create new bank accounts by providing personal details and an initial deposit.
- **Deposit/Withdraw:** Users can deposit or withdraw money from their accounts.
- **Data Persistence:** All account information is saved to a file, ensuring data is retained between sessions.
- **Graphical User Interface:** The application uses a GUI for user-friendly interaction (e.g., using libraries like WinBGIm, GTK, or similar for C).

## Getting Started
1. **Clone or Download** this repository to your local machine.
2. **Compile the source code** using a C compiler that supports GUI libraries (e.g., GCC with WinBGIm/graphics.h on Windows).
3. **Run the executable** to start the Banking Management System.

## Example Usage
- Launch the application.
- Create a new account by entering user details.
- Deposit or withdraw money using the provided options.
- Exit the application to save all data to a file.

## File Structure
- `index.c` : Main source code for the Banking Management System.
- `readme.md` : Project documentation.
- `accounts.dat` : (Example) Data file for storing account information (created at runtime).

## Dependencies
- C Compiler (GCC recommended)
- GUI Library for C (e.g., WinBGIm/graphics.h for Windows, GTK for Linux)

## Notes
- Ensure the required graphics library is installed and properly linked during compilation.
- The GUI implementation may vary depending on the platform and library used.

## License
This project is for educational purposes.
