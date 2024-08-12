#include <cstdlib>  // for system()
#include <cerrno>   // For perror()
#include <iostream> // For std::cerr

int main() {
    // Replace the path with the correct path to your executable
    int result = system("./Downloads/Dopl/DoplOR-win32-x64/DoplOR.exe");
    
    // Check the result of the system call
    if (result == -1) {
        perror("Error running the executable");
        return 1;
    }
    return 0;
}