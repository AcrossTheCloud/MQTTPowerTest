#include <iostream>
#include <string.h>
#include <unistd.h>
#include "raspberry_osio_client.h"

using namespace std;

RaspberryOSIOClient * client = 0;


int main()
{
  // Our raspberry MQTT client instance.
  client = new RaspberryOSIOClient((char *) "username", (char *) "deviceid", (char *) "7s4ZHOQJ", "10.8.239.81");

  cout << "Client started." << endl;
  cout << "Publishing messages: ";
  while(true) {
    bool result = client->publish((char *) "topic/rpi", (char *) "connected");
    cout << (result == OSIO_ERROR_SUCCESS ? "success" : "error") << endl;
    sleep(30);
  }
  return 0;
}
