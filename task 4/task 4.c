#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to compress a file
void compressFile(const char* source, const char* destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");
    
    if (!src || !dest) {
        printf("Error opening files!\n");
        return;
    }

    int ch, nextCh;
    while ((ch = fgetc(src)) != EOF) {
        int count = 1;
        while ((nextCh = fgetc(src)) == ch) {
            count++;
        }
        // Write character and its count to the file
        fprintf(dest, "%c%d", ch, count);
        
        // Put back the non-matching character for the next iteration
        if (nextCh != EOF) ungetc(nextCh, src);
    }

    fclose(src);
    fclose(dest);
    printf("Compression successful: %s -> %s\n", source, destination);
}

// Function to decompress a file
void decompressFile(const char* source, const char* destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");

    if (!src || !dest) {
        printf("Error opening files!\n");
        return;
    }

    int ch;
    int count;
    // Format expects a char followed by an integer count
    while ((ch = fgetc(src)) != EOF) {
        if (fscanf(src, "%d", &count) == 1) {
            for (int i = 0; i < count; i++) {
                fputc(ch, dest);
            }
        }
    }

    fclose(src);
    fclose(dest);
    printf("Decompression successful: %s -> %s\n", source, destination);
}

int main() {
    [span_4](start_span)[span_5](start_span)// Requirements: Proper commenting and modularity[span_4](end_span)[span_5](end_span)
    int choice;
    printf("CODTECH Task 4: Data Compression Tool\n");
    printf("1. Compress File\n2. Decompress File\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        compressFile("input.txt", "compressed.rle");
    } else if (choice == 2) {
        decompressFile("compressed.rle", "output.txt");
    } else {
        printf("Invalid selection.\n");
    }

    return 0;
}