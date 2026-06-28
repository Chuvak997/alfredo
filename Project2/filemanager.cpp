#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>


class FileManager {
public:
    void createFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file) {
            std::cout << "File created: " << filename << std::endl;
        }
        else {
            std::cerr << "Error creating file: " << filename << std::endl;
        }
    }
		void deleteFile(const std::string& filename) {
			if (std::remove(filename.c_str()) == 0) {
				std::cout << "File deleted: " << filename << std::endl;
			} else {
				std::cerr << "Error deleting file: " << filename << std::endl;
			}
		}
        void renameFile(const std::string& oldName, const std::string& newName) {
            if (std::rename(oldName.c_str(), newName.c_str()) == 0) {
                std::cout << "File renamed from " << oldName << " to " << newName << std::endl;
            } else {
                std::cerr << "Error renaming file: " << oldName << std::endl;
            }
		}
        void copyFile(const std::string& source, const std::string& destination) {
            std::ifstream src(source, std::ios::binary);
            std::ofstream dest(destination, std::ios::binary);
            dest << src.rdbuf();
            if (src && dest) {
                std::cout << "File copied from " << source << " to " << destination << std::endl;
            } else {
                std::cerr << "Error copying file: " << source << std::endl;
            }
        }
        void moveFile(const std::string& source, const std::string& destination) {
            copyFile(source, destination);
            deleteFile(source);
        }
        void writeFile(const std::string& filename, const std::string& content) {
            std::ofstream file(filename);
            if (file) {
                file << content;
                std::cout << "Written to file: " << filename << std::endl;
            } else {
                std::cerr << "Error writing to file: " << filename << std::endl;
            }
        }
        void readFile(const std::string& filename) {
            std::ifstream file(filename);
            if (file) {
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
            } else {
                std::cerr << "Error reading file: " << filename << std::endl;
            }
		}


};



int main() {
    FileManager fileManager;

   
    fileManager.createFile("example.txt");
    fileManager.writeFile("example.txt", "Hello, World!");
    fileManager.readFile("example.txt");
    fileManager.renameFile("example.txt", "example_renamed.txt");
    fileManager.copyFile("example_renamed.txt", "example_copy.txt");
    fileManager.moveFile("example_copy.txt", "example_moved.txt");
    fileManager.deleteFile("example_renamed.txt");
    fileManager.deleteFile("example_moved.txt");

    return 0;
}

