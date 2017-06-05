#include <iostream>
#include <string.h>
#include <unistd.h>
#include "raspberry_osio_client.h"

using namespace std;

RaspberryOSIOClient * client = 0;


int main()
{
  // Our raspberry MQTT client instance.
  client = new RaspberryOSIOClient("username", "deviceid", "7s4ZHOQJ");

  cout << "Client started." << endl;
  cout << "Publishing messages: ";
  while(true) {
    result = client->publish("topic/rpi", "connected");
    cout << (result == OSIO_ERROR_SUCCESS ? "success" : "error") << endl;
    usleep(15*60*1000);
  }
  return 0;
}
