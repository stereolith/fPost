#include "clui.h"


string logo[7] =
{
    "   ______           __ ",
    "  / _/ _ \\___  ___ / /_",
    " / _/ ___/ _ \\(_-</ __/",
    "/_//_/   \\___/___/\\__/ ",
    "",
    "Getr\204nkeversand-Management",
    ""
};
string optionenHaupt[4] = {
    "Daten einlesen",
    "Daten konvertieren",
    "Daten durchsuchen",
    "Beenden"
};
string optionenLesen[2] = {
    "Artikelliste einlesen",
    "Auftragsliste einlesen"
};

void druckeOptionen(string optionen[], int anz);

clUI::clUI()
{
    breite = 50;
    hoehe = 20;
    inventar = NULL;
    artikel = NULL;
    auftrag = NULL;
}
void clUI::mainMenu()
{
    bool exit = false;
    while(!exit)
    {
        //Logo
        for (int i = 0; i < breite; i++) cout << "-";
        for (int i = 0; i < 7; i++) cout << endl << logo[i];
        cout << endl;

        //Menu-Optionen
        druckeOptionen(optionenHaupt, 4);
        for (int i = 0; i < breite; i++) cout << "-";
        cout << endl;

        //Menuauswahl
        char auswahl;
        cin >> auswahl;
        switch(auswahl)
        {
        case'1':
            druckeOptionen(optionenLesen,2);
            cin >> auswahl;
            switch(auswahl)
            {
                case'1':
                {
                    if(artikel != NULL)
                    {
                        cout << "Es wurde bereits eine Artikelliste eingelesen. M\224chten Sie die Daten \201berschreiben? (j/n)" << endl;
                        char antwort[1];
                        cin >> antwort;
                        if (strcmp(antwort,"j") == 0) {
                            artikel = NULL;
                        } else if (strcmp(antwort,"n") == 0) {
                            break;
                        }
                    }
                    ClToken *token = leseDaten();
                    artikel = new Artikel();
                    artikel->fill(token);
                    break;
                }
                case'2':
                {
                    if(auftrag != NULL)
                    {
                        cout << "Es wurde bereits eine Auftragsliste eingelesen. M\224chten Sie die Daten \201berschreiben? (j/n)" << endl;
                        char antwort[1];
                        cin >> antwort;
                        if (strcmp(antwort,"j") == 0) {
                            auftrag = NULL;
                        } else if (strcmp(antwort,"n") == 0) {
                            break;
                        }
                    }
                    ClToken *token = leseDaten();
                    auftrag = new Auftrag();
                    auftrag->fill(token);
                    //cout << "lieferzeit von index 2: " << auftrag->getLieferZeit() << endl;
                    break;
                }
                default:
                    break;
            }
            break;
        case'2':
            if(artikel == NULL) cout << "Es wurde noch keine Artikelliste eingelesen." << endl;
            if(auftrag == NULL) cout << "Es wurde noch keine Auftragsliste eingelesen." << endl;
            if(artikel !=NULL && auftrag != NULL)
            {
                konvertieren();
            }
            break;
        case'3':
            break;
        case'4':
            exit = true;
            break;
        default:
            cout << "Bitte wählen Sie eine Option aus." << endl;
            break;
        }
    }

}

ClToken *clUI::leseDaten()
{
    //Schriftfarben:
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ClElement *wurzel = NULL;
    ClToken *token = NULL;

    char dateiname[100];
    ifstream eingabe;
    wurzel = new ClElement();

    cout << "DTD-Dateiname:" << endl;
    cin >> dateiname;
    eingabe.open(dateiname);
    if(!eingabe.is_open()) {
        cout << "Datei nicht gefunden." << endl;
        mainMenu();
        return NULL;
    }
    wurzel=wurzel->verarbeite(eingabe);
    cout << "DTD geladen." << endl;
    eingabe.close();

    cout << "XML-Dateiname:" << endl;
    cin >> dateiname;
    eingabe.open(dateiname);

    token=new ClToken;

    if (token->getToken(eingabe,NULL,wurzel)!=0)
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout << "XML erfolgreich geladen und validiert." << endl;
        SetConsoleTextAttribute(hConsole, 15);
    } else {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Beim Validieren traten Fehler auf." << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    eingabe.close();
    return token;
}

void clUI::konvertieren()
{
    inventar = new ArtikelInventar();
    inventar->kopiere(artikel);
    inventar->verarbeite(auftrag);
    cout << "Daten konvertiert." << endl;

    char dateiname[50];
    cout << "Bitte geben Sie einen Dateinamen f\201r die Ausgabgsdatei ein: ";
    cin >> dateiname;
    ofstream datei(dateiname);
    if (datei.is_open())
    {
        inventar->speichern(datei);
        datei.close();
    }
}

void druckeOptionen(string optionen[], int anz){
    for (int i = 0; i < anz; i++){
        cout << "    (" << i+1 << ") " << optionen[i] << endl;
    }
}