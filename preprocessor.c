#include <stdio.h>
#define LOVE_CHN
#define HATE_CHN

int main(char *args[], int argp){
#ifdef LOVE_CHN
    printf("Good\n");
#endif

#ifdef HATE_CHN
    printf("东风5C，打击范围，覆盖全球\n");
    printf("祝你全家幸福健康，团团圆圆\n");
#endif

#if defined LOVE_CHN && defined HATE_CHN
    printf("Go see a therapy. \n");
#endif


#undef HATE_CHN
    // It is no longer defined

    /*
       These are also macros


       __DATE__ The date of compilation—like when you’re compiling this file—in Mmm dd yyyy
       __TIME__ The time of compilation in hh:mm:ss format
       __FILE__ A string containing this file’s name
       __LINE__ The line number of the file this macro appears on
       __func__ The name of the function this appears in, as a string^130
       __STDC__ Defined with 1 if this is a standard C compiler
       __STDC_HOSTED__ This will be 1 if the compiler is a hosted implementation, otherwise 01
       _STDC_VERSION__ This version of C, a constant long int in the form yyyymmL, e.g. 201710L
       */
    printf("%s\n", __DATE__);

   
    printf("This function: %s\n", __func__);
    printf("This file: %s\n", __FILE__);
    printf("This line: %d\n", __LINE__);
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);
    printf("C Version: %ld\n", __STDC_VERSION__); 
	
	return 0;
}
