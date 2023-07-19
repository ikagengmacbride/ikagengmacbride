#include <ros.h>
#include <geometry_msg/Twist.h>
#include <std_msg/String.h>
#include <turtlesim/Pose.h>
#include <ros/time.h>

const int trig_pin = 2;
const int echo_pin = 4;

ros::NodeHandle nh;

geometry_msg::Twist msg;
ros::Publisher ultrasonic_node("turtle1/cmd_vel", &ultrasonic_msg);

long distance;
long duration;

float valx;
float valy;

void setup() 
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  nh.initNode();
  nh.advertise(ultrasonic_node);

}

void loop() 
{
 digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  //digitalWrite(trig_pin,LOW);
  duration = pulseIn(echo_pin, HIGH);
  
  /*distance_in_cm = ( duration * SPEED_OF_SOUND) / 2;
  ultrasonic_msg.data = distance_in_cm;
  ultrasonic_node.publish(&ultrasonic_msg);
  nh.spinOnce();*/
  distance = int(0.017 *duration );


  if(distance <10)
  {
      valx = -0.4;
      valy = 0.0;
  }
  if(distance <10 && distance < 20 )
  {
      valx = -0.4;
      valy = 0.0;
  }
  if(distance >30)
  {
      valx = 0.4;
      valy = 0.0;
  }
  msg.linear.x = valx;
  msg.angular.z = valz;
  pub.publish(&msg);
  n.spinOnce();
  delay(3);
  
 // delay(500);

}
