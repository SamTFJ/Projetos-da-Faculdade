# -*- coding: utf-8 -*-

class Tabuleiro:
    DESCONHECIDO = 0
    JOGADOR_0 = 1
    JOGADOR_X = 4

    def __init__(self):
        self.matriz = [ [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO], 
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO],
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO]]
       
        
    def tem_campeao(self):
        l = 0
        c = 0

        #Checando as linhas
        for c in range(0,3): 
                if ((self.matriz[l][c] & self.matriz[l+1][c] & self.matriz[l+2][c])== Tabuleiro.JOGADOR_0):
                    return Tabuleiro.JOGADOR_0
                if ((self.matriz[l][c] & self.matriz[l+1][c] & self.matriz[l+2][c])== Tabuleiro.JOGADOR_X):
                    return Tabuleiro.JOGADOR_X
                
        l = 0
        c = 0

        #Checando as colunas        
        for l in range(0,3): 
                if ((self.matriz[l][c] & self.matriz[l][c+1] & self.matriz[l][c+2])== Tabuleiro.JOGADOR_0):
                    return Tabuleiro.JOGADOR_0
                if ((self.matriz[l][c] & self.matriz[l][c+1] & self.matriz[l][c+2])== Tabuleiro.JOGADOR_X):
                    return Tabuleiro.JOGADOR_X

        l = 0
        c = 0

        #Checando as diagonais
        if ((self.matriz[l][c] & self.matriz[l+1][c+1] & self.matriz[l+2][c+2])== Tabuleiro.JOGADOR_0):
            return Tabuleiro.JOGADOR_0  
        if ((self.matriz[l][c] & self.matriz[l+1][c+1] & self.matriz[l+2][c+2])== Tabuleiro.JOGADOR_X):
            return Tabuleiro.JOGADOR_X

        if ((self.matriz[l][c+2] & self.matriz[l+1][c+1] & self.matriz[l+2][c])== Tabuleiro.JOGADOR_0):
            return Tabuleiro.JOGADOR_0
        if ((self.matriz[l][c+2] & self.matriz[l+1][c+1] & self.matriz[l+2][c])== Tabuleiro.JOGADOR_X):
            return Tabuleiro.JOGADOR_X