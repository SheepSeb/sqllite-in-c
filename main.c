#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    char* buffer;
    size_t buffer_len;
    ssize_t input_len;
} InputBuffer;

InputBuffer* new_input_buffer(){
    InputBuffer* input = (InputBuffer*)malloc(sizeof(InputBuffer));
    input->buffer = NULL;
    input->buffer_len = 0;
    input->input_len = 0;

    return input;
}

void print_promt() {
    printf("sebDB> ");
}

void read(InputBuffer* input){
    ssize_t byte_read = getline(&(input->buffer), &(input->buffer_len), stdin);

    if(byte_read <= 0){
        printf("ERROR READING INPUT\n");
        exit(EXIT_FAILURE);
    }

    input->input_len = byte_read - 1;
    input->buffer[byte_read - 1] = 0;
}

void close_buffer(InputBuffer* buffer){
    free(buffer->buffer);
    free(buffer);
}

int main(int argc, char const *argv[])
{
    InputBuffer* input = new_input_buffer();
    while(1){
        print_promt();
        read(input);

        if(strcmp(input->buffer, "*exit") == 0){
            printf("Closing CLI \n");
            close_buffer(input);
            exit(EXIT_SUCCESS);
        }
        else{
            printf("COMMAND UNKNOWN %s .\n",input->buffer);
        }
    }
    return 0;
}
