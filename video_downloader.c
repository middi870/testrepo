#include <stdio.h>
#include <stdlib.h>

void download_video(const char *url) {
    char command[512];

    // Construct the system command to call yt-dlp
    snprintf(command, sizeof(command), "yt-dlp -f best %s", url);

    printf("Downloading video from: %s\n", url);
    
    // Execute the command
    int ret = system(command);
    
    if (ret == 0) {
        printf("Download complete!\n");
    } else {
        printf("An error occurred while downloading.\n");
    }
}

int main() {
    char url[256];

    printf("Enter the YouTube video URL: ");
    if (fgets(url, sizeof(url), stdin) != NULL) {
        // Remove trailing newline character from URL
        url[strcspn(url, "\n")] = '\0';

        download_video(url);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
