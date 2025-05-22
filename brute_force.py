import os
import time
import numpy as np
import pandas as pd

def subset_sum(set_, target, n=None):
    if n is None:
        n = len(set_)
    if target == 0:
        return True
    if n == 0:
        return False
    if set_[n - 1] > target:
        return subset_sum(set_, target, n - 1)
    return subset_sum(set_, target, n - 1) or subset_sum(set_, target - set_[n - 1], n - 1)

def medir_tempo_execucao(set_, target, rep=30):
    tempos = []
    for _ in range(rep):
        inicio = time.perf_counter()
        subset_sum(set_, target)
        fim = time.perf_counter()
        tempos.append(fim - inicio)
    return {
        "tempo_medio_s": np.mean(tempos),
        "desvio_padrao_s": np.std(tempos)
    }

entrada_pequena = list(range(1, 19))   

alvo_pequeno = sum(entrada_pequena) // 2

entrada_media = list(range(1, 26))        
alvo_medio = sum(entrada_media) // 2

entrada_grande = list(range(1, 34))        
alvo_grande = sum(entrada_grande) // 2

resultado_pequeno = medir_tempo_execucao(entrada_pequena, alvo_pequeno)
resultado_medio = medir_tempo_execucao(entrada_media, alvo_medio)
resultado_grande = medir_tempo_execucao(entrada_grande, alvo_grande)

df_tempos_ajustado = pd.DataFrame([
    {"categoria": "Pequena (n=18)", **resultado_pequeno},
    {"categoria": "Media (n=25)", **resultado_medio},
    {"categoria": "Grande (n=33)", **resultado_grande}
])

df_tempos_ajustado["categoria"] = [
    "Pequena (n=18)",
    "Média (n=25)",
    "Grande (n=33)"
]

os.makedirs("data", exist_ok=True)

caminho_arquivo = "data/results_py.txt"

mean_p = df_tempos_ajustado.loc[0, "tempo_medio_s"]
std_p = df_tempos_ajustado.loc[0, "desvio_padrao_s"]
mean_m = df_tempos_ajustado.loc[1, "tempo_medio_s"]
std_m = df_tempos_ajustado.loc[1, "desvio_padrao_s"]
mean_g = df_tempos_ajustado.loc[2, "tempo_medio_s"]
std_g = df_tempos_ajustado.loc[2, "desvio_padrao_s"]

conteudo_formatado = (
    f"mean-p={mean_p:.6f}\n"
    f"mean-m={mean_m:.6f}\n"
    f"mean-g={mean_g:.6f}\n"
    f"std-p={std_p:.6f}\n"
    f"std-m={std_m:.6f}\n"
    f"std-g={std_g:.6f}\n"
)

with open("data/results_py.txt", "w") as f:
    f.write(conteudo_formatado)


