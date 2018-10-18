// source: https://github.com/Cuijie12358/wasd-TurtleController
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ackermann_msgs/AckermannDriveStamped.h>

int kbhit(void);
char getch(void);


int main(int argc, char **argv) {

	// TODO:
	// - initialise a publisher
	// - initialise a message and assign values
	// - set topics and node name
  ros::init(argc, argv, "talk"); // node
  std::string topic = "some_topic"; //topic name
  ros::NodeHandle n;
  char temp;
  ros::Rate loopRate(2);
  ROS_INFO("talk cpp start...");



  
	while(ros::ok())
	{
		while(kbhit())
		{
			temp = getch();
			switch (temp)
			{
				case 'w':
					// TODO: Update message values and publish

					ros::spinOnce();
					loopRate.sleep();
				case 'a':
					// TODO: Update message values and publish
					
					ros::spinOnce();
					loopRate.sleep();

					break;
				case 's':
					// TODO: Update message values and publish

					ros::spinOnce();
					loopRate.sleep();
					break;
				case 'd':
					// TODO: Update message values and publish

					ros::spinOnce();
					loopRate.sleep();
					break;
				default: break;
			}
		}
		
	}
  return 0;
}



// DON'T EDIT THIS
// These are functions to read keystrokes
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {

        ungetc(ch, stdin);

        return 1;

    }

    return 0;

}

char getch()
{
	char buf = 0;
	struct termios old = {0};
	if(tcgetattr(0,&old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if(tcsetattr(0,TCSANOW,&old) < 0)
		perror("tcsetattr ICANON");
	if(read(0,&buf,1) < 0)
		perror("read()");
	old.c_lflag |= ~ICANON;
	old.c_lflag |= ~ECHO;
	if(tcsetattr(0,TCSADRAIN,&old) < 0)
		perror("tcsetattr ~ICANON");
	return (buf);
}
