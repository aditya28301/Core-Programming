#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

#define SUCCESS 1
#define FAILURE 2
#define MAX_LINE_LENGTH 4096

typedef int status_t;

// Function to touch file (update modification time) to trigger VS Code refresh
void touch_file(const char* filename) {
    struct stat st;
    struct timespec times[2];
    
    stat(filename, &st);
    times[0] = st.st_atim;
    times[1].tv_sec = time(NULL);
    times[1].tv_nsec = 0;
    utimensat(0, filename, times, 0);
}

status_t copy_file(const char* source_file, const char* destination_file) {
    FILE* read_fd = NULL;
    FILE* write_fd = NULL;
    FILE* log_fd = NULL;
    char line_buffer[MAX_LINE_LENGTH];
    char log_buffer[MAX_LINE_LENGTH + 100];
    int line_count = 0;
    
    // Create fresh files
    write_fd = fopen(destination_file, "w");
    if (write_fd == NULL) {
        return FAILURE;
    }
    fclose(write_fd);
    
    log_fd = fopen("log.txt", "w");
    if (log_fd == NULL) {
        return FAILURE;
    }
    fclose(log_fd);
    
    // Open source file
    read_fd = fopen(source_file, "r");
    if (read_fd == NULL) {
        log_fd = fopen("log.txt", "a");
        time_t current_time = time(NULL);
        char* timeString = ctime(&current_time);
        timeString[strlen(timeString) - 1] = '\0';
        fprintf(log_fd, "[%s] ERROR: Cannot open source file '%s' - %s\n", 
                timeString, source_file, strerror(errno));
        fclose(log_fd);
        touch_file("log.txt");
        return FAILURE;
    }
    
    // Log start
    log_fd = fopen("log.txt", "a");
    time_t start_time = time(NULL);
    char* startTimeString = ctime(&start_time);
    startTimeString[strlen(startTimeString) - 1] = '\0';
    fprintf(log_fd, "[%s] START: Copying '%s' to '%s' line by line\n", 
            startTimeString, source_file, destination_file);
    fclose(log_fd);
    touch_file("log.txt");  // Force VS Code to notice the change
    
    // Read each line with delay
    while (fgets(line_buffer, MAX_LINE_LENGTH, read_fd) != NULL) {
        line_count++;
        
        // Wait 2 seconds between lines (except for first line)
        if (line_count > 1) {
            sleep(2);
        }
        
        // Append line to destination
        write_fd = fopen(destination_file, "a");
        if (write_fd == NULL) {
            log_fd = fopen("log.txt", "a");
            time_t current_time = time(NULL);
            char* timeString = ctime(&current_time);
            timeString[strlen(timeString) - 1] = '\0';
            fprintf(log_fd, "[%s] ERROR: Cannot write to destination - %s\n", 
                    timeString, strerror(errno));
            fclose(log_fd);
            touch_file("log.txt");
            fclose(read_fd);
            return FAILURE;
        }
        
        // Write the line
        fprintf(write_fd, "%s", line_buffer);
        fclose(write_fd);
        
        // Touch file to trigger VS Code refresh
        touch_file(destination_file);
        
        // Remove newline for logging
        char display_line[MAX_LINE_LENGTH];
        strcpy(display_line, line_buffer);
        size_t len = strlen(display_line);
        if (len > 0 && display_line[len-1] == '\n') {
            display_line[len-1] = '\0';
        }
        
        // Append to log
        log_fd = fopen("log.txt", "a");
        time_t current_time = time(NULL);
        char* timeString = ctime(&current_time);
        timeString[strlen(timeString) - 1] = '\0';
        fprintf(log_fd, "[%s] LINE %d: Copied \"%s\"\n", 
                timeString, line_count, display_line);
        fclose(log_fd);
        
        // Touch log file to trigger VS Code refresh
        touch_file("log.txt");
    }
    
    // Log completion
    log_fd = fopen("log.txt", "a");
    time_t end_time = time(NULL);
    char* endTimeString = ctime(&end_time);
    endTimeString[strlen(endTimeString) - 1] = '\0';
    fprintf(log_fd, "[%s] COMPLETE: Successfully copied %d lines\n", 
            endTimeString, line_count);
    fclose(log_fd);
    touch_file("log.txt");
    
    fclose(read_fd);
    return SUCCESS;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    
    status_t status = copy_file(argv[1], argv[2]);
    
    return (status == SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}