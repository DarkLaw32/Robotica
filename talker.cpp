#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 * Credito: Tutorial Oficial de ROS
 */
int main(int argc, char **argv)
{
  // Inicializamos el nodo
  ros::init(argc, argv, "talker");

  // Creamos un manejador de nodos
  ros::NodeHandle n;

  // Creamos en publicador con el topico
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  // Seteamos el looprate
  ros::Rate loop_rate(10);

  
  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    // Logeamos en consola
    ROS_INFO("%s", msg.data.c_str());

    // Pubicamos el mensaje
    chatter_pub.publish(msg);

    // Necesario
    ros::spinOnce();

    // Necesario 
    loop_rate.sleep();
    // Conteo
    ++count;
  }


  return 0;
}
