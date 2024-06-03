def calcular_pontos(resultado):
    vitorias, empates, _ = resultado
    return vitorias * 3 + empates

def ler_arquivo(nome_arquivo):
    with open(nome_arquivo, 'r', encoding='utf-8') as arquivo:  
        linhas = arquivo.readlines()[1:] 
        dados = []
        for linha in linhas:
            dados_time = linha.strip().split(';')
            time = dados_time[0]
            jogos, vitorias, empates, _, saldo = map(int, dados_time[1:])
            pontos = calcular_pontos((vitorias, empates, 0))
            dados.append((time, pontos, saldo))
        return dados

if __name__ == "__main__":
    arquivo = "times.csv"
    dados_times = ler_arquivo(arquivo)

    # Ordena os times por pontos e saldo de gols
    dados_times.sort(key=lambda x: (x[1], x[2]), reverse=True)

    # Imprime a classificação com caracteres acentuados
    print("Posição | Time       | Pontos | Saldo de gols")
    for i, (time, pontos, saldo) in enumerate(dados_times, start=1):
        print(f"{i:^7} | {time:<10} | {pontos:^6} | {saldo:^13}")
