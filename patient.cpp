#include <cstdlib>  // for system()
#include <iostream> // for std::cout and std::endl

void runExecutable(const char* command, const char* name) {
    // Print the command being run
    std::cout << "Running " << name << "..." << std::endl;

    // Execute the command
    int result = system(command);

    // Check the result and log the appropriate message
    if (result == 0) {
        std::cout << name << " ran successfully." << std::endl;
    }
    else {
        std::cerr << "Error: " << name << " failed with exit code " << result << "." << std::endl;
    }
}

int main() {
    // Correct the file paths
    const char* doplorCommand = "C:\\Users\\Dopl\\Downloads\\Dopl\\DoplOR-win32-x64\\DoplOR.exe";
    const char* dataCommunicatorCommand = "C:\\Users\\Dopl\\Downloads\\Dopl\\dataCommunicator.exe";
    const char* robotCommand = "C:\\Users\\Dopl\\Downloads\\Dopl\\patient_site\\patient_site.exe";

    // Run the first executable
    runExecutable(dataCommunicatorCommand, "dataCommunicator.exe");

    // Run the third executable
    runExecutable(doplorCommand, "DoplOR.exe");

    return 0;
}
