#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int first;
    int last;
} First_Last_Numbers;

int convert_word_to_number(char* str)
{
    char* words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int x = 0; x < 9; x++)
    {
        if(strstr(str, words[x])) 
        {
            return x + 1;
        }
    }

    return 0;
}

// Extract numbers from string into the First_Last_Numbers
First_Last_Numbers extract_numbers_from_string(char* str, First_Last_Numbers numbers)
{
    int first_number_found = 0;

    // Buffer to verify if there is a word in the string
    char buffer[5], sliced_buffer[3];
    
    // Read string
    while(*str)
    {
        // Check each character and the 4 next for a first number
        if(!first_number_found)
        {
            // Loading buffers to get a possible word
            for(int x = 0; x < 5; x++)
                buffer[x] = *(str + x);
            if(convert_word_to_number(buffer))
            {
                numbers.first = convert_word_to_number(buffer);
                numbers.last = numbers.first;
                first_number_found = 1;
            }

            // Verify if the next character is a digit
            if(isdigit(*(str + 1)))
            {
                numbers.first = *(str + 1) - 48;
                first_number_found = 1;
                numbers.last = numbers.first;
            }

            // Verify if character is a digit
            if(isdigit(*str))
            {
                numbers.first = *str - 48;
                first_number_found = 1;
                numbers.last = numbers.first;
            }
        }
       
        // Inverted order from the first number
        if(isdigit(*str))
            numbers.last = *str - 48;

        if(isdigit(*(str + 1)))
            numbers.last = *(str + 1) - 48;

        for(int x = 0; x < 5; x++)
            buffer[x] = *(str + x);
        if(convert_word_to_number(buffer))
            numbers.last = convert_word_to_number(buffer);
        
        str++;
    }

    return numbers;
}

int main()
{
    unsigned int sum = 0;

    // Open file
    FILE* aoc_day1_part2 = fopen("day1.txt", "r");
    if(!aoc_day1_part2) 
    {
        perror("File not found");
    }

    // Buffer to store lines
    char buffer[80];

    // Struct to store numbers extracted from the line
    First_Last_Numbers numbers;

    // Read file
    while(fgets(buffer, sizeof buffer, aoc_day1_part2))
    {
        numbers = extract_numbers_from_string(buffer, numbers);
        sum += 10*(numbers.first) + numbers.last;
    }
    printf("\nSUM : %d", sum);

    return 0;
}
