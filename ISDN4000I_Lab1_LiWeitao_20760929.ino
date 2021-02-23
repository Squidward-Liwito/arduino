int a[8];
int b[10];
int n = 0;
double sum0 = 0;
double sum = 0.0;
double sum2 = 0.0;
double sum3 = 0.0;
void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  for (int i = 0; i < 8; i++)
  {
    a[i] = 1024 - analogRead(i);    //Process the data
    sum0 = a[i] + sum0;     //Store the data
    sum = ((i + 1) * a[i] + sum);     //Weighted average of the sensor values (Step1)
  }
  if (sum0 < 60)      //Check whether there is a line
  {
    Serial.print("Nothing there!");
  }
  else
  {
    sum2 = sum / sum0;      //Weighted average of the sensor values (Step2)
    sum2 = map(sum2, 0.0, 8.0, 0.0 , 1000.0);     //Weighted average of the sensor values (Step3)
    n++;      
    if (n % 10 == 0)      //Get previous data
    {
      for (int i = 8; i > -1; i--)      //Update the previous data group
      {
        b[i] = b[i + 1];
      }
      b[9] = sum2;
      sum3 = 0;
      for (int i = 10; i > 0; i--)      //Use the average of the previous data group as a fliter
      {
        sum3 = sum3 + b[i - 1];
      }
      sum3 = sum3 / 10;
    }
    Serial.print(sum2);
    Serial.print(" ");
    Serial.print(sum3);
    Serial.print(" ");
    if (sum3 > 500)
      Serial.println("Turn right!");
    else if (sum3 == 500)
      Serial.println("Go straight!");
    else if (sum3 < 500)
      Serial.println("Turn left!");
  }
  Serial.println();
  sum = 0;
  sum0 = 0;
  delay(2);
}
