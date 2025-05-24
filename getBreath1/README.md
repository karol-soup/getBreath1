# getBreath (C++)
_________________________
A guided breathing and emotional check-in application written in C++.
This is a remake, but rewritten in Object-Oriented Programming (OOP, hence the branch name). This project encourages users to pause, regulate their breathing and reflect on their mood. It demonstrates core C++ principles, including smart pointers, STL containers, struct-based data design, file handling, and unit testing with Google Testing.

---

## Features

- Prompt users for name, date, mood, and breathing cycles
- Validates user input (name, date, mood, cycles)
- Tracks emotional states before and after breathing
- Uses structured breathing timers (4-7-8 pattern)
- Organizes data with structs and enums
- Text files to read off quotes
- Binary file to store and read data
- Unit tests for all key components using Google Test

## Project Structure
''
getBreath/
├── include/ # Header files (Date.h, Mood.h, UserInfo.h, etc.)
├── src/ # Implementation files (main.cpp, beginBreathing.cpp, etc.)
├── test/ # Google Test unit tests (test_getBreath.cpp, etc.)
├── CMakeLists.txt # Build configuration
├── .gitignore # Git ignore rules
├──  Quotes.txt # quotes file
''

---

## Build Instructions (Windows PowerShell)

### Prerequisites

- Visual Studio 2022 with C++ support
- CMake 3.16+ installed
- Google Test linked via CMake

### Build and Run

```powershell
# Navigate to your project folder
cd C:\Users\name\Desktop\getBreath1\getBreath1

# Run the main application
build\Debug\main_exec.exe

# Run unit tests
build\Debug\test_exec.exe

```
### LINK TO VIDEO
---
