#include <cstdlib>
#include <iostream> 
#include <thread>
#include <string>

// Function to run an executable in a new terminal
void runExecutableInNewTerminal(const std::string& executablePath, const std::string& name) {
    std::cout << "Running " << name << " in a new terminal..." << std::endl;

    // Build the command to start a new Command Prompt and run the executable
    std::string command = "start cmd /k \"";
    command += executablePath;
    command += "\"";

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

void runInThread(const std::string& executablePath, const std::string& name) {
    runExecutableInNewTerminal(executablePath, name);
}

int main() {
    // Define the file paths
    const char* dataCommunicatorCmd = ".\\dataCommunicator\\dataCommunicator.exe";
    const char* controllerSiteCmd = ".\\controllerSite\\run_expert.exe";
    const char* expertWebCmd = ".\\expertWeb\\DoplSUR.exe";

    std::thread dataCommunicatorThread(runInThread, dataCommunicatorCmd, "dataCommunicator");
    std::thread controllerSiteThread(runInThread, controllerSiteCmd, "controllerSite");
    std::thread expertWebThread(runInThread, expertWebCmd, "expertWeb");

    dataCommunicatorThread.join();
    controllerSiteThread.join();
    expertWebThread.join();

    return 0;
}
