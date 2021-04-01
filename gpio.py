import RPi.GPIO as GPIO
import time

GPIO_pins = (21, 20, 16, 12, 7, 8, 25, 24)

def DecToBinList(number):
    return list(map(int, bin(number)[2:].zfill(8)))

def lightUp(ledNumber, period):
    GPIO.output(ledNumber, 1)
    time.sleep(period)
    GPIO.output(ledNumber, 0)

def blink(ledNumber, blinkCount, blinkPeriod):
    for counter in range(blinkCount):
        lightUp(ledNumber, blinkPeriod)
        time.sleep(blinkPeriod)

def runningLight(count, period):
    global GPIO_pins
    while count:
        count -=1
        for idx in range(0,8,1):
            lightUp(GPIO_pins[idx], period)

def runningDark(count, period):
    global GPIO_pins
    GPIO.output(GPIO_pins, 1)
    while count:
        count -=1
        for idx in range(0,8,1):
            GPIO.output(GPIO_pins[idx], 0)
            time.sleep(period)
            GPIO.output(GPIO_pins[idx], 1)


def lightNumber(number):
    global GPIO_pins
    binNumberList = DecToBinList(number)
    for idx in range(8):
        GPIO.output(GPIO_pins[idx], binNumberList[idx])

def bitShift(number, direction):
    left = 1
    right = 0
    return (number * 2 + number // 128) % 256 if direction == left else (number // 2 + ((number % 2) << 7))

def runningPattern(pattern, direction):
    global GPIO_pins
    
    for idx in range(0, 8, 1):
        lightNumber(pattern)
        pattern = bitShift(pattern, direction)
        time.sleep(0.5)

def gradBright(pin, delay):
    delay = delay / 100
    p = GPIO.PWM(pin, 50)
    p.start(0)
    for i in list(range(100)) + list(range(99, -1, -1)):
        p.ChangeDutyCycle(i)
        time.sleep(delay)
    p.stop()

GPIO.setmode(GPIO.BCM)

GPIO.setup(GPIO_pins, GPIO.OUT)

runningLight(2, 0.2)
lightNumber(255)
time.sleep(1)

runningDark(2, 0.2)
lightNumber(255)
time.sleep(1)

lightNumber(0b11000101)
time.sleep(1)
lightNumber(255)
time.sleep(1)

runningPattern(0b11000101, 1)
lightNumber(255)
time.sleep(1)

runningPattern(0b11000101, 0)
lightNumber(255)
time.sleep(1)

lightNumber(0)
gradBright(21, 5)

GPIO.cleanup()


print ("Input number")

num = input()

while num != -1:
    num2dac (num)
    print ("Input number")
    num = input()
