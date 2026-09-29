

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