int printf(const char* fmt, ...);

int main(void){
    int c;
    c = 0;
    while (c < 256)
    {
        printf(" %hhu = %c\n",c,c);
        c = c + 1 ;
    }
    
    return (0);
}