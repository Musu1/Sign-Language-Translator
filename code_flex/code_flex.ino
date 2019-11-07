#include <potholes.h>
#include <math.h>

const int FLEX_PIN1 = A0; // Pin connected to voltage divider output
const int FLEX_PIN2 = A1;
const int FLEX_PIN3 = A2;
const int FLEX_PIN4 = A3;


// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const double VCC = 4.98; // Measured voltage of Ardunio 5V line
const double R_DIV = 47500.0; // Measured resistance of 3.3k resistor


// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const double STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const double BEND_RESISTANCE = 90000.0; // resistance at 90 deg
unsigned char alphabet[2]={'A','B'};
double flex_values_learn[2][4]={0,0,0,0,0,0,0,0};

potholes flex4;
potholes flex1;
potholes flex2;
potholes flex3;

double average1=0;
double average2=0;
double average3=0;
double average4=0;
  int count=0;
  
void setup() {
  Serial.begin(38400);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);

}

void loop() {

  if(count==0){
  learn();
  delay(2000);
  Serial.println("Learnt the values");
  Serial.println("Following are the values of 4 flex sensor for two postures");
  Serial.println("----------------------------------------------------------------------------------------");
  for(int i=0;i<2;i++){
    Serial.print("Posture ");
    Serial.println(i+1);
    Serial.print(" ");
  for(int j=0;j<4;j++){
  Serial.print("Flex ");
  Serial.print(j+1);
  Serial.print("--- ");
  Serial.print(flex_values_learn[i][j]);
  Serial.println("");
  }
  }
  count++;
  }
  delay(2000);
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC1 = analogRead(FLEX_PIN1);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
  Serial.println("Resistance1: " + String(flexR1) + " ohms");
  Serial.println();  
   
  int flexADC2 = analogRead(FLEX_PIN2);
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
  Serial.println("Resistance2: " + String(flexR2) + " ohms");
  Serial.println();
  
  int flexADC3 = analogRead(FLEX_PIN3);
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);
  Serial.println("Resistance3: " + String(flexR3) + " ohms");
  Serial.println();
  
  int flexADC4 = analogRead(FLEX_PIN4);
  float flexV4 = flexADC4 * VCC / 1023.0;
  float flexR4 = R_DIV * (VCC / flexV4 - 1.0);
  Serial.println("Resistance4: " + String(flexR4) + " ohms");
  Serial.println();
delay(2000);
Serial.println("POSTURE1");
Serial.println("Lower Limit --------  ");
Serial.print(flex_values_learn[0][0]-100000); 
Serial.println("Upper Limit --------  ");
Serial.print(flex_values_learn[0][0]+100000);
Serial.println("Our sensor value");
Serial.println(flexR1);
delay(2000);

  if(flexR1>flex_values_learn[0][0]-100000 && flexR1<flex_values_learn[0][0]+100000){
    Serial.println("Thank you");
  }
  
delay(2000);
Serial.println("POSTURE2");
Serial.println("Lower Limit --------  ");
Serial.print(flex_values_learn[1][0]-100000); 
Serial.println("Upper Limit --------  ");
Serial.print(flex_values_learn[1][0]+100000);
Serial.println("Our sensor value");
Serial.println(flexR1);
delay(2000);
  if(flexR1>(flex_values_learn[1][0]-100000) && flexR1<(flex_values_learn[1][0]+100000)){
    Serial.println("Sorry");
  }
  delay(10000);
}

void learn(void){ 

Serial.println("Learn mode");
for(int i=0;i<2;i++){
  Serial.println("--------------------------------------");
  Serial.println("Do the gesture for ---- ");
  Serial.print(char(alphabet[i]));
  delay(5000);
  for(int i=0;i<5;i++){
    
           // Read the ADC, and calculate voltage and resistance from it
            int flexADC1 = analogRead(FLEX_PIN1);
            double flexV1 = flexADC1 * VCC / 1023.0;
            double flexR1 = R_DIV * (VCC / flexV1 - 1.0);
            Serial.println("Resistance1: " + String(flexR1) + " ohms");
            Serial.println();
            flex1.add(flexR1);  
   
            int flexADC2 = analogRead(FLEX_PIN2);
            double flexV2 = flexADC2 * VCC / 1023.0;
            double flexR2 = R_DIV * (VCC / flexV2 - 1.0);
            Serial.println("Resistance2: " + String(flexR2) + " ohms");
            Serial.println();
            flex2.add(flexR2);
  
            int flexADC3 = analogRead(FLEX_PIN3);
            double flexV3 = flexADC3 * VCC / 1023.0;
            double flexR3 = R_DIV * (VCC / flexV3 - 1.0);
            Serial.println("Resistance3: " + String(flexR3) + " ohms");
            Serial.println();
            flex3.add(flexR3);
  
            int flexADC4 = analogRead(FLEX_PIN4);
            double flexV4 = flexADC4 * VCC / 1023.0;
            double flexR4 = R_DIV * (VCC / flexV4 - 1.0);
            Serial.println("Resistance4: " + String(flexR4) + " ohms");
            Serial.println();
            flex4.add(flexR4);

            delay(5000);
  }

  Serial.println("Learning");
  Serial.println("Please wait till the next instruction:");
  Serial.println("--------------------------------------");
  average1=flex1.get_avg();
  average2=flex2.get_avg();
  average3=flex3.get_avg();
  average4=flex4.get_avg();
  flex_values_learn[i][0]=average1;
  flex_values_learn[i][1]=average2;
  flex_values_learn[i][2]=average3;
  flex_values_learn[i][3]=average4;
}
}
            
