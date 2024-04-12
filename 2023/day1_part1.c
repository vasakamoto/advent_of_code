#include <stdio.h>
#include <stdlib.h>

int convert_char_to_integer(char ch)
{
    if(ch > 47 && ch < 58)
    {
        return ch - 48;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char ch;
    int first_digit, last_digit, sum, line, number, first_digit_acquired;
    first_digit = last_digit = sum = line = number = first_digit_acquired = 0;

    // Open file 
    FILE * aoc_day1_part1;
    aoc_day1_part1 = fopen("day1.txt." ,"r");
    
    // Read file
    while(ch != EOF)
    {
        ch = fgetc(aoc_day1_part1);

        // Get first numeric character of line
        if(convert_char_to_integer(ch) != -1)
        {
            first_digit = convert_char_to_integer(ch);
            first_digit_acquired = 1;
        }

        // Get last numeric character
        if(first_digit_acquired)
        {
            //In case that there is no other numeric character
            last_digit = first_digit;

            // Proceed reading until end of line
            while(ch != 10)
            {
                ch = fgetc(aoc_day1_part1);
                if(convert_char_to_integer(ch) != -1)
                {
                    last_digit = convert_char_to_integer(ch);
                }
            }

            // Accumulate into a buffer
            number = (first_digit * 10) + last_digit;
            sum += number;
            line++;

            // Search for next first numeric character
            first_digit_acquired = 0;
        }

    }

    // Close file
    fclose(aoc_day1_part1);

    printf("\nSum = %d\n\n", sum);
    return 0;
}
