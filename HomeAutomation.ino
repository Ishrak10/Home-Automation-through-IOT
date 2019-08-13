#include<ESP8266WiFi.h>
#include<HttpClient.h>

#define D0 tubelight
#define D1 nightlamp
#define D2 fan
#define D3 ac

char *ssid = "BADDE";
char *pwd = "drogo9191"
char *link = "http://www.webhost000.com/drogo9191/2.php"

void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
WiFi.begin(ssid,pwd);
if(WiFi.status()!= WL_CONNECTED){
  delay(1000);
  } 
}
HttpClient client;
void loop() {

  client.get("http://www.webhost000.com/drogo9191/2.php");
  while (client.available()) {
    char c = client.read();
    if(c=='t'){
      if(client.read()=='0')
      digitalWrite(tubelight,HIGH);
      if(client.read()=='1')
      digitalWrite(tubelight,LOW);
      }
    if(c=='l'){
      if(client.read()=='0')
      digitalWrite(nightlamp,HIGH);
      if(client.read()=='1')
      digitalWrite(nightlamp,LOW);
      }
    if(c=='f'){
      if(client.read()=='0')
      digitalWrite(fan,HIGH);
      if(client.read()=='1')
      digitalWrite(fan,LOW);
      }
    if(c=='a'){
      if(client.read()=='0')
      digitalWrite(ac,HIGH);
      if(client.read()=='1')
      digitalWrite(ac,LOW);
      }
  }

  delay(5000);
}
  
}
