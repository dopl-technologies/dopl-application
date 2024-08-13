#include <cstdlib>  // for system()
#include <iostream> // for std::cout and std::endl
#include <Python.h>

void runPythonCode(const char* code) {
    // Initialize the Python interpreter
    Py_Initialize();

    // Execute Python code
    PyRun_SimpleString(code);

    // Finalize the Python interpreter
    Py_Finalize();
}

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

    // Run Python code
    runPythonCode("print('Hello from embedded Python!')");

    // Run the first executable
    runExecutable(dataCommunicatorCommand, "dataCommunicator.exe");

    //Run second executable
    runExecutable(robotCommand, "patient_site.exe");

    // Run the third executable
    runExecutable(doplorCommand, "DoplOR.exe");

    return 0;
}
