#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

int main() {
    std::string filename = "myfile.txt";
    std::ofstream ofs(filename, std::ios::ate);
    ofs << "Hello this is line 1;\n"
        << "Maybe this is line 2 idk:\n"
        << "Okay now this is line 3 kekek\n\n";
    ofs.close();
    std::cout << "Wrote lines to file " << filename << "\n";

    std::ifstream ifs(filename, std::ios::in);
    std::string line;
    uint32_t i = 1;
    while(std::getline(ifs, line)) {
        std::cout << "[" << i << "] `" << line << "`\n";

        i++;
    }
    ifs.close();


    return 0;
}