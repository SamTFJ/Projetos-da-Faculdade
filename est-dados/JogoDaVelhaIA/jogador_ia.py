# -*- coding: utf-8 -*-
from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)
            

    def getJogada(self) -> (int, int):
        lista = []
        for l in range(0,3):
            for c in range(0,3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))

        #Regra 1: Complete ou bloqueie uma sequência
        for l in range(3):
            #Completar ou bloquear linha
            if self.matriz[l].count(1) == 2 and self.matriz[l].count(Tabuleiro.DESCONHECIDO) == 1:
                c = self.matriz[l].index(Tabuleiro.DESCONHECIDO)
                return (l, c)
            if self.matriz[l].count(4) == 2 and self.matriz[l].count(Tabuleiro.DESCONHECIDO) == 1:
                c = self.matriz[l].index(Tabuleiro.DESCONHECIDO)
                return (l, c)

        for c in range(3):
            #Completar ou bloquear coluna
            coluna = [self.matriz[l][c] for l in range(3)]
            if coluna.count(1) == 2 and coluna.count(Tabuleiro.DESCONHECIDO) == 1:
                l = coluna.index(Tabuleiro.DESCONHECIDO)
                return (l, c)
            if coluna.count(4) == 2 and coluna.count(Tabuleiro.DESCONHECIDO) == 1:
                l = coluna.index(Tabuleiro.DESCONHECIDO)
                return (l, c)

        #Completar ou bloquear diagonal principal
        diagonal1 = [self.matriz[i][i] for i in range(3)]
        if diagonal1.count(1) == 2 and diagonal1.count(Tabuleiro.DESCONHECIDO) == 1:
            i = diagonal1.index(Tabuleiro.DESCONHECIDO)
            return (i, i)
        if diagonal1.count(4) == 2 and diagonal1.count(Tabuleiro.DESCONHECIDO) == 1:
            i = diagonal1.index(Tabuleiro.DESCONHECIDO)
            return (i, i)

        #Completar ou bloquear diagonal secundária
        diagonal2 = [self.matriz[i][2 - i] for i in range(3)]
        if diagonal2.count(1) == 2 and diagonal2.count(Tabuleiro.DESCONHECIDO) == 1:
            i = diagonal2.index(Tabuleiro.DESCONHECIDO)
            return (i, 2 - i)
        if diagonal2.count(4) == 2 and diagonal2.count(Tabuleiro.DESCONHECIDO) == 1:
            i = diagonal2.index(Tabuleiro.DESCONHECIDO)
            return (i, 2 - i)

        #Regra 2
        for l, c in lista:
            self.matriz[l][c] = 1 
            #Conta quantas linhas, colunas e diagonais têm duas marcas e um vazio
            duas_linhas = 0
            for linha in range(3):
                if self.matriz[linha].count(1) == 2 and self.matriz[linha].count(Tabuleiro.DESCONHECIDO) == 1:
                    duas_linhas += 1
            for coluna in range(3):
                col = [self.matriz[linha][coluna] for linha in range(3)]
                if col.count(1) == 2 and col.count(Tabuleiro.DESCONHECIDO) == 1:
                    duas_linhas += 1
            diag1 = [self.matriz[i][i] for i in range(3)]
            diag2 = [self.matriz[i][2 - i] for i in range(3)]
            if diag1.count(1) == 2 and diag1.count(Tabuleiro.DESCONHECIDO) == 1:
                duas_linhas += 1
            if diag2.count(1) == 2 and diag2.count(Tabuleiro.DESCONHECIDO) == 1:
                duas_linhas += 1
            self.matriz[l][c] = Tabuleiro.DESCONHECIDO
            if duas_linhas >= 2:
                return (l, c)

        #Regra 3
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            return (1, 1)

        #Regra 4
        for (l, c) in [(0, 0), (0, 2), (2, 0), (2, 2)]:
            if self.matriz[l][c] == 4:
                oposto = (2 - l, 2 - c)
                if self.matriz[oposto[0]][oposto[1]] == Tabuleiro.DESCONHECIDO:
                    return oposto

        #Regra 5
        for (l, c) in [(0, 0), (0, 2), (2, 0), (2, 2)]:
            if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                return (l, c)

  
        if(len(lista) > 0):
            p = randint(0, len(lista)-1)
            return lista[p]
        else:
           return None