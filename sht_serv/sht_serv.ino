#include <SPI.h>
#include <Ethernet.h>
#include <SHT1x.h>
#define dataPin 4
#define clockPin 3
SHT1x sht1x(dataPin, clockPin);
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 10, 10);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

String HTTP_req;          // stores the HTTP request
boolean LED_status = 0;   // state of LED, off by default
int count=0;
int T[20],S[20],K[20];
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
     pinMode(13, OUTPUT);       // LED on pin 2    
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  T[0]=0;
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        HTTP_req += c;  //Save the HTTP request 1 char at a time
//        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
                    client.println("<HTML>");
                    client.println(" <HEAD>");
                    client.println("  <TITLE> Web Weather Station </TITLE>");
                    client.println("</head>");
                    client.println("<style>");
                    client.println("table {");
                    client.println("    width:70%;");
                    client.println("}");
                    client.println("table, th, td {");
                    client.println("    border: 1px solid black;");
                    client.println("    border-collapse: collapse;");
                    client.println("}");
                    client.println(" th, td {");
                    client.println("    padding: 5px;");
                    client.println("    text-align: left;");
                    client.println("}");
                    client.println("table#t01 tr:nth-child(even) {");
                    client.println("    background-color: #eee;");
                    client.println("}");

                    client.println("table#t01 tr:nth-child(odd) {");
                    client.println("   background-color:#fff;");
                    client.println("}");
                    client.println("table#t01 th {");
                    client.println("    background-color: #00A8A9;");
                    client.println("    color: white;");
                    client.println("}");
                    client.println("</style>");
                    client.println(" </HEAD>");
                    client.println("<body>");
                    client.println("<center>");
                    T[count]=T[count]+5;
                    S[count]=sht1x.readTemperatureC();
                    K[count]=sht1x.readHumidity();
                    client.println("<table id=""t01"">");
                    client.println("                    <tr>");
                    client.println("      <th>Sr. No</th>");
                    client.println("      <th>Temprature</th>");
                    client.println("      <th>Light Intensity</th>");
                    client.println("      <th>Humidity</th>");
                    client.println("      <th>Pressure</th> ");
                    client.println(" </tr>");
             for(int i=0;i<count;i++)
         {
                    client.println("<tr>");
                    client.print("<td>"); client.print(i+1); client.print("</td>");
                    client.print("<td>"); client.print(T[i]); client.print("</td>");
                    client.print("<td>"); client.print(S[i]); client.print(" C</td>");
                    client.print("<td>"); client.print(K[i]); client.print(" %</td>");
                    client.println("</tr>");
        }
        count++;
        if(count==20){count=0;}//Make count 0 max data logging is 20 values
                    client.println(" </table>");
                    client.println(" </center>");
                    client.println(" </body>");
                    client.println(" </html>");          Serial.print(HTTP_req);
          HTTP_req = "";  //finishehed with request, empty string
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
