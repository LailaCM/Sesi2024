def ler_arquivo(nome_arquivo):
    with open(nome_arquivo, 'r', encoding='utf-8') as arquivo:
        linhas = arquivo.readlines()
        total_votos = sum(int(linha.strip().split(',')[1]) for linha in linhas)
        resultados = []
        for linha in linhas:
            candidato, votos = linha.strip().split(',')
            votos = int(votos)
            percentual_votos = (votos / total_votos) * 100
            resultados.append((candidato, votos, percentual_votos))
        return resultados

if __name__ == "__main__":
    arquivo = "votos.csv"
    dados_votos = ler_arquivo(arquivo)

    # Ordena os candidatos por votos em ordem decrescente
    dados_votos.sort(key=lambda x: x[1], reverse=True)

    primeiro_colocado = dados_votos[0]
    segundo_colocado = dados_votos[1]

    print("Resultado das Eleições:")
    for candidato, votos, percentual in dados_votos:
        print(f"{candidato}: {percentual:.2f}% dos votos")

    if primeiro_colocado[2] > 50:
        print(f"\n{primeiro_colocado[0]} ganhou em primeiro turno com {primeiro_colocado[2]:.2f}% dos votos.")
    else:
        print(f"\nHaverá segundo turno entre {primeiro_colocado[0]} e {segundo_colocado[0]}.")
