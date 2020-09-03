#include <stdio.h>

unsigned short reverse(unsigned short word)
{
    unsigned short size = sizeof(word) * 8;
    unsigned short oldMask = ~0;
    unsigned short newMask = 0;
    printf("Word to reverse: 0x%04x\n", word);
    while(size >>= 1)
    {
        newMask = oldMask ^ (oldMask << size);
        word = ((word >> size) & newMask) | ((word << size) & ~newMask);
        oldMask = newMask;
    }
    return word;
}

int main(int argc, char *argv[])
{
    unsigned short word = 0x1234;
    printf("A word has %lu bits.\n", sizeof(word) * 8);
    printf("The reverse of 0x%04x is 0x%04x\n", word, reverse(word));
}
