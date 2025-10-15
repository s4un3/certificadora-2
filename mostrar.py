import pygame
from serial.serialutil import SerialException
from receptor import getMedida, conectar, Serial, Medida
from sys import exit

LARGURA = 800
ALTURA = 450
COR_FUNDO = (25, 25, 25)
COR_TEXTO = (255, 255, 255)

ESCALA_CARRO = 0.8
ESCALA_FONTE = 3.5

pygame.init()

tela = pygame.display.set_mode((LARGURA, ALTURA))
pygame.display.set_caption("Pressão do fluido de freio das rodas")

# /100 para tornar o valor de ESCALA_FONTE mais "amigável" (sem ser algo do tipo 0.05)
tam_fonte = int(LARGURA / 100 * ESCALA_FONTE)

# preferência para courier por ser monoespaçada
fonte = pygame.font.SysFont(["courier", "Arial"], tam_fonte)
img_carro = pygame.image.load("carro.png").convert_alpha()
carro_altura = int(ALTURA * ESCALA_CARRO)
carro_largura = int(carro_altura * img_carro.get_width() / img_carro.get_height())
img_carro = pygame.transform.scale(img_carro, (carro_largura, carro_altura))
img_carro = pygame.transform.rotate(img_carro, 180)
rect_carro = img_carro.get_rect(center=(LARGURA // 2, ALTURA // 2))

s: Serial | None = None
medida: Medida | None = None

while True:
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            exit()

    tela.fill(COR_FUNDO)

    medida: Medida | None = None

    """
    if s is None:
        texto = fonte.render("Nenhuma porta detectada", False, COR_TEXTO)
        rect_texto = texto.get_rect(center=(LARGURA // 2, ALTURA // 2))
        tela.blit(texto, rect_texto)
        pygame.display.flip()

        s = conectar()
        if s is not None:
            tela.fill(COR_FUNDO)
            texto = fonte.render(f'Porta "{s.name}" conectada', False, COR_TEXTO)
            rect_texto = texto.get_rect(center=(LARGURA // 2, ALTURA // 2))
            tela.blit(texto, rect_texto)
            pygame.display.flip()
        continue
    try:
        medida = getMedida(s)
    except SerialException:
        s = None

    if medida is None:
        # surface para renderizar os dois textos
        surface = pygame.Surface((LARGURA, ALTURA), pygame.SRCALPHA)
        surface.fill((0, 0, 0, 0))

        texto1 = fonte.render("Medida inválida", False, COR_TEXTO)
        texto2 = fonte.render("Aguarde alguns segundos", False, COR_TEXTO)

        rect_texto1 = texto1.get_rect(centerx=LARGURA // 2, centery=ALTURA // 2 - 50)
        surface.blit(texto1, rect_texto1)

        rect_texto2 = texto2.get_rect(centerx=LARGURA // 2, top=rect_texto1.bottom + 20)
        surface.blit(texto2, rect_texto2)

        tela.blit(surface, (0, 0))
        pygame.display.flip()
        continue

    """

    medida = Medida(1250, 1250, 1250, 1250)

    tela.blit(img_carro, rect_carro)

    dd_texto = fonte.render(f"DD: {medida.DD: >8.2f} psi", False, COR_TEXTO)
    de_texto = fonte.render(f"DE: {medida.DE: >8.2f} psi", False, COR_TEXTO)
    td_texto = fonte.render(f"TD: {medida.TD: >8.2f} psi", False, COR_TEXTO)
    te_texto = fonte.render(f"TE: {medida.TE: >8.2f} psi", False, COR_TEXTO)

    dd_rect = dd_texto.get_rect(topleft=(rect_carro.right + 20, rect_carro.top))
    tela.blit(dd_texto, dd_rect)

    de_rect = de_texto.get_rect(topright=(rect_carro.left - 20, rect_carro.top))
    tela.blit(de_texto, de_rect)

    td_rect = td_texto.get_rect(bottomleft=(rect_carro.right + 20, rect_carro.bottom))
    tela.blit(td_texto, td_rect)

    te_rect = te_texto.get_rect(bottomright=(rect_carro.left - 20, rect_carro.bottom))
    tela.blit(te_texto, te_rect)

    pygame.display.flip()
