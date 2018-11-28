--baza.sql
DROP TABLE IF EXISTS miasta;
DROP TABLE IF EXISTS dane_demograficzne;
DROP TABLE IF EXISTS powierzchnie;
CREATE TABLE miasta(
      id_miasta INTEGER PRIMARY KEY AUTOINCREMENT,
      nazwa_miasta TEXT(30),
      wojewodztwo TEXT(30)
  );
CREATE TABLE dane_demigraficzne(
      id INTEGER,
      liczba_mieszkancow INTEGER,
      liczba_kobiet INTEGER,
      grupa_wiekowa TEXT(15),
      data_aktualizacji DATE,
      id_miasta INTEGER,
      FOREIGN KEY (id_miasta) REFERENCES miasta(id_miasta)
   ); 
CREATE TABLE powierzchnie(
    id INTEGER,
    powierzchnia DECIMAL,
    powierzchnie_zielone DECIMAL,
    data_aktualizacji DATE,
    id_miasta INTEGER,
    FOREIGN KEY (id_miasta) REFERENCES miasta(id_miasta)
    );
INSERT INTO miasta VALUES(NULL, 'Warszawa', 'Mazowieckie'):
-- sqlite3 baza.db < bazagus.sql
-- sqlite3 
