##----- Importation des modules ------##
from numpy import *
import random
"""
Tri selection permet de trier ces heures de décollage dans un tab
"""
def indice_du_mini_a_partir_de(tab: [int], i : int):
    """
    """
    i_mini = i 
    while i < len(tab):
        if tab[i] < tab[i_mini]:
            i_mini = i
        i = i + 1
    return i_mini

def tri_selection(tab : [int]):
    """
    """
    i = 0
    while i < len(tab) - 1:
        i_mini = indice_du_mini_a_partir_de(tab, i)
        temp = tab[i]
        tab[i] = tab[i_mini]
        tab[i_mini] = temp
        i = i + 1
    return tab

def inserer(tab : [int], i : int):
    """
    """
    val = tab[i]
    while i > 0 and tab[i] < tab[i - 1]:
        tab[i] = tab[i - 1]
        tab[i - 1] = val
        i = i - 1
    return tab

def tri_Insertion(tab : [int]):
    """
    """
    i = 1
    while i < len(tab):
        tab = inserer(tab, i)
        i = i + 1
    return tab

def gen_tab(n : int):
    i = 0
    s = zeros(n)
    while i < n:
        s[i] = random.randint(600,2200)
        i = i + 1
    return s

def tab_heure(n : int):
    i = 0 
    j = 0
    k = 0
    m = n
    tab = gen_tab(n)
    while i < n:
        if (tab[i] % 100) > 60:
            m = m - 1
        i = i + 1
    new_tab = zeros(m)
    while j < n:
        if(tab[j]% 100) < 60:
            new_tab[k] = tab[j]
            k = k + 1
        j = j + 1
    return new_tab 


print(tri_Insertion(tab_heure(10)))
print(tri_selection(tab_heure(10))) 

def permuter_jusqua(tab : [int], i : int):
    """
    """
    j = 0 
    while j < i:
        if tab[j] > tab[j + 1]:
            temp = tab[j] 
            tab[j] = tab[j + 1]
            tab[j + 1] = temp
        i = i - 1
    return tab

def tri_a_bulles(tab : [float]):
    """
    """
    i = len(tab) - 1
    while i > 0:
        tab = permuter_jusqua(tab, i)
        i = i - 1
    return tab


def est_minuscule(c: str):
    """
    """
    fina = False
    if 97 <= ord(c) <= 122:
        fina = True
    return fina


def nb_minuscules(txt : str) -> (int):
    """
    """
    compt = 0
    i = 0
    while i < len(txt):
        if 97 <= ord(txt[i]) <= 122:
            compt = compt + 1
        i = i + 1
    return compt
    """
    compt = 0
    i = 0
    while i < len(txt):
        if est_minuscule(txt[i]):
            compt = compt + 1
        i = i + 1
    return compt
    """

def respect_case(txt: str):
    """
    """
    i = 0
    nv = ""
    while i < len(txt):
        if est_minuscule(txt[i]):
            nv = nv + ord(txt[i] - 32)
        i = i + 1
    return nv

# 97 a 122 les minuscules, de 65 à 90 les MAJUSCULES donc la difference est 32
# Pour les chiffres c'est de 48 a 57

def decim_to_str(s : int) ->(str):
    """
    """
    txt = 0
    i = 0
    while i // 10 != 0:
        txt = txt + chr(ord(s[i]))
        i = i // 10
    return txt


def bien_p(txt : str) :
    """
    """
    i = 0
    compt = 0
    val = True
    while i < len(txt):
        if txt[i] == '(':
            compt = compt + 1
        if txt[i] == ')':
            compt = compt - 1
        i = i + 1
    if compt != 0:
        val = False
    return val


def rech_dichtomie(tab : [int], valeur : int) -> (bool):
    """
    """
    i_d = 0
    i_f = len(tab) - 1
    trouve = False
    while i_d <= i_f and not trouve:
        i_m = (i_d + i_f) // 2
        if tab[i_m] == valeur:
            trouve = True
        else:
            if tab[i_m] > valeur:
                i_f = i_m - 1
            else :
                i_d = i_m + 1
    return trouve

def permuter_jusqua(tab : [int], i : int):
    """
    """
    j = 0
    while j < i:
        temp = tab[j]
        tab[j] = tab[j + 1]
        tab[j + 1] = temp
        j = j + 1   
    return tab

def tri_a_bulles(tab : [float]):
    """
    """
    i = len(tab) - 1
    while i > 0:
        tab = permuter_jusqua(tab, i)
        i = i - 1
    return tab


tri_selection , indice_du_mini_a_partir_de
tri_Insertion, inserer
tri_a_bulles, permuter_jusqua