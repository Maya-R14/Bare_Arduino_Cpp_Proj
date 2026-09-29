//This is some simple code generated using Claude, I want to see if I can get the arduino libraries working here also and to fix the intily lens issues.

void main(void) {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);

    while (true) {
        Serial.println("Hello World");
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
    }
}