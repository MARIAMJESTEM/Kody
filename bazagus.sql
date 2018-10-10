--baza.sql
DROP TABLE miasta IF EXISTS
DROP TABLE dane_demograficzne IF EXISTS
DROP TABLE powierzchnie IF EXISTS 
CREATE TABLE miasta(
      id_miasta INTEGER PRIMARY KEY AUTOINCREMENT,
      nazwa_miasta TEXT(30),
      wojewodztwo TEXT(30)
  );
CREATE TABLE dane_demigraficzne(
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      liczba_mieszkancow INTEGER,
      liczba_kobiet INTEGER,
      grupa_wiekowa TEXT(15),
      data_aktualizacji DATE,
      id_miasta INTEGER,
      FOREIGN KEY (id_miasta) REFERENCES miasta(id_miasta)
   ); 
CREATE TABLE powierzchnie(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    powierzchnia DECIMAL,
    powierzchnie_zielone DECIMAL,
    data_aktualizacji DATE,
    id_miasta INTEGER,
    FOREIGN KEY (id_miasta) REFERENCES miasta(id_miasta)
    );
-- sqlite3 baza.db < bazagus.sql
-- sqlite3 
