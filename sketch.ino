/*
 * ESP32 Simple Audio Player - this is the easiest combonition of both wsd and df player from github repos and yt, the audi switching and all isnt done yst will be doine iteratively or once i found resourde
 * * Basic functionalies:
 * - read and play sonf vis df player, neopixel-WS2812B LED ring (16 LEDs), rotatory encoders -control play pause prev next, potentomenter for brightness- havent done thiss yret

 * * This is a seasy version yet to add complex control lie wswitching withwot code is useless dont try this yrt. i need parts to test , also the switch patterns foe led not added uyet
 */

#include <SoftwareSerial.h> //sericl pins communicate
 #include <DFRobotDFPlayerMini.h>//dfplayer lib
  #include <FastLED.h>//neopixel rong control

// Pin definitions -esp 32 wroom devki pins
// u1 is esp, u5 df player ,WS2812B is no ides ,Rotary Encoder 1 u2,Potentiometer r1
#define DFPLAYER_RX 24  // ESP32 to df player daTA lines tx rx
#define DFPLAYER_TX 23
#define LED_PIN 16
#define NUM_LEDS 16
#define ENC_CLK 32
#define ENC_DT 33
#define BUTTON_PIN 21
#define VOLUME_PIN 34

// Global objects like led and data
SoftwareSerial mp3Serial(DFPLAYER_RX, DFPLAYER_TX);
DFRobotDFPlayerMini mp3;
CRGB leds[NUM_LEDS];

// State variables- initial
bool isPlaying = false; // when it tart ill have no sound
int currentSong = 1;
int totalSongs = 0;
int volume = 15;
int lastEncValue = 0;
bool buttonPressed = false;//button not pressed
unsigned long lastCheck = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Audio Player...");

  // Setup pin for encoders
  pinMode(ENC_CLK, INPUT_PULLUP);
  pinMode(ENC_DT, INPUT_PULLUP);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // the leds setp here
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  showStartup();

  // mp3 librsry
  mp3Serial.begin(9600);
  delay(2000); // Wait for DFPlayer to strt

  if (!mp3.begin(mp3Serial)) {
    Serial.println("DFPlayer failed!");
    showError();
    while(1);
  }

  Serial.println("DFPlayer ready!");
  mp3.volume(volume);

  // Get total music , plys 1st
  delay(200);
  totalSongs = mp3.readFileCounts();
  Serial.print("Found ");
  Serial.print(totalSongs);
  Serial.println(" songs");

  if (totalSongs > 0) {
    startPlaying();
  }

  lastEncValue = digitalRead(ENC_CLK);
}

void loop() {
  // Check inputs every 50ms to avoid bouncing
  if (millis() - lastCheck > 50) {
    checkEncoder();
    checkButton();
    checkVolume();
    lastCheck = millis();
  }

  updateLEDs();

  // Handle mP3 player messages
  if (mp3.available()) {
    handleMP3Messages();
  }
}

void checkEncoder() {
  int encValue = digitalRead(ENC_CLK);

  if (encValue != lastEncValue) {
      if (digitalRead(ENC_DT) != encValue) {
      // encoder next by turning
        nextSong();
    } else {
      // Counter-clockwise prev song
          previousSong();
    }
  }
  lastEncValue = encValue;
}

void checkButton() {
  if (digitalRead(BUTTON_PIN) == LOW && !buttonPressed) {
    togglePlayPause();
    buttonPressed = true;
  } else if (digitalRead(BUTTON_PIN) == HIGH) {
    buttonPressed = false;
  }
}

void checkVolume() {
  int potValue = analogRead(VOLUME_PIN);
  int newVolume = map(potValue, 0, 4095, 0, 30);

  if (abs(newVolume - volume) > 1) {
    volume = newVolume;
    mp3.volume(volume);
    Serial.print("Volume: ");
    Serial.println(volume);
    showVolume();
  }
}

void startPlaying() {
  mp3.play(currentSong);
  isPlaying = true;
  Serial.print("Playing song ");
  Serial.println(currentSong);
  showPlay();
}

void togglePlayPause() {
  if (isPlaying) {
    mp3.pause();
    isPlaying = false;
    Serial.println("Paused");
    showPause();
  } else {
    mp3.start();
    isPlaying = true;
    Serial.println("Playing");
    showPlay();
  }
}

void nextSong() {
  if (totalSongs > 0) {
    currentSong++;
    if (currentSong > totalSongs) currentSong = 1;

    mp3.play(currentSong);
    isPlaying = true;
    Serial.print("Next song: ");
    Serial.println(currentSong);
    showNext();
  }
}

void previousSong() {
  if (totalSongs > 0) {
    currentSong--;
    if (currentSong < 1) currentSong = totalSongs;

    mp3.play(currentSong);
    isPlaying = true;
    Serial.print("Previous song: ");
    Serial.println(currentSong);
    showPrev();
  }
}

void handleMP3Messages() {
  uint8_t type = mp3.readType();

  if (type == DFPlayerPlayFinished) {
    Serial.println("Song finished - playing next");
    nextSong();
  }
}

// LED Functions
void updateLEDs() {
  static unsigned long lastUpdate = 0;
  static int pos = 0;

  if (millis() - lastUpdate > 100) {
    if (isPlaying) {
      // Rotating dot when playing
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      leds[pos] = CRGB::Blue;
        leds[(pos + 8) % NUM_LEDS] = CRGB::Red; 
      pos = (pos + 1) % NUM_LEDS;
    } else {
      // Dim static when paus
      fill_solid(leds, NUM_LEDS, CRGB(20, 20, 20));
    }
   FastLED.show();
    lastUpdate = millis();
  }
}

void showStartup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(50);
  }
    delay(500);
}

void showPlay() {
  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
  delay(200);
}

void showPause() {
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(200);
}

void showNext() {
  for (int i = 0; i < NUM_LEDS; i++) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
     leds[i] = CRGB::Cyan; // Slightly inconsistent here
    FastLED.show();
    delay(30);
  }
}

void showPrev() {
  for (int i = NUM_LEDS-1; i >= 0; i--) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
     leds[i] = CRGB::Magenta;
    FastLED.show();
    delay(30);
  }
}
//shows vol
void showVolume() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  int volumeLEDs = map(volume, 0, 30, 0, NUM_LEDS);
  for (int i = 0; i < volumeLEDs; i++) {
    leds[i] = CRGB::Yellow;
  }
  FastLED.show();
  delay(300);
}
//[ronts error
void showError() {
  while(1) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(500);
  }
}
