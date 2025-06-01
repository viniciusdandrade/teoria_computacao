# Projeto de Análise do Problema Subset Sum

## Visão Geral
Este projeto analisa o desempenho do problema de subset sum implementado em C e Python utilizando a abordagem de força bruta. Ele compara os tempos de execução e eficiência usando vários tamanhos de entrada. Os resultados são visualizados por meio de gráficos e tabelas.

## Estrutura do Projeto
```
brute_force.c       # Implementação em C do problema subset sum
brute_force.py      # Implementação em Python do problema subset sum
graficos.ipynb      # Jupyter Notebook para visualização de dados
requirements.txt    # Dependências do Python
data/               # Diretório contendo os resultados
    results_c.txt   # Resultados da implementação em C
    results_py.txt  # Resultados da implementação em Python
```

## Requisitos
- Python 3.8 ou superior
- Compilador GCC para C
- Bibliotecas especificadas em `requirements.txt`

## Configuração
1. Instale as dependências do Python:
   ```bash
   pip install -r requirements.txt
   ```
2. Compile o programa em C:
   ```bash
   gcc brute_force.c -o brute_force
   ```

## Executando o Projeto
### Implementação em C
Execute o programa compilado:
```bash
./brute_force
```
Os resultados serão salvos em `output/results_c.txt`.

### Implementação em Python
Execute o script Python:
```bash
python brute_force.py
```
Os resultados serão salvos em `data/results_py.txt`.

### Visualização de Dados
Abra o Jupyter Notebook `graficos.ipynb` para visualizar os resultados:
```bash
jupyter notebook graficos.ipynb
```

## Resultados
Os resultados incluem:
- Tempos de execução para tamanhos de entrada pequenos, médios e grandes.
- Comparação de eficiência entre as implementações em C e Python.
- Gráficos ilustrando as diferenças de desempenho.

## Relatório
O relatório completo da análise pode ser acessado através do seguinte link:
[Relatório de Análise](https://docs.google.com/document/d/1Vg-jgMCgrI2I7dyJfvL5ffwwD3KPAZztNgBSpcMpJZA/)
