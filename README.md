Un file di testo contiene una matrice di interi con il seguente formato:
- la prima riga del file specifica le dimensioni reali della matrice (numero di righe nr e numero di colonne nc). Si assuma che entrambi i valori siano comunque al più pari a 20
- ciascuna delle nr righe successive contiene gli nc valori corrispondenti a una riga della matrice, separati da uno o più spazi.


Si scriva un programma C che:
- legga tale matrice dal file di ingresso
- generi una nuova matrice, in cui il valore di ciascun elemento è dato dalla media aritmetica delle (al più) 8 caselle adiacenti all’elemento corrispondente della matrice di ingresso
- scriva la matrice così ottenuta su un file di uscita, con lo stesso formato del file di ingresso.




      --Esempio--

      Sia il contenuto del file di ingresso il seguente:
      3 4
      1 2 3 4
      5 6 7 8
      9 10 11 12


      Il file di uscita scritto dal programma deve dunque avere il contenuto seguente:

      3 4
      4.3 4.4 5.4 6.0
      5.6 6.0 7.0 7.4
      7.0 7.6 8.6 8.7

      in cui il primo valore è ottenuto con il calcolo (2+5+6)/3, il secondo come (1+3+5+6+7)/5, etc.
