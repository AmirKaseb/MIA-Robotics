// Pin assignments
const int encoderPinA = 2;   // Encoder channel A pin
const int encoderPinB = 3;   // Encoder channel B pin

// Filter parameters (adjust as needed)
const float cutoffFrequency = 84.35;  
const float samplingRate = 1000.0;    

// Calculate the smoothing factor alpha based on the cutoff frequency and sampling rate
const float alpha = 1 / (2 * PI * cutoffFrequency / samplingRate);

// Variables for encoder reading and filtered value
volatile int encoderValue = 0;
float filteredValue = 0.0;

void setup() {
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  
  // Attach an interrupt to encoder channel A
  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, CHANGE);
  
  Serial.begin(9600);
}

void loop() {
  // Read the filtered encoder value
  float currentValue = filteredValue;
  
  // Print the filtered value
  Serial.println(currentValue);
}

void updateEncoder() {
  // Read the state of encoder channel B
  int channelBState = digitalRead(encoderPinB);
  
  // Update the encoder value based on channel B's state
  if (channelBState == HIGH) {
    encoderValue++;
  } else {
    encoderValue--;
  }
  
  // Update the filtered value using the low-pass filter
  filteredValue = (1 - alpha) * filteredValue + alpha * encoderValue;
}
