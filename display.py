import serial

port: str = ""
with serial.Serial(port, 9600, timeout=1) as serial:
    serial.readline()
