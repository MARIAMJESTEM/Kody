CREATE TABLE premia (
    id VARCHAR(20) PRIMARY KEY,
    premia NUMERIC
);

CREATE TABLE dzialy (
    id INTEGER PRIMARY KEY,
    nazwa VARCHAR(40),
    siedziba VARCHAR(40)
);

CREATE TABLE pracownicy (
    id VARCHAR(6) PRIMARY KEY,
    nazwisko VARCHAR(20),
    imie VARCHAR(20),
    stanowisko VARCHAR(20),
    data_zatrudnienia VARCHAR(23),
    placa NUMERIC,
    premia NUMERIC,
    id_dzialy INTEGER,
    FOREIGN KEY(staniowisko) REFERENCES premia(id),
    FOREIGN KEY(id_dzialy) REFERENCES działy(id)
);
