def calcola_frequenze(file_path, mu):
    # Calcola le soglie
    soglia_2mu = 2 * mu
    soglia_3mu = 3 * mu

    # Inizializza i contatori
    count_2mu = 0
    count_3mu = 0

    # Leggi il file e conta le occorrenze
    with open(file_path, 'r') as file:
        for linea in file:
            try:
                scambi = float(linea.strip())  # Leggi e converti il numero di scambi
                if scambi > soglia_2mu:
                    count_2mu += 1
                if scambi > soglia_3mu:
                    count_3mu += 1
            except ValueError:
                print(f"Valore non valido trovato nella riga: {linea}")

    # Calcola le frequenze empiriche
    totale_iterazioni = 100000  # Modifica se il numero di iterazioni è diverso
    frequenza_2mu = count_2mu / totale_iterazioni
    frequenza_3mu = count_3mu / totale_iterazioni

    return frequenza_2mu, frequenza_3mu

# Esempio di utilizzo
file_path = "./results.txt"  # Modifica con il percorso del tuo file
mu = 155766  # Valore medio atteso
frequenza_2mu, frequenza_3mu = calcola_frequenze(file_path, mu)

print(f"Frequenza empirica per soglia 2μ: {frequenza_2mu:.6f}")
print(f"Frequenza empirica per soglia 3μ: {frequenza_3mu:.6f}")
