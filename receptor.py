from serial import Serial
from dataclasses import dataclass
import json


@dataclass
class Medida:
    DD: float
    DE: float
    TD: float
    TE: float

    def __init__(self):
        pass


def getMedida(s: Serial) -> Medida | None:
    text = ""

    try:

        while True:
            line: str = s.readline().decode()
            text += line

            if line[0] == "}":
                break

        m = Medida()
        obj = json.loads(text)

        for key in obj:
            m.__setattr__(key, obj[key])

        return m

    except (UnicodeDecodeError, json.decoder.JSONDecodeError):
        return None
