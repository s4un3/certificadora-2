from serial import Serial
from dataclasses import dataclass
import json
from serial.serialutil import SerialException
from serial import Serial
import serial.tools.list_ports


@dataclass
# classe de dados que guarda as medidas
class Medida:
    DD: float = 0.0
    DE: float = 0.0
    TD: float = 0.0
    TE: float = 0.0


def conectar() -> Serial | None:
    # tenta conectar a uma porta
    s: Serial | None = None

    ports = [comport.device for comport in serial.tools.list_ports.comports()]
    for port in ports:
        try:
            s = Serial(port, 9600, timeout=1)
            break
        except SerialException:
            continue

    return s


TIMEOUT_SERIAL: bool = False


def getMedida(s: Serial) -> Medida | None:
    # lê do serial, dá parse como json e extrai os valores, retornando uma Medida
    # None é retornado caso:
    # Json contém algo além de DD, DE, TD, TE
    # Erro de decoding de unicode ou de decoding de json (para quando a medida começou a ser lida na posição errada)
    text = ""

    try:

        while True:
            line: str = s.readline().decode()
            text += line

            if not line:
                return None
            if line[0] == "}":
                break  # final do json

        m = Medida()
        obj = json.loads(text)

        for key in obj:
            match key:
                case "DD":
                    m.DD = float(obj[key])
                    continue
                case "DE":
                    m.DE = float(obj[key])
                    continue
                case "TD":
                    m.TD = float(obj[key])
                    continue
                case "TE":
                    m.TE = float(obj[key])
                    continue
                case _:
                    return None
        return m

    except (UnicodeDecodeError, json.decoder.JSONDecodeError):
        return None
