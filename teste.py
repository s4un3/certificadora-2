from receptor import getMedida, Medida
from serial import Serial

port: str = "/dev/ttyUSB0"

serial = Serial(port, 9600, timeout=1)

while True:
    print(getMedida(serial))
