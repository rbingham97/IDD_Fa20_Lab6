
# GreetingBot

In this lab, we will use a Raspberry Pi to create a GreetingBot! 

## Introducing the **Raspberry Pi**

### Preparing your Raspberry Pi

Done! Took some re-editing of the config file, but the Pi is connected to the internet. 

## Connect to your Interaction Engine

**Record the IP address and the MAC address for the RPi.** 

Done! I won't put the actual addresses here for security reasons, but they're somewhere ;) . 

### 1. Verify the Pi is online

Done! Terminal access granted [#hackerman](https://twitter.com/hashtag/hackerman?lang=en). 

### 2.  SSH into the Pi.

Done, and password changed!

## Explore the RPi

### Enable X Windows

Working! Nice and convenient.

**Look in the RPi image and see where things are at. In specific, see if you can find:**

``The Arduino sketchbook`` -> In Home > Programming > Arduino

``Banana.jpg`` -> Can't find this :(

``Wormy.py`` -> This is the last file in home > pi > python_games

### Try some Python code on the Pi

We will be using Python in future modules, so try running some of the sample python code in ``python_games``:

``wormy.py`` -> Got to mid 30s in Snake!

``catanimation.py`` -> Cool bouncing cat :)

``tetromino.py`` -> Got a few lines going in Tetris, but honestly a shameful performance :(

Take a look at the code in the python file, using ``cat``, or ``nano``. (Used nano)

**How do you know what the shell script is doing?**

The shell scripts are all quite simple, and they contain a simple string that is the speech output. 

**Adapt the scripts so that they say what you want them to say.**

My Pi is now telling me that its name is Inigo Montoya and I should prepare to die... Yikes! 

**How do we use ``vosk`` to recognize words and phrases?**

We open a .wav file then feed it to a Kaldi recognizer in chunks until the whole file has passed through, then print a final result of what was said. 


**Include the output of vosk recognizing phrases you taught it to look for.**

Here is the final stub of output from vosk trying to recognize from the following list: "hello good morning my friend". Vosk is very unreliable, particularly with this mic, but I was able to get it to recognize most of the words. 

```shell
{
  "partial" : "good morning my"
}
{
  "partial" : "good morning my"
}
{
  "partial" : "good morning my"
}
{
  "partial" : "good morning my"
}
{
  "partial" : "good morning my"
}
{
  "partial" : "good morning my"
}
final result: good morning my
```

**Include the listing for a shell script and model files that you use to get vosk to recognize these phrases.**

I don't really understand what this is asking for. I'm using the vosk_demo_mic.sh script to run the code inside test_words.py. I'm using the existing model in /model within the speechtotext/ directory, and guiding it to the right words by changing the word list in the kaldiRecognizer() constructor. 

### Experimenting with Linux processes

Done, following the instructions!! Very cool stuff didn't know how to interact with processes that directly before. 

## Connect the Arduino and the RPi

I flashed Blink, which works, then flashed AnalogInOutSerial which reads a potentiometer, prints the value to serial, and outputs a voltage for LED control based on the sensor value. I set up a circuit to control two LEDs with the input value. See video of this [here](https://youtu.be/7bkHWh7kckQ).

### Hello Pi, Hello Arduino

**What would you change to make sayHelloPi say something else?**

Changing the value of the 'data' string at the top of helloPi.ino changes the message that gets sent. I changed mine to say "Hello, Russell!" and running helloPi.py prints this repeatedly to the Pi terminal. 

**How could you make it so that the Pi would only say something if the lights came on in the room?**

Adding an 'if' block to the loop of helloPi.ino that only prints data to Serial if the value of an analog pin is above a threshold would accomplish this. 

**How could you make it so that the Pi would say different things based on different sensor values read by the Arduino?**

Adding 'else if' blocks to the above solution that split up the analog sensor range into different reaction types would accomplish this. 

**Next, try out ``HelloArduino``. First have ``HelloArduino.ino`` listen for messages from ``HelloArduino.py``. Next, use ``morse_code_translator.ino``. What happens differently? **

The base HelloArduino.py file just blinks the LED on the Arduino when it gets any message at all from the Pi. The Morse Code file translates the input into Morse Code and flashes the onboard LED with the correct timing to indicate what the input was. 

**Change the ``HelloArduino.py`` program to take in inputs from the user to have them translated to morse code on the Arduino.**

Done! The program now takes in input from the user, converts it to a sequence of bytes, then sends those bytes via serial to be translated. 

## Your own voice agent 

**Program a simple application that understands different basic greetings (for example, Yo!, Good morning! And Good afternoon!) and responds either visibly, physically or auditorially in kind!**

I programmed the Pi to listen for the words "hello good morning my friend" with the hope of Vosk being able to recognize that phrase. In practice, either Vosk or the microphone I'm using is so unstable that I rarely get it to recognize more than one of those words if I say the whole sentence. Even so, I send the output of the recognizer to the Arduino over serial, and the Arduino responds by saying "Good Morning!", then "You said: ", then the message it received as the Vosk output over serial. The Arduino's response is displayed using the small OLED from Lab 1. 

**Record someone trying out your design**

I live alone and for COVID reasons didn't want to invite someone to my apartment just to talk at my Pi, so [here](https://youtu.be/RFFvTFDf74M) and [here](https://youtu.be/bkqiry1crMg) are two videos of me demonstrating that the device works. 

**Submit your code to Github**

My code is in the Github repo with this Readme. The Pi file is wordsToScreen.py, and the Arduino sketch is messageToScreen.ino. The other modified files from other lab parts retain their original names. 



