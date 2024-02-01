void setup() {
 
pinMode(15, INPUT_PULLUP);      // Input button T245
pinMode(16, INPUT_PULLUP);      // Input button NT115A
pinMode(17, INPUT_PULLUP);      // Input button AN115A
pinMode(5, OUTPUT);             // 245/210 Tool Select
pinMode(6, OUTPUT);             // ToolChange Relay Set
pinMode(7, OUTPUT);             // AN115A Relay Set
pinMode(8, OUTPUT);             // NT115A Relay Set
pinMode(9, OUTPUT);             // T245 Relay Set

digitalWrite(5, LOW);           // T245 is the default tool selected
digitalWrite(6, LOW);           // ToolChange Relay default state OFF
digitalWrite(7, LOW);           // AN115A Relay Set default state OFF
digitalWrite(8, LOW);           // NT115A Relay Set default state OFF
digitalWrite(9, HIGH);          // T245 Relay Set default state ON

delay(300);                     // Give time for T245 Relays to set
digitalWrite(6, HIGH);          // ToolChange relay ON for default tool T245

}


void loop() {

//NT115A Input button
//
if(digitalRead(16) == LOW) {    // If NT115A Input button is pressed (LOW)
digitalWrite(6, LOW);           // Disconnect the tool
delay(300);                     // Debounce and allow JBC station for "NO Tool" 
digitalWrite(5, HIGH);          // T210 tool code for JBC station
digitalWrite(9, LOW);           // T245 Relay Set default state OFF  
digitalWrite(7, LOW);           // AN115A Relay Set default state OFF
digitalWrite(8, HIGH);          // NT115A Relay Set default state ON
delay(200);                     // Allow low power relays to set before turning on ToolChange Relay  
digitalWrite(6, HIGH);          // Reconnect the tool
}

//AN115A Input button
//
if(digitalRead(17) == LOW) {    //If AN115A Input button is pressed (LOW)
digitalWrite(6, LOW);           // Disconnect the tool
delay(300);                     // Debounce and allow JBC station for "NO Tool"
digitalWrite(5, HIGH);          // T210 tool code for JBC station
digitalWrite(9, LOW);           // T245 Relay Set default state OFF   
digitalWrite(8, LOW);           // NT115A Relay Set default state OFF
digitalWrite(7, HIGH);          // AN115A Relay Set default state ON
delay(200);                     // Allow low power relays to set before turning on ToolChange Relay  
digitalWrite(6, HIGH);          // Reconnect the tool
}

//T245 Input button
//
if(digitalRead(15) == LOW) {    //If T245 Input button is pressed (LOW)
digitalWrite(6, LOW);           // Disconnect the tool
delay(300);                     // Debounce and allow JBC station for "NO Tool"
digitalWrite(5, LOW);           // T245 tool code for JBC station
digitalWrite(7, LOW);           // AN115A Relay Set default state OFF
digitalWrite(8, LOW);           // NT115A Relay Set default state OFF
digitalWrite(9, HIGH);          // T245 Relay Set default state ON   
delay(200);                     // Allow low power relays to set before turning on ToolChange Relay  
digitalWrite(6, HIGH);          // Reconnect the tool

}
}
