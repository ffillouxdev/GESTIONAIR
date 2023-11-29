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