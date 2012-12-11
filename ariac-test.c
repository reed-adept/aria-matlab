#include "ariac.h"
#include <stdio.h>

#ifdef _MSC_VER
#include <windows.h>
#define usleep(ms) Sleep(ms)
#else
#include <unistd.h>
#endif


int main(int argc, char **argv)
{
	aria_init(argc, argv);
	if(!arrobot_connect())
	{
		puts("Could not connect to robot. Exiting.");
		usleep(2000);
		aria_exit(1);
	}

	usleep(1000);
	printf("Width=%.1f Length=%.1f Radius=%.1f NumFrontBumps=%d NumRearBumps=%d\n",
		arrobot_width(),
		arrobot_length(),
		arrobot_radius(),
		arrobot_num_front_bumpers(),
		arrobot_num_rear_bumpers()
	);

	while(1)
	{
		int i;
		printf("X=%.1f Y=%.1f Th=%.1f Vel=%.1f RotVel=%.1f Bat=%.1f NumSon=%d LeftStall=%d RightStall=%d\n",
			arrobot_getx(),
			arrobot_gety(),
			arrobot_getth(),
			arrobot_getvel(),
			arrobot_getrotvel(),
			arrobot_getbatteryvoltage(),
			arrobot_getnumsonar(),
			arrobot_isleftstalled(),
			arrobot_isrightstalled()
		);
		for(i = 0; i < arrobot_num_front_bumpers(); ++i)
			if(arrobot_get_front_bumper(i))
				printf("Front bumper %d pressed.\n", i);
		for(i = 0; i < arrobot_num_rear_bumpers(); ++i)
			if(arrobot_get_rear_bumper(i))
				printf("Rear bumper %d pressed.\n", i);

		usleep(2000);
	}

	aria_exit(0);
}