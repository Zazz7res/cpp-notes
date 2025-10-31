/*  shoes1.c  --  change shoes  */


#include <stdio.h>
#define ADJUST 7.31
#define SHOE "Shoe size (men's)"
#define FOOT "foot length"


int  main(void)
{

    const double SCALE =0.333;

    double shoe, foot;


    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("%20s %20s\n", SHOE, FOOT);
    printf("%20.1f", shoe);
    printf("%20.2f\n", foot);





    return 0;


}
