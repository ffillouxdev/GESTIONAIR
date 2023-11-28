"""
A partir d'un fichier .csv, cet algo est un tri par sélection 

Numero de vol,     Compagnie,       Destination,    Numero comptoir,       Heure debut enregistrement,        Heure fin enregistrement,          Salle dembarquement,        Heure debut embarquement,      Heure fin embarquement,          Heure decollage,        Etat vol,            Liste des passagers
    1        ,     Lufthansa,       Paris,                10,                         1134,                             1158,                             1,                           1220,                        1250,                           1319,            Retarde (6 min),     "NOM44,Prenom44,11/12/1979,1,888.85;NOM70,Prenom70,06/10/1971,1,234.27;NOM4,Prenom4,10/07/1963,10,690.55;NOM11,Prenom11,19/02/2013,4,455.99;NOM12,Prenom12,25/04/1992,2,733.64"
"""

import csv

#recupere les durees d'heure de decollage
def generationSelectHD():
    with open('data_vols.csv', newline='') as csvfile:
        csvreader = csv.DictReader(csvfile, delimiter=',')

        # mettre les valeurs de la colonne 'Heure decollage' dans un tableau
        next(csvreader, None)  # skip header
        heure_decollage_values = []

        row = next(csvreader, None)
        while row != None:
            numero_vol = int(row['Numero de vol'])
            heure_decollage = int (row['Heure decollage'])
            if 600 <= heure_decollage <= 2200:
                heure_decollage_values.append((numero_vol, heure_decollage))
            row = next(csvreader, None)
        
    return heure_decollage_values

print("Version non trié :\n ",generationSelectHD())


"""
Tri selection permet de trier ces heures de décollage dans un tab
"""
def indice_du_mini_a_partir_de(tab: [int], i : int):
    """
    """
    i_mini = i
    while i < len(tab):
        if tab[i][1] < tab[i_mini][1]:
            i_mini = i
        i = i + 1
    return i_mini

def tri_Insertion(tab : [int]):
    i = 0
    while i < len(tab) - 1:
        i_mini = indice_du_mini_a_partir_de(tab, i)
        temp = tab[i]
        tab[i] = tab[i_mini]
        tab[i_mini] = temp
        i = i + 1
    return tab

print("Version trié \n",tri_Insertion(generationSelectHD()))

#et si le vol est au dessus de 2200, il est annulé?
#et si le vol est au dessous de 600, il est annulé?
