static inline unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

#define VIDEO_MEMORY ((char*)0xB8000)
#define VGA_WIDTH 80

void print_char(char c, int col, int row) {
    VIDEO_MEMORY[(row * VGA_WIDTH + col) * 2] = c;
}

void keyboard_handler() {
    unsigned char scancode = inb(0x60);  // Read from keyboard port
    char letter = '?';

    // Convert scancode to ASCII (simplified)
    if (scancode == 0x1E) letter = 'A';
    else if (scancode == 0x30) letter = 'B';
    else if (scancode == 0x2E) letter = 'C';

    print_char(letter, 0, 0);
}

void main() {
    while (1) keyboard_handler();
}
