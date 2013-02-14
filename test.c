
#include "ariac.h"
#include <stdio.h>
#include <unistd.h> // for sleep()

int main(int argc, char **argv)
{
  aria_init(argc, argv);
  while(1)
  {
    if(!arrobot_connect())
      return 1 ;
    printf("radius=%.2f, length=%.2fmm, width=%.2fmm\n", 
      arrobot_radius(),
      arrobot_length(),
      arrobot_width()
    );
    arrobot_setvel(200);
    arrobot_setrotvel(10);
    for(int c = 0; c < 10; ++c)
    {
      arrobot_connect(); // should skip connection if already connected.
      printf("x=%.1f y=%.1f th=%.1f vel=%.1f rotvel=%.1f left=%.1f right=%.1f stall=%d\n",
        arrobot_getx(),
        arrobot_gety(),
        arrobot_getth(),
        arrobot_getvel(),
        arrobot_getrotvel(),
        arrobot_getleftvel(),
        arrobot_getrightvel(),
        arrobot_isstalled()
      );
      printf("sonar");
      for(int i = 0; i < arrobot_getnumsonar(); ++i)
      {
        printf(" %d=%d", i, arrobot_getsonarrange(i));
      }
      puts("");
      sleep(1);
    }
    arrobot_disconnect();
    puts("disconnected, reconnecting in 5 sec...");
    sleep(5);
  }
  return 0;
}
