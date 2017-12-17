#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * Credito: Tutorial Oficial de ROS
 */

// Funcion que se ejecuta cada ves que llega el mensaje
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // Inicializamos el nodo
  ros::init(argc, argv, "listener");

  // Creamos un manejador de nodos
  ros::NodeHandle n;

  // Nos suscribimos y usamos la funcion de callback
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  // Necesario
  ros::spin();

  return 0;
}
