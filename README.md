# fPost
fPost – CLI für den Getränkeversand

## Dokumentation

fPost ist ein Managementsystem für einen Getränkeversand.
Daten in Form einer Artikelliste (xml) lassen sich mit einer Auftragsliste (xml) zu einer ArtikelInventar-Liste zusammenführen, 
die eine erweiterte Artikelliste mit aktualisiertem Inventar und weiteren Informationen ist. Die zusammengeführte Datei lässt sich
wiederum als xml-Dokument ausgeben.

### Menüführung:
 
#### (1) Daten einlesen

 - ermöglicht, die Artikel- und Auftragsliste einzulesen. Die Daten müssen mit den dazugehörigen DTD-Dateien im Build-Verzeichnis  (oder anderes angegebenes Hauptverzeichnis) liegen. Beispieldaten sind im Ordner "data" zu finden.
   Die Standard-Dateinamen der Beispieldaten sind:
	 - artikel.dtd
	 - artikel.xml
	 - auftraege.dtd
	 - auftraege.xml


#### (2) Daten konvertieren
 - 	führt beide eingelesenen Dateien zusammen und speichert diese in Form einer XML-Instanz unter einem beliebigen Dateinamen.


#### (3) Daten durchsuchen
 - erlaubt, die Daten nach Termen und Kategorien zu durchsuchen
	 1. Kategorie eingeben (z.B. name) 
	 2. Suchterm eingebn (z.B. Fanta)
	 3. ggf. neuen Suchterm hinzufügen mit Eingabe von "j", um Suche einzuschränken (z.B. "normalpreis": "10,99")
		---sonst mit "n" Suche bestätigen
	4. Die Ergebnisse werden in der Konsole ausgegeben. Die Ergebnisse können mit der Option (4) im Hauptmenü exportiert
		werden.

#### (4) Daten exportieren
	

 - (1) Gesamte InventarArtikel-Liste exportieren
		 - Gibt die Möglichkeit, die gesamten zusammengeführten Daten in einer Datei als XML-Instanz zu speichern
 - (2) Letzte Suchergebnisse exporteiren
		 - Gibt die Möglichkeit, die Liste der letzten Suchergebnisse in einer Datei als XML-Instanz zu speichern

#### (5) Statistiken

 - Zeigt einige Statistiken an, die aus den zusammengeführten Daten berechnet werden:
		 - Anzahl Kästen, Flaschen und das Gesamtvolumen im Inventar
		 - Verkaufte Kästen nach dem letzten Auftragsimport (Anzahl verkaufter Kästen in der importierten Auftragsdatei)
		 - Durchschnittliche Lieferzeit

Die Statistiken können auch in einer Ausgabedatei gespeichert werden.

#### (6) Beenden

 - Beendet das Programm

