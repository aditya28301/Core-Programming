#include <fstream>
#include <iostream>
#include <cstring> // for strerror
#include <cstdlib> // for EXIT_FAILURE

int main() {
    std::ifstream read_file("source.txt");
    std::ofstream write_file("destination.txt");

    if (!read_file.is_open()) {
        std::cerr << "ERROR OPENING SOURCE FILE: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    if (!write_file.is_open()) {
        std::cerr << "ERROR OPENING DESTINATION FILE: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    while (getline(read_file, line)) {
        // Write the line and add back the newline that getline removed
        if (!(write_file << line << '\n')) {
            std::cerr << "ERROR WRITING TO FILE: " << strerror(errno) << std::endl;
            return EXIT_FAILURE;
        }
    }

    // Check if loop ended due to error (other than EOF)
    if (!read_file.eof() && read_file.fail()) {
        std::cerr << "ERROR READING FILE: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    read_file.close();
    write_file.close();

    return 0;
}
