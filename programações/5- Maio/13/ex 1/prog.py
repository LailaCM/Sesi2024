def tipo_triangulo(a, b, c):
    if a == b == c:
        return "Equilátero"
    elif a == b or a == c or b == c:
        return "Isósceles"
    else:
        return "Escaleno"

def ler_arquivo(nome_arquivo):
    with open(nome_arquivo, 'r', encoding='utf-8') as arquivo:
        linhas = arquivo.readlines()
        for linha in linhas:
            lados = list(map(int, linha.strip().split(';')))
            a, b, c = lados
            if a + b > c and a + c > b and b + c > a:
                tipo = tipo_triangulo(a, b, c)
                print(f"{a}, {b}, {c} - {tipo}")
            else:
                print(f"{a}, {b}, {c} - Não é um triângulo")

if __name__ == "__main__":
    arquivo = "triangulos.csv"
    ler_arquivo(arquivo)
