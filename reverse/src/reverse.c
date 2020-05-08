#include <stdio.h>

#define WORD_LENGTH     32

unsigned int reverse(unsigned int word)
{
    unsigned int reversed = 0;
    for(int i = 0; i < WORD_LENGTH; i++)
    {
        if(word & (1 << i))
            reversed |= 1 << (WORD_LENGTH - 1 -i);
    }
    return reversed;
}

int main(int argc, char *argv[])
{
    unsigned int word = 0x43;
    printf("A word has %lu bits.\n", sizeof(unsigned int) * 8);
    printf("The reverse of 0x%x is 0x%x\n", word, reverse(word));
}
