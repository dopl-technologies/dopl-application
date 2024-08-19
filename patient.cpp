#include <cstdlib>  // For system()
#include <iostream> // For std::cout and std::cerr

// Function to run an executable in a new terminal
void runExecutableInNewTerminal(const char* executablePath, const char* name) {
    std::cout << "Running " << name << " in a new terminal..." << std::endl;

    // Build the command to start a new Command Prompt and run the executable
    std::string command = "start cmd /k \"";
    command += executablePath;
    //command += "\"";
    command += " > output.log 2>&1\"";

    // Execute the command
    int result = system(command.c_str());

    // Check the result and log the appropriate message
    if (result == 0) {
        std::cout << name << " started successfully." << std::endl;
    }
    else {
        std::cerr << "Error: " << name << " failed with exit code " << result << "." << std::endl;
    }
}

int main() {
    // Define the file paths
    const char* doplorCommand = "C:\\Users\\Dopl\\Downloads\\Dopl\\DoplOR-win32-x64\\DoplOR.exe";
    const char* dataCommunicatorCommand = "C:\\Users\\Dopl\\Downloads\\Dopl\\dataCommunicator.exe";
    const char* robotCommand = "C:\\Users\\Dopl\\Downloads\\Dopl\\patient_site.exe";

    // Run the executables in separate terminals
    runExecutableInNewTerminal(dataCommunicatorCommand, "dataCommunicator.exe");
    runExecutableInNewTerminal(robotCommand, "patient_site.exe");
    runExecutableInNewTerminal(doplorCommand, "DoplOR.exe");

    return 0;
}
