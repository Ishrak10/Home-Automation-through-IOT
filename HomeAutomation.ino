#include<ESP8266WiFi.h>
#include<HttpClient.h>

//connect following pins of arduino to relay pins respectively 
#define D0 tubelight
#define D1 nightlamp
#define D2 fan
#define D3 ac

char *ssid = "ssid-of-your-wifi";
char *pwd = "password-of-your-wifi"
char *link = "http://www.webhost000.com/drogo9191/2.php" //link of the file from which data is retrieved

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

  client.get(link);
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
