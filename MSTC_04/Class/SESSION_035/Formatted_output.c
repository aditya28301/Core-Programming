int printf(const char* fmt,...);

char chr = 'A';
unsigned char b_num = 145;
short s_num = -1582;
unsigned short us_num = 58200;
int n = 34861;
unsigned int un = 34346;
long int lng_n = -36343632;
unsigned long int u_lng_n = 343434;
unsigned long int  v_lng_n = -334131231231233123;
unsigned long long u_v_lng_n = 3848234823423;

int main(void){
    printf("chr=%c\n",chr);
    printf("b_num= %hhu\n",b_num);
    printf("s_num= %hd\n",s_num);
    printf("us_num= %hu\n",us_num);
    printf("n = %d\n", n);
    printf("un = %u\n",un);
    printf("lng_n = %ld\n", lng_n);
    printf("u_lng_n = %lu\n", u_lng_n);
    printf("v_lng_ = %lld\n", v_lng_n);
    printf("u_v_lng = %llu\n", u_v_lng_n);
    return (0);
}