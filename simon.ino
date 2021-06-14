void setup() {
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 randomSeed(236);
 pinMode(8, INPUT);
 pinMode(9, INPUT);
 pinMode(10, INPUT);
 pinMode(11, INPUT);
 pinMode(13,OUTPUT);
}

int button_push(void)
{
  int val = 0;

  while (val == 0) {
    if (digitalRead(8)== HIGH) {
      val= 2;
    }
    if (digitalRead(9)== HIGH) {
      val = 3;
    }
    if (digitalRead(10)== HIGH) {
      val = 4;
    }
    if (digitalRead(11)== HIGH) {
      val = 5;
    }
  }
  digitalWrite(val, HIGH);
  tone(13, val * 150, 200);
  delay(500);
  digitalWrite(val, LOW);
  return (val);
}

int rand_led(int nb)
{
  int order[nb + 1];

  for (int i = 0; i <= nb; i += 1) {
    order[i] = random(2,6);
    tone(13, order[i] * 150,200);
    digitalWrite(order[i], HIGH);
    delay(500);
    digitalWrite(order[i], LOW);
    delay(200);
  }
  for (int i = 0; i <= nb; i += 1) {
    if (order[i] != button_push()) {
      return (1);
    }
  }
  return (0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int re = 0;
  for (int i = 0; re == 0; i += 1) {
    delay(500);
    re = rand_led(i);
  }
  tone(13,250,500);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
