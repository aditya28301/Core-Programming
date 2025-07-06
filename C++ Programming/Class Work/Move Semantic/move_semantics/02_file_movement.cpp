#include <iostream> 
#include <fstream>
#include <cassert>  
#include <cstdio> 
#include <cstring> 
#include <string> 

class FileWrapper
{
    private: 
        const char* file_path; 
        // static void fcopy(const char* dest_path, const char* src_path, const char* dest_open_mode); 
    public: 
        FileWrapper(const char* fp) : file_path(fp) 
        {
        }

        FileWrapper(const FileWrapper&) = delete; 
        FileWrapper& operator=(const FileWrapper&) = delete; 

        ~FileWrapper()
        {
            if(file_path)
            {
                std::remove(file_path); 
                file_path = NULL; 
            }
        }

        FileWrapper(FileWrapper&& otherFile)
        {
            #define BUFFER_SIZE 256
            FILE* fp_dest = NULL; 
            FILE* fp_src = NULL; 
            static char buffer[BUFFER_SIZE];  
            fp_dest = fopen(file_path, "a"); 
            assert(fp_dest); 

            fp_src = fopen(otherFile.file_path, "r"); 
            assert(fp_src); 

            while(fgets(buffer, BUFFER_SIZE, fp_src))
            {
                fputs(buffer, fp_dest); 
                memset(buffer, 0, BUFFER_SIZE); 
            }

            fclose(fp_src); 
            fp_src = NULL; 

            fclose(fp_dest); 
            fp_dest = NULL; 

            std::remove(otherFile.file_path); 
            otherFile.file_path = NULL; 
        }

        FileWrapper& operator=(FileWrapper&& otherFile)
        {
            #define BUFFER_SIZE 256
            FILE* fp_dest = NULL; 
            FILE* fp_src = NULL; 
            static char buffer[BUFFER_SIZE]; 
            fp_dest = fopen(file_path, "a"); 
            assert(fp_dest); 

            fp_src = fopen(otherFile.file_path, "r"); 
            assert(fp_src); 

            while(fgets(buffer, BUFFER_SIZE, fp_src))
            {
                fputs(buffer, fp_dest); 
                memset(buffer, 0, BUFFER_SIZE); 
            }

            fclose(fp_src); 
            fp_src = NULL; 

            fclose(fp_dest); 
            fp_dest = NULL; 

            std::remove(otherFile.file_path); 
            otherFile.file_path = NULL; 

            return *this; 
        }
}; 

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout << "Usage Error:" << argv[0] << "source_file(s) dest_files" << std::endl; 
        exit(EXIT_FAILURE);
    }

    FileWrapper fDest(argv[argc-1]); 
    for(int i = 1; i < argc-1; ++i)
        fDest = std::move(FileWrapper(argv[i])); 

    return (0); 
}