from receptor import getMedida, Medida
from serial import Serial

port: str = "/dev/ttyUSB0"  # mudar de acordo com a porta que o arduino está conectado

serial = Serial(port, 9600, timeout=1)  # instanciar o serial

while True:
    print(getMedida(serial))  # apenas printa as medidas
